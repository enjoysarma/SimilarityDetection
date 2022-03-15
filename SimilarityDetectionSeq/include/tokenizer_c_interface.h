//tokenizer_c_interface.h

#ifndef _TOKENIZER_C_INTERFACE_
#define _TOKENIZER_C_INTERFACE_

#include "tokentype.h"

void insertToken(TokenId, int);
void insertToken_openScope(TokenId, int);
void insertToken_closeScope(TokenId, int);
void insertToken_reopenScope(TokenId, int);

void openProgramScope();
void closeProgramScope(int);

#endif
