%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "tokentype.h"
	#include "tokenizer_c_interface.h"
	#include "bison_util.h"

	extern FILE *yyin;
	extern int yylineno;
	extern int yylex (void);

	void yyerror (char const *s) {
		fprintf (stderr, "line:%d %s\n", yylineno,s);
	}

	#define SIMPLEVAR 0
	#define ARRAYVAR 1
	#define FPOINTER 2

	TokenId last_read_type = USERTYPE_VARDEF;
	TokenId definition_type = USERTYPE_VARDEF;
	int var_definition = SIMPLEVAR;

	void insertParametersInScope() {
		while( !b_util_tid_buffer_empty() )
			insertToken( b_util_tid_buffer_remove(), yylineno );
	}

	void insertDeclaratorInScope() {
		if( var_definition == ARRAYVAR )
			insertToken( getArrayToken(definition_type), yylineno); 
		else if (var_definition == SIMPLEVAR)
			insertToken(definition_type, yylineno);
		else 
			insertToken(FUNCTION_POINTER, yylineno);
	}

	void insertDeclaratorInParameterList() {
		if( var_definition == ARRAYVAR )
			b_util_tid_buffer_insert( getArrayToken(definition_type)); 
		else if ( var_definition == SIMPLEVAR )
			b_util_tid_buffer_insert(definition_type);
		else 
			b_util_tid_buffer_insert(FUNCTION_POINTER);
	}


%}

%initial-action { yylineno = 1; }


%glr-parser
%expect-rr 2
%expect 5

%token IDENT  
%token BREAK_ CONTINUE_ GOTO_ RETURN_
%token SWITCH_ CASE_ DEFAULT
%token CLASS ENUM_
%token TRY_ CATCH_ THROW_
%token NEW DELETE_
%token IF ELSE_ DO WHILE FOR
%token BOOL_VALUE CHAR_VALUE STRING_VALUE NUMERIC_VALUE
%token FUNC_OPERATOR UNION
%token CAST SIZEOF
%token BOOL_TYPE CHAR_TYPE STRING_TYPE NUMERIC_TYPE VOID
%token SCOPE_OP "::" PTR_OP "->" ELLIPSIS "..."
%token INC_OP "++" DEC_OP "--" SHL_OP "<<" SHR_OP ">>"
%token LE_OP "<=" GE_OP ">=" EQ_OP "==" NE_OP "!=" 
%token AND_OP "&&" OR_OP "||"
%token SHR_ASSIGN ">>=" SHL_ASSIGN "<<="
%token ADD_ASSIGN "+=" SUB_ASSIGN "-="
%token MUL_ASSIGN "*=" DIV_ASSIGN "/=" MOD_ASSIGN "%="
%token AND_ASSIGN "&=" XOR_ASSIGN "^=" OR_ASSIGN "|="


%left OR_OP
%left AND_OP
%left '|'
%left '^'
%left '&'
%left EQ_OP NE_OP
%left '<' LE_OP '>' GE_OP
%left SHL_OP SHR_OP
%left '+' '-'
%left '*' '/' '%'
%nonassoc DECLARATION

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE_

%%

Program : { openProgramScope(); } DeclList { closeProgramScope(yylineno); /*printf("OK\n");*/};



DeclList 	:	DeclList DeclPart
			|	/* epsilon */
			;
			
DeclPart 	:	VarDecl
			|	FunctionDef
			|	ConstructorDecl
			|	DestructorDecl
			|	ClassDecl
			|	EnumSpecifier
			|	UnionDecl
			|	error
			;


/*********************************************** Function ******************************************/
OptSemi	:	';'
		|	/* epsilon */
		;

ThrowParamList	:	TypeList
				|	/* epsilon */
				;

FunParamList	:	ParameterList
				|	ParameterList ',' ELLIPSIS
				|	ELLIPSIS
				|	/* epsilon */
				;

FunctionPrototype	: 	Identifier '(' FunParamList ')' 
					|	Identifier '(' FunParamList ')' THROW_ '(' ThrowParamList ')' 
					;

