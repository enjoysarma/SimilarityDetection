/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Skeleton implementation for Bison GLR parsers in C

   Copyright (C) 2002-2015, 2018-2020 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C GLR parser skeleton written by Paul Hilfinger.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "glr.c"

/* Pure parsers.  */
#define YYPURE 0






/* First part of user prologue.  */
#line 1 "res/dpl.y"

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



#line 106 "/mnt/d/Markov folder/Nauka/2019/CCPE/Kod/SimilarityDetection/SimilarityDetectionCuda/build/../src/parser.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.hpp"

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Default (constant) value used for initialization for null
   right-hand sides.  Unlike the standard yacc.c template, here we set
   the default value of $$ to a zeroed-out value.  Since the default
   value is undefined, this behavior is technically correct.  */
static YYSTYPE yyval_default;



#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YYFREE
# define YYFREE free
#endif
#ifndef YYMALLOC
# define YYMALLOC malloc
#endif
#ifndef YYREALLOC
# define YYREALLOC realloc
#endif

#define YYSIZEMAX \
  (PTRDIFF_MAX < SIZE_MAX ? PTRDIFF_MAX : YY_CAST (ptrdiff_t, SIZE_MAX))

#ifdef __cplusplus
  typedef bool yybool;
# define yytrue true
# define yyfalse false
#else
  /* When we move to stdbool, get rid of the various casts to yybool.  */
  typedef signed char yybool;
# define yytrue 1
# define yyfalse 0
#endif

#ifndef YYSETJMP
# include <setjmp.h>
# define YYJMP_BUF jmp_buf
# define YYSETJMP(Env) setjmp (Env)
/* Pacify Clang and ICC.  */
# define YYLONGJMP(Env, Val)                    \
 do {                                           \
   longjmp (Env, Val);                          \
   YY_ASSERT (0);                               \
 } while (yyfalse)
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* The _Noreturn keyword of C11.  */
#ifndef _Noreturn
# if (defined __cplusplus \
      && ((201103 <= __cplusplus && !(__GNUC__ == 4 && __GNUC_MINOR__ == 7)) \
          || (defined _MSC_VER && 1900 <= _MSC_VER)))
#  define _Noreturn [[noreturn]]
# elif ((!defined __cplusplus || defined __clang__) \
        && (201112 <= (defined __STDC_VERSION__ ? __STDC_VERSION__ : 0)  \
            || 4 < __GNUC__ + (7 <= __GNUC_MINOR__)))
   /* _Noreturn works as-is.  */
# elif 2 < __GNUC__ + (8 <= __GNUC_MINOR__) || 0x5110 <= __SUNPRO_C
#  define _Noreturn __attribute__ ((__noreturn__))
# elif 1200 <= (defined _MSC_VER ? _MSC_VER : 0)
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2181

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  86
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  120
/* YYNRULES -- Number of rules.  */
#define YYNRULES  297
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  546
/* YYMAXRHS -- Maximum number of symbols on right-hand side of rule.  */
#define YYMAXRHS 11
/* YYMAXLEFT -- Maximum number of symbols to the left of a handle
   accessed by $0, $-1, etc., in any rule.  */
#define YYMAXLEFT 0

/* YYMAXUTOK -- Last valid token number (for yychar).  */
#define YYMAXUTOK   316
/* YYUNDEFTOK -- Symbol number (for yytoken) that denotes an unknown
   token.  */
#define YYUNDEFTOK  2

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                         \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    84,     2,     2,     2,    68,    61,     2,
      73,    74,    66,    64,    72,    65,    83,    67,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    77,    71,
      62,    79,    63,    85,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    80,     2,    81,    60,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    75,    59,    76,    78,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    69,    70,    82
};

#if YYDEBUG
/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    95,    95,    95,    99,   100,   103,   104,   105,   106,
     107,   108,   109,   110,   115,   116,   119,   120,   123,   124,
     125,   126,   129,   130,   133,   134,   141,   142,   145,   146,
     147,   155,   157,   160,   160,   161,   164,   165,   168,   169,
     170,   175,   176,   179,   180,   185,   186,   189,   190,   191,
     192,   193,   198,   199,   202,   203,   206,   208,   209,   210,
     211,   212,   215,   216,   219,   220,   223,   224,   227,   228,
     229,   230,   231,   232,   233,   234,   237,   238,   243,   244,
     247,   248,   249,   255,   256,   259,   262,   263,   266,   267,
     270,   271,   274,   275,   278,   279,   282,   284,   285,   286,
     287,   290,   291,   292,   293,   298,   301,   302,   305,   306,
     309,   310,   313,   314,   317,   318,   325,   327,   329,   332,
     334,   335,   343,   344,   347,   348,   354,   355,   356,   357,
     360,   361,   367,   369,   372,   374,   376,   379,   381,   387,
     388,   389,   392,   393,   394,   395,   396,   397,   400,   401,
     402,   405,   406,   407,   408,   409,   410,   413,   414,   415,
     416,   417,   418,   422,   423,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   448,   449,   452,   453,   454,   457,
     458,   459,   460,   461,   462,   463,   464,   465,   466,   467,
     470,   471,   474,   476,   477,   478,   481,   482,   485,   487,
     488,   493,   494,   495,   496,   499,   500,   503,   504,   507,
     508,   509,   512,   513,   517,   518,   519,   521,   522,   524,
     526,   527,   528,   529,   530,   531,   532,   534,   535,   536,
     537,   538,   538,   540,   541,   543,   545,   547,   548,   549,
     550,   552,   553,   560,   561,   562,   565,   566,   569,   570,
     574,   575,   578,   579,   583,   584,   585,   588,   589,   593,
     594,   599,   600,   602,   603,   605,   606,   608,   609,   611,
     612,   613,   614,   616,   617,   619,   620,   622,   623,   625,
     626,   628,   629,   631,   632,   634,   635,   637
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENT", "BREAK_", "CONTINUE_", "GOTO_",
  "RETURN_", "SWITCH_", "CASE_", "DEFAULT", "CLASS", "ENUM_", "TRY_",
  "CATCH_", "THROW_", "NEW", "DELETE_", "IF", "ELSE_", "DO", "WHILE",
  "FOR", "BOOL_VALUE", "CHAR_VALUE", "STRING_VALUE", "NUMERIC_VALUE",
  "FUNC_OPERATOR", "UNION", "CAST", "SIZEOF", "BOOL_TYPE", "CHAR_TYPE",
  "STRING_TYPE", "NUMERIC_TYPE", "VOID", "\"::\"", "\"->\"", "\"...\"",
  "\"++\"", "\"--\"", "\"<<\"", "\">>\"", "\"<=\"", "\">=\"", "\"==\"",
  "\"!=\"", "\"&&\"", "\"||\"", "\">>=\"", "\"<<=\"", "\"+=\"", "\"-=\"",
  "\"*=\"", "\"/=\"", "\"%=\"", "\"&=\"", "\"^=\"", "\"|=\"", "'|'", "'^'",
  "'&'", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "'%'", "DECLARATION",
  "LOWER_THAN_ELSE", "';'", "','", "'('", "')'", "'{'", "'}'", "':'",
  "'~'", "'='", "'['", "']'", "\",\"", "'.'", "'!'", "'?'", "$accept",
  "Program", "$@1", "DeclList", "DeclPart", "OptSemi", "ThrowParamList",
  "FunParamList", "FunctionPrototype", "FunctionDef", "Extends",
  "ClassDecl", "ConstructorInitList", "ConstructorInitItem", "$@2",
  "ConstructorParamList", "ConstructorDecl", "DestructorPrototype",
  "DestructorDecl", "ParameterList", "ParameterDecl", "TemplateList",
  "TemplateItem", "ScopeExpr", "SimpleType", "UserType", "NestedType",
  "Identifier", "Type", "TypeList", "Pointer", "PointerDecoration",
  "VarDecl", "VariableDeclaration", "VarDeclItemList", "VarDeclItem",
  "FirstVarItem", "Declarator", "CleanDeclarator", "SimpleDeclarator",
  "FPointerList", "LocalVarDecl", "LocalItemList", "FirstLocalDecl",
  "LocalDeclItem", "LocalDeclarator", "LocalCleanDeclarator",
  "Initializer", "InitializerList", "ArgumentList", "FunctionCall",
  "Constant", "String", "NewExpression", "NewObjectExpression",
  "NewArrayExpression", "SimpleExpression", "PrimaryExpression",
  "PostfixExpression", "UnaryExpression", "UnaryOperator",
  "ExpandedArithmeticExpr", "ArithmeticExpression",
  "ConditionalExpression", "AssignmentExpression", "AssignmentOperator",
  "DeleteExpression", "ThrowExpression", "SoloExpression", "Expression",
  "ConstantExpression", "Throw", "Delete", "Case", "Default", "BeginIf",
  "Else", "ExpressionStatement", "ExprDecl", "CatchStatement",
  "StatementList", "Statement", "$@3", "EnumSpecifier", "BeginEnum",
  "EndEnum", "EnumeratorList", "Enumerator", "EnumItem", "EnumAssign",
  "UnionDecl", "UnionDeclList", "IdList", "a_BeginWhile", "a_EndWhile",
  "a_BeginDo", "a_EndDo", "a_BeginFor", "a_EndFor", "a_BeginSwitch",
  "a_EndSwitch", "a_BeginTry", "a_EndTry", "a_BeginCatch", "a_EndCatch",
  "a_BeginClass", "a_EndClass", "a_BeginUnion", "a_EndUnion",
  "a_BeginFunction", "a_EndFunction", "a_NewArray", "a_NewObject",
  "a_BeginDestructor", "a_EndDestructor", "a_BeginConstructor",
  "a_EndConstructor", "a_BeginConditional", "a_EndConditional", "a_Then", YY_NULLPTR
};
#endif

