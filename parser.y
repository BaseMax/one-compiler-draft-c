%{

#include <stdio.h>
#include <stdlib.h>

#include "ast.h"
//#include "sds.h"
#include "one.h"
#include "print.h"

//int yylex();
void yyerror(const char *s);

%}

%union {
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
}

 /* math operators */
%left    OP_ADD OP_SUB
%left    OP_MUL OP_DIV OP_POW OP_MOL OP_SIGN

 /* comparison operators */
%left    OP_GT OP_LT OP_EQ OP_TEQ OP_NE OP_TNE OP_LE OP_GE

 /* assignment operator */
%token   OP_ASSIGN
%token   OP_DOT
%token   OP_DOTDOT
%token   OP_DOTDOTDOT

 /* statement terminator */
%token   SEMICOLON COLON

 /* grouping symbols */
%token   LBRACKET
%token   RBRACKET

%token   LBRACE
%token   RBRACE

%token   LPAREN
%token   RPAREN

 /* keywords */
%token   KW_BOOL KW_VOID KW_TRUE KW_FALSE
%token   KW_NULL
%token   KW_STRING
%token   KW_CHAR

%token   KW_INT8
%token   KW_INT16
%token   KW_INT32
%token   KW_INT64

%token   KW_UINT8
%token   KW_UINT16
%token   KW_UINT32
%token   KW_UINT64

%token   KW_FLOAT32
%token   KW_FLOAT64
%token   KW_FLOAT128

%token   KW_IF
%token   KW_ELSE
%token   KW_WHILE
%token   KW_RETURN
%token   KW_FOR
%token   KW_FN KW_PRINTLN KW_PRINT

%token KW_WINDOW KW_WINDOW_BOX KW_WINDOW_FIELD KW_WINDOW_BUTTON  KW_WINDOW_LABEL

 /* integer and floating constants */
%token <int_const>      INT_CONSTANT
%token <float_const>    FLOAT_CONSTANT
%token <string_const>   STRING_CONSTANT

 /* identifier's name */
%token <identifier>     IDENTIFIER

 /* rule types */
%type <type_specifier>       type_specifier
%type <expression>           primary_expression expression assignment
%type <declaration>          declaration
%type <node>                 statement function
%type <statement_list>       statement_list function_list element_items function_argument_list
%type <expression_list>  expression_list
%type <compound_statement>   compound_statement element_compound_statement
%type <selection_statement>  selection_statement selection_rest_statement
%type <translation_unit>     translation_unit

%type <function_argument>    function_argument
%type <while_statement>      while_statement
%type <print_statement>      print_statement
%type <return_statement>     return_statement
%type <element_item>         element_item
%type <element_statement>    element_statement
%%

 /* rule that matches a translation unit (aka. a source file) */
translation_unit
	: function_list {
		$$ = create_translation_unit($1);
		print_program((struct ast_node *) $$);
	}
	| {
	}
;

 /* rules for: 1) statements
               2) list of statements
               3) compound statements */


element_compound_statement
   : LBRACE RBRACE {
      $$ = create_compound_statement_empty();
   }
   | LBRACE element_items RBRACE {
      $$ = create_compound_statement($2);
   }
   ;

element_items
   : element_item {
      $$ = create_statement_list((struct ast_node *) $1);
   }
   | element_items element_item {
      $$ = statement_list_add_statement($1, (struct ast_node *) $2);
   }
   ;

element_item
   : IDENTIFIER OP_DOTDOT expression {
      $$ = create_element_item($1, $3);
   }
   | statement {
      $$ = $1;
   }
   ;

compound_statement
   : LBRACE statement_list RBRACE {
      $$ = create_compound_statement($2);
   }
   | LBRACE RBRACE {
      $$ = create_compound_statement_empty();
   }
   ;

function_list
   : function {
      $$ = create_statement_list($1);
   }
   | function_list function {
      $$ = statement_list_add_statement($1, $2);
   }
   ;

function_argument_list
   : function_argument {
      $$ = create_argument_list($1);
   }
   | function_argument_list COLON function_argument {
      $$ = argument_list_add_argument($1, $3);
   }
   | {
      $$ = create_argument_list_empty();
   }
   ;