FunctionDef	:	Type FunctionPrototype 	a_BeginFunction '{' StatementList '}' a_EndFunction OptSemi
			|	error 					a_BeginFunction '{' StatementList '}' a_EndFunction OptSemi
			;



/*------------------------------------ Class ----------------------------------------*/

Extends :	':' Identifier
		|	/* epsilon */
		;

ClassDecl 	:	CLASS Identifier ';' ;
			|	CLASS Identifier Extends a_BeginClass '{' DeclList '}' IdList ';' a_EndClass
			|	CLASS a_BeginClass '{' UnionDeclList '}' a_EndClass IdList ';'
			;



/*----------------------------------------------------------- Consturctor --------------------------------------------------------------------*/


ConstructorInitList :	ConstructorInitList ',' ConstructorInitItem
						|
						ConstructorInitItem
						;

ConstructorInitItem	:	Identifier '(' 		{ insertToken(ASSIGN, yylineno); } 	Expression ')' ; 
					|	Identifier '(' ')'	{ insertToken(ASSIGN, yylineno); };
					;

ConstructorParamList	:	ParameterList 
						|	/* epsilon */
						;

ConstructorDecl	:	Identifier '(' ConstructorParamList ')' ';'  { b_util_tid_buffer_clear(); };
				|	Identifier '(' ConstructorParamList ')' 	a_BeginConstructor 						'{' StatementList '}' a_EndConstructor
				|	Identifier '(' ConstructorParamList ')' ':' a_BeginConstructor ConstructorInitList	'{' StatementList '}' a_EndConstructor
				;

/*------------------------------------ Destructor -------------------------------------------*/

DestructorPrototype	:	'~' Identifier '(' ')'
					|	ScopeExpr '~' Identifier '(' ')' 
					;

DestructorDecl	:	DestructorPrototype ';'
				|	DestructorPrototype '{' a_BeginDestructor StatementList a_EndDestructor '}' 
				;

/*------------------------------------- ParameterList ---------------------------------------------*/

ParameterList 	:	ParameterList ',' ParameterDecl
				|	ParameterDecl
				;

ParameterDecl	: 	Type SimpleDeclarator 					{ insertDeclaratorInParameterList();  }
				|	Type SimpleDeclarator '=' Initializer 	{ insertDeclaratorInParameterList();  }
				|	Type
				|	Type '[' ']'
				|	error
				;	

/*------------------------------------ Types ------------------------------------*/

TemplateList	: 	TemplateList ',' TemplateItem
				|	TemplateItem
				;

TemplateItem 	:	Type
				|	Constant
				;	

ScopeExpr	:	NestedType "::" ;

SimpleType	:	NUMERIC_TYPE	{ last_read_type = NUM_VARDEF; } 
			|	BOOL_TYPE		{ last_read_type = BOOL_VARDEF;	}
			|	CHAR_TYPE		{ last_read_type = CHAR_VARDEF; }
			|	STRING_TYPE		{ last_read_type = STRING_VARDEF; }
			|	VOID 			{}
			;

UserType 	:	IDENT 						
			|	IDENT '<' TemplateList '>'
			;

NestedType	: 	ScopeExpr UserType
			|	UserType
			;	

Identifier	: 	NestedType		{ last_read_type = USERTYPE_VARDEF; }
			|	SimpleType
			;

Type	:	Identifier PointerDecoration 	{ definition_type = last_read_type; }
		|	Identifier						{ definition_type = last_read_type; }
		|	CLASS Identifier				{ definition_type = last_read_type; }
		|	UNION Identifier 				{ definition_type = last_read_type; }
		|	ENUM_  Identifier 				{ definition_type = last_read_type; }
		|	CLASS Identifier 	PointerDecoration				{ definition_type = last_read_type; }
		|	UNION Identifier 	PointerDecoration				{ definition_type = last_read_type; }
		|	ENUM_  Identifier 	PointerDecoration				{ definition_type = last_read_type; }
		;

TypeList 	:	TypeList ',' Type
			|	Type
			;

/*------------------------------ Pointers -----------------------------------------*/