#define YYPACT_NINF (-362)
#define YYTABLE_NINF (-293)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -362,    71,  -362,  -362,   172,   103,   -23,   134,   220,    51,
    -362,  -362,  -362,  -362,  -362,   134,  -362,  -362,  -362,  -362,
     235,  -362,    19,  -362,  -362,    16,   -15,   161,  -362,    -8,
    -362,  -362,  -362,    15,  1307,   198,   217,   153,   149,    96,
     171,   150,  -362,    96,   163,  -362,  -362,   134,  -362,  -362,
    -362,  -362,   399,   182,  -362,    -5,    52,   199,   206,   145,
    -362,   224,   207,  -362,  -362,   134,   134,  -362,  -362,  -362,
    -362,   134,   113,  -362,    96,  -362,  -362,   299,  -362,   134,
    -362,  -362,  -362,  -362,   262,  -362,   309,  -362,  -362,  -362,
    -362,   269,  -362,   283,  -362,   301,   317,  -362,    26,  -362,
    -362,    52,    16,    30,   324,  1979,   451,  1522,  1755,   527,
      96,  -362,  1307,  -362,  -362,   328,   488,   309,  -362,   237,
    -362,   312,  -362,  1228,  -362,   609,   327,    27,  1420,  -362,
     332,    75,    30,   142,  -362,  -362,   333,   344,  -362,   161,
    -362,   340,  -362,   134,   363,  1875,  1875,  1875,  -362,  -362,
    -362,   410,  1154,  1522,  -362,  -362,  -362,  -362,  -362,  -362,
    -362,  -362,  -362,   107,   355,   393,  1875,  2024,   433,  -362,
    -362,  -362,  -362,  -362,   347,   215,    12,   358,   364,   435,
     365,   367,  -362,  -362,  -362,  -362,  -362,  -362,  -362,   379,
     382,  -362,  -362,  -362,  -362,  1990,    38,  -362,  -362,  -362,
    -362,  -362,   110,  1819,  1578,  1931,   380,   391,  -362,  -362,
    -362,  -362,   453,  -362,  -362,   394,  -362,   161,  -362,   266,
     309,  -362,   389,  1228,   400,   401,  -362,  -362,  -362,   403,
    -362,  -362,  1522,   164,   396,   691,   455,  1356,  -362,  1522,
       7,  1371,  -362,  -362,  -362,  -362,   134,  -362,   405,   221,
    -362,   272,   478,  1643,  1410,   484,  -362,  -362,  -362,  -362,
    -362,  -362,  -362,  -362,  -362,  -362,  -362,  -362,  -362,  -362,
    1819,  -362,  1931,  1931,  1931,  1931,  1931,  1931,  1931,  1931,
    1931,  1931,  1931,  1931,  1931,  1931,  1931,  1931,  1931,  1931,
    -362,  -362,  -362,  -362,  1019,  -362,  -362,   419,  -362,  1410,
    1154,  1019,  1019,  1154,  1090,   773,   421,   420,   207,   326,
    -362,   415,  -362,  1410,  -362,   414,  -362,   424,  1019,  1154,
     423,  1019,   346,  -362,  -362,  -362,  -362,  1931,   422,  -362,
    -362,   134,  -362,  -362,   440,  1164,  -362,   442,  -362,  -362,
     431,   446,   473,   491,  -362,  1875,  -362,  1466,  -362,  -362,
    -362,   281,  -362,   168,  -362,  -362,   395,  -362,   395,   304,
     304,  2113,  2113,  2062,  2034,  2071,  2099,  2106,   304,   304,
     284,   284,  -362,  -362,  -362,  1410,  -362,  -362,   334,  -362,
     493,   489,  -362,  -362,   512,   144,  -362,  -362,  -362,  -362,
    -362,  -362,  -362,    85,  1522,  -362,  1819,  1019,  -362,   513,
    1243,  -362,  -362,    39,  -362,    63,  -362,  -362,    69,   250,
    -362,   516,   855,  1164,  -362,  -362,    89,   520,   421,  1371,
     510,  1410,  1699,   522,  -362,  -362,  -362,  1819,  -362,  -362,
     244,  -362,  -362,   453,   575,  -362,  -362,  1218,  1218,    38,
    -362,   518,  -362,  -362,  -362,  -362,  -362,   525,    21,  -362,
      74,  -362,  -362,    76,  -362,    78,  -362,   134,  -362,   530,
    -362,   532,  1371,   563,  -362,  -362,   533,   536,  1410,   203,
    -362,   287,  1875,  -362,  1819,  1019,  -362,   555,  1019,  1019,
    1282,  1346,  -362,  1522,  1019,  -362,  -362,   202,  -362,  -362,
    -362,  -362,   937,  -362,  1410,  -362,  -362,  -362,  -362,  -362,
     208,  -362,  -362,   535,  -362,  -362,  1019,  1154,  -362,  -362,
    1019,   290,  1019,   310,  -362,   617,  -362,  -362,  -362,   316,
    -362,  -362,  -362,  -362,  -362,   571,  -362,  -362,  -362,  1019,
    -362,  1019,  -362,  1019,  -362,  -362,  -362,   576,  -362,  -362,
    -362,  -362,  -362,  -362,  -362,  -362
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       2,     0,     5,     1,     0,    13,    62,   283,   256,     0,
      58,    59,    60,    57,    61,     0,     4,     7,    10,     8,
       0,     9,     0,    67,    65,    66,    69,     0,     6,     0,
      11,    12,    84,     0,     0,     0,    70,     0,    62,    72,
       0,    62,   285,    71,     0,    43,   291,     0,    64,    56,
      82,    79,     0,    81,    68,    96,     0,    95,     0,    85,
      87,    90,    94,    83,   223,     0,     0,   128,   127,   131,
     126,     0,     0,    53,    69,    54,    55,   129,    28,     0,
     283,    73,   268,   255,     0,    75,     0,   266,   285,   268,
      74,     0,   223,     0,    51,     0,    36,    46,    49,    80,
      78,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      70,    63,     0,   130,    26,     0,     0,     0,   262,     0,
     258,   260,   268,     0,    41,     0,     0,   293,     0,    96,
       0,    47,     0,     0,   223,    20,     0,    18,    95,     0,
      86,    88,    92,     0,     0,     0,     0,     0,   157,   159,
     160,   158,     0,   121,   161,   162,   139,    91,   140,   187,
     132,   133,   142,   148,   151,   165,     0,     0,   163,   186,
     116,    98,   165,   208,     0,     0,    62,     0,     0,     0,
     241,     0,   211,   212,   279,   209,   210,   213,   273,     0,
       0,   216,   223,   288,   248,   139,     0,   247,   203,   204,
     205,   206,     0,     0,     0,     0,     0,     0,   245,   222,
     249,   250,     0,    52,     5,     0,   284,     0,   267,     0,
       0,   257,     0,     0,     0,     0,    42,    38,   293,     0,
      45,    50,     0,     0,     0,     0,    22,     0,    93,     0,
     290,     0,   158,   156,   152,   153,     0,   164,     0,     0,
     119,     0,     0,     0,     0,     0,   144,   149,   150,   196,
     195,   193,   194,   190,   191,   192,   197,   198,   199,   189,
       0,   154,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     295,    97,   251,   252,     0,   239,   238,     0,   240,     0,
       0,     0,     0,     0,     0,     0,    15,    96,   114,     0,
     107,   108,   215,     0,   202,     0,   200,     0,     0,     0,
       0,     0,     0,   270,   257,   259,   270,     0,     0,   270,
      44,     0,   223,    48,     0,   102,   288,     0,    19,    89,
     289,     0,   134,     0,   290,     0,   141,     0,   117,   146,
     124,     0,   122,     0,   145,   188,   171,   163,   172,   175,
     176,   177,   178,   182,   183,   181,   180,   179,   173,   174,
     169,   170,   166,   167,   168,     0,   224,   237,     0,   218,
     217,     0,   280,   274,     0,     0,   275,   275,   246,    14,
      25,   115,   105,     0,     0,   207,     0,     0,   226,     0,
       0,   282,   270,     0,   270,     0,   261,   270,     0,     0,
      32,     0,     0,   102,   103,    77,   101,     0,    15,    17,
       0,     0,     0,     0,   155,   118,   120,     0,   125,   143,
       0,   242,   277,     0,     0,   271,   275,     0,     0,     0,
     106,   110,   113,   109,   201,   225,   297,     0,     0,   244,
       0,   269,    30,     0,   253,     0,   265,     0,   223,    33,
     294,     0,     0,     0,    99,    24,     0,    16,     0,     0,
     135,     0,     0,   123,     0,     0,   281,     0,     0,     0,
       0,     0,   112,     0,     0,   221,   220,     0,   284,   254,
     264,    31,     0,    35,     0,    39,   100,    76,   104,    23,
       0,   137,   136,     0,   296,   278,     0,     0,   272,   276,
       0,     0,     0,     0,   111,   227,   219,    29,   294,     0,
     138,   147,   185,   229,   282,     0,   230,   236,   276,     0,
     276,     0,   214,     0,    40,    34,   243,     0,   235,   276,
     232,   276,   228,   231,   234,   233
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -362,  -362,  -362,   432,  -362,   251,  -362,  -362,   641,  -362,
    -362,    11,  -362,   214,  -362,  -362,  -362,  -362,  -362,   567,
    -101,  -362,   564,    -3,  -362,    -1,   621,    -4,     4,   259,
     -42,   -30,    -2,  -275,  -362,  -362,  -362,  -362,   -69,   -63,
     268,  -362,  -362,  -362,  -362,  -362,  -361,  -117,  -362,   257,
     376,    31,  -362,  -362,   537,  -362,  -362,  -362,  -362,   -16,
    -362,   296,   378,   -88,   -62,  -362,  -362,  -362,   373,  -140,
    -189,  -362,  -362,  -362,  -362,  -362,  -362,  -285,  -293,   256,
     -85,   -92,  -362,    13,   652,   386,   574,   498,  -362,  -362,
      14,   -29,  -279,  -362,  -362,  -362,  -362,  -323,  -342,  -362,
    -362,  -362,  -362,   252,   205,   647,   245,   644,   511,   678,
     402,   397,  -362,  -362,  -362,   508,   222,  -362,  -362,  -362
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     4,    16,   390,   466,   136,   138,    17,
      80,   194,   409,   410,   494,    95,    19,    20,    21,    96,
      97,    72,    73,    35,    23,    24,    25,   156,   196,   416,
      53,    54,   218,    29,    59,   140,    60,   141,    61,    62,
     417,   197,   309,   310,   440,   441,   311,   157,   251,   351,
     256,   158,    77,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   198,   270,   199,   200,   201,   202,
     174,   203,   204,   205,   206,   207,   533,   208,   381,   321,
     109,   209,   299,   210,    40,   326,   119,   120,   121,   222,
     211,   116,   403,   478,   526,   302,   434,   437,   527,   475,
     523,   301,   433,   212,   449,    37,   323,    89,   224,    33,
     306,   341,   342,    92,   225,   229,   495,   375,   522,   484
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      26,    22,    28,    36,    39,    43,    81,   125,    27,    85,
     384,    44,   249,    90,   103,    18,   317,    30,    31,   387,
     173,    48,     6,    58,   129,   379,   399,   230,   379,   129,
      74,   -62,   442,   129,    48,   131,   250,   142,    75,    34,
     133,   307,   451,    93,   379,   170,    50,   405,    74,   235,
     408,    51,    49,   101,    41,     6,    98,    34,    52,   132,
     123,   110,    39,    63,   438,    76,   451,    43,   -62,   233,
     238,     3,   451,    51,    34,   114,   139,   451,   482,   451,
      81,   451,    10,    11,    12,    13,    14,  -289,   307,   294,
      64,   170,   172,   223,    56,   486,   100,    47,   227,    56,
      48,    74,    58,    56,   228,   195,   130,   305,    74,    98,
     452,    56,    74,   479,   353,   333,    75,   173,    51,    74,
     217,   195,   339,   450,    74,   453,    42,   217,   455,   243,
     244,   245,    98,   308,   454,    58,   230,     6,   406,   240,
     456,   314,   316,    76,   252,   488,    50,   489,   195,   490,
     271,    51,   480,   481,   232,   108,   248,    50,    56,   378,
     380,   462,    51,   380,    55,    10,    11,    12,    13,    14,
     170,   463,    -3,     5,    32,     6,   111,   170,  -287,   380,
     253,   312,   313,     7,     8,   112,   538,   254,   540,   172,
     255,   352,    10,    11,    12,    13,    14,   544,   340,   545,
       9,     6,   376,    10,    11,    12,    13,    14,   355,   382,
     383,    34,    34,    58,   525,    32,   234,   106,   436,    74,
      83,    87,   108,    38,  -256,    88,   398,   217,    82,   401,
     426,   195,   379,    74,    56,   430,    91,    74,   334,   173,
     313,    98,   344,    99,   108,   343,    86,   412,   100,   429,
      15,    10,    11,    12,    13,    14,   172,   172,   172,   172,
     172,   172,   172,   172,   172,   172,   172,   172,   172,   172,
     172,   172,   172,   172,  -287,   313,   516,   443,    50,   105,
     313,   469,   108,    51,   501,   170,   292,   108,    78,   520,
     195,   293,   -27,   313,    79,   346,   195,   195,   195,   195,
     195,   195,   386,   107,   217,   445,    45,   217,   217,   220,
      46,   172,   118,   221,   195,   195,   313,   195,    26,    22,
      28,   474,   457,   217,   113,   458,    27,   411,   500,   424,
     308,    74,   170,    18,   444,    30,    31,   117,   220,   415,
     511,   513,   324,   124,   347,   272,   273,     5,   348,     6,
     287,   288,   289,   427,   519,   428,   126,     7,     8,   427,
     352,   502,   313,   439,   529,   473,   514,   380,   285,   286,
     287,   288,   289,   492,     9,   127,   308,    10,    11,    12,
      13,    14,   313,   505,   531,   487,   508,   509,   313,   128,
     535,  -263,   515,   195,   257,   258,    74,   392,   393,   134,
      94,   226,     6,   214,   448,   431,   313,   236,   195,    74,
      65,    66,   504,   231,   524,    74,   237,   415,   528,   239,
     530,   170,   402,   415,    15,   241,   246,    71,   291,   295,
      10,    11,    12,    13,    14,   296,   298,   539,   297,   541,
     300,   542,   259,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   303,   411,    55,   304,   503,   318,    74,   285,
     286,   287,   288,   289,   319,    32,   497,   320,   327,   335,
     337,   195,   269,   -37,   195,   195,   329,   330,   332,   345,
     195,   349,    10,    11,    12,    13,    14,   354,   195,   215,
     377,     6,   389,   253,   394,   396,   400,   100,   407,    65,
      66,   397,   195,   195,  -184,  -184,   195,  -184,   195,  -184,
    -184,   217,    50,   413,  -184,   419,    71,    51,   290,    10,
      11,    12,    13,    14,    56,   195,   421,   195,   175,   195,
     176,   177,   178,   179,   180,   181,   182,   183,     7,     8,
     184,  -281,   185,   143,   186,   187,   422,   188,   189,   190,
      67,    68,    69,    70,   423,     9,   144,   145,    10,    11,
      12,    13,    14,   432,   216,   313,   146,   147,   356,   358,
     359,   360,   361,   362,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,   435,   446,   148,   459,
     468,   149,   150,   151,   464,   472,   477,   483,   191,   485,
     152,   498,   192,   193,   493,   154,   496,   499,   462,   521,
     175,   155,   176,   177,   178,   179,   180,   181,   182,   183,
       7,     8,   184,  -281,   185,   143,   186,   187,   507,   188,
     189,   190,    67,    68,    69,    70,   532,     9,   144,   145,
      10,    11,    12,    13,    14,   537,   322,   543,   146,   147,
     357,   357,   357,   357,   357,   357,   357,   357,   357,   357,
     357,   357,   357,   357,   357,   357,   357,   357,    57,   465,
     148,   491,   137,   149,   150,   151,   213,   102,   467,   471,
     191,   461,   152,   391,   192,  -292,   395,   154,   247,   476,
      84,   219,   175,   155,   176,   177,   178,   179,   180,   181,
     182,   183,     7,     8,   184,  -281,   185,   143,   186,   187,
     404,   188,   189,   190,    67,    68,    69,    70,   325,     9,
     144,   145,    10,    11,    12,    13,    14,   115,   506,   536,
     146,   147,   122,   517,   328,   104,   331,   420,   418,     0,
     534,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   148,     0,     0,   149,   150,   151,     0,     0,
       0,     0,   191,     0,   152,     0,   192,   336,     0,   154,
       0,     0,     0,     0,   175,   155,   176,   177,   178,   179,
     180,   181,   182,   183,     7,     8,   184,  -281,   185,   143,
     186,   187,     0,   188,   189,   190,    67,    68,    69,    70,
       0,     9,   144,   145,    10,    11,    12,    13,    14,     0,
       0,     0,   146,   147,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   148,     0,     0,   149,   150,   151,
       0,     0,     0,     0,   191,     0,   152,     0,   192,   388,
       0,   154,     0,     0,     0,     0,   175,   155,   176,   177,
     178,   179,   180,   181,   182,   183,     7,     8,   184,  -281,
     185,   143,   186,   187,     0,   188,   189,   190,    67,    68,
      69,    70,     0,     9,   144,   145,    10,    11,    12,    13,
      14,     0,     0,     0,   146,   147,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   148,     0,     0,   149,
     150,   151,     0,     0,     0,     0,   191,     0,   152,     0,
     192,   460,     0,   154,     0,     0,     0,     0,   175,   155,
     176,   177,   178,   179,   180,   181,   182,   183,     7,     8,
     184,  -281,   185,   143,   186,   187,     0,   188,   189,   190,
      67,    68,    69,    70,     0,     9,   144,   145,    10,    11,
      12,    13,    14,     0,     0,     0,   146,   147,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   148,     0,
       0,   149,   150,   151,     0,     0,     0,     0,   191,     0,
     152,     0,   192,   518,     0,   154,     0,     0,     0,     0,
     175,   155,   176,   177,   178,   179,   180,   181,   182,   183,
       7,     8,   184,  -281,   185,   143,   186,   187,     0,   188,
     189,   190,    67,    68,    69,    70,     0,     9,   144,   145,
      10,    11,    12,    13,    14,     0,     0,     0,   146,   147,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     148,     0,     0,   149,   150,   151,     0,     0,     0,     0,
     191,   385,   152,     6,   192,     0,     0,   154,     0,     0,
       0,    65,    66,   155,     0,   185,   143,   186,     0,     0,
       0,     0,     0,    67,    68,    69,    70,     0,    71,   144,
     145,    10,    11,    12,    13,    14,     0,     0,     0,   146,
     147,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   148,     0,     0,   149,   150,   151,     6,     0,     0,
       0,   191,     0,   152,     0,    65,    66,     6,   154,   185,
     143,   186,     0,     0,   155,    65,    66,    67,    68,    69,
      70,     0,    71,   144,   145,    10,    11,    12,    13,    14,
       0,     0,    71,   146,   147,    10,    11,    12,    13,    14,
       0,     0,   414,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   148,     0,     0,   149,   150,
     151,     6,     0,     0,     0,     0,     0,   152,     0,   215,
       0,     6,   154,   185,   143,   186,     0,     0,   155,    65,
      66,    67,    68,    69,    70,     0,     6,   144,   145,    10,
      11,    12,    13,    14,    65,    66,    71,   146,   147,    10,
      11,    12,    13,    14,     0,     0,     0,     0,     0,     0,
       0,    71,     0,     0,    10,    11,    12,    13,    14,   148,
       0,   447,   149,   150,   151,     6,     0,     0,     0,   191,
       0,   152,     0,     0,     0,     0,   154,   185,   143,   186,
       0,     0,   155,     0,  -286,    67,    68,    69,    70,     0,
       6,   144,   145,    10,    11,    12,    13,    14,    65,    66,
       0,   146,   147,     0,     0,     0,     0,     0,     0,     0,
      67,    68,    69,    70,     0,    71,     0,     0,    10,    11,
      12,    13,    14,   148,     0,     0,   149,   150,   151,     6,
       0,     0,     0,     0,     0,   152,   510,    94,     0,     6,
     154,   185,   143,   186,     0,     0,   155,    65,    66,    67,
      68,    69,    70,     0,     6,   144,   145,    10,    11,    12,
      13,    14,    65,    66,    71,   146,   147,    10,    11,    12,
      13,    14,     0,     0,   338,     0,     0,     0,     0,    71,
       0,     0,    10,    11,    12,    13,    14,   148,     0,     0,
     149,   150,   151,     6,     0,     0,     0,     0,     0,   152,
     512,    94,     0,     6,   154,   185,   143,   186,     0,     0,
     155,    65,    66,    67,    68,    69,    70,     0,     0,   144,
     145,    10,    11,    12,    13,    14,     0,     0,    71,   146,
     147,    10,    11,    12,    13,    14,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     6,
       0,   148,     0,     0,   149,   150,   151,     0,     0,     0,
       0,     0,   143,   152,     0,     0,     0,     0,   154,    67,
      68,    69,    70,     0,   155,   144,   145,    10,    11,    12,
      13,    14,     0,     0,     0,   146,   147,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     6,     0,   148,     0,     0,
     149,   150,   151,     0,     0,     0,     0,     0,   143,   152,
       0,   153,   425,     0,   154,    67,    68,    69,    70,     0,
     155,   144,   145,    10,    11,    12,    13,    14,     0,     0,
       0,   146,   147,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     6,     0,   148,     0,     0,   149,   150,   151,     0,
       0,     0,     0,     0,   143,   152,     0,   153,     0,     0,
     154,    67,    68,    69,    70,     0,   155,   144,   145,    10,
      11,    12,    13,    14,     0,     0,     0,   146,   147,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   148,
       0,     0,   149,   150,   151,     0,     6,     0,     0,     0,
       0,   152,     0,     0,     0,     0,   154,     0,   315,   143,
       0,     0,   155,     0,     0,     0,    67,    68,    69,    70,
       0,     0,   144,   145,    10,    11,    12,    13,    14,     0,
       0,     0,   146,   147,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     6,     0,   148,     0,     0,   149,   150,   151,
       0,     0,     0,     0,     0,   143,   152,   350,     0,     0,
       0,   154,    67,    68,    69,    70,     0,   155,   144,   145,
      10,    11,    12,    13,    14,     0,     0,     0,   146,   147,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     6,     0,
     148,     0,     0,   149,   150,   151,     0,     0,     0,     0,
       0,     0,   152,   470,     0,     0,     0,   154,    67,    68,
      69,    70,     0,   155,   144,   145,    10,    11,    12,    13,
      14,     0,     0,     0,   146,   147,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   148,     0,     0,   149,
     150,   151,     6,     0,     0,     0,     0,     0,   152,     0,
       0,     0,     0,   154,     0,   143,   171,     0,     0,   155,
       0,     0,    67,    68,    69,    70,     0,     0,   144,   145,
      10,    11,    12,    13,    14,     0,     0,     0,   146,   147,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     6,     0,
     148,     0,     0,   149,   150,   151,     0,     0,     0,     0,
       0,     0,   152,     0,     0,     0,     0,   154,    67,    68,
      69,    70,     0,   155,   144,   145,    10,    11,    12,    13,
      14,     0,     0,     0,   146,   147,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     6,     0,   148,     0,     0,   149,
     150,   242,     0,     0,     0,     0,     0,     0,   152,     0,
       0,     0,     0,   154,    67,    68,    69,    70,     0,   155,
     144,   145,    10,    11,    12,    13,    14,     0,     0,     0,
     146,   147,     0,     0,     0,     0,     0,     0,     0,     0,
      94,     0,     6,     0,     0,     0,     0,     0,     0,     0,
      65,    66,   148,   -69,     0,   149,   150,   151,     0,     0,
       0,     0,     0,     0,   152,     0,     0,    71,     0,   154,
      10,    11,    12,    13,    14,   155,     0,   135,     0,     0,
       0,   -69,   -69,   -69,   -69,   -69,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    50,     0,   -21,     0,     0,    51,     0,     0,     0,
       0,     0,     0,   -69,   -69,   272,   273,   274,   275,   276,
     277,   278,   279,     0,     0,   272,   273,   274,   275,   276,
     277,   278,     0,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   272,   273,   274,   275,   276,   277,     0,
       0,     0,   272,   273,   274,   275,   276,   277,     0,     0,
       0,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     272,   273,   274,   275,   276,   277,     0,   272,   273,   274,
     275,   276,   277,     0,   272,   273,   274,   275,     0,     0,
     282,   283,   284,   285,   286,   287,   288,   289,   283,   284,
     285,   286,   287,   288,   289,   283,   284,   285,   286,   287,
     288,   289
};

