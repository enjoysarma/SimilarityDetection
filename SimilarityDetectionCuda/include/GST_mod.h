/**
 * Modified version of the Greedy-String-Tiling algorithm
 * Doesn't use file checksums (Rabin-Karp hashing)
 */

#ifndef GST_MOD_H
#define GST_MOD_H

#include "Tile.h"

#include <cstdint>
#include <list>
#include <vector>


class Program;
class ProgramPair;

class GST_mod
{
public:
    static std::vector<ProgramPair*> compareGPU(std::vector<Program*>& programs, float& gpu_phase1, float& gpu_phase2);
    
private:
    static void compareGPUPhase2(std::list<Tile>& substrList, std::vector<Tile>& tiles);
    static int updateTile(std::vector<Tile>& tiles, Tile& tile);
};

#endif
