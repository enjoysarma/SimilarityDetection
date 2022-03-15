/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Skeleton interface for Bison GLR parsers in C

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

#ifndef YY_YY_MNT_D_MARKOV_FOLDER_NAUKA_2019_CCPE_KOD_SIMILARITYDETECTION_SEQ_BUILD_SRC_PARSER_HPP_INCLUDED
# define YY_YY_MNT_D_MARKOV_FOLDER_NAUKA_2019_CCPE_KOD_SIMILARITYDETECTION_SEQ_BUILD_SRC_PARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IDENT = 258,
    BREAK_ = 259,
    CONTINUE_ = 260,
    GOTO_ = 261,
    RETURN_ = 262,
    SWITCH_ = 263,
    CASE_ = 264,
    DEFAULT = 265,
    CLASS = 266,
    ENUM_ = 267,
    TRY_ = 268,
    CATCH_ = 269,
    THROW_ = 270,
    NEW = 271,
    DELETE_ = 272,
    IF = 273,
    ELSE_ = 274,
    DO = 275,
    WHILE = 276,
    FOR = 277,
    BOOL_VALUE = 278,
    CHAR_VALUE = 279,
    STRING_VALUE = 280,
    NUMERIC_VALUE = 281,
    FUNC_OPERATOR = 282,
    UNION = 283,
    CAST = 284,
    SIZEOF = 285,
    BOOL_TYPE = 286,
    CHAR_TYPE = 287,
    STRING_TYPE = 288,
    NUMERIC_TYPE = 289,
    VOID = 290,
    SCOPE_OP = 291,
    PTR_OP = 292,
    ELLIPSIS = 293,
    INC_OP = 294,
    DEC_OP = 295,
    SHL_OP = 296,
    SHR_OP = 297,
    LE_OP = 298,
    GE_OP = 299,
    EQ_OP = 300,
    NE_OP = 301,
    AND_OP = 302,
    OR_OP = 303,
    SHR_ASSIGN = 304,
    SHL_ASSIGN = 305,
    ADD_ASSIGN = 306,
    SUB_ASSIGN = 307,
    MUL_ASSIGN = 308,
    DIV_ASSIGN = 309,
    MOD_ASSIGN = 310,
    AND_ASSIGN = 311,
    XOR_ASSIGN = 312,
    OR_ASSIGN = 313,
    DECLARATION = 314,
    LOWER_THAN_ELSE = 315
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_MNT_D_MARKOV_FOLDER_NAUKA_2019_CCPE_KOD_SIMILARITYDETECTION_SEQ_BUILD_SRC_PARSER_HPP_INCLUDED  */