static const yytype_int16 yycheck[] =
{
       4,     4,     4,     7,     8,     9,    36,    92,     4,    39,
     303,    15,   152,    43,    56,     4,   205,     4,     4,   304,
     108,    22,     3,    27,     3,   300,   319,   128,   303,     3,
      34,    36,   393,     3,    35,    98,   153,   106,    34,    62,
     103,     3,     3,    47,   319,   107,    61,   326,    52,   134,
     329,    66,    36,    56,     3,     3,    52,    62,    73,   101,
      89,    65,    66,    71,   387,    34,     3,    71,    73,   132,
     139,     0,     3,    66,    62,    79,   106,     3,   439,     3,
     110,     3,    31,    32,    33,    34,    35,    80,     3,    77,
      75,   153,   108,   122,    73,    74,    66,    78,    71,    73,
     101,   105,   106,    73,    77,   109,    80,   192,   112,   105,
      71,    73,   116,   436,   254,   232,   112,   205,    66,   123,
     116,   125,   239,   402,   128,   404,    75,   123,   407,   145,
     146,   147,   128,   196,    71,   139,   237,     3,   327,   143,
      71,   203,   204,   112,    37,    71,    61,    71,   152,    71,
     166,    66,   437,   438,    79,    80,   152,    61,    73,   299,
     300,    72,    66,   303,     3,    31,    32,    33,    34,    35,
     232,    82,     0,     1,    71,     3,    63,   239,    75,   319,
      73,    71,    72,    11,    12,    72,   528,    80,   530,   205,
      83,   253,    31,    32,    33,    34,    35,   539,   240,   541,
      28,     3,   294,    31,    32,    33,    34,    35,   270,   301,
     302,    62,    62,   217,   507,    71,    74,    72,    74,   223,
      71,    71,    80,     3,    75,    75,   318,   223,    75,   321,
     347,   235,   507,   237,    73,   375,    73,   241,    74,   327,
      72,   237,   246,    61,    80,   241,    75,   332,    66,    81,
      78,    31,    32,    33,    34,    35,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,    75,    72,    74,   394,    61,    73,
      72,   421,    80,    66,    81,   347,    71,    80,    71,    81,
     294,    76,    75,    72,    77,    74,   300,   301,   302,   303,
     304,   305,   304,    79,   300,   397,    71,   303,   304,    72,
      75,   327,     3,    76,   318,   319,    72,   321,   322,   322,
     322,    77,    72,   319,    25,    75,   322,   331,   468,   345,
     393,   335,   394,   322,   396,   322,   322,    75,    72,   335,
     480,   481,    76,    74,    72,    41,    42,     1,    76,     3,
      66,    67,    68,    72,   494,    74,    73,    11,    12,    72,
     422,    74,    72,   393,    74,   427,   483,   507,    64,    65,
      66,    67,    68,   458,    28,    74,   439,    31,    32,    33,
      34,    35,    72,   475,    74,   448,   478,   479,    72,    72,
      74,    79,   484,   397,    39,    40,   400,    71,    72,    75,
       1,    74,     3,    75,   400,    71,    72,    74,   412,   413,
      11,    12,   474,    81,   506,   419,    72,   413,   510,    79,
     512,   483,    76,   419,    78,    62,    16,    28,    81,    71,
      31,    32,    33,    34,    35,    71,    71,   529,     3,   531,
      73,   533,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    73,   457,     3,    73,   472,    77,   462,    64,
      65,    66,    67,    68,    73,    71,   462,    14,    79,    73,
      15,   475,    79,    74,   478,   479,    76,    76,    75,    74,
     484,     3,    31,    32,    33,    34,    35,     3,   492,     1,
      71,     3,    71,    73,    79,    81,    73,    66,    76,    11,
      12,    77,   506,   507,    71,    72,   510,    74,   512,    76,
      77,   507,    61,    73,    81,    73,    28,    66,    85,    31,
      32,    33,    34,    35,    73,   529,    80,   531,     1,   533,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    73,    20,    21,    22,
      23,    24,    25,    26,    63,    28,    29,    30,    31,    32,
      33,    34,    35,    74,    76,    72,    39,    40,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,    74,    74,    61,    73,
      80,    64,    65,    66,    74,    73,    21,    79,    71,    74,
      73,    38,    75,    76,    74,    78,    74,    74,    72,    74,
       1,    84,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    73,    20,
      21,    22,    23,    24,    25,    26,    19,    28,    29,    30,
      31,    32,    33,    34,    35,    74,   214,    71,    39,    40,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,    27,   418,
      61,   457,   105,    64,    65,    66,   112,    56,   419,   422,
      71,   413,    73,   307,    75,    76,   313,    78,   151,   433,
      38,   117,     1,    84,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
     324,    20,    21,    22,    23,    24,    25,    26,   220,    28,
      29,    30,    31,    32,    33,    34,    35,    80,   476,   524,
      39,    40,    88,   488,   223,    57,   228,   340,   336,    -1,
     518,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    61,    -1,    -1,    64,    65,    66,    -1,    -1,
      -1,    -1,    71,    -1,    73,    -1,    75,    76,    -1,    78,
      -1,    -1,    -1,    -1,     1,    84,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    -1,    20,    21,    22,    23,    24,    25,    26,
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    -1,
      -1,    -1,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    61,    -1,    -1,    64,    65,    66,
      -1,    -1,    -1,    -1,    71,    -1,    73,    -1,    75,    76,
      -1,    78,    -1,    -1,    -1,    -1,     1,    84,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    -1,    20,    21,    22,    23,    24,
      25,    26,    -1,    28,    29,    30,    31,    32,    33,    34,
      35,    -1,    -1,    -1,    39,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    61,    -1,    -1,    64,
      65,    66,    -1,    -1,    -1,    -1,    71,    -1,    73,    -1,
      75,    76,    -1,    78,    -1,    -1,    -1,    -1,     1,    84,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    -1,    20,    21,    22,
      23,    24,    25,    26,    -1,    28,    29,    30,    31,    32,
      33,    34,    35,    -1,    -1,    -1,    39,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    -1,
      -1,    64,    65,    66,    -1,    -1,    -1,    -1,    71,    -1,
      73,    -1,    75,    76,    -1,    78,    -1,    -1,    -1,    -1,
       1,    84,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    -1,    20,
      21,    22,    23,    24,    25,    26,    -1,    28,    29,    30,
      31,    32,    33,    34,    35,    -1,    -1,    -1,    39,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      61,    -1,    -1,    64,    65,    66,    -1,    -1,    -1,    -1,
      71,     1,    73,     3,    75,    -1,    -1,    78,    -1,    -1,
      -1,    11,    12,    84,    -1,    15,    16,    17,    -1,    -1,
      -1,    -1,    -1,    23,    24,    25,    26,    -1,    28,    29,
      30,    31,    32,    33,    34,    35,    -1,    -1,    -1,    39,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    61,    -1,    -1,    64,    65,    66,     3,    -1,    -1,
      -1,    71,    -1,    73,    -1,    11,    12,     3,    78,    15,
      16,    17,    -1,    -1,    84,    11,    12,    23,    24,    25,
      26,    -1,    28,    29,    30,    31,    32,    33,    34,    35,
      -1,    -1,    28,    39,    40,    31,    32,    33,    34,    35,
      -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    61,    -1,    -1,    64,    65,
      66,     3,    -1,    -1,    -1,    -1,    -1,    73,    -1,     1,
      -1,     3,    78,    15,    16,    17,    -1,    -1,    84,    11,
      12,    23,    24,    25,    26,    -1,     3,    29,    30,    31,
      32,    33,    34,    35,    11,    12,    28,    39,    40,    31,
      32,    33,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    28,    -1,    -1,    31,    32,    33,    34,    35,    61,
      -1,    38,    64,    65,    66,     3,    -1,    -1,    -1,    71,
      -1,    73,    -1,    -1,    -1,    -1,    78,    15,    16,    17,
      -1,    -1,    84,    -1,    76,    23,    24,    25,    26,    -1,
       3,    29,    30,    31,    32,    33,    34,    35,    11,    12,
      -1,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      23,    24,    25,    26,    -1,    28,    -1,    -1,    31,    32,
      33,    34,    35,    61,    -1,    -1,    64,    65,    66,     3,
      -1,    -1,    -1,    -1,    -1,    73,    74,     1,    -1,     3,
      78,    15,    16,    17,    -1,    -1,    84,    11,    12,    23,
      24,    25,    26,    -1,     3,    29,    30,    31,    32,    33,
      34,    35,    11,    12,    28,    39,    40,    31,    32,    33,
      34,    35,    -1,    -1,    38,    -1,    -1,    -1,    -1,    28,
      -1,    -1,    31,    32,    33,    34,    35,    61,    -1,    -1,
      64,    65,    66,     3,    -1,    -1,    -1,    -1,    -1,    73,
      74,     1,    -1,     3,    78,    15,    16,    17,    -1,    -1,
      84,    11,    12,    23,    24,    25,    26,    -1,    -1,    29,
      30,    31,    32,    33,    34,    35,    -1,    -1,    28,    39,
      40,    31,    32,    33,    34,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
      -1,    61,    -1,    -1,    64,    65,    66,    -1,    -1,    -1,
      -1,    -1,    16,    73,    -1,    -1,    -1,    -1,    78,    23,
      24,    25,    26,    -1,    84,    29,    30,    31,    32,    33,
      34,    35,    -1,    -1,    -1,    39,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,    -1,    61,    -1,    -1,
      64,    65,    66,    -1,    -1,    -1,    -1,    -1,    16,    73,
      -1,    75,    76,    -1,    78,    23,    24,    25,    26,    -1,
      84,    29,    30,    31,    32,    33,    34,    35,    -1,    -1,
      -1,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,    -1,    61,    -1,    -1,    64,    65,    66,    -1,
      -1,    -1,    -1,    -1,    16,    73,    -1,    75,    -1,    -1,
      78,    23,    24,    25,    26,    -1,    84,    29,    30,    31,
      32,    33,    34,    35,    -1,    -1,    -1,    39,    40,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,
      -1,    -1,    64,    65,    66,    -1,     3,    -1,    -1,    -1,
      -1,    73,    -1,    -1,    -1,    -1,    78,    -1,    80,    16,
      -1,    -1,    84,    -1,    -1,    -1,    23,    24,    25,    26,
      -1,    -1,    29,    30,    31,    32,    33,    34,    35,    -1,
      -1,    -1,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,    -1,    61,    -1,    -1,    64,    65,    66,
      -1,    -1,    -1,    -1,    -1,    16,    73,    74,    -1,    -1,
      -1,    78,    23,    24,    25,    26,    -1,    84,    29,    30,
      31,    32,    33,    34,    35,    -1,    -1,    -1,    39,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,
      61,    -1,    -1,    64,    65,    66,    -1,    -1,    -1,    -1,
      -1,    -1,    73,    74,    -1,    -1,    -1,    78,    23,    24,
      25,    26,    -1,    84,    29,    30,    31,    32,    33,    34,
      35,    -1,    -1,    -1,    39,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    61,    -1,    -1,    64,
      65,    66,     3,    -1,    -1,    -1,    -1,    -1,    73,    -1,
      -1,    -1,    -1,    78,    -1,    16,    81,    -1,    -1,    84,
      -1,    -1,    23,    24,    25,    26,    -1,    -1,    29,    30,
      31,    32,    33,    34,    35,    -1,    -1,    -1,    39,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,
      61,    -1,    -1,    64,    65,    66,    -1,    -1,    -1,    -1,
      -1,    -1,    73,    -1,    -1,    -1,    -1,    78,    23,    24,
      25,    26,    -1,    84,    29,    30,    31,    32,    33,    34,
      35,    -1,    -1,    -1,    39,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,    -1,    61,    -1,    -1,    64,
      65,    66,    -1,    -1,    -1,    -1,    -1,    -1,    73,    -1,
      -1,    -1,    -1,    78,    23,    24,    25,    26,    -1,    84,
      29,    30,    31,    32,    33,    34,    35,    -1,    -1,    -1,
      39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       1,    -1,     3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      11,    12,    61,     3,    -1,    64,    65,    66,    -1,    -1,
      -1,    -1,    -1,    -1,    73,    -1,    -1,    28,    -1,    78,
      31,    32,    33,    34,    35,    84,    -1,    38,    -1,    -1,
      -1,    31,    32,    33,    34,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    61,    -1,    74,    -1,    -1,    66,    -1,    -1,    -1,
      -1,    -1,    -1,    73,    74,    41,    42,    43,    44,    45,
      46,    47,    48,    -1,    -1,    41,    42,    43,    44,    45,
      46,    47,    -1,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    41,    42,    43,    44,    45,    46,    -1,
      -1,    -1,    41,    42,    43,    44,    45,    46,    -1,    -1,
      -1,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      41,    42,    43,    44,    45,    46,    -1,    41,    42,    43,
      44,    45,    46,    -1,    41,    42,    43,    44,    -1,    -1,
      61,    62,    63,    64,    65,    66,    67,    68,    62,    63,
      64,    65,    66,    67,    68,    62,    63,    64,    65,    66,
      67,    68
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    87,    88,     0,    89,     1,     3,    11,    12,    28,
      31,    32,    33,    34,    35,    78,    90,    95,    97,   102,
     103,   104,   109,   110,   111,   112,   113,   114,   118,   119,
     169,   176,    71,   195,    62,   109,   113,   191,     3,   113,
     170,     3,    75,   113,   113,    71,    75,    78,   111,    36,
      61,    66,    73,   116,   117,     3,    73,    94,   113,   120,
     122,   124,   125,    71,    75,    11,    12,    23,    24,    25,
      26,    28,   107,   108,   113,   114,   137,   138,    71,    77,
      96,   117,    75,    71,   170,   117,    75,    71,    75,   193,
     117,    73,   199,   113,     1,   101,   105,   106,   114,    61,
      66,   109,   112,   116,   195,    73,    72,    79,    80,   166,
     113,    63,    72,    25,   113,   191,   177,    75,     3,   172,
     173,   174,   193,   177,    74,   166,    73,    74,    72,     3,
      80,   125,   116,   125,    75,    38,    93,   105,    94,   117,
     121,   123,   124,    16,    29,    30,    39,    40,    61,    64,
      65,    66,    73,    75,    78,    84,   113,   133,   137,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,    81,   145,   149,   156,     1,     3,     4,     5,     6,
       7,     8,     9,    10,    13,    15,    17,    18,    20,    21,
      22,    71,    75,    76,    97,   113,   114,   127,   150,   152,
     153,   154,   155,   157,   158,   159,   160,   161,   163,   167,
     169,   176,   189,   108,    75,     1,    76,   114,   118,   172,
      72,    76,   175,   177,   194,   200,    74,    71,    77,   201,
     106,    81,    79,   125,    74,   166,    74,    72,   124,    79,
     113,    62,    66,   145,   145,   145,    16,   140,   114,   155,
     133,   134,    37,    73,    80,    83,   136,    39,    40,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    79,
     151,   145,    41,    42,    43,    44,    45,    46,    47,    48,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      85,    81,    71,    76,    77,    71,    71,     3,    71,   168,
      73,   187,   181,    73,    73,   166,   196,     3,   125,   128,
     129,   132,    71,    72,   150,    80,   150,   156,    77,    73,
      14,   165,    89,   192,    76,   173,   171,    79,   194,    76,
      76,   201,    75,   133,    74,    73,    76,    15,    38,   133,
     116,   197,   198,   114,   113,    74,    74,    72,    76,     3,
      74,   135,   150,   155,     3,   150,   147,   148,   147,   147,
     147,   147,   147,   147,   147,   147,   147,   147,   147,   147,
     147,   147,   147,   147,   147,   203,   167,    71,   155,   119,
     155,   164,   167,   167,   164,     1,   118,   163,    76,    71,
      91,   136,    71,    72,    79,   154,    81,    77,   167,   164,
      73,   167,    76,   178,   171,   178,   156,    76,   178,    98,
      99,   113,   166,    73,    38,   114,   115,   126,   196,    73,
     197,    80,    73,    63,   145,    76,   133,    72,    74,    81,
     155,    71,    74,   188,   182,    74,    74,   183,   183,   117,
     130,   131,   132,   133,   150,   167,    74,    38,   114,   190,
     178,     3,    71,   178,    71,   178,    71,    72,    75,    73,
      76,   126,    72,    82,    74,    91,    92,   115,    80,   155,
      74,   135,    73,   150,    77,   185,   165,    21,   179,   183,
     163,   163,   132,    79,   205,    74,    74,   125,    71,    71,
      71,    99,   166,    74,   100,   202,    74,   114,    38,    74,
     155,    81,    74,   145,   150,   167,   189,    73,   167,   167,
      74,   155,    74,   155,   133,   167,    74,   192,    76,   155,
      81,    74,   204,   186,   167,   164,   180,   184,   167,    74,
     167,    74,    19,   162,   202,    74,   190,    74,   184,   167,
     184,   167,   167,    71,   184,   184
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    86,    88,    87,    89,    89,    90,    90,    90,    90,
      90,    90,    90,    90,    91,    91,    92,    92,    93,    93,
      93,    93,    94,    94,    95,    95,    96,    96,    97,    97,
      97,    98,    98,   100,    99,    99,   101,   101,   102,   102,
     102,   103,   103,   104,   104,   105,   105,   106,   106,   106,
     106,   106,   107,   107,   108,   108,   109,   110,   110,   110,
     110,   110,   111,   111,   112,   112,   113,   113,   114,   114,
     114,   114,   114,   114,   114,   114,   115,   115,   116,   116,
     117,   117,   117,   118,   118,   119,   120,   120,   121,   121,
     122,   122,   123,   123,   124,   124,   125,   125,   125,   125,
     125,   126,   126,   126,   126,   127,   128,   128,   129,   129,
     130,   130,   131,   131,   132,   132,   133,   133,   133,   134,
     134,   134,   135,   135,   136,   136,   137,   137,   137,   137,
     138,   138,   139,   139,   140,   140,   140,   141,   141,   142,
     142,   142,   143,   143,   143,   143,   143,   143,   144,   144,
     144,   145,   145,   145,   145,   145,   145,   146,   146,   146,
     146,   146,   146,   147,   147,   148,   148,   148,   148,   148,
     148,   148,   148,   148,   148,   148,   148,   148,   148,   148,
     148,   148,   148,   148,   149,   149,   150,   150,   150,   151,
     151,   151,   151,   151,   151,   151,   151,   151,   151,   151,
     152,   152,   153,   154,   154,   154,   155,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   163,   164,   164,   165,
     165,   165,   166,   166,   167,   167,   167,   167,   167,   167,
     167,   167,   167,   167,   167,   167,   167,   167,   167,   167,
     167,   168,   167,   167,   167,   167,   167,   167,   167,   167,
     167,   167,   167,   169,   169,   169,   170,   171,   172,   172,
     173,   173,   174,   175,   176,   176,   176,   177,   177,   178,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     2,     0,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     1,     0,     1,     3,
       1,     0,     4,     8,     8,     7,     2,     0,     3,    10,
       8,     3,     1,     0,     5,     3,     1,     0,     5,     9,
      11,     4,     5,     2,     6,     3,     1,     2,     4,     1,
       3,     1,     3,     1,     1,     1,     2,     1,     1,     1,
       1,     1,     1,     4,     2,     1,     1,     1,     2,     1,
       2,     2,     2,     3,     3,     3,     3,     1,     2,     1,
       2,     1,     1,     2,     2,     2,     3,     1,     1,     3,
       1,     3,     1,     2,     1,     1,     1,     4,     3,     7,
       8,     1,     0,     1,     3,     3,     3,     1,     1,     3,
       1,     3,     2,     1,     1,     2,     1,     3,     4,     1,
       3,     0,     1,     3,     2,     3,     1,     1,     1,     1,
       2,     1,     1,     1,     3,     5,     6,     6,     7,     1,
       1,     3,     1,     4,     2,     3,     3,     7,     1,     2,
       2,     1,     2,     2,     2,     4,     2,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     7,     1,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     4,     2,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     2,     1,     1,     1,     5,
       4,     4,     2,     0,     3,     4,     3,     6,     8,     7,
       7,     9,     8,     9,     9,     8,     7,     3,     2,     2,
       2,     0,     4,     8,     4,     1,     3,     1,     1,     1,
       1,     2,     2,     8,     9,     3,     0,     0,     1,     3,
       1,     4,     1,     0,     9,     8,     3,     2,     0,     2,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0
};


/* YYDPREC[RULE-NUM] -- Dynamic precedence of rule #RULE-NUM (0 if none).  */
static const yytype_int8 yydprec[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     2,     0,     0,     1,     3,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     2,     5,     5,     0,     4,
       4,     0,     0,     0,     1,     0,     0,     0,     0,     3,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     1,     0,     2,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0
};

/* YYMERGER[RULE-NUM] -- Index of merging function for rule #RULE-NUM.  */
static const yytype_int8 yymerger[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0
};

/* YYIMMEDIATE[RULE-NUM] -- True iff rule #RULE-NUM is not to be deferred, as
   in the case of predicates.  */
static const yybool yyimmediate[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0
};

/* YYCONFLP[YYPACT[STATE-NUM]] -- Pointer into YYCONFL of start of
   list of conflicting reductions corresponding to action entry for
   state STATE-NUM in yytable.  0 means no conflicts.  The list in
   yyconfl is terminated by a rule number of 0.  */
static const yytype_int8 yyconflp[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     1,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     3,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     5,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     7,     0,     0,     0,     0,     9,     0,     0,     0,
       0,     0,     0,    11,    13,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0
};

/* YYCONFL[I] -- lists of conflicting rule numbers, each terminated by
   0, pointed into by YYCONFLP.  */
static const short yyconfl[] =
{
       0,    62,     0,    69,     0,    62,     0,   139,     0,   139,
       0,   139,     0,   139,     0
};

