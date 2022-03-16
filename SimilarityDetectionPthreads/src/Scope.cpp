//Scope.cpp

#include "Scope.h"

Scope* Scope::getOuter() {
	return this->outer;
}

void Scope::setOuter(Scope* parent) {
	this->outer = parent;
}

vector<Token*>& Scope::getTokens() {
	return this->tokens;
}

void Scope::addToken(Token* token) {
	tokens.push_back(token);
}

void Scope::addTokens(vector<Token*>& tokens) {
	if(&tokens != &this->tokens)
		this->tokens.insert(this->tokens.end(), tokens.begin(), tokens.end());
}