Pointer	:	Pointer '*'
		|	'*'
		;

PointerDecoration 	:	Pointer '&'
					|	Pointer
					|	'&'
					;


/*------------------------------- Global Variable Declaration -------------------------------------*/

VarDecl :	VariableDeclaration ';'
		|	error ';' 
		;

VariableDeclaration : 	Type VarDeclItemList ;

				
VarDeclItemList :	VarDeclItemList ',' VarDeclItem
				|	FirstVarItem
				;
					
VarDeclItem	:	Declarator
			|	Declarator '=' Initializer 						{ insertToken(ASSIGN, yylineno); }
			;
				
FirstVarItem	:	CleanDeclarator
				|	CleanDeclarator '=' Initializer 			{ insertToken(ASSIGN, yylineno); }
				;

Declarator 	:	CleanDeclarator
			|	PointerDecoration CleanDeclarator
			;

CleanDeclarator	:	SimpleDeclarator								{ insertDeclaratorInScope(); }
				|	FunctionPrototype								{ b_util_tid_buffer_clear(); }
				;

SimpleDeclarator 	:	IDENT 												{ var_definition = SIMPLEVAR; }		
					//|	'(' Declarator ')'
					|	SimpleDeclarator '[' ConstantExpression ']' 		{ var_definition = ARRAYVAR; }
					|	SimpleDeclarator '[' ']'							{ var_definition = ARRAYVAR; }
					|	'(' Pointer SimpleDeclarator ')' '(' FPointerList ')'				{ var_definition = FPOINTER; }
					|	'(' ScopeExpr Pointer SimpleDeclarator ')' '(' FPointerList ')'	{ var_definition = FPOINTER; }					
					;

FPointerList 	:	TypeList
				|	/* epsilon */
				|	"..."
				|	TypeList "," "..."
				;

/********************************** Local Variable Declaration ***********************************/

LocalVarDecl 	: 	Type LocalItemList ';' ;


LocalItemList	:	LocalItemList ',' LocalDeclItem
				|	FirstLocalDecl
				;

FirstLocalDecl 	:	LocalCleanDeclarator 
				|	LocalCleanDeclarator '=' Initializer  { insertToken(ASSIGN, yylineno); }
				;
				
LocalDeclItem	:	LocalDeclarator
				|	LocalDeclarator '=' Initializer 	{ insertToken(ASSIGN, yylineno); }
				;
				
LocalDeclarator	: 	PointerDecoration LocalCleanDeclarator
				|	LocalCleanDeclarator 
				;

LocalCleanDeclarator	:	SimpleDeclarator			{ 	insertDeclaratorInScope(); 		}
						|	IDENT FunctionCall			{ 	insertDeclaratorInScope(); 
															insertToken(ASSIGN, yylineno); 	}
						;


/********************** Initializer ***********************/

Initializer :	AssignmentExpression
				| 
				'{' InitializerList '}'
				| 
				'{' InitializerList ',' '}'
				;

InitializerList :	Initializer
					| 
					InitializerList ',' Initializer
					|
					/* */
					;				



/********************** Function Call ********************/

ArgumentList 	:	AssignmentExpression
				|	ArgumentList ',' AssignmentExpression
				;

FunctionCall 	:	'(' ')'
				|	'(' ArgumentList ')'
				;


/************* Constant *******************/

Constant 	:	NUMERIC_VALUE
			|	CHAR_VALUE
			|	BOOL_VALUE
			|	String
			;

String 		:	String STRING_VALUE
			|	STRING_VALUE
			;


/******************************** New **************************************/

NewExpression :	NewObjectExpression 
				|
				NewArrayExpression
				;

NewObjectExpression :	NEW Identifier a_NewObject
						|
						NEW Identifier a_NewObject '('				')'
						|
						NEW Identifier a_NewObject '(' ArgumentList ')'
						;

NewArrayExpression:	NEW Identifier 			a_NewArray  '[' Expression ']'
					|
					NEW Identifier Pointer 	a_NewArray  '[' Expression ']'
					;


/***************************** Expression **********************************/

