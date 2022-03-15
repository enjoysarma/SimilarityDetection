/**
 * Modified version of the Greedy-String-Tiling algorithm
 * Doesn't use file checksums (Rabin-Karp hashing)
 */

#ifndef GST_MOD_H
#define GST_MOD_H

#include "Tile.h"

#include <pthread.h>

#include <cstdint>
#include <list>
#include <vector>

class Token;
class Program;
class ProgramPair;

struct ThreadData_t
{
    uint32_t id;
    std::vector<Program*>& programs;
    std::vector<ProgramPair*>& programPairs;
    uint32_t& MML;

    uint32_t& paIndex;
    std::vector<uint32_t>& pbIndexes;

    //mutexes and conditionals
    pthread_mutex_t& 	currentlyIdleMutex;
    pthread_cond_t&  	currentlyIdleCond;
    uint32_t&          	currentlyIdle;

    pthread_mutex_t& 	workReadyMutex;
    pthread_cond_t&  	workReadyCond;
    uint32_t&          	workReady;

    pthread_mutex_t& 	currentlyWorkingMutex;
    pthread_cond_t&  	currentlyWorkingCond;
    uint32_t&          	currentlyWorking;

    pthread_mutex_t& 	canFinishMutex;
    pthread_cond_t&  	canFinishCond;
    uint32_t&          	canFinish;

    pthread_mutex_t& 	pbMutex;
    pthread_mutex_t& 	coutMutex;
    pthread_mutex_t& 	addProgramPairMutex;

    ThreadData_t(
				uint32_t s_id,
				
				std::vector<Program*>& s_programs, std::vector<ProgramPair*>& s_programPairs,
				uint32_t s_MML,
				
				uint32_t& s_paIndex,
				std::vector<uint32_t>& s_pbIndexes,
				
				pthread_mutex_t& s_currentlyIdleMutex,    pthread_cond_t& s_currentlyIdleCond,      uint32_t& s_currentlyIdle,
				pthread_mutex_t& s_workReadyMutex,        pthread_cond_t& s_workReadyCond,          uint32_t& s_workReady,
				pthread_mutex_t& s_currentlyWorkingMutex, pthread_cond_t& s_currentlyWorkingCond,   uint32_t& s_currentlyWorking,
				pthread_mutex_t& s_canFinishMutex,        pthread_cond_t& s_canFinishCond,          uint32_t& s_canFinish,
				
				pthread_mutex_t& s_pbMutex,
				pthread_mutex_t& s_coutMutex,
				pthread_mutex_t& s_addProgramPairMutex
				)
				: id(s_id),
				
				  programs(s_programs), programPairs(s_programPairs), MML(s_MML),
				  
				  paIndex(s_paIndex),
				  pbIndexes(s_pbIndexes),
				  
				  currentlyIdleMutex(s_currentlyIdleMutex), currentlyIdleCond(s_currentlyIdleCond), currentlyIdle(s_currentlyIdle),
				  workReadyMutex(s_workReadyMutex), workReadyCond(s_workReadyCond), workReady(s_workReady),
				  currentlyWorkingMutex(s_currentlyWorkingMutex), currentlyWorkingCond(s_currentlyWorkingCond), currentlyWorking(s_currentlyWorking),
				  canFinishMutex(s_canFinishMutex), canFinishCond(s_canFinishCond), canFinish(s_canFinish),
				  
				  pbMutex(s_pbMutex),
				  coutMutex(s_coutMutex),
				  addProgramPairMutex(s_addProgramPairMutex)
    {}
};

class GST_mod
{
public:
    static std::vector<ProgramPair*> comparePthreads(std::vector<Program*>& programs);

private:
	static void* comparePthreads(void* func_args);
    static void comparePhase2(std::list<Tile>& substrList, std::vector<Tile>& tiles);

	static void findMatches(
							const std::vector<Token*>& paTokens,
							const std::vector<Token*>& pbTokens,
							uint32_t MML,
							std::list<Tile>& matches
							);
	
    static int updateTile(std::vector<Tile>& tiles, Tile& tile);

private:
    static const uint32_t TOKENS_COUNT_MAX = 1000;

public:
	static uint32_t NUM_OF_THREADS;

	/**
	 * Synchronization primitives, used by pthreads
	 */

	static pthread_mutex_t currentlyIdleMutex;
	static pthread_cond_t  currentlyIdleCond;
	static uint32_t        currentlyIdle;

	static pthread_mutex_t workReadyMutex;
	static pthread_cond_t  workReadyCond;
	static uint32_t 	   workReady;

	static pthread_mutex_t currentlyWorkingMutex;
	static pthread_cond_t  currentlyWorkingCond;
	static uint32_t        currentlyWorking;

	static pthread_mutex_t canFinishMutex;
	static pthread_cond_t  canFinishCond;
	static uint32_t        canFinish;

	static pthread_mutex_t pbMutex;
	static pthread_mutex_t coutMutex;
	static pthread_mutex_t addProgramPairMutex;
};

#endif
