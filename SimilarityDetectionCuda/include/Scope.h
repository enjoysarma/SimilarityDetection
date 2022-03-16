//Scope.h

#ifndef _SCOPE_H_
#define _SCOPE_H_

#include <vector>
#include "Token.h"
using namespace std;


class Scope {
	Scope* outer;
	vector<Token*> tokens;
public:
	Scope() : outer(0) {}
	Scope(Scope* o) : outer(o) {}

	Scope* getOuter();
	void setOuter(Scope*);

	vector<Token*>& getTokens();

	void addToken(Token*);
	void addTokens(vector<Token*>&);

};


#endif
