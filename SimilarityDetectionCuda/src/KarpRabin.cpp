//KarpRabin.cpp

#include "KarpRabin.h"
#include "Program.h"
#include "Parameters.h"
#include "Token.h"
#include <cmath>

#include <iostream>

unsigned int KarpRabin::init_hash(vector<Token*>& tokens) {
    unsigned int mml 	= Parameters::getMinimumMatchLength();
    unsigned int b 		= Parameters::getHashBase();
    unsigned int hash = 0;

    for ( unsigned int i = 0; i < tokens.size() && i < mml; ++i) {
        hash *= b;
        hash += tokens[i]->getTokenId();
    }
	
    return hash;
}

void KarpRabin::hash(Program *p) {
    vector<Token*>& tokens	= p->getTokens();
    HTPMap& htpMap 			= p->getHtpMap();
    vector<unsigned int>& hashes 	= p->getKgramHashes();

    unsigned int mml 			= Parameters::getMinimumMatchLength();
    unsigned int b 				= Parameters::getHashBase();
    unsigned int base			= pow(b, mml - 1);
    unsigned int hash 			= init_hash(tokens);

    hashes.push_back(hash);
    htpMap.insert(HTP(hash, 0));

    /**
     * Implementation of the rolling hash system...
     *
     * TODO: Would be interesting to figure out how much of a memory hog is the system now, since there is a lot of maps and multimaps
     * that have unsigned long long type elements...
     */
    for(int i = 1; i <= static_cast<int>(tokens.size() - mml); i++) {
        hash = ( hash - tokens[i-1]->getTokenId() * base )*b  + tokens[i+mml-1]->getTokenId();
        hashes.push_back(hash);
        htpMap.insert(HTP(hash, i));
    }

}