/* Error token number */
#define YYTERROR 1



YYSTYPE yylval;

int yynerrs;
int yychar;

static const int YYEOF = 0;
static const int YYEMPTY = -2;

typedef enum { yyok, yyaccept, yyabort, yyerr } YYRESULTTAG;

#define YYCHK(YYE)                              \
  do {                                          \
    YYRESULTTAG yychk_flag = YYE;               \
    if (yychk_flag != yyok)                     \
      return yychk_flag;                        \
  } while (0)

#if YYDEBUG

# ifndef YYFPRINTF
#  define YYFPRINTF fprintf
# endif

# define YY_FPRINTF                             \
  YY_IGNORE_USELESS_CAST_BEGIN YY_FPRINTF_

# define YY_FPRINTF_(Args)                      \
  do {                                          \
    YYFPRINTF Args;                             \
    YY_IGNORE_USELESS_CAST_END                  \
  } while (0)

# define YY_DPRINTF                             \
  YY_IGNORE_USELESS_CAST_BEGIN YY_DPRINTF_

# define YY_DPRINTF_(Args)                      \
  do {                                          \
    if (yydebug)                                \
      YYFPRINTF Args;                           \
    YY_IGNORE_USELESS_CAST_END                  \
  } while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif



/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                  \
  do {                                                                  \
    if (yydebug)                                                        \
      {                                                                 \
        YY_FPRINTF ((stderr, "%s ", Title));                            \
        yy_symbol_print (stderr, Type, Value);        \
        YY_FPRINTF ((stderr, "\n"));                                    \
      }                                                                 \
  } while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;

struct yyGLRStack;
static void yypstack (struct yyGLRStack* yystackp, ptrdiff_t yyk)
  YY_ATTRIBUTE_UNUSED;
static void yypdumpstack (struct yyGLRStack* yystackp)
  YY_ATTRIBUTE_UNUSED;

#else /* !YYDEBUG */

# define YY_DPRINTF(Args) do {} while (yyfalse)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)

#endif /* !YYDEBUG */

/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   SIZE_MAX < YYMAXDEPTH * sizeof (GLRStackItem)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif

/* Minimum number of free items on the stack allowed after an
   allocation.  This is to allow allocation and initialization
   to be completed by functions that call yyexpandGLRStack before the
   stack is expanded, thus insuring that all necessary pointers get
   properly redirected to new data.  */
#define YYHEADROOM 2

#ifndef YYSTACKEXPANDABLE
#  define YYSTACKEXPANDABLE 1
#endif

#if YYSTACKEXPANDABLE
# define YY_RESERVE_GLRSTACK(Yystack)                   \
  do {                                                  \
    if (Yystack->yyspaceLeft < YYHEADROOM)              \
      yyexpandGLRStack (Yystack);                       \
  } while (0)
#else
# define YY_RESERVE_GLRSTACK(Yystack)                   \
  do {                                                  \
    if (Yystack->yyspaceLeft < YYHEADROOM)              \
      yyMemoryExhausted (Yystack);                      \
  } while (0)
#endif


#if YYERROR_VERBOSE

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static ptrdiff_t
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      ptrdiff_t yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return YY_CAST (ptrdiff_t, strlen (yystr));
}
# endif

#endif /* !YYERROR_VERBOSE */

/** State numbers. */
typedef int yyStateNum;

/** Rule numbers. */
typedef int yyRuleNum;

/** Grammar symbol. */
typedef int yySymbol;

/** Item references. */
typedef short yyItemNum;

typedef struct yyGLRState yyGLRState;
typedef struct yyGLRStateSet yyGLRStateSet;
typedef struct yySemanticOption yySemanticOption;
typedef union yyGLRStackItem yyGLRStackItem;
typedef struct yyGLRStack yyGLRStack;

struct yyGLRState {
  /** Type tag: always true.  */
  yybool yyisState;
  /** Type tag for yysemantics.  If true, yysval applies, otherwise
   *  yyfirstVal applies.  */
  yybool yyresolved;
  /** Number of corresponding LALR(1) machine state.  */
  yyStateNum yylrState;
  /** Preceding state in this stack */
  yyGLRState* yypred;
  /** Source position of the last token produced by my symbol */
  ptrdiff_t yyposn;
  union {
    /** First in a chain of alternative reductions producing the
     *  nonterminal corresponding to this state, threaded through
     *  yynext.  */
    yySemanticOption* yyfirstVal;
    /** Semantic value for this state.  */
    YYSTYPE yysval;
  } yysemantics;
};

struct yyGLRStateSet {
  yyGLRState** yystates;
  /** During nondeterministic operation, yylookaheadNeeds tracks which
   *  stacks have actually needed the current lookahead.  During deterministic
   *  operation, yylookaheadNeeds[0] is not maintained since it would merely
   *  duplicate yychar != YYEMPTY.  */
  yybool* yylookaheadNeeds;
  ptrdiff_t yysize;
  ptrdiff_t yycapacity;
};

struct yySemanticOption {
  /** Type tag: always false.  */
  yybool yyisState;
  /** Rule number for this reduction */
  yyRuleNum yyrule;
  /** The last RHS state in the list of states to be reduced.  */
  yyGLRState* yystate;
  /** The lookahead for this reduction.  */
  int yyrawchar;
  YYSTYPE yyval;
  /** Next sibling in chain of options.  To facilitate merging,
   *  options are chained in decreasing order by address.  */
  yySemanticOption* yynext;
};

/** Type of the items in the GLR stack.  The yyisState field
 *  indicates which item of the union is valid.  */
union yyGLRStackItem {
  yyGLRState yystate;
  yySemanticOption yyoption;
};

struct yyGLRStack {
  int yyerrState;


  YYJMP_BUF yyexception_buffer;
  yyGLRStackItem* yyitems;
  yyGLRStackItem* yynextFree;
  ptrdiff_t yyspaceLeft;
  yyGLRState* yysplitPoint;
  yyGLRState* yylastDeleted;
  yyGLRStateSet yytops;
};

#if YYSTACKEXPANDABLE
static void yyexpandGLRStack (yyGLRStack* yystackp);
#endif

_Noreturn static void
yyFail (yyGLRStack* yystackp, const char* yymsg)
{
  if (yymsg != YY_NULLPTR)
    yyerror (yymsg);
  YYLONGJMP (yystackp->yyexception_buffer, 1);
}

_Noreturn static void
yyMemoryExhausted (yyGLRStack* yystackp)
{
  YYLONGJMP (yystackp->yyexception_buffer, 2);
}

#if YYDEBUG || YYERROR_VERBOSE
/** A printable representation of TOKEN.  */
static inline const char*
yytokenName (yySymbol yytoken)
{
  return yytoken == YYEMPTY ? "" : yytname[yytoken];
}
#endif

/** Fill in YYVSP[YYLOW1 .. YYLOW0-1] from the chain of states starting
 *  at YYVSP[YYLOW0].yystate.yypred.  Leaves YYVSP[YYLOW1].yystate.yypred
 *  containing the pointer to the next state in the chain.  */
static void yyfillin (yyGLRStackItem *, int, int) YY_ATTRIBUTE_UNUSED;
static void
yyfillin (yyGLRStackItem *yyvsp, int yylow0, int yylow1)
{
  int i;
  yyGLRState *s = yyvsp[yylow0].yystate.yypred;
  for (i = yylow0-1; i >= yylow1; i -= 1)
    {
#if YYDEBUG
      yyvsp[i].yystate.yylrState = s->yylrState;
#endif
      yyvsp[i].yystate.yyresolved = s->yyresolved;
      if (s->yyresolved)
        yyvsp[i].yystate.yysemantics.yysval = s->yysemantics.yysval;
      else
        /* The effect of using yysval or yyloc (in an immediate rule) is
         * undefined.  */
        yyvsp[i].yystate.yysemantics.yyfirstVal = YY_NULLPTR;
      s = yyvsp[i].yystate.yypred = s->yypred;
    }
}


/** If yychar is empty, fetch the next token.  */
static inline yySymbol
yygetToken (int *yycharp)
{
  yySymbol yytoken;
  if (*yycharp == YYEMPTY)
    {
      YY_DPRINTF ((stderr, "Reading a token: "));
      *yycharp = yylex ();
    }
  if (*yycharp <= YYEOF)
    {
      *yycharp = yytoken = YYEOF;
      YY_DPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (*yycharp);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }
  return yytoken;
}

/* Do nothing if YYNORMAL or if *YYLOW <= YYLOW1.  Otherwise, fill in
 * YYVSP[YYLOW1 .. *YYLOW-1] as in yyfillin and set *YYLOW = YYLOW1.
 * For convenience, always return YYLOW1.  */
static inline int yyfill (yyGLRStackItem *, int *, int, yybool)
     YY_ATTRIBUTE_UNUSED;
static inline int
yyfill (yyGLRStackItem *yyvsp, int *yylow, int yylow1, yybool yynormal)
{
  if (!yynormal && yylow1 < *yylow)
    {
      yyfillin (yyvsp, *yylow, yylow1);
      *yylow = yylow1;
    }
  return yylow1;
}

/** Perform user action for rule number YYN, with RHS length YYRHSLEN,
 *  and top stack item YYVSP.  YYLVALP points to place to put semantic
 *  value ($$), and yylocp points to place for location information
 *  (@$).  Returns yyok for normal return, yyaccept for YYACCEPT,
 *  yyerr for YYERROR, yyabort for YYABORT.  */
