#ifndef AST_H
#define AST_H

#include <inttypes.h>
#include <string.h>
//#include "sds.h"

typedef char int8;
typedef unsigned char uint8;
typedef short int16;
typedef unsigned short uint16;
typedef int int32;
typedef unsigned int uint32;
typedef int64_t int64;
typedef uint64_t uint64;
typedef char *string;
typedef float float32;
typedef double float64;
typedef long double float128;
typedef enum { FALSE, TRUE } boolean;

struct ast_node;
struct ast_declaration;
struct ast_expression;
struct ast_statement_list;
struct ast_compound_statement;
struct ast_selection_statement;
struct ast_while_statement;
struct ast_translation_unit;
struct ast_function;

#define AST_NODE                    1
#define AST_DECLARATION             2
#define AST_EXPRESSION              3
#define AST_STATEMENT_LIST          4
#define AST_COMPOUND_STATEMENT      5
#define AST_SELECTION_STATEMENT     6
#define AST_WHILE_STATEMENT         7
#define AST_TRANSLATION_UNIT        8
#define AST_FUNCTION                9
#define AST_PRINT_STATEMENT         10
#define AST_RETURN_STATEMENT 11
#define AST_ELEMENT_STATEMENT 12
#define AST_ELEMENT_ITEM 13
// #define AST_FUNCTION_ARGUMENT 20
#define ast_function_argument_LIST 14
#define ast_function_argument_ITEM 15
#define AST_FUNCTION_CALL 44
#define AST_EXPRESSION_LIST 46
struct ast_node {
   int tag;
};

enum ast_value_type {
    AST_VALUE_INT8,
    AST_VALUE_UINT8,

    AST_VALUE_INT16,
    AST_VALUE_UINT16,

    AST_VALUE_INT32, // 4
    AST_VALUE_UINT32,

    AST_VALUE_INT64,
    AST_VALUE_UINT64,

    AST_VALUE_FLOAT32,
    AST_VALUE_FLOAT64,
    AST_VALUE_FLOAT128,

    AST_VALUE_STRING,
    AST_VALUE_IDENTIFIER,

    AST_VALUE_CHAR,
    AST_VALUE_CHARACTER,

    AST_VALUE_BOOLEAN,

    AST_VALUE_VOID,
    AST_VALUE_NULL,
    AST_VALUE_UNDEFINED,

    AST_VALUE_ARRAY,
    AST_VALUE_POINTER,
};

struct ast_value {
   // enum ast_value_type tag;
   int tag;

   union {
      string value_character;
      int8 value_char;

      int8 value_int8;
      uint8 value_uint8;

      int16 value_int16;
      uint16 value_uint16;

      int32 value_int32;
      uint32 value_uint32;

      int64 value_int64;
      uint64 value_uint64;

      float32 value_float32;
      float64 value_float64;
      float128 value_float128;

      void *value_pointer;
      boolean value_boolean;

      string value_identifier;
      // string value_ident;
      char* value_string;
      struct ast_function_call *function_call;
      // string value_string;
   } primary;
};

struct ast_expression {
   int tag;

#define AST_ADD            1     /* '+'   */
#define AST_SUB            2     /* '-'   */
#define AST_MUL            3     /* '*'   */
#define AST_DIV            4     /* '/'   */

#define AST_GT             5     /* '>'   */
#define AST_LT             6     /* '<'   */
#define AST_EQ             7     /* '=='  */
#define AST_NE             8     /* '!='  */
#define AST_LE             9     /* '<='  */
#define AST_GE             10    /* '>='  */

#define AST_ASSIGN         11    /* '='   */

#define AST_TEQ            15    /* '===' */
#define AST_TNE            16    /* '!==' */
#define AST_MOL            17    /* '%' */
#define AST_SIGN           18    /* '^' */
#define AST_DOT            19    /* '.' */
#define AST_DOTDOT         20    /* '..' */
#define AST_DOTDOTDOT      21    /* '...' */

#define AST_POW            22    /* '**' */
#define AST_PARENT         23    /* (..) */
#define AST_VALUE  30
#define AST_TYPE   31
   int operator;
   struct ast_expression *subexpr[2];


   struct ast_value value;
};

struct ast_function_call {
   int tag;

   string name;
   struct ast_expression_list *expressions;
};

struct ast_declaration {
   int tag;

   struct ast_type *type;
   char *identifier;
   struct ast_expression *value;
};

