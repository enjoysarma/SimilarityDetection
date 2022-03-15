//Parameters.cpp

#include "Parameters.h"

const int 		HASH_BASE 				= 5;
const int 		MINIMUM_MATCH_LENGTH 	= 12;
const double 	CUTOFF_TRASHOLD			= 0.5;

unsigned int 	Parameters::hash_base = HASH_BASE;
unsigned int 	Parameters::minimum_match_length = MINIMUM_MATCH_LENGTH;
double			Parameters::cutoff_treshold	= CUTOFF_TRASHOLD;

unsigned int Parameters::getHashBase() {
	return hash_base;
}

void Parameters::setHashBase(unsigned int hashBase) {
	hash_base = hashBase;
}

unsigned int Parameters::getMinimumMatchLength() {
	return minimum_match_length;
}

void Parameters::setMinimumMatchLength(unsigned int minimumMatchLength) {
	minimum_match_length = minimumMatchLength;
}

double Parameters::getCutoffTreshold() {
	return cutoff_treshold;
}

void Parameters::setCutoffTreshold(double cutoffTreshold) {
	cutoff_treshold = cutoffTreshold;
}
