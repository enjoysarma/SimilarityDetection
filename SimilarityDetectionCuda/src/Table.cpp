//Table.cpp

#include "Table.h"
#include "Scope.h"
#include "Token.h"

Scope* Table::currentScope = 0;
vector<Scope*> Table::programScopes = vector<Scope*>();

void Table::openProgramScope() {
	currentScope = new Scope();
}

void Table::closeProgramScope() {
	programScopes.push_back(currentScope);
	currentScope = 0;
}

void Table::openScope() {
	currentScope = new Scope(currentScope);
}

void Table::closeScope(){
	if(currentScope == 0) return;
	Scope* outerScope = currentScope->getOuter();
	if ( outerScope != 0) {
		chainTokens(outerScope);
		delete currentScope;
		currentScope = outerScope;
	} else {
		closeProgramScope();
	}
}

void Table::insert(Token* token) {
	currentScope->addToken(token);
}

void Table::chainTokens(Scope* scope) {
	if ( scope != 0 && currentScope != 0) scope->addTokens(currentScope->getTokens());
}

vector<Scope*>& Table::getProgramScopes() {
	return programScopes;
}

void Table::finish() {
	for( unsigned int i = 0; i < programScopes.size(); ++i ) destructScope(programScopes[i]);
}

Scope* Table::getCurrentScope() {
	return currentScope;
}

void Table::destructScope(Scope*& scope) {
	if( scope == 0 ) return;
	for( unsigned int i = 0; i < scope->getTokens().size(); ++i ) delete scope->getTokens()[i];
	delete scope;
	scope = 0;
}
