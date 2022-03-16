/**
 * GST_mod.cu - GST algorithm modification that utilises GPU using CUDA is defined here
 */

#include "GST_mod.h"
#include "Program.h"
#include "ProgramPair.h"
#include "Parameters.h"
#include "Token.h"

#include "Refactor.h"

#include <list>
#include <vector>

#include <cstdint>

#include <cuda_runtime.h>

#include <chrono>
#include <iostream>

#define gpuErrorCheck(ans) {gpuAssert((ans), __FILE__, __LINE__); }
inline void gpuAssert(cudaError_t code, const char* file, int line, bool abort = true)
{
    if (code != cudaSuccess)
    {
        std::cerr << "GPUassert: " << cudaGetErrorString(code) << ' ' << file << ' ' << line << std::endl;
        if (abort) exit(code);
    }
}

/**
 * @brief: Wrapper function for kernel calls. Defined in findMatchesKernel.cu
 */
void findMatches(
    uint32_t*   dpaTokens,
    uint32_t*   dpaTokensHashes,
    uint32_t    dpaTokensSize,
    uint32_t*   dpbTokens,
    uint32_t*   dpbTokensHashes,
    uint32_t    dpbTokensSize,
    uint32_t    MML,
    uint32_t*   dMatches,
    uint32_t*   dMatchesIndex,
    uint32_t    iteration
);

/**
 * @brief: This method compares files provided in programs vector and returns a vector of program pairs for all possible pairs
 *
 * @param in: programs      - vector of programs that are to be compared for similarities
 * @param in: gpu_phase1    - used in profiling/timing the execution for the first phase of the algorithm
 * @param in: gpu_phase2    - used in profiling/timing the execution for the second phase of the algorithm
 *
 * @returns: programPairs   - vector of program pairs with all similarities calculated
 */
