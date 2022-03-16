//Table.h

#ifndef _TABLE_H_
#define _TABLE_H_

#include <vector>
using namespace std;

class Token;
class Scope;

class Table {
	static Scope *currentScope;
	static vector<Scope*> programScopes;
public:
	static void openProgramScope();
	static void closeProgramScope();

	static void openScope();
	static void closeScope();

	static void insert(Token*);
	static void chainTokens(Scope*);

	static vector<Scope*>& getProgramScopes();

	static void finish();
private:
	Table(){}
	Table(const Table&){}

	static Scope* 	getCurrentScope();
	static void 	destructScope(Scope*&);
};

#endif