SimpleExpression 	:	Identifier
					| 	Constant	
					|	'(' Expression ')' 
					;

PrimaryExpression 	:	SimpleExpression
					|	PrimaryExpression '[' Expression ']'
					|	PrimaryExpression FunctionCall { insertToken(APPLY, yylineno); }
					|	PrimaryExpression '.' IDENT
					|	PrimaryExpression "->" IDENT
					|	CAST '<' Type '>' '(' UnaryExpression ')'
					; 

PostfixExpression 	:	PrimaryExpression
					|	PostfixExpression "++" 	{ insertToken(ASSIGN, yylineno); }
					|	PostfixExpression "--" 	{ insertToken(ASSIGN, yylineno); }
					;

UnaryExpression 	:	PostfixExpression 					%dprec 2
					|	"++" UnaryExpression 				{ insertToken(ASSIGN, yylineno); }
					|	"--" UnaryExpression 				{ insertToken(ASSIGN, yylineno); }
					|	UnaryOperator UnaryExpression		%dprec 1
					|	'(' Type ')' UnaryExpression		%dprec 3
					|	SIZEOF UnaryExpression
					;

UnaryOperator 	:	'&'
				|	'*'
				|	'+'
				|	'-'
				|	'~'
				|	'!'
				;


ExpandedArithmeticExpr 	:	ArithmeticExpression
						|	'*' NewObjectExpression
						;

ArithmeticExpression	:	UnaryExpression											%dprec 2
						|	ExpandedArithmeticExpr '*'	ExpandedArithmeticExpr		%dprec 5
						|	ExpandedArithmeticExpr '/' 	ExpandedArithmeticExpr		%dprec 5
						|	ExpandedArithmeticExpr '%' 	ExpandedArithmeticExpr
						|	ExpandedArithmeticExpr '+' 	ExpandedArithmeticExpr		%dprec 4
						|	ExpandedArithmeticExpr '-' 	ExpandedArithmeticExpr		%dprec 4
						|	ExpandedArithmeticExpr "<<" ExpandedArithmeticExpr
						|	ExpandedArithmeticExpr ">>" ExpandedArithmeticExpr
						|	ExpandedArithmeticExpr '<' 	ExpandedArithmeticExpr		
						|	ExpandedArithmeticExpr '>' 	ExpandedArithmeticExpr		%dprec 1
						|	ExpandedArithmeticExpr "<=" ExpandedArithmeticExpr
						|	ExpandedArithmeticExpr ">=" ExpandedArithmeticExpr
						|	ExpandedArithmeticExpr "==" ExpandedArithmeticExpr
						|	ExpandedArithmeticExpr "!=" ExpandedArithmeticExpr		
						|	ExpandedArithmeticExpr '&' 	ExpandedArithmeticExpr		%dprec 3
						|	ExpandedArithmeticExpr '^' 	ExpandedArithmeticExpr
						|	ExpandedArithmeticExpr '|' 	ExpandedArithmeticExpr
						|	ExpandedArithmeticExpr "&&" ExpandedArithmeticExpr
						|	ExpandedArithmeticExpr "||" ExpandedArithmeticExpr
						;


ConditionalExpression 	: 	ArithmeticExpression
						|	ArithmeticExpression '?' a_BeginConditional Expression ':' AssignmentExpression a_EndConditional
						;

AssignmentExpression 	:	ConditionalExpression
						|	NewExpression
						|	UnaryExpression AssignmentOperator AssignmentExpression  { insertToken(ASSIGN, yylineno); } 
						;

AssignmentOperator 		:	'='
						| 	"*="
						|	"/="
						|	"%="
						|	"+="
						|	"-="
						|	"<<="
						|	">>="
						|	"&="
						|	"^="
						|	"|="
						;

DeleteExpression 	:	Delete 			AssignmentExpression 
					|	Delete '[' ']' 	AssignmentExpression 
					;

ThrowExpression 	:	 Throw AssignmentExpression ;

SoloExpression 	:	AssignmentExpression
				|	DeleteExpression
				|	ThrowExpression
				;
		
Expression 	:	SoloExpression
			|	Expression ',' SoloExpression
			;

