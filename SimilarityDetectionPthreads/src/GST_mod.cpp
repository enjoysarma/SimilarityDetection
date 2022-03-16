//GST_mod.cpp

#include "GST_mod.h"

#include "Program.h"
#include "ProgramPair.h"
#include "Parameters.h"
#include "Token.h"

#include <pthread.h>

// Needed for detection of hardware_concurrency
#include <thread>

#include <numeric>

#include <chrono>
#include <iostream>

uint32_t GST_mod::NUM_OF_THREADS 				  	= std::thread::hardware_concurrency();

pthread_mutex_t GST_mod::currentlyIdleMutex   		= PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t GST_mod::currentlyIdleCond       	= PTHREAD_COND_INITIALIZER;
uint32_t GST_mod::currentlyIdle 					= 0;

pthread_mutex_t GST_mod::workReadyMutex         	= PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t GST_mod::workReadyCond           	= PTHREAD_COND_INITIALIZER;
uint32_t GST_mod::workReady 						= 0;

pthread_mutex_t GST_mod::currentlyWorkingMutex  	= PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t GST_mod::currentlyWorkingCond    	= PTHREAD_COND_INITIALIZER;
uint32_t GST_mod::currentlyWorking 					= 0;

pthread_mutex_t GST_mod::canFinishMutex         	= PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t GST_mod::canFinishCond           	= PTHREAD_COND_INITIALIZER;
uint32_t GST_mod::canFinish 						= 0;

pthread_mutex_t GST_mod::pbMutex           		= PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t GST_mod::coutMutex           	= PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t GST_mod::addProgramPairMutex  	= PTHREAD_MUTEX_INITIALIZER;

