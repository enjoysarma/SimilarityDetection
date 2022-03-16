//tokentype.cpp

#include <stdlib.h>
#include <string>
#include "tokentype.h"

const int VAR_TO_ARRAY_DISTANCE = 5;

TokenId getArrayToken(TokenId token) {
	if(token > USERTYPE_ARRAY_VARDEF ) exit(1);

	return (TokenId)(token + VAR_TO_ARRAY_DISTANCE);
}


