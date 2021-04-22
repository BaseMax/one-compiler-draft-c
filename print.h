static void
print_declaration(struct ast_declaration *);

static void
print_value(struct ast_value);

static void
print_expression(struct ast_expression *expression);

static void
print_statement_list(struct ast_statement_list *);

static void
print_compound_statement(struct ast_compound_statement *);

static void
print_selection_statement(struct ast_selection_statement *);

static void
print_function(struct ast_function *);

static void
print_while_statement(struct ast_while_statement *);

static void
print_print_statement(struct ast_print_statement *);

static void
print_translation_unit(struct ast_translation_unit *);

static void
emit(char *q);

static void
print_return_statement(struct ast_return_statement *return_statement);

static string
int32_to_string(int32 v);

static string
float32_to_string(float32 v);

static boolean
type_is_int(int tag);

static boolean
type_is_float(int tag);

static string
type_value(int tag);

static void //string
print_function_expressions(struct ast_expression_list *expressions);

static void //string
print_function_arguments(struct ast_function_argument_list *arguments);


void
print_type(struct ast_type *type);

void
print_program(void *node);