ConstantExpression 	: ConditionalExpression ;					

Throw 	:	THROW_ 	{ insertToken(THROW, yylineno); 	} ;
Delete 	:	DELETE_ { insertToken(DELETE, yylineno); 	} ;


/********************************* Statement *************************************/

Case 	:	CASE_ 	{ insertToken(CASE, yylineno); } ;
Default	:	DEFAULT { insertToken(CASE, yylineno); } ;
BeginIf		: IF { insertToken_openScope(BEGIN_IF, yylineno); } ;
Else 		: ELSE_ { insertToken_reopenScope(ELSE, yylineno); } ;	


ExpressionStatement :	Expression ';'
					|	';'
					;

ExprDecl 	:	Expression 
			|	VariableDeclaration
			;

CatchStatement :	CATCH_ '(' Type SimpleDeclarator ')' { insertDeclaratorInParameterList(); }
				|	CATCH_ '(' Type 	')'
				|	CATCH_ '(' ELLIPSIS ')'
				;

StatementList 	:	StatementList Statement
				|	/* epsilon */
				;


Statement 	:	IDENT ':' Statement
			| 	Case ConstantExpression ':' Statement
			| 	Default ':' Statement
			
			|	BeginIf 	'(' ExprDecl ')' a_Then Statement 					{ insertToken_closeScope(END_IF, yylineno); } %prec LOWER_THAN_ELSE 
			| 	BeginIf 	'(' ExprDecl ')' a_Then Statement Else Statement 	{ insertToken_closeScope(END_IF, yylineno); }
			
			|	SWITCH_ 	'(' ExprDecl ')' a_BeginSwitch 	Statement a_EndSwitch
			
			|	WHILE 		'(' ExprDecl ')' a_BeginWhile 	Statement a_EndWhile
			| 	DO a_BeginDo Statement a_EndDo WHILE '(' ExprDecl ')' ';'
			| 	FOR '(' ExpressionStatement a_BeginFor ExpressionStatement 				')'  Statement a_EndFor
			| 	FOR '(' ExpressionStatement a_BeginFor ExpressionStatement Expression 	')'  Statement a_EndFor
			|	FOR '(' VarDecl 			a_BeginFor ExpressionStatement Expression 	')'  Statement a_EndFor
			|	FOR '(' VarDecl 			a_BeginFor ExpressionStatement 				')'  Statement a_EndFor
			|	FOR '(' error ')'  a_BeginFor Statement a_EndFor
			
			|	GOTO_ IDENT ';' 	{ insertToken(GOTO, yylineno); 		}
			| 	CONTINUE_ 	';' 	{ insertToken(CONTINUE, yylineno); 	}
			| 	BREAK_ 		';'	 	{ insertToken(BREAK, yylineno); 	}
			|  	RETURN_ 	';' 	{ insertToken(RETURN, yylineno); 	}
			| 	RETURN_ 			{ insertToken(RETURN, yylineno); 	} 	Expression ';'
			
			|	TRY_ a_BeginTry Statement a_EndTry CatchStatement a_BeginCatch Statement a_EndCatch
			|	a_BeginCatch CatchStatement Statement a_EndCatch
			
			|	ExpressionStatement	 %dprec 1
			
			|	'{' StatementList '}'

			|	LocalVarDecl %dprec 2
			|	ClassDecl
			|	EnumSpecifier
			|	UnionDecl

			|	error ';' 
			|	error '}'
			;


/**************************** Enum **************************/

EnumSpecifier
	: ENUM_ BeginEnum '{' EnumeratorList '}' EndEnum IdList ';'
	| ENUM_ IDENT BeginEnum '{' EnumeratorList '}' EndEnum IdList ';'
	| ENUM_ IDENT ';'
	;

BeginEnum : { insertToken(BEGIN_ENUM, yylineno); } ;
EndEnum	: { insertToken(END_ENUM, yylineno); } ;

EnumeratorList
	: Enumerator
	| EnumeratorList ',' Enumerator
	;

Enumerator
	: EnumItem
	| EnumItem EnumAssign '=' ConstantExpression
	;