std::vector<ProgramPair*> GST_mod::comparePthreads(std::vector<Program*>& programs)
{

    std::cout << "Hardware concurency: " << GST_mod::NUM_OF_THREADS << std::endl;

    //writes to this vector (programPairs.push_back(programPair)) from different pthreads have to be serialized
    //so using some sort of a pthread_mutex is a must
    std::vector<ProgramPair*> programPairs;

    uint32_t paIndex;
    std::vector<uint32_t> pbIndexes(programs.size() - 1);
	std::iota(pbIndexes.begin(), pbIndexes.end(), 1);

	// std::cout << "Initial pbIndexes" << std::endl;
	// for (auto it = pbIndexes.begin(); it != pbIndexes.end(); ++it)
		// std::cout << *it << ' ';
	// std::cout << std::endl;

    uint32_t MML = Parameters::getMinimumMatchLength();

    //here all the available pthreads will have to be initialized and started
    //they won't be able to do anything yet, because they will wait for the start signal from the main thread AKA this code
    std::vector<pthread_t> threads(NUM_OF_THREADS);
    std::vector<ThreadData_t*> threadData;
    GST_mod::workReady           = 0;
    GST_mod::canFinish           = 0;
    GST_mod::currentlyIdle       = 0;
    GST_mod::currentlyWorking    = 0;

    //initial setting up the threads, and their creation
    for (uint32_t i = 0; i < GST_mod::NUM_OF_THREADS; i++)
    {
        threadData.push_back(new ThreadData_t(
                                            i,

                                            programs,
                                            programPairs,
                                            MML,

                                            paIndex,
                                            pbIndexes,

                                            GST_mod::currentlyIdleMutex,
                                            GST_mod::currentlyIdleCond,
                                            GST_mod::currentlyIdle,

                                            GST_mod::workReadyMutex,
                                            GST_mod::workReadyCond,
                                            GST_mod::workReady,

                                            GST_mod::currentlyWorkingMutex,
                                            GST_mod::currentlyWorkingCond,
                                            GST_mod::currentlyWorking,

                                            GST_mod::canFinishMutex,
                                            GST_mod::canFinishCond,
                                            GST_mod::canFinish,

                                            GST_mod::pbMutex,
                                            GST_mod::coutMutex,
                                            GST_mod::addProgramPairMutex
                                           )
                            );

        int rc = pthread_create(&threads[i], NULL, GST_mod::comparePthreads, (void*) threadData[i]);
        if(rc)
        {
            std::cerr << "Error: " << rc << " while creating pthread " << i << std::endl;
			//returns empty vector of ProgramPairs
            return std::vector<ProgramPair*>();
        }
    }

	//std::cout << "Program_size: " << programs_size << std::endl;

	//make sure that all pthreads are ready
	pthread_mutex_lock(&GST_mod::currentlyIdleMutex);
	while (GST_mod::currentlyIdle != GST_mod::NUM_OF_THREADS)
	{
		pthread_cond_wait(&GST_mod::currentlyIdleCond, &GST_mod::currentlyIdleMutex);
	}
	pthread_mutex_unlock(&GST_mod::currentlyIdleMutex);

	//all threads are now blocked; it's safe to unlock the mutex
	//prevent threads from finishing unauthorized
	GST_mod::canFinish = 0;

	//reset the number of currently working threads
	GST_mod::currentlyWorking = GST_mod::NUM_OF_THREADS;

	//setup threads for new round of work
	//assign new first program to all threads
	paIndex = 0;

	//signal threads to start
	pthread_mutex_lock(&GST_mod::workReadyMutex);
	GST_mod::workReady = 1;
	pthread_cond_broadcast(&GST_mod::workReadyCond);
	pthread_mutex_unlock(&GST_mod::workReadyMutex);

	//wait for them to finish
	pthread_mutex_lock(&GST_mod::currentlyWorkingMutex);
	while (GST_mod::currentlyWorking != 0)
	{
		pthread_cond_wait(&GST_mod::currentlyWorkingCond, &GST_mod::currentlyWorkingMutex);
	}
	pthread_mutex_unlock(&GST_mod::currentlyWorkingMutex);

	//the threads are now waiting for permission to finish
	//prevent them from starting next batch of work immediately
	GST_mod::workReady = 0;
	GST_mod::currentlyIdle = 0;

	//allow them to finish execution
	pthread_mutex_lock(&GST_mod::canFinishMutex);
	GST_mod::canFinish = 1;
	pthread_cond_broadcast(&GST_mod::canFinishCond);
	pthread_mutex_unlock(&GST_mod::canFinishMutex);


    for (uint32_t i = 0; i < GST_mod::NUM_OF_THREADS; i++)
    {
        int rc = pthread_join(threads[i], NULL);
        if (rc)
        {
            std::cerr << "Error: " << rc << " while joining thread " << i << std::endl;
            return std::vector<ProgramPair*>();
        }
    }

    return programPairs;
}