static YYRESULTTAG
yyuserAction (yyRuleNum yyn, int yyrhslen, yyGLRStackItem* yyvsp,
              yyGLRStack* yystackp,
              YYSTYPE* yyvalp)
{
  yybool yynormal YY_ATTRIBUTE_UNUSED = yystackp->yysplitPoint == YY_NULLPTR;
  int yylow;
  YYUSE (yyvalp);
  YYUSE (yyrhslen);
# undef yyerrok
# define yyerrok (yystackp->yyerrState = 0)
# undef YYACCEPT
# define YYACCEPT return yyaccept
# undef YYABORT
# define YYABORT return yyabort
# undef YYERROR
# define YYERROR return yyerrok, yyerr
# undef YYRECOVERING
# define YYRECOVERING() (yystackp->yyerrState != 0)
# undef yyclearin
# define yyclearin (yychar = YYEMPTY)
# undef YYFILL
# define YYFILL(N) yyfill (yyvsp, &yylow, (N), yynormal)
# undef YYBACKUP
# define YYBACKUP(Token, Value)                                              \
  return yyerror (YY_("syntax error: cannot back up")),     \
         yyerrok, yyerr

  yylow = 1;
  if (yyrhslen == 0)
    *yyvalp = yyval_default;
  else
    *yyvalp = yyvsp[YYFILL (1-yyrhslen)].yystate.yysemantics.yysval;
  switch (yyn)
    {
  case 2:
#line 95 "res/dpl.y"
          { openProgramScope(); }
#line 2018 "/mnt/d/Markov folder/Nauka/2019/CCPE/Kod/SimilarityDetection/SimilarityDetectionCuda/build/../src/parser.cpp"
    break;

  case 3:
#line 95 "res/dpl.y"
                                           { closeProgramScope(yylineno); /*printf("OK\n");*/}
#line 2024 "/mnt/d/Markov folder/Nauka/2019/CCPE/Kod/SimilarityDetection/SimilarityDetectionCuda/build/../src/parser.cpp"
    break;

  case 33:
#line 160 "res/dpl.y"
                                                        { insertToken(ASSIGN, yylineno); }
#line 2030 "/mnt/d/Markov folder/Nauka/2019/CCPE/Kod/SimilarityDetection/SimilarityDetectionCuda/build/../src/parser.cpp"
    break;

  case 35:
#line 161 "res/dpl.y"
                                                                        { insertToken(ASSIGN, yylineno); }
#line 2036 "/mnt/d/Markov folder/Nauka/2019/CCPE/Kod/SimilarityDetection/SimilarityDetectionCuda/build/../src/parser.cpp"
    break;

  case 38:
#line 168 "res/dpl.y"
                                                                     { b_util_tid_buffer_clear(); }
#line 2042 "/mnt/d/Markov folder/Nauka/2019/CCPE/Kod/SimilarityDetection/SimilarityDetectionCuda/build/../src/parser.cpp"
    break;

  case 47:
#line 189 "res/dpl.y"
                                                                                { insertDeclaratorInParameterList();  }
#line 2048 "/mnt/d/Markov folder/Nauka/2019/CCPE/Kod/SimilarityDetection/SimilarityDetectionCuda/build/../src/parser.cpp"
    break;

  case 48:
#line 190 "res/dpl.y"
                                                                                { insertDeclaratorInParameterList();  }
#line 2054 "/mnt/d/Markov folder/Nauka/2019/CCPE/Kod/SimilarityDetection/SimilarityDetectionCuda/build/../src/parser.cpp"
    break;

  case 57:
#line 208 "res/dpl.y"
                                        { last_read_type = NUM_VARDEF; }
#line 2060 "/mnt/d/Markov folder/Nauka/2019/CCPE/Kod/SimilarityDetection/SimilarityDetectionCuda/build/../src/parser.cpp"
    break;

  case 58:
#line 209 "res/dpl.y"
                                                        { last_read_type = BOOL_VARDEF;	}
#line 2066 "/mnt/d/Markov folder/Nauka/2019/CCPE/Kod/SimilarityDetection/SimilarityDetectionCuda/build/../src/parser.cpp"
    break;

  case 59:
#line 210 "res/dpl.y"
                                                        { last_read_type = CHAR_VARDEF; }
#line 2072 "/mnt/d/Markov folder/Nauka/2019/CCPE/Kod/SimilarityDetection/SimilarityDetectionCuda/build/../src/parser.cpp"
    break;

  case 60:
#line 211 "res/dpl.y"
                                                        { last_read_type = STRING_VARDEF; }
#line 2078 "/mnt/d/Markov folder/Nauka/2019/CCPE/Kod/SimilarityDetection/SimilarityDetectionCuda/build/../src/parser.cpp"
    break;

  case 61:
#line 212 "res/dpl.y"
                                                        {}
#line 2084 "/mnt/d/Markov folder/Nauka/2019/CCPE/Kod/SimilarityDetection/SimilarityDetectionCuda/build/../src/parser.cpp"
    break;

  case 66:
#line 223 "res/dpl.y"
                                                { last_read_type = USERTYPE_VARDEF; }
#line 2090 "/mnt/d/Markov folder/Nauka/2019/CCPE/Kod/SimilarityDetection/SimilarityDetectionCuda/build/../src/parser.cpp"
    break;

  case 68:
#line 227 "res/dpl.y"
                                                { definition_type = last_read_type; }
#line 2096 "/mnt/d/Markov folder/Nauka/2019/CCPE/Kod/SimilarityDetection/SimilarityDetectionCuda/build/../src/parser.cpp"
    break;

  case 69:
#line 228 "res/dpl.y"
                                                                                { definition_type = last_read_type; }
#line 2102 "/mnt/d/Markov folder/Nauka/2019/CCPE/Kod/SimilarityDetection/SimilarityDetectionCuda/build/../src/parser.cpp"
    break;

  case 70:
#line 229 "res/dpl.y"
                                                                        { definition_type = last_read_type; }
#line 2108 "/mnt/d/Markov folder/Nauka/2019/CCPE/Kod/SimilarityDetection/SimilarityDetectionCuda/build/../src/parser.cpp"
    break;

  case 71:
#line 230 "res/dpl.y"
                                                                        { definition_type = last_read_type; }
#line 2114 "/mnt/d/Markov folder/Nauka/2019/CCPE/Kod/SimilarityDetection/SimilarityDetectionCuda/build/../src/parser.cpp"
    break;

  case 72:
#line 231 "res/dpl.y"
                                                                        { definition_type = last_read_type; }
#line 2120 "/mnt/d/Markov folder/Nauka/2019/CCPE/Kod/SimilarityDetection/SimilarityDetectionCuda/build/../src/parser.cpp"
    break;

  case 73:
#line 232 "res/dpl.y"
                                                                                                { definition_type = last_read_type; }
#line 2126 "/mnt/d/Markov folder/Nauka/2019/CCPE/Kod/SimilarityDetection/SimilarityDetectionCuda/build/../src/parser.cpp"
    break;

  case 74:
#line 233 "res/dpl.y"
                                                                                                { definition_type = last_read_type; }
#line 2132 "/mnt/d/Markov folder/Nauka/2019/CCPE/Kod/SimilarityDetection/SimilarityDetectionCuda/build/../src/parser.cpp"
    break;

  case 75:
#line 234 "res/dpl.y"
                                                                                                { definition_type = last_read_type; }
#line 2138 "/mnt/d/Markov folder/Nauka/2019/CCPE/Kod/SimilarityDetection/SimilarityDetectionCuda/build/../src/parser.cpp"
    break;

  case 89:
#line 267 "res/dpl.y"
                                                                                                        { insertToken(ASSIGN, yylineno); }
#line 2144 "/mnt/d/Markov folder/Nauka/2019/CCPE/Kod/SimilarityDetection/SimilarityDetectionCuda/build/../src/parser.cpp"
    break;

  case 91:
#line 271 "res/dpl.y"
                                                                                                { insertToken(ASSIGN, yylineno); }
#line 2150 "/mnt/d/Markov folder/Nauka/2019/CCPE/Kod/SimilarityDetection/SimilarityDetectionCuda/build/../src/parser.cpp"
    break;

  case 94:
#line 278 "res/dpl.y"
                                                                                                        { insertDeclaratorInScope(); }
#line 2156 "/mnt/d/Markov folder/Nauka/2019/CCPE/Kod/SimilarityDetection/SimilarityDetectionCuda/build/../src/parser.cpp"
    break;

  case 95:
#line 279 "res/dpl.y"
                                                                                                                        { b_util_tid_buffer_clear(); }
#line 2162 "/mnt/d/Markov folder/Nauka/2019/CCPE/Kod/SimilarityDetection/SimilarityDetectionCuda/build/../src/parser.cpp"
    break;

  case 96:
#line 282 "res/dpl.y"
                                                                                                                                { var_definition = SIMPLEVAR; }
#line 2168 "/mnt/d/Markov folder/Nauka/2019/CCPE/Kod/SimilarityDetection/SimilarityDetectionCuda/build/../src/parser.cpp"
    break;

  case 97:
#line 284 "res/dpl.y"
                                                                                                        { var_definition = ARRAYVAR; }
#line 2174 "/mnt/d/Markov folder/Nauka/2019/CCPE/Kod/SimilarityDetection/SimilarityDetectionCuda/build/../src/parser.cpp"
    break;

  case 98:
#line 285 "res/dpl.y"
                                                                                                                                { var_definition = ARRAYVAR; }
#line 2180 "/mnt/d/Markov folder/Nauka/2019/CCPE/Kod/SimilarityDetection/SimilarityDetectionCuda/build/../src/parser.cpp"
    break;

  case 99:
#line 286 "res/dpl.y"
                                                                                                                                { var_definition = FPOINTER; }
#line 2186 "/mnt/d/Markov folder/Nauka/2019/CCPE/Kod/SimilarityDetection/SimilarityDetectionCuda/build/../src/parser.cpp"
    break;

  case 100:
#line 287 "res/dpl.y"
                                                                                                                { var_definition = FPOINTER; }
#line 2192 "/mnt/d/Markov folder/Nauka/2019/CCPE/Kod/SimilarityDetection/SimilarityDetectionCuda/build/../src/parser.cpp"
    break;

  case 109:
#line 306 "res/dpl.y"
                                                                              { insertToken(ASSIGN, yylineno); }
#line 2198 "/mnt/d/Markov folder/Nauka/2019/CCPE/Kod/SimilarityDetection/SimilarityDetectionCuda/build/../src/parser.cpp"
    break;

  case 111:
#line 310 "res/dpl.y"
                                                                                { insertToken(ASSIGN, yylineno); }
#line 2204 "/mnt/d/Markov folder/Nauka/2019/CCPE/Kod/SimilarityDetection/SimilarityDetectionCuda/build/../src/parser.cpp"
    break;

  case 114:
#line 317 "res/dpl.y"
                                                                        { 	insertDeclaratorInScope(); 		}
#line 2210 "/mnt/d/Markov folder/Nauka/2019/CCPE/Kod/SimilarityDetection/SimilarityDetectionCuda/build/../src/parser.cpp"
    break;

  case 115:
#line 318 "res/dpl.y"
                                                                                                { 	insertDeclaratorInScope(); 
															insertToken(ASSIGN, yylineno); 	}
#line 2217 "/mnt/d/Markov folder/Nauka/2019/CCPE/Kod/SimilarityDetection/SimilarityDetectionCuda/build/../src/parser.cpp"
    break;

  case 144:
#line 394 "res/dpl.y"
                                                                               { insertToken(APPLY, yylineno); }
#line 2223 "/mnt/d/Markov folder/Nauka/2019/CCPE/Kod/SimilarityDetection/SimilarityDetectionCuda/build/../src/parser.cpp"
    break;

  case 149:
#line 401 "res/dpl.y"
                                                                        { insertToken(ASSIGN, yylineno); }
#line 2229 "/mnt/d/Markov folder/Nauka/2019/CCPE/Kod/SimilarityDetection/SimilarityDetectionCuda/build/../src/parser.cpp"
    break;

  case 150:
#line 402 "res/dpl.y"
                                                                        { insertToken(ASSIGN, yylineno); }
#line 2235 "/mnt/d/Markov folder/Nauka/2019/CCPE/Kod/SimilarityDetection/SimilarityDetectionCuda/build/../src/parser.cpp"
    break;

  case 152:
#line 406 "res/dpl.y"
                                                                                                { insertToken(ASSIGN, yylineno); }
#line 2241 "/mnt/d/Markov folder/Nauka/2019/CCPE/Kod/SimilarityDetection/SimilarityDetectionCuda/build/../src/parser.cpp"
    break;

  case 153:
#line 407 "res/dpl.y"
                                                                                                { insertToken(ASSIGN, yylineno); }
#line 2247 "/mnt/d/Markov folder/Nauka/2019/CCPE/Kod/SimilarityDetection/SimilarityDetectionCuda/build/../src/parser.cpp"
    break;

  case 188:
#line 454 "res/dpl.y"
                                                                                                                 { insertToken(ASSIGN, yylineno); }
#line 2253 "/mnt/d/Markov folder/Nauka/2019/CCPE/Kod/SimilarityDetection/SimilarityDetectionCuda/build/../src/parser.cpp"
    break;

  case 209:
#line 487 "res/dpl.y"
                        { insertToken(THROW, yylineno); 	}
#line 2259 "/mnt/d/Markov folder/Nauka/2019/CCPE/Kod/SimilarityDetection/SimilarityDetectionCuda/build/../src/parser.cpp"
    break;

  case 210:
#line 488 "res/dpl.y"
                        { insertToken(DELETE, yylineno); 	}
#line 2265 "/mnt/d/Markov folder/Nauka/2019/CCPE/Kod/SimilarityDetection/SimilarityDetectionCuda/build/../src/parser.cpp"
    break;

  case 211:
#line 493 "res/dpl.y"
                        { insertToken(CASE, yylineno); }
#line 2271 "/mnt/d/Markov folder/Nauka/2019/CCPE/Kod/SimilarityDetection/SimilarityDetectionCuda/build/../src/parser.cpp"
    break;

  case 212:
#line 494 "res/dpl.y"
                        { insertToken(CASE, yylineno); }
#line 2277 "/mnt/d/Markov folder/Nauka/2019/CCPE/Kod/SimilarityDetection/SimilarityDetectionCuda/build/../src/parser.cpp"
    break;

  case 213:
#line 495 "res/dpl.y"
                     { insertToken_openScope(BEGIN_IF, yylineno); }
#line 2283 "/mnt/d/Markov folder/Nauka/2019/CCPE/Kod/SimilarityDetection/SimilarityDetectionCuda/build/../src/parser.cpp"
    break;

  case 214:
#line 496 "res/dpl.y"
                        { insertToken_reopenScope(ELSE, yylineno); }
#line 2289 "/mnt/d/Markov folder/Nauka/2019/CCPE/Kod/SimilarityDetection/SimilarityDetectionCuda/build/../src/parser.cpp"
    break;

  case 219:
#line 507 "res/dpl.y"
                                                             { insertDeclaratorInParameterList(); }
#line 2295 "/mnt/d/Markov folder/Nauka/2019/CCPE/Kod/SimilarityDetection/SimilarityDetectionCuda/build/../src/parser.cpp"
    break;

  case 227:
#line 521 "res/dpl.y"
                                                                                                                        { insertToken_closeScope(END_IF, yylineno); }
#line 2301 "/mnt/d/Markov folder/Nauka/2019/CCPE/Kod/SimilarityDetection/SimilarityDetectionCuda/build/../src/parser.cpp"
    break;

  case 228:
#line 522 "res/dpl.y"
                                                                                                        { insertToken_closeScope(END_IF, yylineno); }
#line 2307 "/mnt/d/Markov folder/Nauka/2019/CCPE/Kod/SimilarityDetection/SimilarityDetectionCuda/build/../src/parser.cpp"
    break;

  case 237:
#line 534 "res/dpl.y"
                                                        { insertToken(GOTO, yylineno); 		}
#line 2313 "/mnt/d/Markov folder/Nauka/2019/CCPE/Kod/SimilarityDetection/SimilarityDetectionCuda/build/../src/parser.cpp"
    break;

  case 238:
#line 535 "res/dpl.y"
                                                        { insertToken(CONTINUE, yylineno); 	}
#line 2319 "/mnt/d/Markov folder/Nauka/2019/CCPE/Kod/SimilarityDetection/SimilarityDetectionCuda/build/../src/parser.cpp"
    break;

  case 239:
#line 536 "res/dpl.y"
                                                                { insertToken(BREAK, yylineno); 	}
#line 2325 "/mnt/d/Markov folder/Nauka/2019/CCPE/Kod/SimilarityDetection/SimilarityDetectionCuda/build/../src/parser.cpp"
    break;

  case 240:
#line 537 "res/dpl.y"
                                                        { insertToken(RETURN, yylineno); 	}
#line 2331 "/mnt/d/Markov folder/Nauka/2019/CCPE/Kod/SimilarityDetection/SimilarityDetectionCuda/build/../src/parser.cpp"
    break;

  case 241:
#line 538 "res/dpl.y"
                                                                { insertToken(RETURN, yylineno); 	}
#line 2337 "/mnt/d/Markov folder/Nauka/2019/CCPE/Kod/SimilarityDetection/SimilarityDetectionCuda/build/../src/parser.cpp"
    break;

  case 256:
#line 565 "res/dpl.y"
            { insertToken(BEGIN_ENUM, yylineno); }
#line 2343 "/mnt/d/Markov folder/Nauka/2019/CCPE/Kod/SimilarityDetection/SimilarityDetectionCuda/build/../src/parser.cpp"
    break;

  case 257:
#line 566 "res/dpl.y"
          { insertToken(END_ENUM, yylineno); }
#line 2349 "/mnt/d/Markov folder/Nauka/2019/CCPE/Kod/SimilarityDetection/SimilarityDetectionCuda/build/../src/parser.cpp"
    break;

  case 262:
#line 578 "res/dpl.y"
                        { insertToken(ENUM_VALUE, yylineno); }
#line 2355 "/mnt/d/Markov folder/Nauka/2019/CCPE/Kod/SimilarityDetection/SimilarityDetectionCuda/build/../src/parser.cpp"
    break;

  case 263:
#line 579 "res/dpl.y"
                  { insertToken(ASSIGN, yylineno); }
#line 2361 "/mnt/d/Markov folder/Nauka/2019/CCPE/Kod/SimilarityDetection/SimilarityDetectionCuda/build/../src/parser.cpp"
    break;

  case 271:
#line 599 "res/dpl.y"
                        { insertToken_openScope(BEGIN_WHILE, yylineno); }
#line 2367 "/mnt/d/Markov folder/Nauka/2019/CCPE/Kod/SimilarityDetection/SimilarityDetectionCuda/build/../src/parser.cpp"
    break;

  case 272:
#line 600 "res/dpl.y"
                                { insertToken_closeScope(END_WHILE, yylineno); }
#line 2373 "/mnt/d/Markov folder/Nauka/2019/CCPE/Kod/SimilarityDetection/SimilarityDetectionCuda/build/../src/parser.cpp"
    break;

  case 273:
#line 602 "res/dpl.y"
                                { insertToken_openScope(BEGIN_DO, yylineno); }
#line 2379 "/mnt/d/Markov folder/Nauka/2019/CCPE/Kod/SimilarityDetection/SimilarityDetectionCuda/build/../src/parser.cpp"
    break;

  case 274:
#line 603 "res/dpl.y"
                                { insertToken_closeScope(END_DO, yylineno); }
#line 2385 "/mnt/d/Markov folder/Nauka/2019/CCPE/Kod/SimilarityDetection/SimilarityDetectionCuda/build/../src/parser.cpp"
    break;

  case 275:
#line 605 "res/dpl.y"
                                { insertToken_openScope(BEGIN_FOR, yylineno); }
#line 2391 "/mnt/d/Markov folder/Nauka/2019/CCPE/Kod/SimilarityDetection/SimilarityDetectionCuda/build/../src/parser.cpp"
    break;

  case 276:
#line 606 "res/dpl.y"
                                { insertToken_closeScope(END_FOR, yylineno); }
#line 2397 "/mnt/d/Markov folder/Nauka/2019/CCPE/Kod/SimilarityDetection/SimilarityDetectionCuda/build/../src/parser.cpp"
    break;

  case 277:
#line 608 "res/dpl.y"
                        { insertToken_openScope(BEGIN_SWITCH, yylineno); }
#line 2403 "/mnt/d/Markov folder/Nauka/2019/CCPE/Kod/SimilarityDetection/SimilarityDetectionCuda/build/../src/parser.cpp"
    break;

  case 278:
#line 609 "res/dpl.y"
                        { insertToken_closeScope(END_SWITCH, yylineno); }
#line 2409 "/mnt/d/Markov folder/Nauka/2019/CCPE/Kod/SimilarityDetection/SimilarityDetectionCuda/build/../src/parser.cpp"
    break;

  case 279:
#line 611 "res/dpl.y"
                                { insertToken_openScope(BEGIN_TRY, yylineno); }
#line 2415 "/mnt/d/Markov folder/Nauka/2019/CCPE/Kod/SimilarityDetection/SimilarityDetectionCuda/build/../src/parser.cpp"
    break;

  case 280:
#line 612 "res/dpl.y"
                                { insertToken_closeScope(END_TRY, yylineno); }
#line 2421 "/mnt/d/Markov folder/Nauka/2019/CCPE/Kod/SimilarityDetection/SimilarityDetectionCuda/build/../src/parser.cpp"
    break;

  case 281:
#line 613 "res/dpl.y"
                        { insertToken_openScope(BEGIN_CATCH, yylineno); insertParametersInScope(); }
#line 2427 "/mnt/d/Markov folder/Nauka/2019/CCPE/Kod/SimilarityDetection/SimilarityDetectionCuda/build/../src/parser.cpp"
    break;

  case 282:
#line 614 "res/dpl.y"
                                { insertToken_closeScope(END_CATCH, yylineno); }
#line 2433 "/mnt/d/Markov folder/Nauka/2019/CCPE/Kod/SimilarityDetection/SimilarityDetectionCuda/build/../src/parser.cpp"
    break;

  case 283:
#line 616 "res/dpl.y"
                        { insertToken_openScope(BEGIN_CLASS, yylineno); }
#line 2439 "/mnt/d/Markov folder/Nauka/2019/CCPE/Kod/SimilarityDetection/SimilarityDetectionCuda/build/../src/parser.cpp"
    break;

  case 284:
#line 617 "res/dpl.y"
                                { insertToken_closeScope(END_CLASS, yylineno); }
#line 2445 "/mnt/d/Markov folder/Nauka/2019/CCPE/Kod/SimilarityDetection/SimilarityDetectionCuda/build/../src/parser.cpp"
    break;

  case 285:
#line 619 "res/dpl.y"
                        { insertToken_openScope(BEGIN_UNION, yylineno); }
#line 2451 "/mnt/d/Markov folder/Nauka/2019/CCPE/Kod/SimilarityDetection/SimilarityDetectionCuda/build/../src/parser.cpp"
    break;

  case 286:
#line 620 "res/dpl.y"
                                { insertToken_closeScope(END_UNION, yylineno); }
#line 2457 "/mnt/d/Markov folder/Nauka/2019/CCPE/Kod/SimilarityDetection/SimilarityDetectionCuda/build/../src/parser.cpp"
    break;

  case 287:
#line 622 "res/dpl.y"
                        { insertToken_openScope(BEGIN_FUNCTION, yylineno); insertParametersInScope(); }
#line 2463 "/mnt/d/Markov folder/Nauka/2019/CCPE/Kod/SimilarityDetection/SimilarityDetectionCuda/build/../src/parser.cpp"
    break;

  case 288:
#line 623 "res/dpl.y"
                        { insertToken_closeScope(END_FUNCTION, yylineno);	}
#line 2469 "/mnt/d/Markov folder/Nauka/2019/CCPE/Kod/SimilarityDetection/SimilarityDetectionCuda/build/../src/parser.cpp"
    break;

  case 289:
#line 625 "res/dpl.y"
                                { insertToken(NEW_ARRAY, yylineno); }
#line 2475 "/mnt/d/Markov folder/Nauka/2019/CCPE/Kod/SimilarityDetection/SimilarityDetectionCuda/build/../src/parser.cpp"
    break;

  case 290:
#line 626 "res/dpl.y"
                        { insertToken(NEW_OBJECT, yylineno); }
#line 2481 "/mnt/d/Markov folder/Nauka/2019/CCPE/Kod/SimilarityDetection/SimilarityDetectionCuda/build/../src/parser.cpp"
    break;

  case 291:
#line 628 "res/dpl.y"
                                { insertToken_openScope(BEGIN_DESTRUCTOR, yylineno); 	}
#line 2487 "/mnt/d/Markov folder/Nauka/2019/CCPE/Kod/SimilarityDetection/SimilarityDetectionCuda/build/../src/parser.cpp"
    break;

  case 292:
#line 629 "res/dpl.y"
                                { insertToken_closeScope(END_DESTRUCTOR, yylineno); 	}
#line 2493 "/mnt/d/Markov folder/Nauka/2019/CCPE/Kod/SimilarityDetection/SimilarityDetectionCuda/build/../src/parser.cpp"
    break;

  case 293:
#line 631 "res/dpl.y"
                                { insertToken_openScope(BEGIN_CONSTRUCTOR, yylineno); insertParametersInScope(); }
#line 2499 "/mnt/d/Markov folder/Nauka/2019/CCPE/Kod/SimilarityDetection/SimilarityDetectionCuda/build/../src/parser.cpp"
    break;

  case 294:
#line 632 "res/dpl.y"
                                { insertToken_closeScope(END_CONSTRUCTOR, yylineno); }
#line 2505 "/mnt/d/Markov folder/Nauka/2019/CCPE/Kod/SimilarityDetection/SimilarityDetectionCuda/build/../src/parser.cpp"
    break;

  case 295:
#line 634 "res/dpl.y"
                                { insertToken(BEGIN_CONDITIONAL, yylineno); }
#line 2511 "/mnt/d/Markov folder/Nauka/2019/CCPE/Kod/SimilarityDetection/SimilarityDetectionCuda/build/../src/parser.cpp"
    break;

  case 296:
#line 635 "res/dpl.y"
                                { insertToken(END_CONDITIONAL, yylineno); }
#line 2517 "/mnt/d/Markov folder/Nauka/2019/CCPE/Kod/SimilarityDetection/SimilarityDetectionCuda/build/../src/parser.cpp"
    break;

  case 297:
#line 637 "res/dpl.y"
                          {insertToken(THEN, yylineno);}
#line 2523 "/mnt/d/Markov folder/Nauka/2019/CCPE/Kod/SimilarityDetection/SimilarityDetectionCuda/build/../src/parser.cpp"
    break;


#line 2527 "/mnt/d/Markov folder/Nauka/2019/CCPE/Kod/SimilarityDetection/SimilarityDetectionCuda/build/../src/parser.cpp"

      default: break;
    }

  return yyok;
# undef yyerrok
# undef YYABORT
# undef YYACCEPT
# undef YYERROR
# undef YYBACKUP
# undef yyclearin
# undef YYRECOVERING
}


static void
yyuserMerge (int yyn, YYSTYPE* yy0, YYSTYPE* yy1)
{
  YYUSE (yy0);
  YYUSE (yy1);

  switch (yyn)
    {

      default: break;
    }
}

                              /* Bison grammar-table manipulation.  */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}

/** Number of symbols composing the right hand side of rule #RULE.  */
static inline int
yyrhsLength (yyRuleNum yyrule)
{
  return yyr2[yyrule];
}

static void
yydestroyGLRState (char const *yymsg, yyGLRState *yys)
{
  if (yys->yyresolved)
    yydestruct (yymsg, yystos[yys->yylrState],
                &yys->yysemantics.yysval);
  else
    {
#if YYDEBUG
      if (yydebug)
        {
          if (yys->yysemantics.yyfirstVal)
            YY_FPRINTF ((stderr, "%s unresolved", yymsg));
          else
            YY_FPRINTF ((stderr, "%s incomplete", yymsg));
          YY_SYMBOL_PRINT ("", yystos[yys->yylrState], YY_NULLPTR, &yys->yyloc);
        }
#endif

      if (yys->yysemantics.yyfirstVal)
        {
          yySemanticOption *yyoption = yys->yysemantics.yyfirstVal;
          yyGLRState *yyrh;
          int yyn;
          for (yyrh = yyoption->yystate, yyn = yyrhsLength (yyoption->yyrule);
               yyn > 0;
               yyrh = yyrh->yypred, yyn -= 1)
            yydestroyGLRState (yymsg, yyrh);
        }
    }
}

