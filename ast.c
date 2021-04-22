#include <stdio.h>
#include <stdlib.h>
#include "ast.h"

static void *
alloc_node(int tag)
{
   struct ast_node *node;
   size_t size = 0;

   switch (tag) {
      case AST_NODE:
         size = sizeof(struct ast_node);
         break;
      case AST_PRINT_STATEMENT:
         size = sizeof(struct ast_print_statement);
         break;
      case AST_TYPE:
         size = sizeof(struct ast_type);
         break;
      case AST_DECLARATION:
         size = sizeof(struct ast_declaration);
         break;
      case AST_FUNCTION:
         size = sizeof(struct ast_function);
         break;
      case AST_EXPRESSION:
         size = sizeof(struct ast_expression);
         break;
      case AST_STATEMENT_LIST:
         size = sizeof(struct ast_statement_list);
         break;
      case AST_COMPOUND_STATEMENT:
         size = sizeof(struct ast_compound_statement);
         break;
      case AST_RETURN_STATEMENT:
         size = sizeof(struct ast_return_statement);
         break;
      case AST_SELECTION_STATEMENT:
         size = sizeof(struct ast_selection_statement);
         break;
      case AST_WHILE_STATEMENT:
         size = sizeof(struct ast_while_statement);
         break;
      case AST_ELEMENT_STATEMENT:
         size = sizeof(struct ast_element_statement);
         break;
      case AST_ELEMENT_ITEM:
         size = sizeof(struct ast_element_item);
         break;
      case AST_TRANSLATION_UNIT:
         size = sizeof(struct ast_translation_unit);
         break;

      case ast_function_argument_LIST:
         size = sizeof(struct ast_function_argument_list);
         break;

      case ast_function_argument_ITEM:
         size = sizeof(struct ast_function_argument);
         break;

      case AST_FUNCTION_CALL:
         size = sizeof(struct ast_function_call);
         break;

      case AST_EXPRESSION_LIST:
         size = sizeof(struct ast_expression_list);
         break;

      default:
         fprintf(stderr, "Unknown node type: %d\n", tag);
         exit(EXIT_FAILURE);
   }

   node = calloc(1, size);
   if (node == NULL) {
      fprintf(stderr, "Memory allocation request failed.!\n");
      exit(EXIT_FAILURE);
   }

   node->tag = tag;
   return node;
}

struct ast_expression *
create_expression(int operator, struct ast_expression *lhs,
                                 struct ast_expression *rhs)
{
   struct ast_expression *expression;

   expression = alloc_node(AST_EXPRESSION);
   expression->operator = operator;
   expression->subexpr[0] = lhs;
   expression->subexpr[1] = rhs;

   return expression;
}

struct ast_declaration *
create_declaration_value(struct ast_type *type, char *identifier, struct ast_expression *value)
{
   struct ast_declaration *declaration;

   declaration = alloc_node(AST_DECLARATION);
   declaration->type = type;
   declaration->identifier = identifier;
   declaration->value = value;

   return declaration;
}

struct ast_declaration *
create_declaration(struct ast_type *type, char *identifier)
{
   struct ast_declaration *declaration;

   declaration = alloc_node(AST_DECLARATION);
   declaration->type = type;
   declaration->identifier = identifier;
   declaration->value = NULL;

   return declaration;
}

struct ast_function_argument_list *
create_argument_list_empty()
{
   struct ast_function_argument_list *argument_list;

   argument_list = alloc_node(ast_function_argument_LIST);
   argument_list->number_of_arguments = 0;

   return argument_list;
}



struct ast_function_argument_list *
create_argument_list(struct ast_node *argument)
{
   struct ast_function_argument_list *argument_list;

   argument_list = alloc_node(ast_function_argument_LIST);

   argument_list->argument = calloc(1, sizeof(struct ast_node *));
   if (argument_list->argument == NULL) {
      fprintf(stderr, "Memory allocation request failed.\n");
      exit(EXIT_FAILURE);
   }

   argument_list->argument[0] = argument;
   argument_list->number_of_arguments = 1;

   return argument_list;
}

