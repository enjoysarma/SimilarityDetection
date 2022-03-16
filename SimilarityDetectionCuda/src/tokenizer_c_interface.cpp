//tokenizer_c_interface.cpp

#include <climits>
#include "tokenizer_c_interface.h"
#include "Token.h"
#include "Table.h"

void insertToken(TokenId id, int lineNumber) {
	Table::insert(new Token(id, lineNumber));
}

void insertToken_openScope(TokenId id, int lineNumber) {
	/*
	 * Assumption:	The forwarded token belongs to the outer scope
	 */
	Table::insert(new Token(id, lineNumber));
	Table::openScope();
}

void insertToken_closeScope(TokenId id, int lineNumber) {
	/*
	* Assumption:	The forwarded token belongs to the outer scope
	*/
	Table::closeScope();
	Table::insert(new Token(id, lineNumber));
}

void insertToken_reopenScope(TokenId id, int lineNumber) {
	/*
	* Assumption:	The forwarded token belongs to the outer scope
	*/
	Table::closeScope();
	Table::insert(new Token(id, lineNumber));
	Table::openScope();
}

void openProgramScope() {
	Table::openProgramScope();
}

void closeProgramScope(int lineNumber) {
	Table::insert(new Token(END_FILE, lineNumber));
	Table::closeProgramScope();
}