/** Left-hand-side symbol for rule #YYRULE.  */
static inline yySymbol
yylhsNonterm (yyRuleNum yyrule)
{
  return yyr1[yyrule];
}

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

/** True iff LR state YYSTATE has only a default reduction (regardless
 *  of token).  */
static inline yybool
yyisDefaultedState (yyStateNum yystate)
{
  return yypact_value_is_default (yypact[yystate]);
}

/** The default reduction for YYSTATE, assuming it has one.  */
static inline yyRuleNum
yydefaultAction (yyStateNum yystate)
{
  return yydefact[yystate];
}

#define yytable_value_is_error(Yyn) \
  0

/** The action to take in YYSTATE on seeing YYTOKEN.
 *  Result R means
 *    R < 0:  Reduce on rule -R.
 *    R = 0:  Error.
 *    R > 0:  Shift to state R.
 *  Set *YYCONFLICTS to a pointer into yyconfl to a 0-terminated list
 *  of conflicting reductions.
 */
static inline int
yygetLRActions (yyStateNum yystate, yySymbol yytoken, const short** yyconflicts)
{
  int yyindex = yypact[yystate] + yytoken;
  if (yyisDefaultedState (yystate)
      || yyindex < 0 || YYLAST < yyindex || yycheck[yyindex] != yytoken)
    {
      *yyconflicts = yyconfl;
      return -yydefact[yystate];
    }
  else if (! yytable_value_is_error (yytable[yyindex]))
    {
      *yyconflicts = yyconfl + yyconflp[yyindex];
      return yytable[yyindex];
    }
  else
    {
      *yyconflicts = yyconfl + yyconflp[yyindex];
      return 0;
    }
}

/** Compute post-reduction state.
 * \param yystate   the current state
 * \param yysym     the nonterminal to push on the stack
 */
static inline yyStateNum
yyLRgotoState (yyStateNum yystate, yySymbol yysym)
{
  int yyr = yypgoto[yysym - YYNTOKENS] + yystate;
  if (0 <= yyr && yyr <= YYLAST && yycheck[yyr] == yystate)
    return yytable[yyr];
  else
    return yydefgoto[yysym - YYNTOKENS];
}

static inline yybool
yyisShiftAction (int yyaction)
{
  return 0 < yyaction;
}

static inline yybool
yyisErrorAction (int yyaction)
{
  return yyaction == 0;
}

                                /* GLRStates */

/** Return a fresh GLRStackItem in YYSTACKP.  The item is an LR state
 *  if YYISSTATE, and otherwise a semantic option.  Callers should call
 *  YY_RESERVE_GLRSTACK afterwards to make sure there is sufficient
 *  headroom.  */

static inline yyGLRStackItem*
yynewGLRStackItem (yyGLRStack* yystackp, yybool yyisState)
{
  yyGLRStackItem* yynewItem = yystackp->yynextFree;
  yystackp->yyspaceLeft -= 1;
  yystackp->yynextFree += 1;
  yynewItem->yystate.yyisState = yyisState;
  return yynewItem;
}

/** Add a new semantic action that will execute the action for rule
 *  YYRULE on the semantic values in YYRHS to the list of
 *  alternative actions for YYSTATE.  Assumes that YYRHS comes from
 *  stack #YYK of *YYSTACKP. */
static void
yyaddDeferredAction (yyGLRStack* yystackp, ptrdiff_t yyk, yyGLRState* yystate,
                     yyGLRState* yyrhs, yyRuleNum yyrule)
{
  yySemanticOption* yynewOption =
    &yynewGLRStackItem (yystackp, yyfalse)->yyoption;
  YY_ASSERT (!yynewOption->yyisState);
  yynewOption->yystate = yyrhs;
  yynewOption->yyrule = yyrule;
  if (yystackp->yytops.yylookaheadNeeds[yyk])
    {
      yynewOption->yyrawchar = yychar;
      yynewOption->yyval = yylval;
    }
  else
    yynewOption->yyrawchar = YYEMPTY;
  yynewOption->yynext = yystate->yysemantics.yyfirstVal;
  yystate->yysemantics.yyfirstVal = yynewOption;

  YY_RESERVE_GLRSTACK (yystackp);
}

                                /* GLRStacks */

/** Initialize YYSET to a singleton set containing an empty stack.  */
static yybool
yyinitStateSet (yyGLRStateSet* yyset)
{
  yyset->yysize = 1;
  yyset->yycapacity = 16;
  yyset->yystates
    = YY_CAST (yyGLRState**,
               YYMALLOC (YY_CAST (size_t, yyset->yycapacity)
                         * sizeof yyset->yystates[0]));
  if (! yyset->yystates)
    return yyfalse;
  yyset->yystates[0] = YY_NULLPTR;
  yyset->yylookaheadNeeds
    = YY_CAST (yybool*,
               YYMALLOC (YY_CAST (size_t, yyset->yycapacity)
                         * sizeof yyset->yylookaheadNeeds[0]));
  if (! yyset->yylookaheadNeeds)
    {
      YYFREE (yyset->yystates);
      return yyfalse;
    }
  memset (yyset->yylookaheadNeeds,
          0,
          YY_CAST (size_t, yyset->yycapacity) * sizeof yyset->yylookaheadNeeds[0]);
  return yytrue;
}

static void yyfreeStateSet (yyGLRStateSet* yyset)
{
  YYFREE (yyset->yystates);
  YYFREE (yyset->yylookaheadNeeds);
}

/** Initialize *YYSTACKP to a single empty stack, with total maximum
 *  capacity for all stacks of YYSIZE.  */
static yybool
yyinitGLRStack (yyGLRStack* yystackp, ptrdiff_t yysize)
{
  yystackp->yyerrState = 0;
  yynerrs = 0;
  yystackp->yyspaceLeft = yysize;
  yystackp->yyitems
    = YY_CAST (yyGLRStackItem*,
               YYMALLOC (YY_CAST (size_t, yysize)
                         * sizeof yystackp->yynextFree[0]));
  if (!yystackp->yyitems)
    return yyfalse;
  yystackp->yynextFree = yystackp->yyitems;
  yystackp->yysplitPoint = YY_NULLPTR;
  yystackp->yylastDeleted = YY_NULLPTR;
  return yyinitStateSet (&yystackp->yytops);
}


#if YYSTACKEXPANDABLE
# define YYRELOC(YYFROMITEMS, YYTOITEMS, YYX, YYTYPE)                   \
  &((YYTOITEMS)                                                         \
    - ((YYFROMITEMS) - YY_REINTERPRET_CAST (yyGLRStackItem*, (YYX))))->YYTYPE

/** If *YYSTACKP is expandable, extend it.  WARNING: Pointers into the
    stack from outside should be considered invalid after this call.
    We always expand when there are 1 or fewer items left AFTER an
    allocation, so that we can avoid having external pointers exist
    across an allocation.  */
static void
yyexpandGLRStack (yyGLRStack* yystackp)
{
  yyGLRStackItem* yynewItems;
  yyGLRStackItem* yyp0, *yyp1;
  ptrdiff_t yynewSize;
  ptrdiff_t yyn;
  ptrdiff_t yysize = yystackp->yynextFree - yystackp->yyitems;
  if (YYMAXDEPTH - YYHEADROOM < yysize)
    yyMemoryExhausted (yystackp);
  yynewSize = 2*yysize;
  if (YYMAXDEPTH < yynewSize)
    yynewSize = YYMAXDEPTH;
  yynewItems
    = YY_CAST (yyGLRStackItem*,
               YYMALLOC (YY_CAST (size_t, yynewSize)
                         * sizeof yynewItems[0]));
  if (! yynewItems)
    yyMemoryExhausted (yystackp);
  for (yyp0 = yystackp->yyitems, yyp1 = yynewItems, yyn = yysize;
       0 < yyn;
       yyn -= 1, yyp0 += 1, yyp1 += 1)
    {
      *yyp1 = *yyp0;
      if (*YY_REINTERPRET_CAST (yybool *, yyp0))
        {
          yyGLRState* yys0 = &yyp0->yystate;
          yyGLRState* yys1 = &yyp1->yystate;
          if (yys0->yypred != YY_NULLPTR)
            yys1->yypred =
              YYRELOC (yyp0, yyp1, yys0->yypred, yystate);
          if (! yys0->yyresolved && yys0->yysemantics.yyfirstVal != YY_NULLPTR)
            yys1->yysemantics.yyfirstVal =
              YYRELOC (yyp0, yyp1, yys0->yysemantics.yyfirstVal, yyoption);
        }
      else
        {
          yySemanticOption* yyv0 = &yyp0->yyoption;
          yySemanticOption* yyv1 = &yyp1->yyoption;
          if (yyv0->yystate != YY_NULLPTR)
            yyv1->yystate = YYRELOC (yyp0, yyp1, yyv0->yystate, yystate);
          if (yyv0->yynext != YY_NULLPTR)
            yyv1->yynext = YYRELOC (yyp0, yyp1, yyv0->yynext, yyoption);
        }
    }
  if (yystackp->yysplitPoint != YY_NULLPTR)
    yystackp->yysplitPoint = YYRELOC (yystackp->yyitems, yynewItems,
                                      yystackp->yysplitPoint, yystate);

  for (yyn = 0; yyn < yystackp->yytops.yysize; yyn += 1)
    if (yystackp->yytops.yystates[yyn] != YY_NULLPTR)
      yystackp->yytops.yystates[yyn] =
        YYRELOC (yystackp->yyitems, yynewItems,
                 yystackp->yytops.yystates[yyn], yystate);
  YYFREE (yystackp->yyitems);
  yystackp->yyitems = yynewItems;
  yystackp->yynextFree = yynewItems + yysize;
  yystackp->yyspaceLeft = yynewSize - yysize;
}
#endif

static void
yyfreeGLRStack (yyGLRStack* yystackp)
{
  YYFREE (yystackp->yyitems);
  yyfreeStateSet (&yystackp->yytops);
}

/** Assuming that YYS is a GLRState somewhere on *YYSTACKP, update the
 *  splitpoint of *YYSTACKP, if needed, so that it is at least as deep as
 *  YYS.  */
static inline void
yyupdateSplit (yyGLRStack* yystackp, yyGLRState* yys)
{
  if (yystackp->yysplitPoint != YY_NULLPTR && yystackp->yysplitPoint > yys)
    yystackp->yysplitPoint = yys;
}

/** Invalidate stack #YYK in *YYSTACKP.  */
static inline void
yymarkStackDeleted (yyGLRStack* yystackp, ptrdiff_t yyk)
{
  if (yystackp->yytops.yystates[yyk] != YY_NULLPTR)
    yystackp->yylastDeleted = yystackp->yytops.yystates[yyk];
  yystackp->yytops.yystates[yyk] = YY_NULLPTR;
}

/** Undelete the last stack in *YYSTACKP that was marked as deleted.  Can
    only be done once after a deletion, and only when all other stacks have
    been deleted.  */
static void
yyundeleteLastStack (yyGLRStack* yystackp)
{
  if (yystackp->yylastDeleted == YY_NULLPTR || yystackp->yytops.yysize != 0)
    return;
  yystackp->yytops.yystates[0] = yystackp->yylastDeleted;
  yystackp->yytops.yysize = 1;
  YY_DPRINTF ((stderr, "Restoring last deleted stack as stack #0.\n"));
  yystackp->yylastDeleted = YY_NULLPTR;
}

static inline void
yyremoveDeletes (yyGLRStack* yystackp)
{
  ptrdiff_t yyi, yyj;
  yyi = yyj = 0;
  while (yyj < yystackp->yytops.yysize)
    {
      if (yystackp->yytops.yystates[yyi] == YY_NULLPTR)
        {
          if (yyi == yyj)
            YY_DPRINTF ((stderr, "Removing dead stacks.\n"));
          yystackp->yytops.yysize -= 1;
        }
      else
        {
          yystackp->yytops.yystates[yyj] = yystackp->yytops.yystates[yyi];
          /* In the current implementation, it's unnecessary to copy
             yystackp->yytops.yylookaheadNeeds[yyi] since, after
             yyremoveDeletes returns, the parser immediately either enters
             deterministic operation or shifts a token.  However, it doesn't
             hurt, and the code might evolve to need it.  */
          yystackp->yytops.yylookaheadNeeds[yyj] =
            yystackp->yytops.yylookaheadNeeds[yyi];
          if (yyj != yyi)
            YY_DPRINTF ((stderr, "Rename stack %ld -> %ld.\n",
                        YY_CAST (long, yyi), YY_CAST (long, yyj)));
          yyj += 1;
        }
      yyi += 1;
    }
}

/** Shift to a new state on stack #YYK of *YYSTACKP, corresponding to LR
 * state YYLRSTATE, at input position YYPOSN, with (resolved) semantic
 * value *YYVALP and source location *YYLOCP.  */
static inline void
yyglrShift (yyGLRStack* yystackp, ptrdiff_t yyk, yyStateNum yylrState,
            ptrdiff_t yyposn,
            YYSTYPE* yyvalp)
{
  yyGLRState* yynewState = &yynewGLRStackItem (yystackp, yytrue)->yystate;

  yynewState->yylrState = yylrState;
  yynewState->yyposn = yyposn;
  yynewState->yyresolved = yytrue;
  yynewState->yypred = yystackp->yytops.yystates[yyk];
  yynewState->yysemantics.yysval = *yyvalp;
  yystackp->yytops.yystates[yyk] = yynewState;

  YY_RESERVE_GLRSTACK (yystackp);
}

/** Shift stack #YYK of *YYSTACKP, to a new state corresponding to LR
 *  state YYLRSTATE, at input position YYPOSN, with the (unresolved)
 *  semantic value of YYRHS under the action for YYRULE.  */
static inline void
yyglrShiftDefer (yyGLRStack* yystackp, ptrdiff_t yyk, yyStateNum yylrState,
                 ptrdiff_t yyposn, yyGLRState* yyrhs, yyRuleNum yyrule)
{
  yyGLRState* yynewState = &yynewGLRStackItem (yystackp, yytrue)->yystate;
  YY_ASSERT (yynewState->yyisState);

  yynewState->yylrState = yylrState;
  yynewState->yyposn = yyposn;
  yynewState->yyresolved = yyfalse;
  yynewState->yypred = yystackp->yytops.yystates[yyk];
  yynewState->yysemantics.yyfirstVal = YY_NULLPTR;
  yystackp->yytops.yystates[yyk] = yynewState;

  /* Invokes YY_RESERVE_GLRSTACK.  */
  yyaddDeferredAction (yystackp, yyk, yynewState, yyrhs, yyrule);
}

#if !YYDEBUG
# define YY_REDUCE_PRINT(Args)
#else
# define YY_REDUCE_PRINT(Args)          \
  do {                                  \
    if (yydebug)                        \
      yy_reduce_print Args;             \
  } while (0)

/*----------------------------------------------------------------------.
| Report that stack #YYK of *YYSTACKP is going to be reduced by YYRULE. |
`----------------------------------------------------------------------*/

static inline void
yy_reduce_print (yybool yynormal, yyGLRStackItem* yyvsp, ptrdiff_t yyk,
                 yyRuleNum yyrule)
{
  int yynrhs = yyrhsLength (yyrule);
  int yyi;
  YY_FPRINTF ((stderr, "Reducing stack %ld by rule %d (line %d):\n",
               YY_CAST (long, yyk), yyrule - 1, yyrline[yyrule]));
  if (! yynormal)
    yyfillin (yyvsp, 1, -yynrhs);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YY_FPRINTF ((stderr, "   $%d = ", yyi + 1));
      yy_symbol_print (stderr,
                       yystos[yyvsp[yyi - yynrhs + 1].yystate.yylrState],
                       &yyvsp[yyi - yynrhs + 1].yystate.yysemantics.yysval                       );
      if (!yyvsp[yyi - yynrhs + 1].yystate.yyresolved)
        YY_FPRINTF ((stderr, " (unresolved)"));
      YY_FPRINTF ((stderr, "\n"));
    }
}
#endif

/** Pop the symbols consumed by reduction #YYRULE from the top of stack
 *  #YYK of *YYSTACKP, and perform the appropriate semantic action on their
 *  semantic values.  Assumes that all ambiguities in semantic values
 *  have been previously resolved.  Set *YYVALP to the resulting value,
 *  and *YYLOCP to the computed location (if any).  Return value is as
 *  for userAction.  */
static inline YYRESULTTAG
yydoAction (yyGLRStack* yystackp, ptrdiff_t yyk, yyRuleNum yyrule,
            YYSTYPE* yyvalp)
{
  int yynrhs = yyrhsLength (yyrule);

  if (yystackp->yysplitPoint == YY_NULLPTR)
    {
      /* Standard special case: single stack.  */
      yyGLRStackItem* yyrhs
        = YY_REINTERPRET_CAST (yyGLRStackItem*, yystackp->yytops.yystates[yyk]);
      YY_ASSERT (yyk == 0);
      yystackp->yynextFree -= yynrhs;
      yystackp->yyspaceLeft += yynrhs;
      yystackp->yytops.yystates[0] = & yystackp->yynextFree[-1].yystate;
      YY_REDUCE_PRINT ((yytrue, yyrhs, yyk, yyrule));
      return yyuserAction (yyrule, yynrhs, yyrhs, yystackp,
                           yyvalp);
    }
  else
    {
      yyGLRStackItem yyrhsVals[YYMAXRHS + YYMAXLEFT + 1];
      yyGLRState* yys = yyrhsVals[YYMAXRHS + YYMAXLEFT].yystate.yypred
        = yystackp->yytops.yystates[yyk];
      int yyi;
      for (yyi = 0; yyi < yynrhs; yyi += 1)
        {
          yys = yys->yypred;
          YY_ASSERT (yys);
        }
      yyupdateSplit (yystackp, yys);
      yystackp->yytops.yystates[yyk] = yys;
      YY_REDUCE_PRINT ((yyfalse, yyrhsVals + YYMAXRHS + YYMAXLEFT - 1, yyk, yyrule));
      return yyuserAction (yyrule, yynrhs, yyrhsVals + YYMAXRHS + YYMAXLEFT - 1,
                           yystackp, yyvalp);
    }
}

