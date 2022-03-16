%option noyywrap

%{
	# include "dpl.tab.h"
	# include <string.h>
	# include <stdio.h>
%}

%{
	int omit_last_brace = 0;
	int omit_semicolon = 0;
	int unpaired_brace_count = 0;
%}

%x COMMENT
%x ASM
%x DEFINE
%option yylineno

ID [a-zA-Z_][a-zA-Z0-9_]*
/* integer length */
ILEN ([Uu](L|l|LL|ll)?|(L|l|LL|ll)[Uu]?)
/* float exponent */
EXP ([Ee][-+]?[0-9]+)
STRING "\""([^"\n]|"\\\"")*"\""

%%
	/* ignored keywords */
"interrupt"
"explicit"
"friend"
"mutable"
"auto"
"export"
"const"
"extern".*
"register"
"static"
"inline"
"virtual"
"wchar_t"
"volatile"
"typename"
"public"
"protected"
"private"
"public"[ \t]*":"
"protected"[ \t]*":"
"private"[ \t]*":"
"using".*
"typedef"
"template"[ \t]*"<".*">"
"#"[ \t]*"include".*
"#"[ \t]*"ifndef".*
"#"[ \t]*"ifdef".*
"#"[ \t]*"else".*
"#"[ \t]*"endif".*
"#"[ \t]*"pragma".*
"namespace"[ \t]*{ID} 	{ omit_last_brace++; }
	
	
	/* active keywords */
"break"		{ return BREAK_; }
"case"		{ return CASE_; }
"catch"		{ return CATCH_; }
"union"		{ return UNION; }
	
"struct"	|
"class"		{ return CLASS; }
"continue" 	{ return CONTINUE_; }
"default"	{ return DEFAULT; }
"delete"	{ return DELETE_; }
"do"		{ return DO; }
"else"		{ return ELSE_; }
"enum"		{ return ENUM_; }
"for"		{ return FOR; }
"goto"		{ return GOTO_; }
"if"		{ return IF; }
"new"		{ return NEW; }
"return"	{ return RETURN_; }
"switch"	{ return SWITCH_; }
"throw"		{ return THROW_; }
"try"		{ return TRY_; }
"while"		{ return WHILE; }
"or"		{ return OR_OP; }


"sizeof"[ \t]*"("[^)\n]*")" { 
							char * pointer = strchr(yytext, '*');
							if(pointer != 0) {
								char *s = strchr(yytext, '(');
								*pointer = ')';
								int i = pointer - yytext + 1;
								int n = strlen(yytext);
								for(; i < n; i++) yytext[i] = ' ';
								
								yyless(s-yytext);
							}
							return IDENT; 
							}
"sizeof"	{ return SIZEOF; }
	
	/* operator overloading */
