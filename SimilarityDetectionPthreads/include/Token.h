//Token.h

#ifndef _TOKEN_H_
#define _TOKEN_H_

#include "tokentype.h"

class Token {
	TokenId tokenId;
	int	lineNumber;
	bool marked;
public:
	Token(TokenId tId, int lN) : tokenId(tId), lineNumber(lN), marked(false) {}

	int getLineNumber() ;
	void setLineNumber(int lineNumber);
	TokenId getTokenId() ;
	void setTokenId(TokenId tokenId);

	void setMarked();
	void resetMarked();
	bool isMarked();

};

#endif