struct ast_statement_list *
create_statement_list(struct ast_node *statement)
{
   struct ast_statement_list *statement_list;

   statement_list = alloc_node(AST_STATEMENT_LIST);

   statement_list->statement = calloc(1, sizeof(struct ast_node *));
   if (statement_list->statement == NULL) {
      fprintf(stderr, "Memory allocation request failed.\n");
      exit(EXIT_FAILURE);
   }

   statement_list->statement[0] = statement;
   statement_list->number_of_statements = 1;

   return statement_list;
}

struct ast_statement_list *
create_statement_list_empty()
{
   struct ast_statement_list *statement_list;
   statement_list = alloc_node(AST_STATEMENT_LIST);
   statement_list->number_of_statements = 0;

   return statement_list;
}

struct ast_function_argument_list *
argument_list_add_argument(struct ast_function_argument_list *argument_list,
                             struct ast_node *argument)
{
   int nstmts;
   size_t size;

   nstmts = argument_list->number_of_arguments + 1;
   size = nstmts * sizeof(struct ast_statement *);

   argument_list->argument = realloc(argument_list->argument, size);
   if (argument_list->argument == NULL) {
      fprintf(stderr, "Memory reallocation request failed.\n");
      exit(EXIT_FAILURE);
   }

   argument_list->argument[nstmts - 1] = argument;
   argument_list->number_of_arguments++;

   return argument_list;
}

struct ast_statement_list *
statement_list_add_statement(struct ast_statement_list *statement_list,
                             struct ast_node *statement)
{
   int nstmts;
   size_t size;

   nstmts = statement_list->number_of_statements + 1;
   size = nstmts * sizeof(struct ast_statement *);

   statement_list->statement = realloc(statement_list->statement, size);
   if (statement_list->statement == NULL) {
      fprintf(stderr, "Memory reallocation request failed.\n");
      exit(EXIT_FAILURE);
   }

   statement_list->statement[nstmts - 1] = statement;
   statement_list->number_of_statements++;

   return statement_list;
}

struct ast_compound_statement *
create_compound_statement(struct ast_statement_list *statement_list)
{
   struct ast_compound_statement *compound_statement;

   compound_statement = alloc_node(AST_COMPOUND_STATEMENT);
   compound_statement->statement_list = statement_list;

   return compound_statement;
}


struct ast_function_argument *
create_function_argument(struct ast_type *type, string name)
{
   struct ast_function_argument *function_argument;

   function_argument = alloc_node(ast_function_argument_ITEM);
   // printf("create func arg-->%d\n", type->type);
   function_argument->type = type;
   function_argument->name = strdup(name);

   return function_argument;
}

struct ast_compound_statement *
create_compound_statement_empty()
{
   struct ast_compound_statement *compound_statement;

   compound_statement = alloc_node(AST_COMPOUND_STATEMENT);
   compound_statement->statement_list = create_statement_list_empty();

   return compound_statement;
}

struct ast_selection_statement *
create_selection_statement(struct ast_expression *condition,
                           struct ast_compound_statement *then_body,
                           struct ast_compound_statement *else_body)
{
   struct ast_selection_statement *selection_statement;

   selection_statement = alloc_node(AST_SELECTION_STATEMENT);

   selection_statement->condition = condition;
   selection_statement->then_body = then_body;
   selection_statement->else_body = else_body;

   return selection_statement;
}

struct ast_return_statement *
create_return_statement(struct ast_expression *value)
{
   struct ast_return_statement *return_statement;

   return_statement = alloc_node(AST_RETURN_STATEMENT);

   return_statement->value = value;

   return return_statement;
}


struct ast_print_statement *
create_print_statement(struct ast_expression *value, boolean newLine)
{
   struct ast_print_statement *print_statement;

   print_statement = alloc_node(AST_PRINT_STATEMENT);

   print_statement->value = value;
   print_statement->newLine=newLine;

   return print_statement;
}