std::vector<ProgramPair*> GST_mod::compareGPU(std::vector<Program*>& programs, float& gpu_phase1, float& gpu_phase2)
{
    //cudaEvents
    // create events for timing execution
    cudaEvent_t start = cudaEvent_t();
    cudaEvent_t stop = cudaEvent_t();
    cudaEventCreate(&start);
    cudaEventCreate(&stop);
    float elapsed = 0.f;

    //Used for determining DtoH transfer overhead after each kernel invocation
    float gpu_phase2_prep = 0.f;
    
    /**
     * Initialization of the system...
     */
    // record time into start event
    cudaEventRecord( start, 0 ); // 0 is the default stream id 

    uint32_t MML = Parameters::getMinimumMatchLength();
    uint32_t programsSize = programs.size();
    
    std::vector<ProgramPair*> programPairs;

    //vector of indexes on the GPU side, used by GPU kernels
    uint32_t* dMatchesIndexes;
    gpuErrorCheck(cudaMalloc((void**)&dMatchesIndexes, programsSize * sizeof(uint32_t)));
    gpuErrorCheck(cudaMemset(dMatchesIndexes, 0x0, programsSize * sizeof(uint32_t)));

    std::vector<std::vector<uint32_t>> hMatchesIndexes(programsSize);
    for (uint32_t i = 0; i < programsSize; i++)
    {
        hMatchesIndexes[i] = std::vector<uint32_t>(programsSize);
    }

    uint32_t* dMatches;
    gpuErrorCheck(cudaMalloc((void**)&dMatches,
                             (Parameters::getMaxTokenVectorSize() - MML) *
                             (Parameters::getMaxTokenVectorSize() - MML) *
                             programsSize *
                             sizeof(uint32_t)
                            )
                 );
    std::vector<std::vector<uint32_t>> hMatchesVector(programsSize);

    std::vector<uint32_t> hTokenVectors;
    std::vector<uint32_t> hTokenVectorIndexes;
    std::vector<uint32_t> hTokenVectorSizes;
    std::vector<uint32_t> hTokenHashVectors;
    std::vector<uint32_t> hTokenHashVectorIndexes;

    for (uint32_t i = 0; i < programsSize; i++)
    {
        std::vector<uint32_t>& piTokenIds = programs[i]->getTokenIds();
		std::vector<uint32_t>& piTokenHashes = programs[i]->getKgramHashes();

        hTokenVectorIndexes.push_back(hTokenVectors.size());
        hTokenVectors.insert(hTokenVectors.end(),
                             piTokenIds.begin(),
                             piTokenIds.end()
                            );
        hTokenVectorSizes.push_back(piTokenIds.size());
        
        hTokenHashVectorIndexes.push_back(hTokenHashVectors.size());
        hTokenHashVectors.insert(hTokenHashVectors.end(),
                                 piTokenHashes.begin(),
                                 piTokenHashes.end()
                                );
    }

    uint32_t* dTokenVectors;
    gpuErrorCheck(cudaMalloc(&dTokenVectors,
                             hTokenVectors.size() * sizeof(uint32_t)
                            )
                 );
    gpuErrorCheck(cudaMemcpy(dTokenVectors,
                             &hTokenVectors[0],
                             hTokenVectors.size() * sizeof(uint32_t),
                             cudaMemcpyHostToDevice
                            )
                 );
    uint32_t* dTokenHashVectors;
    gpuErrorCheck(cudaMalloc(&dTokenHashVectors,
                             hTokenHashVectors.size() * sizeof(uint32_t)
                            )
                 );
    gpuErrorCheck(cudaMemcpy(dTokenHashVectors,
                             &hTokenHashVectors[0],
                             hTokenHashVectors.size() * sizeof(uint32_t),
                             cudaMemcpyHostToDevice
                            )
                 );

    // record time into stop event
    cudaEventRecord( stop, 0 );
    // synchronize stop event to wait for end of kernel execution on stream 0
    cudaEventSynchronize( stop );
    // compute elapsed time (done by CUDA run-time)

    cudaEventElapsedTime( &elapsed, start, stop );
    std::cout << "GPU initialization phase: " << elapsed << "[ms]" << std::endl;
    
    /*
     * Main algorithm...
     */
    Program *pa, *pb;
    for (unsigned int i = 0; i < programsSize; i++)
    {
//PHASE1:
        // record time into start event
        cudaEventRecord( start, 0 ); // 0 is the default stream id 
        for (unsigned int j = i + 1; j < programsSize; j++)
        {
            //if j == i + 1, findMatches will call firstIter kernel, othervise it will call regular kernel
            //difference between these two is in the setting up the initial dMatchesIndex value
			findMatches(
                &dTokenVectors[hTokenVectorIndexes[i]],
                &dTokenHashVectors[hTokenHashVectorIndexes[i]],
                hTokenVectorSizes[i],
                &dTokenVectors[hTokenVectorIndexes[j]],
                &dTokenHashVectors[hTokenHashVectorIndexes[j]],
                hTokenVectorSizes[j],
                MML,
                dMatches,
                &dMatchesIndexes[j],
                !(j == (i + 1))
            );

            if (j != programsSize - 1)
                gpuErrorCheck(cudaMemcpy(&dMatchesIndexes[j + 1], &dMatchesIndexes[j], sizeof(uint32_t), cudaMemcpyDeviceToDevice));
        }
//PHASE1_END
        // record time into stop event
        cudaEventRecord( stop, 0 );
        // synchronize stop event to wait for end of kernel execution on stream 0
        cudaEventSynchronize( stop );
        // compute elapsed time (done by CUDA run-time)
        cudaEventElapsedTime( &elapsed, start, stop );
        gpu_phase1 += elapsed;

        /**
         * Copying preliminary data - phase2 prep stage
         */
        // record time into start event
        cudaEventRecord( start, 0 ); // 0 is the default stream id 
        //copy dMatchesIndexes to hMatchesIndexes
        gpuErrorCheck(cudaMemcpyAsync(&hMatchesIndexes[i][0], dMatchesIndexes, programsSize * sizeof(uint32_t), cudaMemcpyDeviceToHost));
        //based on the hMatchesIndexes.last copy dMatches back to hMatches
        hMatchesVector[i] = std::vector<uint32_t>(hMatchesIndexes[i].back());
        gpuErrorCheck(cudaMemcpyAsync(&hMatchesVector[i][0], dMatches, hMatchesIndexes[i].back() * sizeof(uint32_t), cudaMemcpyDeviceToHost));
        //reset dMatchesIndexes
        gpuErrorCheck(cudaMemsetAsync(dMatchesIndexes, 0x0, programsSize * sizeof(uint32_t)));
        // record time into stop event
        cudaEventRecord( stop, 0 );
        // synchronize stop event to wait for end of kernel execution on stream 0
        cudaEventSynchronize( stop );
        // compute elapsed time (done by CUDA run-time)
        cudaEventElapsedTime( &elapsed, start, stop );
        gpu_phase2_prep += elapsed;

    }
    
//PHASE2
    std::chrono::high_resolution_clock::time_point phase2_start = std::chrono::high_resolution_clock::now();
    for (unsigned int i = 0; i < programsSize; i++)
    {
        pa = programs[i];
        for (unsigned int j = i + 1; j < programsSize; j++)
        {            
            pb = programs[j];

            ProgramPair* pp = new ProgramPair(pa, pb);

            std::vector<Tile>& tiles = pp->getTiles();

            //Decompress GPU output vector and add to a std::list for convenience sake
            //MASK_TILE_FPI and MASK_TILE_SPI extract the first and second token vector position for the given substring
            //MASK_TILE_LEN extracts the length of the given substring
            std::list<Tile> substrList;
            for (uint32_t k = hMatchesIndexes[i][j - 1]; k < hMatchesIndexes[i][j]; k++)
            {
                substrList.push_back(Tile((hMatchesVector[i][k] & MASK_TILE_FPI) >> TILE_FPI_SH,
                            (hMatchesVector[i][k] & MASK_TILE_SPI) >> TILE_SPI_SH,
                            (hMatchesVector[i][k] & MASK_TILE_LEN)
                            )
                        );
            }
            
            //Sort the new list in the decreasing order of length
            substrList.sort( []( const Tile& t1, const Tile& t2 )
                {
                    return (t1.len > t2.len) ||
                           (t1.len == t2.len && t1.fpi < t2.fpi) ||
                           (t1.len == t2.len && t1.spi < t2.spi);
                }
            );
            //execute phase 2 of the algorithm
            //select best substrings for the final substring list - tiles
            compareGPUPhase2(substrList, tiles);

            pp->estimateSimilarity();
            programPairs.push_back(pp);
        }
    }
//PHASE2_END
    gpu_phase2 += std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - phase2_start).count();
    
    std::cout << "GPUPhase2_prep: " << gpu_phase2_prep << "[ms]" << std::endl;
    
    /*
     * Cleaning up...
     */
     
     //cudaEvents
    // release events
    cudaEventDestroy(start);
    cudaEventDestroy(stop);
    
    //TODO: Perform cleanup of GPU vectors
 
    return programPairs;
}

