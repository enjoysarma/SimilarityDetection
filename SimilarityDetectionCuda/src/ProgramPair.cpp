//ProgramPair.cpp

#include "ProgramPair.h"
#include "Program.h"


ProgramPair::ProgramPair(Program *f, Program *s) : first(f), second(s), similarity(0.0) {}

Program* ProgramPair::getFirst() {
	return this->first;
}

Program* ProgramPair::getSecond() {
	return this->second;
}

vector<Tile>& ProgramPair::getTiles() {
	return this->tiles;
}

double ProgramPair::getSimilarity() {
	return this->similarity;
}

void ProgramPair::addTile(Tile tile) {
	tiles.push_back(tile);
}

void ProgramPair::estimateSimilarity() {
	similarity = static_cast<double>(2 * tilesCoverage()) / ( first->getNumberOfTokens() + second->getNumberOfTokens() );
}

unsigned int ProgramPair::tilesCoverage() {
	unsigned int coverage = 0;
	for( unsigned int i = 0; i < tiles.size(); i++ )
		coverage += tiles[i].len;
	return coverage;
}