EnumItem 	: IDENT { insertToken(ENUM_VALUE, yylineno); } ;
EnumAssign 	: { insertToken(ASSIGN, yylineno); };

/**************************** Union **************************/

UnionDecl 	:	UNION IDENT 	'{' a_BeginUnion UnionDeclList a_EndUnion '}' IdList ';'
			|	UNION 			'{' a_BeginUnion UnionDeclList a_EndUnion '}' IdList ';'
			|	UNION IDENT ';'
			;

UnionDeclList 	:	UnionDeclList VarDecl
				|	/* epsilon */
				;			

/************************** IDLIST **********************/
IdList 	:	IdList IDENT
		|	/**/
		;

/******************************* Actions **********************************/

a_BeginWhile 	: 	{ insertToken_openScope(BEGIN_WHILE, yylineno); } ;
a_EndWhile 		: 	{ insertToken_closeScope(END_WHILE, yylineno); } ;

a_BeginDo 		: 	{ insertToken_openScope(BEGIN_DO, yylineno); } ;
a_EndDo			: 	{ insertToken_closeScope(END_DO, yylineno); } ;

a_BeginFor		: 	{ insertToken_openScope(BEGIN_FOR, yylineno); } ;
a_EndFor		: 	{ insertToken_closeScope(END_FOR, yylineno); } ;	

a_BeginSwitch 	: 	{ insertToken_openScope(BEGIN_SWITCH, yylineno); } ;
a_EndSwitch 	: 	{ insertToken_closeScope(END_SWITCH, yylineno); } ;

a_BeginTry 		:	{ insertToken_openScope(BEGIN_TRY, yylineno); } ;
a_EndTry		:	{ insertToken_closeScope(END_TRY, yylineno); } ;
a_BeginCatch 	: 	{ insertToken_openScope(BEGIN_CATCH, yylineno); insertParametersInScope(); } ;
a_EndCatch		:	{ insertToken_closeScope(END_CATCH, yylineno); } ;

a_BeginClass	: 	{ insertToken_openScope(BEGIN_CLASS, yylineno); };
a_EndClass 		:	{ insertToken_closeScope(END_CLASS, yylineno); };

a_BeginUnion 	:	{ insertToken_openScope(BEGIN_UNION, yylineno); };
a_EndUnion 		:	{ insertToken_closeScope(END_UNION, yylineno); };

a_BeginFunction :	{ insertToken_openScope(BEGIN_FUNCTION, yylineno); insertParametersInScope(); } ;
a_EndFunction	:	{ insertToken_closeScope(END_FUNCTION, yylineno);	} ;

a_NewArray 		:  	{ insertToken(NEW_ARRAY, yylineno); } ;
a_NewObject 	:  	{ insertToken(NEW_OBJECT, yylineno); } ;

a_BeginDestructor 	:	{ insertToken_openScope(BEGIN_DESTRUCTOR, yylineno); 	} ;
a_EndDestructor 	:	{ insertToken_closeScope(END_DESTRUCTOR, yylineno); 	} ;

a_BeginConstructor	:	{ insertToken_openScope(BEGIN_CONSTRUCTOR, yylineno); insertParametersInScope(); };
a_EndConstructor 	:	{ insertToken_closeScope(END_CONSTRUCTOR, yylineno); };

a_BeginConditional 	:	{ insertToken(BEGIN_CONDITIONAL, yylineno); } ;
a_EndConditional 	: 	{ insertToken(END_CONDITIONAL, yylineno); } ;

a_Then 			: {insertToken(THEN, yylineno);};


/************************************************************/




%%
/*
void readFromFile(char* fileName) {
	if(!(yyin = fopen(fileName, "r"))) {
		perror(fileName);
		exit(1);
	}
}

main (int argc, char **argv) {
	int tok;
	
	if(argc > 1) {
		readFromFile(argv[1]);
	} else {
		char fileName[100];
		printf("Enter input file name:\n");
		scanf("%s",&fileName);
		readFromFile(fileName);
	}

	yyparse();						
}

*/