struct ast_element_statement *
create_element_statement(string name, struct ast_compound_statement *body)
{
   struct ast_element_statement *element_item;

   element_item = alloc_node(AST_ELEMENT_STATEMENT);

   element_item->name = name;
   element_item->body = body;

   return element_item;
}

struct ast_element_item *
create_element_item(string name, struct ast_expression *value)
{
   struct ast_element_item *element_item;

   element_item = alloc_node(AST_ELEMENT_ITEM);

   element_item->name = name;
   element_item->value = value;

   return element_item;
}

struct ast_while_statement *
create_while_statement(struct ast_expression *condition,
                       struct ast_compound_statement *body)
{
   struct ast_while_statement *while_statement;

   while_statement = alloc_node(AST_WHILE_STATEMENT);

   while_statement->condition = condition;
   while_statement->body = body;

   return while_statement;
}

struct ast_function *
create_function(struct ast_type *type, string name, void *arguments, struct ast_compound_statement *statement_list)
{
   struct ast_function *function;

   function = alloc_node(AST_FUNCTION);
   function->name = name;
   function->arguments = arguments;
   function->type = type;
   function->body = statement_list;

   return function;
}

struct ast_translation_unit *
create_translation_unit(struct ast_statement_list *statement_list)
{
   struct ast_translation_unit *translation_unit;

   translation_unit = alloc_node(AST_TRANSLATION_UNIT);
   translation_unit->statement_list = statement_list;

   return translation_unit;
}


struct ast_function_call *
create_function_call(string name, struct ast_expression_list *expressions)
{
   // struct ast_expression *expression;

   // expression = alloc_node(AST_EXPRESSION);
   // expression->operator = operator;
   // expression->subexpr[0] = lhs;
   // expression->subexpr[1] = rhs;
   struct ast_function_call *function_call;

   // printf("->Create function calling...\n");
   function_call = alloc_node(AST_FUNCTION_CALL);
   function_call->name = name;
   function_call->expressions = expressions;

   return function_call;
}


struct ast_expression_list *
create_expression_list(struct ast_node *expression)
{
   struct ast_expression_list *expression_list;

   expression_list = alloc_node(AST_EXPRESSION_LIST);

   expression_list->expression = calloc(1, sizeof(struct ast_node *));
   if (expression_list->expression == NULL) {
      fprintf(stderr, "Memory allocation request failed.\n");
      exit(EXIT_FAILURE);
   }

   expression_list->expression[0] = expression;
   expression_list->number_of_expressions = 1;

   return expression_list;
}



struct ast_expression_list *
expression_list_add_expression(struct ast_expression_list *expression_list,
                             struct ast_node *expression)
{
   int nstmts;
   size_t size;

   nstmts = expression_list->number_of_expressions + 1;
   size = nstmts * sizeof(struct ast_statement *);

   expression_list->expression = realloc(expression_list->expression, size);
   if (expression_list->expression == NULL) {
      fprintf(stderr, "Memory reallocation request failed.\n");
      exit(EXIT_FAILURE);
   }

   expression_list->expression[nstmts - 1] = expression;
   expression_list->number_of_expressions++;

   return expression_list;
}

struct ast_expression_list *
create_expression_list_empty()
{
   struct ast_expression_list *expression_list;

   expression_list = alloc_node(AST_EXPRESSION_LIST);
   expression_list->number_of_expressions = 0;

   return expression_list;
}


struct ast_type *
create_type(int value_type)
{
   struct ast_type *t;

   // t = malloc(sizeof(struct ast_type));
   t = alloc_node(AST_TYPE);
   t->type = value_type;
   // printf("-->create a type %d\n", value_type);
   // printf("-->create a type %d\n", t->type);

   return t;
}

struct ast_type *
create_type_void()
{
   return create_type(AST_VALUE_VOID);
}

