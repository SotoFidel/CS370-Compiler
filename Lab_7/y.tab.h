/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    INT = 258,
    AND = 259,
    OR = 260,
    VOID = 261,
    BOOL = 262,
    TRUE = 263,
    FALSE = 264,
    NOT = 265,
    IF = 266,
    THEN = 267,
    ELSE = 268,
    READ = 269,
    WRITE = 270,
    MYRETURN = 271,
    WHILE = 272,
    DO = 273,
    LT = 274,
    GT = 275,
    LE = 276,
    GE = 277,
    EQ = 278,
    NE = 279,
    MYBEGIN = 280,
    END = 281,
    NUM = 282,
    ID = 283
  };
#endif
/* Tokens.  */
#define INT 258
#define AND 259
#define OR 260
#define VOID 261
#define BOOL 262
#define TRUE 263
#define FALSE 264
#define NOT 265
#define IF 266
#define THEN 267
#define ELSE 268
#define READ 269
#define WRITE 270
#define MYRETURN 271
#define WHILE 272
#define DO 273
#define LT 274
#define GT 275
#define LE 276
#define GE 277
#define EQ 278
#define NE 279
#define MYBEGIN 280
#define END 281
#define NUM 282
#define ID 283

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 53 "lab7.y" /* yacc.c:1909  */

    int typeInt;
    char *typeString;
    struct ASTNodeType * node;
    enum DATATYPE type;
    enum OPERATOR opType;

#line 118 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