"operator"[ \t]*"("[ \t]*")"[^(]*/"("	{ return IDENT; }
"operator"[^(]*/"(" 	{ return IDENT; /*FUNC_OPERATOR;*/ }
	
	/* casts */
"static_cast" 		|
"reinterpret_cast" 	|
"const_cast" 		|
"dynamic_cast" 		{ return CAST; }

	/* booleans */
"false"							|
"true" 							{ return BOOL_VALUE; } 
	/* charecter */
"'\\"[abfnrtv0]"'"					|
"'/"[0]"'"						|
"'"[\040-\176]"'"				{ return CHAR_VALUE; }
	
	/* string */
{STRING}([ \b\t\r\n\f]*{STRING})*	{ return STRING_VALUE; }
	
	/* integers */
0[0-7]*{ILEN}?					|
[1-9][0-9]*{ILEN}?				|
0[Xx][0-9a-fA-F]+{ILEN}?		|
	
	/* hex float */
0[Xx]([0-9a-fA-F]*\.[0-9a-fA-F]+|[0-9a-fA-F]+\.?)[Pp][-+]?[0-9]+[flFL]?	|	
	
	/* decimal float */
([0-9]*\.[0-9]+|[0-9]+\.){EXP}?[flFL]?	|
[0-9]+{EXP}[flFL]?						{ return NUMERIC_VALUE; }
	
	/* data types */
"bool"			{ return BOOL_TYPE; } 
"char"			{ return CHAR_TYPE; }
"unsigned"		|
"signed"		|
"short"			|
"short"[ \t]+"int" |
"int"			|
"long"			|
"float"			|
"double"		{ return NUMERIC_TYPE; }
"void"			{ return VOID; }
"long"[ \t]+("long"|"int"|"double"|"unsigned"|"signed")	{ yyless(4); } /* strlen("long") = 4; */
"unsigned"[ \t]+("char"|"short"|"int"|"long") { yyless(8); } /* strlen("unsigned") = 8; */
"signed"[ \t]+("char"|"short"|"int"|"long") { yyless(6); } /* strlen("signed") = 6; */
	
	/* identifiers */
{ID}								{ return IDENT; }
({ID}[ \t]*\.[ \t]*)*{ID} 			{ yyless(strchr(yytext, '.') - yytext + 1); }	
({ID}[ \t]*"->"[ \t]*)*{ID}  		{ yyless(strchr(yytext, '>') - yytext + 1); }
({ID}[ \t]*"::"[ \t]*)*{ID}			{ yyless(strchr(yytext, ':') - yytext + 2); }	/* 2 is added because there are two ':' */


"#"[ \t]*"define".*	{ if(yytext[yyleng-2] == '\\') BEGIN(DEFINE);  }
<DEFINE>.*			{ if(yytext[yyleng-2] != '\\') BEGIN(INITIAL);  }
<DEFINE>\n

"asm"[ \t]*"{"[^}]*	{ BEGIN(ASM);} 
"asm"[ \t]*.*		
<ASM>"}" 			{ BEGIN(INITIAL);}
<ASM>([^}]\n)+|.

	/* comments */
"/*" 			{ BEGIN(COMMENT); }
<COMMENT>"*/" 	{ BEGIN(INITIAL); }
<COMMENT>([^*]|\n)+|.
"//".*
	
	/* white space */
[ \b\t\r\n\f]	


"="		|
"+"|"-"	|
"*"|"/"|"%" |
"["|"]"	|
"("|")"	|
"."|","|":" |
"!"|"~"	|
"&"|"^"|"|" |
"<"|">"	|
"?"			{ return yytext[0]; }

".*"			{ return yytext[0];	}

"::"			{ return SCOPE_OP;	}
"->*"			|
"->"			{ return PTR_OP; 	}
"++"			{ return INC_OP; 	}
"--"			{ return DEC_OP; 	}
"<<"			{ return SHL_OP;	}
">>"			{ return SHR_OP; 	}
"<="			{ return LE_OP; 	}
">="			{ return GE_OP; 	}
"=="			{ return EQ_OP; 	}
"!="			{ return NE_OP; 	}
"&&"			{ return AND_OP;	}
"||"			{ return OR_OP; 	}
">>="			{  return SHR_ASSIGN;	}
"<<="			{  return SHL_ASSIGN; 	}
"+="			{  return ADD_ASSIGN;	}
"-="			{  return SUB_ASSIGN; 	}
"*="			{  return MUL_ASSIGN; 	}
"/="			{  return DIV_ASSIGN; 	}
"%="			{  return MOD_ASSIGN; 	}
"&="			{  return AND_ASSIGN; 	}
"^="			{  return XOR_ASSIGN; 	}
"|="			{  return OR_ASSIGN; 	}
"..."			{  return ELLIPSIS; }	

	/* symbols with special treatment */
"{" { 	unpaired_brace_count++; 
		if( omit_last_brace == 0 || unpaired_brace_count != 1 ) return '{'; 
	}
	
"}" { 	unpaired_brace_count--;
		if(omit_last_brace >= 1 && unpaired_brace_count == 0) omit_last_brace--;
		else return '}';
	}

";" { 	if(omit_semicolon == 1 && unpaired_brace_count == 0) {
			omit_semicolon = 0;
		} else return ';' ;
	}



%%

/*
void readFromFile(char* fileName) {
	if(!(yyin = fopen(fileName, "r"))) {
		perror(fileName);
		exit(1);
	}
}

main(int argc, char **argv) {
	int tok;
	
	if(argc > 1) {
		readFromFile(argv[1]);
	} else {
		char fileName[100];
		printf("Enter input file name:\n");
		scanf("%s",&fileName);
		readFromFile(fileName);
	}

	while(tok = yylex()) {
		//printf("%d\n", tok);
	}						
}
*/