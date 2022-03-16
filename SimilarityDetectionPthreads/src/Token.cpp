//Token.cpp

#include "Token.h"

int Token::getLineNumber() {
	return lineNumber;
}

void Token::setLineNumber(int lineNumber) {
	this->lineNumber = lineNumber;
}

TokenId Token::getTokenId() {
	return tokenId;
}

void Token::setTokenId(TokenId tokenId) {
	this->tokenId = tokenId;
}


void Token::setMarked() {
	this->marked = true;
}

void Token::resetMarked() {
	this->marked = false;
}

bool Token::isMarked() {
	return this->marked;
}