void* GST_mod::comparePthreads(void* func_args)
{
    ThreadData_t* threadData = (ThreadData_t*) func_args;

    std::vector<Program*>& programs         = threadData->programs;
	uint32_t programsSize 					= programs.size();
    std::vector<ProgramPair*>& programPairs = threadData->programPairs;

	Program* pa;
	uint32_t paIndex;
    uint32_t pbIndex;

    uint32_t& MML   = threadData->MML;

	//set myself as idle, and signal main thread
	//when all threads become idle, main will start its work
	pthread_mutex_lock(&threadData->currentlyIdleMutex);
	threadData->currentlyIdle++;
	pthread_cond_signal(&threadData->currentlyIdleCond);
	pthread_mutex_unlock(&threadData->currentlyIdleMutex);

	//wait to receive permission to work from main thread
	pthread_mutex_lock(&threadData->workReadyMutex);
	while (!threadData->workReady)
	{
		 pthread_cond_wait(&threadData->workReadyCond, &threadData->workReadyMutex);
	}
	pthread_mutex_unlock(&threadData->workReadyMutex);

    //threads will run in this "infinite" loop until they run through all the pairs
    do
    {
        //work:
        pthread_mutex_lock(&threadData->pbMutex);
			paIndex = threadData->paIndex;

			if (paIndex < (programsSize - 1))
			{
				pa = programs[paIndex];
				pbIndex = threadData->pbIndexes[paIndex]++;
			}
        pthread_mutex_unlock(&threadData->pbMutex);

		if (paIndex >= (programsSize - 1))
			break;


        //do the following in a loop as long as there are more pbs that need to be compared with curent pa
        while(pbIndex < programs.size())
        {

			Program* pb = programs[pbIndex];

			ProgramPair* pp = new ProgramPair(pa, pb);
			std::vector<Tile>& tiles = pp->getTiles();
			std::list<Tile> matches;

			//find initial matches nad sort them (longer first)
			GST_mod::findMatches(pa, pb, MML, matches);

			comparePhase2(matches, tiles);

            pp->estimateSimilarity();

            pthread_mutex_lock(&threadData->addProgramPairMutex);
            programPairs.push_back(pp);
            pthread_mutex_unlock(&threadData->addProgramPairMutex);

            pthread_mutex_lock(&threadData->pbMutex);
            pbIndex = threadData->pbIndexes[paIndex]++;
            pthread_mutex_unlock(&threadData->pbMutex);

        } //end while

		pthread_mutex_lock(&threadData->pbMutex);
			threadData->paIndex++;
			paIndex = threadData->paIndex;
		pthread_mutex_unlock(&threadData->pbMutex);

	} while (paIndex < (programsSize - 1)); //end while

	//mark myself as finished and signal main thread
	pthread_mutex_lock(&threadData->currentlyWorkingMutex);
	threadData->currentlyWorking--;
	pthread_cond_signal(&threadData->currentlyWorkingCond);
	pthread_mutex_unlock(&threadData->currentlyWorkingMutex);

	//wait for permission to finish execution
	pthread_mutex_lock(&threadData->canFinishMutex);
	while (!threadData->canFinish)
	{
		pthread_cond_wait(&threadData->canFinishCond, &threadData->canFinishMutex);
	}
	pthread_mutex_unlock(&threadData->canFinishMutex);

    return NULL;
}

void GST_mod::findMatches(
	Program* pa,
	 Program* pb,
	const uint32_t& MML,
	std::list<Tile>& matches
	)
{
	std::vector<Token*>& paTokens 			= pa->getTokens();
	std::vector<Token*>& pbTokens 			= pb->getTokens();
	vector<unsigned long long>& paHashes 	= pa->getKgramHashes();
	HTPMap& pbHtpMap 						= pb->getHtpMap();
	pair<HTPMap::iterator, HTPMap::iterator> ret;

	uint32_t substrLen = 0;
	uint32_t paTokensSize = paTokens.size();
	uint32_t pbTokensSize = pbTokens.size();

    for (uint32_t fpi = 0; fpi < paHashes.size(); fpi++)
	{
		ret = pbHtpMap.equal_range(paHashes[fpi]);
		for (auto it = ret.first; it != ret.second; ++it)
		{
			uint32_t spi = it->second;

			while ((fpi + substrLen < paTokensSize) &&
				   (spi + substrLen < pbTokensSize) &&
				   (paTokens[fpi + substrLen]->getTokenId() == pbTokens[spi + substrLen]->getTokenId())
				  )
			{
				substrLen++;
			}

			// only if the length of newly found substring is longer than MML (Minimum Match Length), write it back to dMatches
			if (substrLen >= MML)
			{
				matches.push_back(Tile(fpi, spi, substrLen));
			}

			substrLen = 0;
		}
	}

	matches.sort( []( const Tile& t1, const Tile& t2 )
					{
						return (t1.len > t2.len) ||
							   (t1.len == t2.len && t1.fpi < t2.fpi) ||
							   (t1.len == t2.len && t1.spi < t2.spi);
					}
				);

}

void GST_mod::comparePhase2(
							std::list<Tile>& substrList,
							std::vector<Tile>& tiles
							)
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
 * @returns:
	-1:	if tile was updated, and new length <= MML. This marks the tile for deletion
	0:	if tile wasn't updated, proceed with next step
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
