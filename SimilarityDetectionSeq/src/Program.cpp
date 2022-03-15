//Program.cpp

#include "Program.h"
#include "Token.h"

Program::Program(string n) : name(n) {}

Program::Program(string n, vector<Token*> t) : name(n), tokens(t) {}


HTPMap& Program::getHtpMap(){
	return htpMap;
}

void Program::setHtpMap(HTPMap htpMap) {
	this->htpMap = htpMap;
}

vector<unsigned long long>& Program::getKgramHashes() {
	return kgramHashes;
}

void Program::setKgramHashes(vector<unsigned long long> kgramHashes) {
	this->kgramHashes = kgramHashes;
}

string& Program::getName() {
	return name;
}

void Program::setName(string name) {
	this->name = name;
}

vector<Token*>& Program::getTokens() {
	return tokens;
}

void Program::setTokens(vector<Token*>& tokens) {
	this->tokens = tokens;
}

unsigned int Program::getNumberOfTokens() {
	return tokens.size();
}

void Program::unmarkAllTokens() {
	for(vector<Token*>::iterator it = tokens.begin(); it != tokens.end(); ++it)
		(*it)->resetMarked();
}