/** Pop items off stack #YYK of *YYSTACKP according to grammar rule YYRULE,
 *  and push back on the resulting nonterminal symbol.  Perform the
 *  semantic action associated with YYRULE and store its value with the
 *  newly pushed state, if YYFORCEEVAL or if *YYSTACKP is currently
 *  unambiguous.  Otherwise, store the deferred semantic action with
 *  the new state.  If the new state would have an identical input
 *  position, LR state, and predecessor to an existing state on the stack,
 *  it is identified with that existing state, eliminating stack #YYK from
 *  *YYSTACKP.  In this case, the semantic value is
 *  added to the options for the existing state's semantic value.
 */
static inline YYRESULTTAG
yyglrReduce (yyGLRStack* yystackp, ptrdiff_t yyk, yyRuleNum yyrule,
             yybool yyforceEval)
{
  ptrdiff_t yyposn = yystackp->yytops.yystates[yyk]->yyposn;

  if (yyforceEval || yystackp->yysplitPoint == YY_NULLPTR)
    {
      YYSTYPE yysval;

      YYRESULTTAG yyflag = yydoAction (yystackp, yyk, yyrule, &yysval);
      if (yyflag == yyerr && yystackp->yysplitPoint != YY_NULLPTR)
        YY_DPRINTF ((stderr,
                     "Parse on stack %ld rejected by rule %d (line %d).\n",
                     YY_CAST (long, yyk), yyrule - 1, yyrline[yyrule - 1]));
      if (yyflag != yyok)
        return yyflag;
      YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyrule], &yysval, &yyloc);
      yyglrShift (yystackp, yyk,
                  yyLRgotoState (yystackp->yytops.yystates[yyk]->yylrState,
                                 yylhsNonterm (yyrule)),
                  yyposn, &yysval);
    }
  else
    {
      ptrdiff_t yyi;
      int yyn;
      yyGLRState* yys, *yys0 = yystackp->yytops.yystates[yyk];
      yyStateNum yynewLRState;

      for (yys = yystackp->yytops.yystates[yyk], yyn = yyrhsLength (yyrule);
           0 < yyn; yyn -= 1)
        {
          yys = yys->yypred;
          YY_ASSERT (yys);
        }
      yyupdateSplit (yystackp, yys);
      yynewLRState = yyLRgotoState (yys->yylrState, yylhsNonterm (yyrule));
      YY_DPRINTF ((stderr,
                   "Reduced stack %ld by rule %d (line %d); action deferred.  "
                   "Now in state %d.\n",
                   YY_CAST (long, yyk), yyrule - 1, yyrline[yyrule - 1],
                   yynewLRState));
      for (yyi = 0; yyi < yystackp->yytops.yysize; yyi += 1)
        if (yyi != yyk && yystackp->yytops.yystates[yyi] != YY_NULLPTR)
          {
            yyGLRState *yysplit = yystackp->yysplitPoint;
            yyGLRState *yyp = yystackp->yytops.yystates[yyi];
            while (yyp != yys && yyp != yysplit && yyp->yyposn >= yyposn)
              {
                if (yyp->yylrState == yynewLRState && yyp->yypred == yys)
                  {
                    yyaddDeferredAction (yystackp, yyk, yyp, yys0, yyrule);
                    yymarkStackDeleted (yystackp, yyk);
                    YY_DPRINTF ((stderr, "Merging stack %ld into stack %ld.\n",
                                 YY_CAST (long, yyk), YY_CAST (long, yyi)));
                    return yyok;
                  }
                yyp = yyp->yypred;
              }
          }
      yystackp->yytops.yystates[yyk] = yys;
      yyglrShiftDefer (yystackp, yyk, yynewLRState, yyposn, yys0, yyrule);
    }
  return yyok;
}

static ptrdiff_t
yysplitStack (yyGLRStack* yystackp, ptrdiff_t yyk)
{
  if (yystackp->yysplitPoint == YY_NULLPTR)
    {
      YY_ASSERT (yyk == 0);
      yystackp->yysplitPoint = yystackp->yytops.yystates[yyk];
    }
  if (yystackp->yytops.yycapacity <= yystackp->yytops.yysize)
    {
      ptrdiff_t state_size = sizeof yystackp->yytops.yystates[0];
      ptrdiff_t half_max_capacity = YYSIZEMAX / 2 / state_size;
      if (half_max_capacity < yystackp->yytops.yycapacity)
        yyMemoryExhausted (yystackp);
      yystackp->yytops.yycapacity *= 2;

      {
        yyGLRState** yynewStates
          = YY_CAST (yyGLRState**,
                     YYREALLOC (yystackp->yytops.yystates,
                                (YY_CAST (size_t, yystackp->yytops.yycapacity)
                                 * sizeof yynewStates[0])));
        if (yynewStates == YY_NULLPTR)
          yyMemoryExhausted (yystackp);
        yystackp->yytops.yystates = yynewStates;
      }

      {
        yybool* yynewLookaheadNeeds
          = YY_CAST (yybool*,
                     YYREALLOC (yystackp->yytops.yylookaheadNeeds,
                                (YY_CAST (size_t, yystackp->yytops.yycapacity)
                                 * sizeof yynewLookaheadNeeds[0])));
        if (yynewLookaheadNeeds == YY_NULLPTR)
          yyMemoryExhausted (yystackp);
        yystackp->yytops.yylookaheadNeeds = yynewLookaheadNeeds;
      }
    }
  yystackp->yytops.yystates[yystackp->yytops.yysize]
    = yystackp->yytops.yystates[yyk];
  yystackp->yytops.yylookaheadNeeds[yystackp->yytops.yysize]
    = yystackp->yytops.yylookaheadNeeds[yyk];
  yystackp->yytops.yysize += 1;
  return yystackp->yytops.yysize - 1;
}

/** True iff YYY0 and YYY1 represent identical options at the top level.
 *  That is, they represent the same rule applied to RHS symbols
 *  that produce the same terminal symbols.  */
static yybool
yyidenticalOptions (yySemanticOption* yyy0, yySemanticOption* yyy1)
{
  if (yyy0->yyrule == yyy1->yyrule)
    {
      yyGLRState *yys0, *yys1;
      int yyn;
      for (yys0 = yyy0->yystate, yys1 = yyy1->yystate,
           yyn = yyrhsLength (yyy0->yyrule);
           yyn > 0;
           yys0 = yys0->yypred, yys1 = yys1->yypred, yyn -= 1)
        if (yys0->yyposn != yys1->yyposn)
          return yyfalse;
      return yytrue;
    }
  else
    return yyfalse;
}

/** Assuming identicalOptions (YYY0,YYY1), destructively merge the
 *  alternative semantic values for the RHS-symbols of YYY1 and YYY0.  */
static void
yymergeOptionSets (yySemanticOption* yyy0, yySemanticOption* yyy1)
{
  yyGLRState *yys0, *yys1;
  int yyn;
  for (yys0 = yyy0->yystate, yys1 = yyy1->yystate,
       yyn = yyrhsLength (yyy0->yyrule);
       0 < yyn;
       yys0 = yys0->yypred, yys1 = yys1->yypred, yyn -= 1)
    {
      if (yys0 == yys1)
        break;
      else if (yys0->yyresolved)
        {
          yys1->yyresolved = yytrue;
          yys1->yysemantics.yysval = yys0->yysemantics.yysval;
        }
      else if (yys1->yyresolved)
        {
          yys0->yyresolved = yytrue;
          yys0->yysemantics.yysval = yys1->yysemantics.yysval;
        }
      else
        {
          yySemanticOption** yyz0p = &yys0->yysemantics.yyfirstVal;
          yySemanticOption* yyz1 = yys1->yysemantics.yyfirstVal;
          while (yytrue)
            {
              if (yyz1 == *yyz0p || yyz1 == YY_NULLPTR)
                break;
              else if (*yyz0p == YY_NULLPTR)
                {
                  *yyz0p = yyz1;
                  break;
                }
              else if (*yyz0p < yyz1)
                {
                  yySemanticOption* yyz = *yyz0p;
                  *yyz0p = yyz1;
                  yyz1 = yyz1->yynext;
                  (*yyz0p)->yynext = yyz;
                }
              yyz0p = &(*yyz0p)->yynext;
            }
          yys1->yysemantics.yyfirstVal = yys0->yysemantics.yyfirstVal;
        }
    }
}

/** Y0 and Y1 represent two possible actions to take in a given
 *  parsing state; return 0 if no combination is possible,
 *  1 if user-mergeable, 2 if Y0 is preferred, 3 if Y1 is preferred.  */
static int
yypreference (yySemanticOption* y0, yySemanticOption* y1)
{
  yyRuleNum r0 = y0->yyrule, r1 = y1->yyrule;
  int p0 = yydprec[r0], p1 = yydprec[r1];

  if (p0 == p1)
    {
      if (yymerger[r0] == 0 || yymerger[r0] != yymerger[r1])
        return 0;
      else
        return 1;
    }
  if (p0 == 0 || p1 == 0)
    return 0;
  if (p0 < p1)
    return 3;
  if (p1 < p0)
    return 2;
  return 0;
}

static YYRESULTTAG yyresolveValue (yyGLRState* yys,
                                   yyGLRStack* yystackp);


/** Resolve the previous YYN states starting at and including state YYS
 *  on *YYSTACKP. If result != yyok, some states may have been left
 *  unresolved possibly with empty semantic option chains.  Regardless
 *  of whether result = yyok, each state has been left with consistent
 *  data so that yydestroyGLRState can be invoked if necessary.  */
static YYRESULTTAG
yyresolveStates (yyGLRState* yys, int yyn,
                 yyGLRStack* yystackp)
{
  if (0 < yyn)
    {
      YY_ASSERT (yys->yypred);
      YYCHK (yyresolveStates (yys->yypred, yyn-1, yystackp));
      if (! yys->yyresolved)
        YYCHK (yyresolveValue (yys, yystackp));
    }
  return yyok;
}

/** Resolve the states for the RHS of YYOPT on *YYSTACKP, perform its
 *  user action, and return the semantic value and location in *YYVALP
 *  and *YYLOCP.  Regardless of whether result = yyok, all RHS states
 *  have been destroyed (assuming the user action destroys all RHS
 *  semantic values if invoked).  */
static YYRESULTTAG
yyresolveAction (yySemanticOption* yyopt, yyGLRStack* yystackp,
                 YYSTYPE* yyvalp)
{
  yyGLRStackItem yyrhsVals[YYMAXRHS + YYMAXLEFT + 1];
  int yynrhs = yyrhsLength (yyopt->yyrule);
  YYRESULTTAG yyflag =
    yyresolveStates (yyopt->yystate, yynrhs, yystackp);
  if (yyflag != yyok)
    {
      yyGLRState *yys;
      for (yys = yyopt->yystate; yynrhs > 0; yys = yys->yypred, yynrhs -= 1)
        yydestroyGLRState ("Cleanup: popping", yys);
      return yyflag;
    }

  yyrhsVals[YYMAXRHS + YYMAXLEFT].yystate.yypred = yyopt->yystate;
  {
    int yychar_current = yychar;
    YYSTYPE yylval_current = yylval;
    yychar = yyopt->yyrawchar;
    yylval = yyopt->yyval;
    yyflag = yyuserAction (yyopt->yyrule, yynrhs,
                           yyrhsVals + YYMAXRHS + YYMAXLEFT - 1,
                           yystackp, yyvalp);
    yychar = yychar_current;
    yylval = yylval_current;
  }
  return yyflag;
}

#if YYDEBUG
static void
yyreportTree (yySemanticOption* yyx, int yyindent)
{
  int yynrhs = yyrhsLength (yyx->yyrule);
  int yyi;
  yyGLRState* yys;
  yyGLRState* yystates[1 + YYMAXRHS];
  yyGLRState yyleftmost_state;

  for (yyi = yynrhs, yys = yyx->yystate; 0 < yyi; yyi -= 1, yys = yys->yypred)
    yystates[yyi] = yys;
  if (yys == YY_NULLPTR)
    {
      yyleftmost_state.yyposn = 0;
      yystates[0] = &yyleftmost_state;
    }
  else
    yystates[0] = yys;

  if (yyx->yystate->yyposn < yys->yyposn + 1)
    YY_FPRINTF ((stderr, "%*s%s -> <Rule %d, empty>\n",
                 yyindent, "", yytokenName (yylhsNonterm (yyx->yyrule)),
                 yyx->yyrule - 1));
  else
    YY_FPRINTF ((stderr, "%*s%s -> <Rule %d, tokens %ld .. %ld>\n",
                 yyindent, "", yytokenName (yylhsNonterm (yyx->yyrule)),
                 yyx->yyrule - 1, YY_CAST (long, yys->yyposn + 1),
                 YY_CAST (long, yyx->yystate->yyposn)));
  for (yyi = 1; yyi <= yynrhs; yyi += 1)
    {
      if (yystates[yyi]->yyresolved)
        {
          if (yystates[yyi-1]->yyposn+1 > yystates[yyi]->yyposn)
            YY_FPRINTF ((stderr, "%*s%s <empty>\n", yyindent+2, "",
                         yytokenName (yystos[yystates[yyi]->yylrState])));
          else
            YY_FPRINTF ((stderr, "%*s%s <tokens %ld .. %ld>\n", yyindent+2, "",
                         yytokenName (yystos[yystates[yyi]->yylrState]),
                         YY_CAST (long, yystates[yyi-1]->yyposn + 1),
                         YY_CAST (long, yystates[yyi]->yyposn)));
        }
      else
        yyreportTree (yystates[yyi]->yysemantics.yyfirstVal, yyindent+2);
    }
}
#endif

static YYRESULTTAG
yyreportAmbiguity (yySemanticOption* yyx0,
                   yySemanticOption* yyx1)
{
  YYUSE (yyx0);
  YYUSE (yyx1);

#if YYDEBUG
  YY_FPRINTF ((stderr, "Ambiguity detected.\n"));
  YY_FPRINTF ((stderr, "Option 1,\n"));
  yyreportTree (yyx0, 2);
  YY_FPRINTF ((stderr, "\nOption 2,\n"));
  yyreportTree (yyx1, 2);
  YY_FPRINTF ((stderr, "\n"));
#endif

  yyerror (YY_("syntax is ambiguous"));
  return yyabort;
}

/** Resolve the ambiguity represented in state YYS in *YYSTACKP,
 *  perform the indicated actions, and set the semantic value of YYS.
 *  If result != yyok, the chain of semantic options in YYS has been
 *  cleared instead or it has been left unmodified except that
 *  redundant options may have been removed.  Regardless of whether
 *  result = yyok, YYS has been left with consistent data so that
 *  yydestroyGLRState can be invoked if necessary.  */
static YYRESULTTAG
yyresolveValue (yyGLRState* yys, yyGLRStack* yystackp)
{
  yySemanticOption* yyoptionList = yys->yysemantics.yyfirstVal;
  yySemanticOption* yybest = yyoptionList;
  yySemanticOption** yypp;
  yybool yymerge = yyfalse;
  YYSTYPE yysval;
  YYRESULTTAG yyflag;

  for (yypp = &yyoptionList->yynext; *yypp != YY_NULLPTR; )
    {
      yySemanticOption* yyp = *yypp;

      if (yyidenticalOptions (yybest, yyp))
        {
          yymergeOptionSets (yybest, yyp);
          *yypp = yyp->yynext;
        }
      else
        {
          switch (yypreference (yybest, yyp))
            {
            case 0:
              return yyreportAmbiguity (yybest, yyp);
              break;
            case 1:
              yymerge = yytrue;
              break;
            case 2:
              break;
            case 3:
              yybest = yyp;
              yymerge = yyfalse;
              break;
            default:
              /* This cannot happen so it is not worth a YY_ASSERT (yyfalse),
                 but some compilers complain if the default case is
                 omitted.  */
              break;
            }
          yypp = &yyp->yynext;
        }
    }

  if (yymerge)
    {
      yySemanticOption* yyp;
      int yyprec = yydprec[yybest->yyrule];
      yyflag = yyresolveAction (yybest, yystackp, &yysval);
      if (yyflag == yyok)
        for (yyp = yybest->yynext; yyp != YY_NULLPTR; yyp = yyp->yynext)
          {
            if (yyprec == yydprec[yyp->yyrule])
              {
                YYSTYPE yysval_other;
                yyflag = yyresolveAction (yyp, yystackp, &yysval_other);
                if (yyflag != yyok)
                  {
                    yydestruct ("Cleanup: discarding incompletely merged value for",
                                yystos[yys->yylrState],
                                &yysval);
                    break;
                  }
                yyuserMerge (yymerger[yyp->yyrule], &yysval, &yysval_other);
              }
          }
    }
  else
    yyflag = yyresolveAction (yybest, yystackp, &yysval);

  if (yyflag == yyok)
    {
      yys->yyresolved = yytrue;
      yys->yysemantics.yysval = yysval;
    }
  else
    yys->yysemantics.yyfirstVal = YY_NULLPTR;
  return yyflag;
}

static YYRESULTTAG
yyresolveStack (yyGLRStack* yystackp)
{
  if (yystackp->yysplitPoint != YY_NULLPTR)
    {
      yyGLRState* yys;
      int yyn;

      for (yyn = 0, yys = yystackp->yytops.yystates[0];
           yys != yystackp->yysplitPoint;
           yys = yys->yypred, yyn += 1)
        continue;
      YYCHK (yyresolveStates (yystackp->yytops.yystates[0], yyn, yystackp
                             ));
    }
  return yyok;
}

static void
yycompressStack (yyGLRStack* yystackp)
{
  yyGLRState* yyp, *yyq, *yyr;

  if (yystackp->yytops.yysize != 1 || yystackp->yysplitPoint == YY_NULLPTR)
    return;

  for (yyp = yystackp->yytops.yystates[0], yyq = yyp->yypred, yyr = YY_NULLPTR;
       yyp != yystackp->yysplitPoint;
       yyr = yyp, yyp = yyq, yyq = yyp->yypred)
    yyp->yypred = yyr;

  yystackp->yyspaceLeft += yystackp->yynextFree - yystackp->yyitems;
  yystackp->yynextFree = YY_REINTERPRET_CAST (yyGLRStackItem*, yystackp->yysplitPoint) + 1;
  yystackp->yyspaceLeft -= yystackp->yynextFree - yystackp->yyitems;
  yystackp->yysplitPoint = YY_NULLPTR;
  yystackp->yylastDeleted = YY_NULLPTR;

  while (yyr != YY_NULLPTR)
    {
      yystackp->yynextFree->yystate = *yyr;
      yyr = yyr->yypred;
      yystackp->yynextFree->yystate.yypred = &yystackp->yynextFree[-1].yystate;
      yystackp->yytops.yystates[0] = &yystackp->yynextFree->yystate;
      yystackp->yynextFree += 1;
      yystackp->yyspaceLeft -= 1;
    }
}