function_argument
   : type_specifier IDENTIFIER {
      $$ = create_function_argument($1, $2);
   }
   ;

function
   : IDENTIFIER LPAREN function_argument_list RPAREN compound_statement {
      $$ = (struct ast_node *) create_function(create_type(AST_VALUE_VOID), $1, $3, $5);
   }
   | IDENTIFIER compound_statement {
      $$ = (struct ast_node *) create_function(create_type(AST_VALUE_VOID), $1, create_argument_list_empty(), $2);
   }
   | type_specifier IDENTIFIER LPAREN function_argument_list RPAREN compound_statement {
      $$ = (struct ast_node *) create_function($1, $2, $4, $6);
   }
   | type_specifier IDENTIFIER compound_statement {
      $$ = (struct ast_node *) create_function($1, $2, create_argument_list_empty(), $3);
   }
   ;


statement_list
   : statement {
      $$ = create_statement_list($1);
   }
   | statement_list statement {
      $$ = statement_list_add_statement($1, $2);
   }
   ;

statement: declaration { $$ = (struct ast_node *) $1; }
         | expression  { $$ = (struct ast_node *) $1; }
         | assignment  { $$ = (struct ast_node *) $1; }
         | selection_statement   { $$ = (struct ast_node *) $1; }
         | while_statement       { $$ = (struct ast_node *) $1; }
         | print_statement       { $$ = (struct ast_node *) $1; }
         | return_statement      { $$ = (struct ast_node *) $1; }
         | element_statement      { $$ = (struct ast_node *) $1; }
         ;

 /* while rule */
while_statement
   : KW_WHILE LPAREN expression RPAREN compound_statement {
      $$ = create_while_statement($3, $5);
   }
   ;

 /* return rule */
return_statement
   : KW_RETURN expression {
      $$ = create_return_statement($2);
   }
   ;

 /* element rule */
element_statement
   : IDENTIFIER element_compound_statement {
      $$ = create_element_statement($1, $2);
   }
   ;

 /* print rule */
print_statement
   : KW_PRINT expression {
      $$ = create_print_statement($2, FALSE);
   }
   | KW_PRINTLN expression {
      $$ = create_print_statement($2, TRUE);
   }
   ;

 /* if/then/else rule */
selection_statement
   : KW_IF expression selection_rest_statement {
      $$ = $3;
      $$->condition = $2;
   }
   ;

selection_rest_statement
   : compound_statement {
      $$ = create_selection_statement(NULL, $1, NULL);
   }
   | compound_statement KW_ELSE compound_statement {
      $$ = create_selection_statement(NULL, $1, $3);
   }
   ;

 /* rule to match an assigment statement */
assignment
   : IDENTIFIER OP_ASSIGN expression {
   $$ = create_expression(AST_ASSIGN, $3, NULL);
   $$->value.primary.value_identifier = $1;
}
;

 /* expression group */
expression_list
   : expression {
      $$ = create_expression_list((struct ast_node *) $1);
   }
   | expression_list COLON expression {
      $$ = expression_list_add_expression($1, (struct ast_node *) $3);
   }
   | {
      $$ = create_expression_list_empty();
   }
   ;

 /* expression evaluation rules */
expression
   : expression OP_ADD expression {
      $$ = create_expression(AST_ADD, $1, $3);
   }
   | expression OP_SUB expression {
      $$ = create_expression(AST_SUB, $1, $3);
   }

   | expression OP_SIGN expression {
      $$ = create_expression(AST_SIGN, $1, $3);
   }

   | expression OP_DOT expression {
      $$ = create_expression(AST_DOT, $1, $3);
   }
   | expression OP_DOTDOT expression {
      $$ = create_expression(AST_DOTDOT, $1, $3);
   }
   | expression OP_DOTDOTDOT expression {
      $$ = create_expression(AST_DOTDOTDOT, $1, $3);
   }

   | expression OP_MOL expression {
      $$ = create_expression(AST_MOL, $1, $3);
   }
   | expression OP_MUL expression {
      $$ = create_expression(AST_MUL, $1, $3);
   }
   | expression OP_POW expression {
      $$ = create_expression(AST_POW, $1, $3);
   }
   | expression OP_DIV expression {
      $$ = create_expression(AST_DIV, $1, $3);
   }
   | expression OP_GT  expression {
      $$ = create_expression(AST_GT, $1, $3);
   }
   | expression OP_LT  expression {
      $$ = create_expression(AST_LT, $1, $3);
   }
   | expression OP_TEQ  expression {
      $$ = create_expression(AST_TEQ, $1, $3);
   }
   | expression OP_EQ  expression {
      $$ = create_expression(AST_EQ, $1, $3);
   }
   | expression OP_TNE expression {
      $$ = create_expression(AST_TNE, $1, $3);
   }
   | expression OP_NE  expression {
      $$ = create_expression(AST_NE, $1, $3);
   }
   | LPAREN expression RPAREN {
      $$ = create_expression(AST_PARENT, $2, NULL);
   }
   | primary_expression {
      $$ = $1;
   }
   ;

