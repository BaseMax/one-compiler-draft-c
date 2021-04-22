/* A Bison parser, made by GNU Bison 3.7.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    OP_ADD = 258,                  /* OP_ADD  */
    OP_SUB = 259,                  /* OP_SUB  */
    OP_MUL = 260,                  /* OP_MUL  */
    OP_DIV = 261,                  /* OP_DIV  */
    OP_POW = 262,                  /* OP_POW  */
    OP_MOL = 263,                  /* OP_MOL  */
    OP_SIGN = 264,                 /* OP_SIGN  */
    OP_GT = 265,                   /* OP_GT  */
    OP_LT = 266,                   /* OP_LT  */
    OP_EQ = 267,                   /* OP_EQ  */
    OP_TEQ = 268,                  /* OP_TEQ  */
    OP_NE = 269,                   /* OP_NE  */
    OP_TNE = 270,                  /* OP_TNE  */
    OP_LE = 271,                   /* OP_LE  */
    OP_GE = 272,                   /* OP_GE  */
    OP_ASSIGN = 273,               /* OP_ASSIGN  */
    OP_DOT = 274,                  /* OP_DOT  */
    OP_DOTDOT = 275,               /* OP_DOTDOT  */
    OP_DOTDOTDOT = 276,            /* OP_DOTDOTDOT  */
    SEMICOLON = 277,               /* SEMICOLON  */
    COLON = 278,                   /* COLON  */
    LBRACKET = 279,                /* LBRACKET  */
    RBRACKET = 280,                /* RBRACKET  */
    LBRACE = 281,                  /* LBRACE  */
    RBRACE = 282,                  /* RBRACE  */
    LPAREN = 283,                  /* LPAREN  */
    RPAREN = 284,                  /* RPAREN  */
    KW_BOOL = 285,                 /* KW_BOOL  */
    KW_VOID = 286,                 /* KW_VOID  */
    KW_TRUE = 287,                 /* KW_TRUE  */
    KW_FALSE = 288,                /* KW_FALSE  */
    KW_NULL = 289,                 /* KW_NULL  */
    KW_STRING = 290,               /* KW_STRING  */
    KW_CHAR = 291,                 /* KW_CHAR  */
    KW_INT8 = 292,                 /* KW_INT8  */
    KW_INT16 = 293,                /* KW_INT16  */
    KW_INT32 = 294,                /* KW_INT32  */
    KW_INT64 = 295,                /* KW_INT64  */
    KW_UINT8 = 296,                /* KW_UINT8  */
    KW_UINT16 = 297,               /* KW_UINT16  */
    KW_UINT32 = 298,               /* KW_UINT32  */
    KW_UINT64 = 299,               /* KW_UINT64  */
    KW_FLOAT32 = 300,              /* KW_FLOAT32  */
    KW_FLOAT64 = 301,              /* KW_FLOAT64  */
    KW_FLOAT128 = 302,             /* KW_FLOAT128  */
    KW_IF = 303,                   /* KW_IF  */
    KW_ELSE = 304,                 /* KW_ELSE  */
    KW_WHILE = 305,                /* KW_WHILE  */
    KW_RETURN = 306,               /* KW_RETURN  */
    KW_FOR = 307,                  /* KW_FOR  */
    KW_FN = 308,                   /* KW_FN  */
    KW_PRINTLN = 309,              /* KW_PRINTLN  */
    KW_PRINT = 310,                /* KW_PRINT  */
    KW_WINDOW = 311,               /* KW_WINDOW  */
    KW_WINDOW_BOX = 312,           /* KW_WINDOW_BOX  */
    KW_WINDOW_FIELD = 313,         /* KW_WINDOW_FIELD  */
    KW_WINDOW_BUTTON = 314,        /* KW_WINDOW_BUTTON  */
    KW_WINDOW_LABEL = 315,         /* KW_WINDOW_LABEL  */
    INT_CONSTANT = 316,            /* INT_CONSTANT  */
    FLOAT_CONSTANT = 317,          /* FLOAT_CONSTANT  */
    STRING_CONSTANT = 318,         /* STRING_CONSTANT  */
    IDENTIFIER = 319               /* IDENTIFIER  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 16 "parser.y"

   int int_const;
   float float_const;

   struct ast_type *type_specifier;
   char *identifier;

   char *string_const;

   struct ast_node *node;
   struct ast_declaration *declaration;
   struct ast_expression *expression;
   struct ast_statement_list *statement_list;
   struct ast_expression_list *expression_list;
   struct ast_selection_statement *selection_statement;
   struct ast_function *function;
   struct ast_compound_statement *compound_statement;
   struct ast_translation_unit *translation_unit;

   struct ast_while_statement *while_statement;
   struct ast_print_statement *print_statement;
   struct ast_return_statement *return_statement;
   struct ast_element_item *element_item;
   struct ast_element_statement *element_statement;

   struct ast_function_argument *function_argument;

#line 156 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