struct ast_function_argument_list {
   int tag;

   struct ast_node **argument;
   int number_of_arguments;
};

struct ast_expression_list {
   int tag;

   struct ast_node **expression;
   int number_of_expressions;
};

struct ast_statement_list {
   int tag;

   struct ast_node **statement;
   int number_of_statements;
};

struct ast_function_argument {
   struct ast_type *type;
   string name;
};

struct ast_compound_statement {
   int tag;

   struct ast_statement_list *statement_list;
};

struct ast_selection_statement {
   int tag;

   /* if (condition) { then_body } else { else_body } */
   struct ast_expression *condition;
   struct ast_compound_statement *then_body;
   struct ast_compound_statement *else_body;
};

struct ast_return_statement {
   int tag;

   /* return value */
   struct ast_expression *value;
};

struct ast_print_statement {
   int tag;

   /* _ value */
   /* __ value */
   struct ast_expression *value;
   boolean newLine;
};

struct ast_element_item {
   int tag;

   /* ident : expression */
   string name;
   struct ast_expression *value;
};

struct ast_element_statement {
   int tag;

   /* ident { [element_item + statement |] } */
   string name;
   struct ast_compound_statement *body;
};

struct ast_while_statement {
   int tag;

   /* while (condition) { body } */
   struct ast_expression *condition;
   struct ast_compound_statement *body;
};

struct ast_function {
   int tag;

   /* def name (arguments) { body } */
   struct ast_type *type;
   string name;
   struct ast_function_argument_list *arguments;
   // struct ast_expression *condition;
   struct ast_compound_statement *body;
};

struct ast_translation_unit {
   int tag;

   struct ast_statement_list *statement_list;
};

struct ast_type {
  int tag;

  // cannot enum use at switch(){} : enum ast_value_type *type;
  int type;
};

struct ast_declaration *
create_declaration(struct ast_type *type, char *identifier);

struct ast_expression *
create_expression(int operation, struct ast_expression *lhs,
                                 struct ast_expression *rhs);

struct ast_statement_list *
create_statement_list(struct ast_node *statement);

struct ast_statement_list *
statement_list_add_statement(struct ast_statement_list *statement_list,
                             struct ast_node *statement);

struct ast_compound_statement *
create_compound_statement(struct ast_statement_list *statement_list);

struct ast_selection_statement *
create_selection_statement(struct ast_expression *condition,
                           struct ast_compound_statement *then_body,
                           struct ast_compound_statement *else_body);

struct ast_while_statement *
create_while_statement(struct ast_expression *condition,
                       struct ast_compound_statement *body);

struct ast_translation_unit *
create_translation_unit(struct ast_statement_list *statement_list);

struct ast_compound_statement *
create_compound_statement_empty();

struct ast_statement_list *
create_statement_list_empty();

struct ast_statement_list *
create_function_list(struct ast_node *statement);

struct ast_function *
create_function(struct ast_type *type, string name, void *arguments, struct ast_compound_statement *statement_list);

void
print_node(struct ast_node *node);

struct ast_print_statement *
create_print_statement(struct ast_expression *value, boolean newLine);

static string
type_value(int tag);

struct ast_return_statement *
create_return_statement(struct ast_expression *value);

struct ast_function_argument_list *
argument_list_add_argument(struct ast_function_argument_list *argument_list,
                             struct ast_node *argument);
                           
struct ast_function_argument_list *
create_argument_list(struct ast_node *argument);

struct ast_function_argument_list *
create_argument_list_empty();

struct ast_statement_list *
create_statement_list_empty();

struct ast_function_argument *
create_function_argument(struct ast_type *type, string name);

struct ast_function_call *
create_function_call(string name, struct ast_expression_list *expressions);

struct ast_expression_list *
create_expression_list(struct ast_node *expression);

struct ast_expression_list *
expression_list_add_expression(struct ast_expression_list *expression_list,
                             struct ast_node *expression);

struct ast_expression_list *
create_expression_list_empty();

struct ast_type *
create_type(int value_type);

struct ast_declaration *
create_declaration_value(struct ast_type *type, char *identifier, struct ast_expression *value);

struct ast_element_statement *
create_element_statement(string name, struct ast_compound_statement *body);

struct ast_element_item *
create_element_item(string name, struct ast_expression *value);

struct ast_type *
create_type_void();

#endif /* AST_H */