static YYRESULTTAG
yyprocessOneStack (yyGLRStack* yystackp, ptrdiff_t yyk,
                   ptrdiff_t yyposn)
{
  while (yystackp->yytops.yystates[yyk] != YY_NULLPTR)
    {
      yyStateNum yystate = yystackp->yytops.yystates[yyk]->yylrState;
      YY_DPRINTF ((stderr, "Stack %ld Entering state %d\n",
                   YY_CAST (long, yyk), yystate));

      YY_ASSERT (yystate != YYFINAL);

      if (yyisDefaultedState (yystate))
        {
          YYRESULTTAG yyflag;
          yyRuleNum yyrule = yydefaultAction (yystate);
          if (yyrule == 0)
            {
              YY_DPRINTF ((stderr, "Stack %ld dies.\n", YY_CAST (long, yyk)));
              yymarkStackDeleted (yystackp, yyk);
              return yyok;
            }
          yyflag = yyglrReduce (yystackp, yyk, yyrule, yyimmediate[yyrule]);
          if (yyflag == yyerr)
            {
              YY_DPRINTF ((stderr,
                           "Stack %ld dies "
                           "(predicate failure or explicit user error).\n",
                           YY_CAST (long, yyk)));
              yymarkStackDeleted (yystackp, yyk);
              return yyok;
            }
          if (yyflag != yyok)
            return yyflag;
        }
      else
        {
          yySymbol yytoken = yygetToken (&yychar);
          const short* yyconflicts;
          const int yyaction = yygetLRActions (yystate, yytoken, &yyconflicts);
          yystackp->yytops.yylookaheadNeeds[yyk] = yytrue;

          while (*yyconflicts != 0)
            {
              YYRESULTTAG yyflag;
              ptrdiff_t yynewStack = yysplitStack (yystackp, yyk);
              YY_DPRINTF ((stderr, "Splitting off stack %ld from %ld.\n",
                           YY_CAST (long, yynewStack), YY_CAST (long, yyk)));
              yyflag = yyglrReduce (yystackp, yynewStack,
                                    *yyconflicts,
                                    yyimmediate[*yyconflicts]);
              if (yyflag == yyok)
                YYCHK (yyprocessOneStack (yystackp, yynewStack,
                                          yyposn));
              else if (yyflag == yyerr)
                {
                  YY_DPRINTF ((stderr, "Stack %ld dies.\n", YY_CAST (long, yynewStack)));
                  yymarkStackDeleted (yystackp, yynewStack);
                }
              else
                return yyflag;
              yyconflicts += 1;
            }

          if (yyisShiftAction (yyaction))
            break;
          else if (yyisErrorAction (yyaction))
            {
              YY_DPRINTF ((stderr, "Stack %ld dies.\n", YY_CAST (long, yyk)));
              yymarkStackDeleted (yystackp, yyk);
              break;
            }
          else
            {
              YYRESULTTAG yyflag = yyglrReduce (yystackp, yyk, -yyaction,
                                                yyimmediate[-yyaction]);
              if (yyflag == yyerr)
                {
                  YY_DPRINTF ((stderr,
                               "Stack %ld dies "
                               "(predicate failure or explicit user error).\n",
                               YY_CAST (long, yyk)));
                  yymarkStackDeleted (yystackp, yyk);
                  break;
                }
              else if (yyflag != yyok)
                return yyflag;
            }
        }
    }
  return yyok;
}

static void
yyreportSyntaxError (yyGLRStack* yystackp)
{
  if (yystackp->yyerrState != 0)
    return;
#if ! YYERROR_VERBOSE
  yyerror (YY_("syntax error"));
#else
  {
  yySymbol yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);
  yybool yysize_overflow = yyfalse;
  char* yymsg = YY_NULLPTR;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  ptrdiff_t yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[yystackp->yytops.yystates[0]->yylrState];
      ptrdiff_t yysize0 = yytnamerr (YY_NULLPTR, yytokenName (yytoken));
      yysize = yysize0;
      yyarg[yycount++] = yytokenName (yytoken);
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for this
             state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;
          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytokenName (yyx);
                {
                  ptrdiff_t yysz = yytnamerr (YY_NULLPTR, yytokenName (yyx));
                  if (YYSIZEMAX - yysize < yysz)
                    yysize_overflow = yytrue;
                  else
                    yysize += yysz;
                }
              }
        }
    }

  switch (yycount)
    {
#define YYCASE_(N, S)                   \
      case N:                           \
        yyformat = S;                   \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    ptrdiff_t yysz = YY_CAST (ptrdiff_t, strlen (yyformat)) - 2 * yycount + 1;
    if (YYSIZEMAX - yysize < yysz)
      yysize_overflow = yytrue;
    else
      yysize += yysz;
  }

  if (!yysize_overflow)
    yymsg = YY_CAST (char *, YYMALLOC (YY_CAST (size_t, yysize)));

  if (yymsg)
    {
      char *yyp = yymsg;
      int yyi = 0;
      while ((*yyp = *yyformat))
        {
          if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
            {
              yyp += yytnamerr (yyp, yyarg[yyi++]);
              yyformat += 2;
            }
          else
            {
              ++yyp;
              ++yyformat;
            }
        }
      yyerror (yymsg);
      YYFREE (yymsg);
    }
  else
    {
      yyerror (YY_("syntax error"));
      yyMemoryExhausted (yystackp);
    }
  }
#endif /* YYERROR_VERBOSE */
  yynerrs += 1;
}

/* Recover from a syntax error on *YYSTACKP, assuming that *YYSTACKP->YYTOKENP,
   yylval, and yylloc are the syntactic category, semantic value, and location
   of the lookahead.  */
static void
yyrecoverSyntaxError (yyGLRStack* yystackp)
{
  if (yystackp->yyerrState == 3)
    /* We just shifted the error token and (perhaps) took some
       reductions.  Skip tokens until we can proceed.  */
    while (yytrue)
      {
        yySymbol yytoken;
        int yyj;
        if (yychar == YYEOF)
          yyFail (yystackp, YY_NULLPTR);
        if (yychar != YYEMPTY)
          {
            yytoken = YYTRANSLATE (yychar);
            yydestruct ("Error: discarding",
                        yytoken, &yylval);
            yychar = YYEMPTY;
          }
        yytoken = yygetToken (&yychar);
        yyj = yypact[yystackp->yytops.yystates[0]->yylrState];
        if (yypact_value_is_default (yyj))
          return;
        yyj += yytoken;
        if (yyj < 0 || YYLAST < yyj || yycheck[yyj] != yytoken)
          {
            if (yydefact[yystackp->yytops.yystates[0]->yylrState] != 0)
              return;
          }
        else if (! yytable_value_is_error (yytable[yyj]))
          return;
      }

  /* Reduce to one stack.  */
  {
    ptrdiff_t yyk;
    for (yyk = 0; yyk < yystackp->yytops.yysize; yyk += 1)
      if (yystackp->yytops.yystates[yyk] != YY_NULLPTR)
        break;
    if (yyk >= yystackp->yytops.yysize)
      yyFail (yystackp, YY_NULLPTR);
    for (yyk += 1; yyk < yystackp->yytops.yysize; yyk += 1)
      yymarkStackDeleted (yystackp, yyk);
    yyremoveDeletes (yystackp);
    yycompressStack (yystackp);
  }

  /* Now pop stack until we find a state that shifts the error token.  */
  yystackp->yyerrState = 3;
  while (yystackp->yytops.yystates[0] != YY_NULLPTR)
    {
      yyGLRState *yys = yystackp->yytops.yystates[0];
      int yyj = yypact[yys->yylrState];
      if (! yypact_value_is_default (yyj))
        {
          yyj += YYTERROR;
          if (0 <= yyj && yyj <= YYLAST && yycheck[yyj] == YYTERROR
              && yyisShiftAction (yytable[yyj]))
            {
              /* Shift the error token.  */
              int yyaction = yytable[yyj];
              YY_SYMBOL_PRINT ("Shifting", yystos[yyaction],
                               &yylval, &yyerrloc);
              yyglrShift (yystackp, 0, yyaction,
                          yys->yyposn, &yylval);
              yys = yystackp->yytops.yystates[0];
              break;
            }
        }
      if (yys->yypred != YY_NULLPTR)
        yydestroyGLRState ("Error: popping", yys);
      yystackp->yytops.yystates[0] = yys->yypred;
      yystackp->yynextFree -= 1;
      yystackp->yyspaceLeft += 1;
    }
  if (yystackp->yytops.yystates[0] == YY_NULLPTR)
    yyFail (yystackp, YY_NULLPTR);
}

#define YYCHK1(YYE)                                                          \
  do {                                                                       \
    switch (YYE) {                                                           \
    case yyok:                                                               \
      break;                                                                 \
    case yyabort:                                                            \
      goto yyabortlab;                                                       \
    case yyaccept:                                                           \
      goto yyacceptlab;                                                      \
    case yyerr:                                                              \
      goto yyuser_error;                                                     \
    default:                                                                 \
      goto yybuglab;                                                         \
    }                                                                        \
  } while (0)

/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
  int yyresult;
  yyGLRStack yystack;
  yyGLRStack* const yystackp = &yystack;
  ptrdiff_t yyposn;

  YY_DPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY;
  yylval = yyval_default;

  /* User initialization code.  */
#line 50 "res/dpl.y"
{ yylineno = 1; }

#line 3903 "/mnt/d/Markov folder/Nauka/2019/CCPE/Kod/SimilarityDetection/SimilarityDetectionCuda/build/../src/parser.cpp"


  if (! yyinitGLRStack (yystackp, YYINITDEPTH))
    goto yyexhaustedlab;
  switch (YYSETJMP (yystack.yyexception_buffer))
    {
    case 0: break;
    case 1: goto yyabortlab;
    case 2: goto yyexhaustedlab;
    default: goto yybuglab;
    }
  yyglrShift (&yystack, 0, 0, 0, &yylval);
  yyposn = 0;

  while (yytrue)
    {
      /* For efficiency, we have two loops, the first of which is
         specialized to deterministic operation (single stack, no
         potential ambiguity).  */
      /* Standard mode */
      while (yytrue)
        {
          yyStateNum yystate = yystack.yytops.yystates[0]->yylrState;
          YY_DPRINTF ((stderr, "Entering state %d\n", yystate));
          if (yystate == YYFINAL)
            goto yyacceptlab;
          if (yyisDefaultedState (yystate))
            {
              yyRuleNum yyrule = yydefaultAction (yystate);
              if (yyrule == 0)
                {
                  yyreportSyntaxError (&yystack);
                  goto yyuser_error;
                }
              YYCHK1 (yyglrReduce (&yystack, 0, yyrule, yytrue));
            }
          else
            {
              yySymbol yytoken = yygetToken (&yychar);
              const short* yyconflicts;
              int yyaction = yygetLRActions (yystate, yytoken, &yyconflicts);
              if (*yyconflicts != 0)
                break;
              if (yyisShiftAction (yyaction))
                {
                  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
                  yychar = YYEMPTY;
                  yyposn += 1;
                  yyglrShift (&yystack, 0, yyaction, yyposn, &yylval);
                  if (0 < yystack.yyerrState)
                    yystack.yyerrState -= 1;
                }
              else if (yyisErrorAction (yyaction))
                {                  yyreportSyntaxError (&yystack);
                  goto yyuser_error;
                }
              else
                YYCHK1 (yyglrReduce (&yystack, 0, -yyaction, yytrue));
            }
        }

      while (yytrue)
        {
          yySymbol yytoken_to_shift;
          ptrdiff_t yys;

          for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
            yystackp->yytops.yylookaheadNeeds[yys] = yychar != YYEMPTY;

          /* yyprocessOneStack returns one of three things:

              - An error flag.  If the caller is yyprocessOneStack, it
                immediately returns as well.  When the caller is finally
                yyparse, it jumps to an error label via YYCHK1.

              - yyok, but yyprocessOneStack has invoked yymarkStackDeleted
                (&yystack, yys), which sets the top state of yys to NULL.  Thus,
                yyparse's following invocation of yyremoveDeletes will remove
                the stack.

              - yyok, when ready to shift a token.

             Except in the first case, yyparse will invoke yyremoveDeletes and
             then shift the next token onto all remaining stacks.  This
             synchronization of the shift (that is, after all preceding
             reductions on all stacks) helps prevent double destructor calls
             on yylval in the event of memory exhaustion.  */

          for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
            YYCHK1 (yyprocessOneStack (&yystack, yys, yyposn));
          yyremoveDeletes (&yystack);
          if (yystack.yytops.yysize == 0)
            {
              yyundeleteLastStack (&yystack);
              if (yystack.yytops.yysize == 0)
                yyFail (&yystack, YY_("syntax error"));
              YYCHK1 (yyresolveStack (&yystack));
              YY_DPRINTF ((stderr, "Returning to deterministic operation.\n"));
              yyreportSyntaxError (&yystack);
              goto yyuser_error;
            }

          /* If any yyglrShift call fails, it will fail after shifting.  Thus,
             a copy of yylval will already be on stack 0 in the event of a
             failure in the following loop.  Thus, yychar is set to YYEMPTY
             before the loop to make sure the user destructor for yylval isn't
             called twice.  */
          yytoken_to_shift = YYTRANSLATE (yychar);
          yychar = YYEMPTY;
          yyposn += 1;
          for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
            {
              yyStateNum yystate = yystack.yytops.yystates[yys]->yylrState;
              const short* yyconflicts;
              int yyaction = yygetLRActions (yystate, yytoken_to_shift,
                              &yyconflicts);
              /* Note that yyconflicts were handled by yyprocessOneStack.  */
              YY_DPRINTF ((stderr, "On stack %ld, ", YY_CAST (long, yys)));
              YY_SYMBOL_PRINT ("shifting", yytoken_to_shift, &yylval, &yylloc);
              yyglrShift (&yystack, yys, yyaction, yyposn,
                          &yylval);
              YY_DPRINTF ((stderr, "Stack %ld now in state #%d\n",
                           YY_CAST (long, yys),
                           yystack.yytops.yystates[yys]->yylrState));
            }

          if (yystack.yytops.yysize == 1)
            {
              YYCHK1 (yyresolveStack (&yystack));
              YY_DPRINTF ((stderr, "Returning to deterministic operation.\n"));
              yycompressStack (&yystack);
              break;
            }
        }
      continue;
    yyuser_error:
      yyrecoverSyntaxError (&yystack);
      yyposn = yystack.yytops.yystates[0]->yyposn;
    }

 yyacceptlab:
  yyresult = 0;
  goto yyreturn;

 yybuglab:
  YY_ASSERT (yyfalse);
  goto yyabortlab;

 yyabortlab:
  yyresult = 1;
  goto yyreturn;

 yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;

 yyreturn:
  if (yychar != YYEMPTY)
    yydestruct ("Cleanup: discarding lookahead",
                YYTRANSLATE (yychar), &yylval);

  /* If the stack is well-formed, pop the stack until it is empty,
     destroying its entries as we go.  But free the stack regardless
     of whether it is well-formed.  */
  if (yystack.yyitems)
    {
      yyGLRState** yystates = yystack.yytops.yystates;
      if (yystates)
        {
          ptrdiff_t yysize = yystack.yytops.yysize;
          ptrdiff_t yyk;
          for (yyk = 0; yyk < yysize; yyk += 1)
            if (yystates[yyk])
              {
                while (yystates[yyk])
                  {
                    yyGLRState *yys = yystates[yyk];
                    if (yys->yypred != YY_NULLPTR)
                      yydestroyGLRState ("Cleanup: popping", yys);
                    yystates[yyk] = yys->yypred;
                    yystack.yynextFree -= 1;
                    yystack.yyspaceLeft += 1;
                  }
                break;
              }
        }
      yyfreeGLRStack (&yystack);
    }

  return yyresult;
}

/* DEBUGGING ONLY */
#if YYDEBUG
static void
yy_yypstack (yyGLRState* yys)
{
  if (yys->yypred)
    {
      yy_yypstack (yys->yypred);
      YY_FPRINTF ((stderr, " -> "));
    }
  YY_FPRINTF ((stderr, "%d@%ld", yys->yylrState, YY_CAST (long, yys->yyposn)));
}

static void
yypstates (yyGLRState* yyst)
{
  if (yyst == YY_NULLPTR)
    YY_FPRINTF ((stderr, "<null>"));
  else
    yy_yypstack (yyst);
  YY_FPRINTF ((stderr, "\n"));
}

static void
yypstack (yyGLRStack* yystackp, ptrdiff_t yyk)
{
  yypstates (yystackp->yytops.yystates[yyk]);
}

static void
yypdumpstack (yyGLRStack* yystackp)
{
#define YYINDEX(YYX)                                                    \
  YY_CAST (long,                                                        \
           ((YYX)                                                       \
            ? YY_REINTERPRET_CAST (yyGLRStackItem*, (YYX)) - yystackp->yyitems \
            : -1))

  yyGLRStackItem* yyp;
  for (yyp = yystackp->yyitems; yyp < yystackp->yynextFree; yyp += 1)
    {
      YY_FPRINTF ((stderr, "%3ld. ",
                   YY_CAST (long, yyp - yystackp->yyitems)));
      if (*YY_REINTERPRET_CAST (yybool *, yyp))
        {
          YY_ASSERT (yyp->yystate.yyisState);
          YY_ASSERT (yyp->yyoption.yyisState);
          YY_FPRINTF ((stderr, "Res: %d, LR State: %d, posn: %ld, pred: %ld",
                       yyp->yystate.yyresolved, yyp->yystate.yylrState,
                       YY_CAST (long, yyp->yystate.yyposn),
                       YYINDEX (yyp->yystate.yypred)));
          if (! yyp->yystate.yyresolved)
            YY_FPRINTF ((stderr, ", firstVal: %ld",
                         YYINDEX (yyp->yystate.yysemantics.yyfirstVal)));
        }
      else
        {
          YY_ASSERT (!yyp->yystate.yyisState);
          YY_ASSERT (!yyp->yyoption.yyisState);
          YY_FPRINTF ((stderr, "Option. rule: %d, state: %ld, next: %ld",
                       yyp->yyoption.yyrule - 1,
                       YYINDEX (yyp->yyoption.yystate),
                       YYINDEX (yyp->yyoption.yynext)));
        }
      YY_FPRINTF ((stderr, "\n"));
    }

  YY_FPRINTF ((stderr, "Tops:"));
  {
    ptrdiff_t yyi;
    for (yyi = 0; yyi < yystackp->yytops.yysize; yyi += 1)
      YY_FPRINTF ((stderr, "%ld: %ld; ", YY_CAST (long, yyi),
                   YYINDEX (yystackp->yytops.yystates[yyi])));
    YY_FPRINTF ((stderr, "\n"));
  }
#undef YYINDEX
}
#endif

#undef yylval
#undef yychar
#undef yynerrs



#line 645 "res/dpl.y"

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