/**
 * @brief: Extracts best matches from the input list and puts them in the output list. Best matches are the longest non-overlapping substrings
 *
 * @param in:   substrList  - a list of all found matching substrings
 * @param out:  tiles       - a list of best possible matches
 */
void GST_mod::compareGPUPhase2(std::list<Tile>& substrList, std::vector<Tile>& tiles)
{
    auto it_previous = substrList.begin();
    int tileChanged = 0;

    for (auto it = substrList.begin(); it != substrList.end();)
    {
        tileChanged = updateTile(tiles, *it);

        switch (tileChanged)
        {
            case -1:
                {
                    //delete this tile from substr_list
                    it = substrList.erase(it);
                    break;
                }
            case 0:
                {
                    //add this tile to tiles
                    tiles.push_back(Tile(it->fpi, it->spi, it->len));
                    it_previous = it;
                    ++it;
                    break;
                }
            case 1:
                {
                    //update this tile's location in substr_list
                    auto it_new = it; ++it_new;
                    while (it_new != substrList.end() && *it_new > *it) ++it_new;

                    substrList.splice(it_new, substrList, it);
                    it = it_previous;
                    ++it;
                    break;
                }
            default:
                {
                    cout << endl << "DEFAULT CASE" << endl << endl;
                }
        }

    }

}

/**
 * @brief: Updates the input list by reordering it if necessary
 *
 * @param in|out :  tiles   - list that is updated
 * @param in:       tile    - tile that is to be updated if necessary
 * @returns:
   -1:	if tile was updated, and new length <= MML. This marks the tile for deletion
   0 :	if tile wasn't updated, proceed with next step
   +1:	if tile was updated, and needs to be repositioned withing the list
 */
int GST_mod::updateTile(std::vector<Tile>& tiles, Tile& tile)
{
    int retVal = 0;

    for (auto it = tiles.begin(); it != tiles.end(); ++it)
    {
        if ((tile.fpi >= it->fpi) && (tile.fpi < (it->fpi + it->len)))
        {
            unsigned int move = ((it->fpi + it->len) - tile.fpi);

            if ((move > tile.len) || ((tile.len - move) < Parameters::getMinimumMatchLength())) return -1;

            tile.len -= move;

            //update pointers for both vectors
            tile.fpi += move;
            tile.spi += move;

            retVal = 1;
        }
        else if (tile.fpi + tile.len > it->fpi && tile.fpi + tile.len < it->fpi + it->len)
        {
            unsigned int move = ((tile.fpi + tile.len) - it->fpi);

            if ((move > tile.len) || ((tile.len - move) < Parameters::getMinimumMatchLength())) return -1;

            tile.len -= move;

            retVal = 1;
        }

        if (tile.spi >= it->spi && tile.spi < it->spi + it->len)
        {
            unsigned int move = ((it->spi + it->len) - tile.spi);

            if ((move > tile.len) || ((tile.len - move) < Parameters::getMinimumMatchLength())) return -1;

            tile.len -= move;

            tile.spi += move;
            tile.fpi += move;

            retVal = 1;
        }
        else if (tile.spi + tile.len > it->spi && tile.spi + tile.len < it->spi + it->len)
        {
            unsigned int move = ((tile.spi + tile.len) - it->spi);

            if ((move > tile.len) || ((tile.len - move) < Parameters::getMinimumMatchLength())) return -1;

            tile.len -= move;

            retVal = 1;
        }
    }

    return retVal;
}
