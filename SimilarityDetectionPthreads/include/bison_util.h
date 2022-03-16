//bison_util.h

#ifndef _BISON_UTIL_H
#define _BISON_UTIL_H

#include "tokentype.h"

void 	b_util_tid_buffer_insert(TokenId);
TokenId b_util_tid_buffer_remove();
int 	b_util_tid_buffer_empty();
void 	b_util_tid_buffer_clear();

#endif