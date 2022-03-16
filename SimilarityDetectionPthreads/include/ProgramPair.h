//ProgramPair.h

#ifndef _PROGRAMPAIR_H_
#define _PROGRAMPAIR_H_

#include <vector>
#include "Tile.h"
using namespace std;

class Program;

class ProgramPair{
	Program *first, *second;
	vector<Tile> tiles;
	double similarity;
public:
	ProgramPair(Program* f, Program* s);
	~ProgramPair(){}
	
	Program * getFirst();
	Program * getSecond();
	vector<Tile>& getTiles();
	double getSimilarity();

	void addTile(Tile);
	void estimateSimilarity();
//private:
	unsigned int tilesCoverage();
};

#endif
