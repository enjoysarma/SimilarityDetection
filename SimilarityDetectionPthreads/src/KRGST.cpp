//KRGST.cpp

#include "KRGST.h"
#include "Program.h"
#include "ProgramPair.h"
#include "Parameters.h"
#include "Token.h"
#include <vector>


#include <chrono>
#include <iostream>
using namespace std;


ProgramPair* KRGST::compare(Program* pa, Program* pb) {
	if(pa->getNumberOfTokens() > pb->getNumberOfTokens()) swap(pa, pb);

	ProgramPair *pp 						= new ProgramPair(pa, pb);
	vector<Tile>& tiles 					= pp->getTiles();
	vector<Token*>& pa_tokens 				= pa->getTokens();
	vector<Token*>& pb_tokens 				= pb->getTokens();
	vector<unsigned long long>& pa_hashes	= pa->getKgramHashes();
	HTPMap& pb_htpmap 						= pb->getHtpMap();

	unsigned int maxmatch = Parameters::getMinimumMatchLength();
	vector<Tile> matches;
	pair<HTPMap::iterator, HTPMap::iterator> ret;

	pa->unmarkAllTokens();
	pb->unmarkAllTokens();

	do {
		maxmatch = Parameters::getMinimumMatchLength();
		matches.clear();

		for( unsigned int ai = 0; ai < pa_hashes.size(); ai++ ) {
			ret = pb_htpmap.equal_range(pa_hashes[ai]);
			for ( HTPMap::iterator it = ret.first; it != ret.second; ++it ) {
				unsigned int bi = it->second;
				unsigned int j = 0;

				while(	ai+j < pa_tokens.size() && bi+j < pb_tokens.size()	&&
						pa_tokens[ai+j]->getTokenId() == pb_tokens[bi+j]->getTokenId() &&
						pa_tokens[ai+j]->isMarked() == false &&
						pb_tokens[bi+j]->isMarked() == false
				) j++;

				if( j == maxmatch )
					addMatch(matches, Tile(ai, bi, j));
				else if( j > maxmatch ) {
					matches.clear();
					matches.push_back(Tile(ai, bi, j));
					maxmatch = j;
				}
			}
		}

		for( vector<Tile>::iterator it = matches.begin(); it != matches.end(); ++it ) {
			for( unsigned int j = 0; j < it->len; ++j ) {
				pa_tokens[it->fpi+j]->setMarked();
				pb_tokens[it->spi+j]->setMarked();
			}
			tiles.push_back(*it);
		}

	}while( maxmatch > Parameters::getMinimumMatchLength() );

	return pp;
}


void KRGST::swap(Program*& pa, Program*& pb) {
	Program *tmp = pa;
	pa = pb;
	pb = tmp;
}

void KRGST::addMatch(vector<Tile>& tiles, Tile tile) {
	for( vector<Tile>::iterator it = tiles.begin(); it != tiles.end(); ++it )
		if(	(tile.fpi <= it->fpi 			&& 	it->fpi 			< tile.fpi + tile.len) 	||
			(tile.fpi <	 it->fpi + it->len 	&& 	it->fpi + it->len 	< tile.fpi + tile.len) 	||
			(tile.spi <= it->spi 			&& 	it->spi 			< tile.spi + tile.len) 	||
			(tile.spi <  it->spi + it->len 	&& 	it->spi + it->len 	< tile.spi + tile.len)
		) return;

	tiles.push_back(tile);
}
