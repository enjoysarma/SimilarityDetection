//tokentype.h

#ifndef _TOKENTYPE_H_
#define _TOKENTYPE_H_

enum TokenId{
	NUM_VARDEF = 1,
	BOOL_VARDEF,
	CHAR_VARDEF,
	STRING_VARDEF,
	USERTYPE_VARDEF,

	NUM_ARRAY_VARDEF,
	BOOL_ARRAY_VARDEF,
	CHAR_ARRAY_VARDEF,
	STRING_ARRAY_VARDEF,
	USERTYPE_ARRAY_VARDEF,

	FUNCTION_POINTER,
	ENUM_VALUE,
	ASSIGN,
	APPLY,
	NEW_OBJECT,
	NEW_ARRAY,
	GOTO,
	CONTINUE,
	BREAK,
	RETURN,
	THROW,
	DELETE,
	CASE,

	BEGIN_FUNCTION,
	END_FUNCTION,
	BEGIN_CLASS,
	END_CLASS,
	BEGIN_UNION,
	END_UNION,
	BEGIN_CONSTRUCTOR,
	END_CONSTRUCTOR,
	BEGIN_DESTRUCTOR,
	END_DESTRUCTOR,
	BEGIN_CONDITIONAL,
	END_CONDITIONAL,
	BEGIN_IF,
	THEN,
	ELSE,
	END_IF,
	BEGIN_WHILE,
	END_WHILE,
	BEGIN_DO,
	END_DO,
	BEGIN_FOR,
	END_FOR,
	BEGIN_SWITCH,
	END_SWITCH,
	BEGIN_TRY,
	END_TRY,
	BEGIN_CATCH,
	END_CATCH,
	BEGIN_ENUM,
	END_ENUM,
	END_FILE
};

TokenId getArrayToken(TokenId);

#endif
