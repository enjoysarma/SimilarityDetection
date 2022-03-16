/**
 *
 * findMatchesKernel.cu - GPU kernels and wrapper functions are defined in this file
 *
 */
#include "Refactor.h"

#include <cmath>
#include <cstdint>
#include <iostream>

#define MAX_THREADS_PER_BLOCK 1024

/**
 * @brief: Error checking utility
 */
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
 * @brief: Convenience structure for input arguments passed to the GPU kernels
 */
template <typename T>
struct KernelVector
{
    T*  m_vector;
    T*  m_hashes;
    uint32_t m_size;

    KernelVector(T* dVec)
    {
        m_vector = dVec;
        m_size = 0;
    }

    KernelVector(T* dVec, T dVecSize)
    {
        m_vector 	= dVec;
        m_size 		= dVecSize;
    }

    KernelVector(T* dVec, T* dVecHashes, T dVecSize)
    {
        m_vector 	= dVec;
        m_hashes 	= dVecHashes;
        m_size 		= dVecSize;
    }
};


__device__ uint32_t compressTile(uint32_t fpi, uint32_t spi, uint32_t len)
{
    return (((fpi << TILE_FPI_SH) & MASK_TILE_FPI) |
            ((spi << TILE_SPI_SH) & MASK_TILE_SPI) |
            (len & MASK_TILE_LEN)
           );
}

//using __ldg() to cache read-only data from GMEM - this speeds up the kernel execution by near 12%
__global__ void findMatchesKernel_firstIter (
        KernelVector<uint32_t> dpaTokens,
        KernelVector<uint32_t> dpbTokens,
        uint32_t MML,
        KernelVector<uint32_t> dMatches,
        uint32_t* dMatchesIndex
        )
{
    int32_t idx = blockIdx.x * blockDim.x + threadIdx.x;
    int32_t idy = blockIdx.y * blockDim.y + threadIdx.y;

    uint32_t substrLen = 0;

    // if (dpaTokens.m_hashes[idx] == dpbTokens.m_hashes[idy])
    if (__ldg(&dpaTokens.m_hashes[idx]) == __ldg(&dpbTokens.m_hashes[idy]))
    {
        while ((idx + substrLen < dpaTokens.m_size) &&
                (idy + substrLen < dpbTokens.m_size) &&
                (__ldg(&dpaTokens.m_vector[idx + substrLen]) == __ldg(&dpbTokens.m_vector[idy + substrLen]))
                // (dpaTokens.m_vector[idx + substrLen] == dpbTokens.m_vector[idy + substrLen])
              )
            substrLen++;		

        if (substrLen >= MML)
        {
            dMatches.m_vector[atomicAdd(dMatchesIndex, 1)] = compressTile(idx, idy, substrLen);
        }
    }

    return;
}

//using __ldg() to cache read-only data from GMEM - this speeds up the kernel execution by near 12%
__global__ void findMatchesKernel (
        KernelVector<uint32_t> dpaTokens,
        KernelVector<uint32_t> dpbTokens,
        uint32_t MML,
        KernelVector<uint32_t> dMatches,
        uint32_t* dMatchesIndex
        )
{
    int32_t idx = blockIdx.x * blockDim.x + threadIdx.x;
    int32_t idy = blockIdx.y * blockDim.y + threadIdx.y;

    uint32_t substrLen = 0;

    
    // if (dpaTokens.m_hashes[idx] == dpbTokens.m_hashes[idy])
    if (__ldg(&dpaTokens.m_hashes[idx]) == __ldg(&dpbTokens.m_hashes[idy]))
    {
        while ((idx + substrLen < dpaTokens.m_size) &&
                (idy + substrLen < dpbTokens.m_size) &&
                (__ldg(&dpaTokens.m_vector[idx + substrLen]) == __ldg(&dpbTokens.m_vector[idy + substrLen]))
                // (dpaTokens.m_vector[idx + substrLen] == dpbTokens.m_vector[idy + substrLen])
              )
            substrLen++;		

        if (substrLen >= MML)
        {
            //following doesn't work in the case where no threads write to the output - input files are completely different
            // uint32_t* prevIndex = (dMatchesIndex - 1);
            // atomicCAS(dMatchesIndex, 0, *(prevIndex));
            
            dMatches.m_vector[atomicAdd(dMatchesIndex, 1)] = compressTile(idx, idy, substrLen);
        }
    }

    return;
}

/**
 *
 * @brief: Wrapper function around GPU kernels
 *
 * @param dpaTokens         - vector of tokens for the first program in comparison
 * @param dpaTokensHashes   - vector of hashes for the first program in comparison
 * @param dpaTokensSize     - sizeof(first_vector), needed for kernel grid and block size calculation
 * @param dpbTokens         - same as for the first program
 * @param dpbTokensHashes   - same as for the first program
 * @param dpbTokensSize     - same as for the first program
 * @param MML               - Minimum Match Length as predetermined in Parameters.cpp
 * @param dMatches          - output vector for storing results
 * @param dMatchesIndex     - index thats GPU threads use when writing to the output vector
 * @param iteration         - based on the value, different kernel is executed (first iteration is different from others)
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
)
{

    //threads are organized in a 2D grid,
    //this way each thread works on one pair of partA_hash and partB_hash
    dim3 dimBlock(sqrt(MAX_THREADS_PER_BLOCK), sqrt(MAX_THREADS_PER_BLOCK));
    dim3 dimGrid(
            ceil((dpaTokensSize - MML + 0.0) / dimBlock.x),
            ceil((dpbTokensSize - MML + 0.0) / dimBlock.y)
            );

    //currently both kernels execute same code
    if (0 == iteration)
    {
        findMatchesKernel_firstIter <<< dimGrid, dimBlock >>>
            (
             KernelVector<uint32_t>(dpaTokens, dpaTokensHashes, dpaTokensSize),
             KernelVector<uint32_t>(dpbTokens, dpbTokensHashes, dpbTokensSize),
             MML,
             dMatches,
             dMatchesIndex
            );        
    }
    else
    {
        findMatchesKernel <<< dimGrid, dimBlock >>>
            (
             KernelVector<uint32_t>(dpaTokens, dpaTokensHashes, dpaTokensSize),
             KernelVector<uint32_t>(dpbTokens, dpbTokensHashes, dpbTokensSize),
             MML,
             dMatches,
             dMatchesIndex
            );
    }
        
    gpuErrorCheck(cudaPeekAtLastError());
}