primary_expression
   : IDENTIFIER LPAREN expression_list RPAREN {
      //$$ = create_function_call($1, $3);
      $$ = create_expression(AST_VALUE, NULL, NULL);
      $$->value.tag = AST_FUNCTION_CALL;
      $$->value.primary.function_call = create_function_call($1, $3);
   }
   | IDENTIFIER {
      $$ = create_expression(AST_VALUE, NULL, NULL);
      $$->value.tag = AST_VALUE_IDENTIFIER;
      $$->value.primary.value_identifier = $1;
   }
   | INT_CONSTANT {
      $$ = create_expression(AST_VALUE, NULL, NULL);
      $$->value.tag = AST_VALUE_INT32;
      $$->value.primary.value_int32 = $1;
   }
   | FLOAT_CONSTANT {
      $$ = create_expression(AST_VALUE, NULL, NULL);
      $$->value.tag = AST_VALUE_FLOAT32;
      $$->value.primary.value_float32 = $1;
   }
   | STRING_CONSTANT {
      $$ = create_expression(AST_VALUE, NULL, NULL);
      $$->value.tag = AST_VALUE_STRING;
      $$->value.primary.value_string = $1;
   }
   | KW_TRUE {
      $$ = create_expression(AST_VALUE, NULL, NULL);
      $$->value.tag = AST_VALUE_BOOLEAN;
      $$->value.primary.value_boolean = TRUE;
   }
   | KW_FALSE {
      $$ = create_expression(AST_VALUE, NULL, NULL);
      $$->value.tag = AST_VALUE_BOOLEAN;
      $$->value.primary.value_boolean = FALSE;
   }
   | KW_NULL {
      $$ = create_expression(AST_VALUE, NULL, NULL);
      $$->value.tag = AST_VALUE_NULL;
   }
   ;

 /* variable declaration rules */
declaration
   : type_specifier IDENTIFIER OP_ASSIGN expression {
      $$ = create_declaration_value($1, $2, $4);
   }
   | type_specifier IDENTIFIER {
      $$ = create_declaration($1, $2);
   }
   ;

type_specifier: KW_INT8     { $$ = create_type(AST_VALUE_INT32);     }
              | KW_INT16   { $$ = create_type(AST_VALUE_INT32);   }
              | KW_INT32   { $$ = create_type(AST_VALUE_INT32);   }
              | KW_INT64   { $$ = create_type(AST_VALUE_INT32);   }
              | KW_UINT8   { $$ = create_type(AST_VALUE_INT32);   }
              | KW_UINT16   { $$ = create_type(AST_VALUE_INT32);   }
              | KW_UINT32   { $$ = create_type(AST_VALUE_INT32);   }
              | KW_UINT64   { $$ = create_type(AST_VALUE_INT32);   }
              | KW_FLOAT32   { $$ = create_type(AST_VALUE_FLOAT32);   }
              | KW_FLOAT64   { $$ = create_type(AST_VALUE_FLOAT32);   }
              | KW_FLOAT128   { $$ = create_type(AST_VALUE_FLOAT32);   }
              | KW_BOOL   { $$ = create_type(AST_VALUE_BOOLEAN);   }
              | KW_VOID   { $$ = create_type(AST_VALUE_VOID); }
              ;

%%

//int yylex(YYSTYPE *, void *);

void
yyerror(const char *s)
{
   printf("%s\n", s);
}
