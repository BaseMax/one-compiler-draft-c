#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"
#include "print.h"

static int ntabs = 0;

//sds library;
//sds source;
//sds source_main;
string library[5000];
struct charPtr
{
    size_t size;
    char *p;
};

struct charPtr source={.size = 0,.p=NULL};
struct charPtr source_main={.size = 0,.p=NULL};


//int source_index=0;
//int source_main_index=0;
int state=1;

static void
rand_string(string s, size_t size)
{
	const char charset[]="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	if(size) {
		--size;
		for(size_t n=0;n<size;n++) {
			int key=rand() % (int) (sizeof charset - 1);
			s[n]=charset[key];
		}
		s[size]='\0';
	}
}

static string
randomIdent(size_t size)
{
	string s = malloc(size+1);
	if(s) {
		rand_string(s, size);
	}
	return s;
}


void
print_type(struct ast_type *type)
{
   // printf("->%d\n", type);
   // printf("->%d\n", type->type);
   switch (type->type) {
      case AST_VALUE_INT8:
         emit("int8");
         break;
      case AST_VALUE_INT16:
         emit("int16");
         break;
      case AST_VALUE_INT32:
         emit("int32");
         break;
      case AST_VALUE_INT64:
         emit("int64");
         break;
      case AST_VALUE_FLOAT32:
         emit("float32");
         break;
      case AST_VALUE_FLOAT64:
         emit("float64");
         break;
      case AST_VALUE_STRING:
         emit("string");
         break;
      case AST_VALUE_VOID:
         emit("void");
         break;
      case AST_VALUE_BOOLEAN:
         emit("bool");
         break;
      case AST_VALUE_CHAR:
         emit("char");
         break;
      default:
         fprintf(stderr, "Unknown type specifier\n");
         fprintf(stderr, "Unknown type specifier: %d\n", type->type);
         exit(EXIT_FAILURE);
   }
}

char *uitoa(uint32 n)
{
    int len = n==0 ? 1 : floor(log10l(labs(n)))+1;
    char *buf = malloc(len+1); // +1 for null
    buf[len--]='\0';
    do {
         buf[len--] = n % 10 + '0';
     } while ((n /= 10) > 0);
    return buf;
}


char *itoa(int32 n)
{
    int sign;
    int len = n==0 ? 1 : floor(log10l(labs(n)))+1;
    if (n<0) len++; // room for negative sign '-'
    char *buf = malloc(len+1); // +1 for null
    buf[len--]='\0';
    if ((sign = n) < 0)  n = -n;
    do {
         buf[len--] = n % 10 + '0';
     } while ((n /= 10) > 0);
     if (sign < 0)
         buf[0] = '-';
    return buf;
}

static void
emit_int32(int32 q)
{
   //printf("%d", q);
   char *num_str = itoa(q);
   emit(num_str);
   free(num_str);
}

static void
emit_float32(float32 q)
{ 
  
    uint32 *dd = &q;
    uint32 sign = (((*dd & 0x80000000)>>31)==0)?0:1;
    uint32 fraction= (*dd & 0x00ffffff) | 0x00800000;
    int32 exponent = ((*dd & 0x7f800000)>>23);
    if(exponent == 0xff)    {
        if(fraction & 0x007fffff)
        {
            emit("NaN");
        }
        else
        {
            emit("inf");
        }
    }else{
        if(exponent == 0x00){
            emit("0.0");
        }else{
            double fractpart, intpart;
            float tmp = q;
            int32 exp10 = 0;
            fractpart = modf(tmp , &intpart);
            while((intpart<1) | (intpart>9)){
                if(intpart<1){
                    exp10--;
                    tmp*=10;
                }else{
                    if(intpart>9){
                       exp10++;
                       tmp /=10;
                    }
                }
                fractpart = modf(tmp , &intpart);
            }
           
            fraction<<=8;
            exponent -= 127;
            float32 multipler = powf(2,exponent)/powf(10,exp10);
            int multipler_count = 0;
            while((multipler*10)<0xfffffff){
                multipler_count++;
                multipler*=10;
                }
            uint32 temp = (uint32)multipler;
            uint32 helper =0;
            for(int i=0;i<32;i++){
                if(fraction & 0x80000000){
                    helper += temp;
                }
                fraction <<= 1;
                temp >>= 1;
            }
           char *num_str = uitoa(helper);
           if(sign) emit("-");
           char *num_str2=num_str;
           char num_str1[2]={0,0};
           num_str1[0]=num_str[0];
           num_str2++;
           emit(num_str1);
           emit(".");
           emit(num_str2);
           free(num_str);
           if(exp10 != 0){
               emit("e");
               if(exp10>0)emit("+");
               emit_int32(exp10);
           }
        }
    }
   //printf("%f", q);
}

static void
emit(char *q)
{
//   printf("%d-->%s", ntabs, q);
   printf(q);
   // return;
   // if(state == 0) {
   //    for(int i=0;i<strlen(q);i++) {
   //       source_main[source_main_index]=q[i];
   //    }
   //    source_main_index++;
   // }
   // else {
   //    for(int i=0;i<strlen(q);i++) {
   //       source[source_index]=q[i];
   //    }
   //    source_index++;
   // }

   int length=0;
   while(q[length])length++;
   if(state == 0) {
      source_main.size = source_main.size + length;
      source_main.p=realloc(source_main.p,source_main.size);
      strcat(source_main.p, q);
   }
   else {
      source.size = source.size + length ;
      source.p=realloc(source.p,source.size);
      strcat(source.p, q);
   }
   
}

// void uintToCStr(unsigned int val, char* c)
// {
//     static const char digitPairs[201] = {
//         "00010203040506070809"
//         "10111213141516171819"
//         "20212223242526272829"
//         "30313233343536373839"
//         "40414243444546474849"
//         "50515253545556575859"
//         "60616263646566676869"
//         "70717273747576777879"
//         "80818283848586878889"
//         "90919293949596979899"
//     };

//     int size;

//     if(val >= 10000) {
//         if(val >= 10000000) {
//             if(val >= 1000000000)
//                 size = 10;
//             else if(val >= 100000000)
//                 size = 9;
//             else
//                 size = 8;
//         } else {
//             if(val >= 1000000)
//                 size = 7;
//             else if(val >= 100000)
//                 size = 6;
//             else
//                 size = 5;
//         }
//     } else {
//         if(val >= 100) {
//             if(val >= 1000)
//                 size = 4;
//             else
//                 size = 3;
//         } else {
//             if(val >= 10)
//                 size = 2;
//             else
//                 size = 1;
//         }
//     }

//     c += size - 1;
//     c[1] = 0;

//     while(val >= 100) {
//         int pos = (val % 100) * 2;
//         val /= 100;
//         c[-1] = digitPairs[pos];
//         c[0] = digitPairs[pos + 1];
//         c -= 2;
//     }

//     if (val < 10)
//         c[0] = '0' + val;
//     else {
//         c[-1] = digitPairs[val * 2];
//         c[0] = digitPairs[val * 2 + 1];
//     }
// }

// string
// int32_to_string(int32 n)
// // void intToCStr(int n, char* c)
// {
//    char c*=malloc(90);
//     int sign = -(n < 0);
//     unsigned int val = (n ^ sign) - sign;

//     if(sign)
//         *c++ = '-';

//     uintToCStr(val, c);
//     return c;
// }

// static string
// int32_to_string(int32 v)
// {
//    char str[90];
//    sprintf(str, "%d", v);
//    return str;
// }

// static string
// float32_to_string(float32 v)
// {
//    char str[90];
//    sprintf(str, "%f", v);
//    // printf("==>%s\n", str);
//    return str;
// }

// static string
// float64_to_string(float64 v)
// {
//    char str[90];
//    sprintf(str, "%lf", v);
//    return str;
// }

static void
print_tabs(void)
{
   int i;
//   char *ident=malloc(ntabs*sizeof(char));
   for (i = 0; i < ntabs; i++)
       emit("\t");
//      ident[i]='\t';
//      printf("\t");
   //emit(ident);
   
}

static void
print_declaration(struct ast_declaration *declaration)
{
   // printf("-->");
   // printf("=>%d\n", declaration->type);
   // struct ast_type *t = declaration->type;
   // printf("%d\n", t->type);
   print_type(declaration->type);
   

   emit(" ");
   emit(declaration->identifier);
   if(declaration->value == NULL) {
      emit(";");
   }
   else {
      // emit(";");
      // emit("\n");
      // print_tabs();

      // emit(declaration->identifier);
      emit(" = ");
      print_expression(declaration->value);
      emit(";");
   }
}

static enum ast_value_type
type_of_operator_add(int left, int right, int value)
{
   return left;
	if(type_is_int(left) && type_is_int(right)) {
      printf("-->%s\n", type_value(left));
      printf("-->%s\n", type_value(right));
		return left;
	}
	if(left == AST_VALUE_INT8)
	{
		
	}
	else if(left == AST_VALUE_INT16)
	{
		
	}
	else if(left == AST_VALUE_INT32)
	{
		
	}
	else if(left == AST_VALUE_INT64)
	{
		
	}
	else if(left == AST_VALUE_UINT8)
	{
		
	}
	else if(left == AST_VALUE_UINT16)
	{
		
	}
	else if(left == AST_VALUE_UINT32)
	{
		
	}
	else if(left == AST_VALUE_UINT64)
	{
		
	}
	else if(left == AST_VALUE_FLOAT32)
	{
		
	}
	else if(left == AST_VALUE_FLOAT64)
	{
		
	}
	else if(left == AST_VALUE_FLOAT128)
	{
		
	}
}

static enum ast_value_type
type_of_operator_sub(int left, int right, int value)
{
}

static enum ast_value_type
type_of_operator_mul(int left, int right, int value)
{
}

static enum ast_value_type
type_of_operator_div(int left, int right, int value)
{
}

static enum ast_value_type
type_of_operator_gt(int left, int right, int value)
{
}

static enum ast_value_type
type_of_operator_lt(int left, int right, int value)
{
}

static enum ast_value_type
type_of_operator_eq(int left, int right, int value)
{
}

static enum ast_value_type
type_of_operator_ne(int left, int right, int value)
{
}

static enum ast_value_type
type_of_operator_le(int left, int right, int value)
{
}

static enum ast_value_type
type_of_operator_ge(int left, int right, int value)
{
}

static enum ast_value_type
type_of_operator_mol(int left, int right, int value)
{
}

static enum ast_value_type
type_of_operator_pow(int left, int right, int value)
{
}

static enum ast_value_type
type_of_operator_dotdot(int left, int right, int value)
{
}

static enum ast_value_type
type_of_operator_sign(int left, int right, int value)
{
}
  


static enum ast_value_type
type_of_operator(int op, int left, int right, int value)
{
	// +
	if(op == AST_ADD) {
		return type_of_operator_add(left, right, value);
	}
	// -
	else if(op == AST_SUB) {
		return type_of_operator_sub(left, right, value);
	}
	// *
	else if(op == AST_MUL) {
		return type_of_operator_mul(left, right, value);
	}
	// /
	else if(op == AST_DIV) {
		return type_of_operator_div(left, right, value);
	}
	// >
	else if(op == AST_GT) {
		return type_of_operator_gt(left, right, value);
	}
	// <
	else if(op == AST_LT) {
		return type_of_operator_lt(left, right, value);
	}
	// ==
	else if(op == AST_EQ) {
		return type_of_operator_eq(left, right, value);
	}
	// !=
	else if(op == AST_NE) {
		return type_of_operator_ne(left, right, value);
	}
	// <=
	else if(op == AST_LE) {
		return type_of_operator_le(left, right, value);
	}
	// >=
	else if(op == AST_GE) {
		return type_of_operator_ge(left, right, value);
	}

	// %
	else if(op == AST_MOL) {
		return type_of_operator_mol(left, right, value);
	}
	// ^
	else if(op == AST_POW) {
		return type_of_operator_pow(left, right, value);
	}
	// ..
	else if(op == AST_DOTDOT) {
		return type_of_operator_dotdot(left, right, value);
	}
	// ^
	else if(op == AST_SIGN) {
		return type_of_operator_sign(left, right, value);
	}
	// parent
	else if(op == AST_PARENT) {
		return type_of_operator(value, left, right, value);
	}
	// .
	else if(op == AST_DOT) {
	}
	// ...
	else if(op == AST_DOTDOTDOT) {
	}
	// ==
	else if(op == AST_ASSIGN) {
	}
	// ===
	else if(op == AST_TEQ) {
	}
	// !===
	else if(op == AST_TNE) {
	}
	else if(op == AST_VALUE) {
		return value;
	}
}
  

static boolean
type_is_int(int tag) {
	if(
		tag == AST_VALUE_INT8 ||
		tag == AST_VALUE_INT16 ||
		tag == AST_VALUE_INT32 ||
		tag == AST_VALUE_INT64 ||
		tag == AST_VALUE_UINT8 ||
		tag == AST_VALUE_UINT16 ||
		tag == AST_VALUE_UINT32 ||
		tag == AST_VALUE_UINT64
	) {
		return TRUE;
	}
	return FALSE;
}

static boolean
type_is_float(int tag) {
	if(
		tag == AST_VALUE_FLOAT32 ||
		tag == AST_VALUE_FLOAT64 ||
		tag == AST_VALUE_FLOAT128
	) {
		return TRUE;
	}
	return FALSE;
}

static string
type_value(int tag)
{
   switch(tag) {
      case AST_VALUE_INT8:
         return "int8";
         break;
      case AST_VALUE_INT16:
         return "int16";
         break;
      case AST_VALUE_INT32:
         return "int32";
         break;
      case AST_VALUE_INT64:
         return "int64";
         break;

      case AST_VALUE_UINT8:
         return "uint8";
         break;
      case AST_VALUE_UINT16:
         return "uint16";
         break;
      case AST_VALUE_UINT32:
         return "uint32";
         break;
      case AST_VALUE_UINT64:
         return "uint64";
         break;

      case AST_VALUE_BOOLEAN:
         return "boolean";
         break;
      case AST_VALUE_NULL:
         return "null";
         break;
      case AST_VALUE_FLOAT32:
         return "float32";
         break;
      case AST_VALUE_FLOAT64:
         return "float32";
         break;
      case AST_VALUE_FLOAT128:
         return "float128";
         break;
      case AST_VALUE_STRING:
         return "string";
         break;
      case AST_VALUE_IDENTIFIER:
         return "ident";
         break;
      default:
         return "none";
         break;
   }
}


 
static void
print_value(struct ast_value value)
{
   switch(value.tag) {
      case AST_VALUE_INT32:
         // printf("print int\n");
         // emit(int32_to_string(value.primary.value_int32));
         // printf("->'%d'\n", value.primary.value_int32);
         // emit(int32_to_string(value.primary.value_int32));
         emit_int32(value.primary.value_int32);
         break;
      case AST_VALUE_BOOLEAN:
         emit(value.primary.value_boolean == TRUE ? "TRUE" : "FALSE");
         break;
      case AST_VALUE_NULL:
         emit(NULL);
         break;
      case AST_VALUE_FLOAT32:
         // emit("...");
         // emit(float32_to_string(value.primary.value_float32));
         emit_float32(value.primary.value_float32);
         break;
      case AST_VALUE_STRING:
         emit("\"");
         emit(value.primary.value_string);
         emit("\"");
         break;
      case AST_VALUE_IDENTIFIER:
         emit(value.primary.value_identifier);
         break;

      case AST_FUNCTION_CALL:
         // emit(expression->;
         emit(value.primary.function_call->name);
         emit("(");
         print_function_expressions(value.primary.function_call->expressions);
         emit(")");
         break;

      default:
         emit("\"other\"");
         break;
   }
}

static void
print_expression(struct ast_expression *expression)
{
   switch (expression->operator) {
      case AST_ADD:
         // if(expression->subexpr[0]->operator == AST_VALUE) {
         //    printf("%s\n", type_value(expression->subexpr[0]->value.tag));
         // }
         // printf("==>");
         // printf("%d, %d, %d, %d\n", expression->operator, expression->subexpr[0]->tag, expression->subexpr[1]->tag, expression->value.tag);
         // printf(">>>%d\n", (type_of_operator(expression->operator, expression->subexpr[0]->tag, expression->subexpr[1]->tag, expression->value.tag)));
         //emit(type_value(expression->subexpr[0]->value.tag));
         print_expression(expression->subexpr[0]);
         emit(" + ");
         //emit(type_value(expression->subexpr[0]->value.tag));
         print_expression(expression->subexpr[1]);
   
         // if(expression->subexpr[1]->operator == AST_VALUE) {
         //    printf("%s\n", type_value(expression->subexpr[1]->value.tag));
         // }
         break;
      case AST_SUB:
         print_expression(expression->subexpr[0]);
         emit(" - ");
         print_expression(expression->subexpr[1]);
         break;
      case AST_MUL:
         print_expression(expression->subexpr[0]);
         emit(" * ");
         print_expression(expression->subexpr[1]);
         break;
      case AST_PARENT:
         emit(" (");
         print_expression(expression->subexpr[0]);
         emit(") ");
         break;
      case AST_DIV:
         print_expression(expression->subexpr[0]);
         emit(" / ");
         print_expression(expression->subexpr[1]);
         break;

      case AST_GT:
         print_expression(expression->subexpr[0]);
         emit(" > ");
         print_expression(expression->subexpr[1]);
         break;
      case AST_LT:
         print_expression(expression->subexpr[0]);
         emit(" < ");
         print_expression(expression->subexpr[1]);
         break;
      case AST_EQ:
         print_expression(expression->subexpr[0]);
         emit(" == ");
         print_expression(expression->subexpr[1]);
         break;
      case AST_NE:
         print_expression(expression->subexpr[0]);
         emit(" != ");
         print_expression(expression->subexpr[1]);
         break;

      case AST_ASSIGN:
         emit(expression->value.primary.value_identifier);
         emit(" = ");
         print_expression(expression->subexpr[0]);
         break;

      case AST_VALUE:
         // printf("print value\n");
         print_value(expression->value);
         break;

      default:
         fprintf(stderr, "Unknown expression operator: %d\n",
                         expression->operator);
         exit(EXIT_FAILURE);
   }
}

static void
print_statement_list(struct ast_statement_list *statement_list)
{
   int i;

   for (i = 0; i < statement_list->number_of_statements; i++) {
      if(statement_list->statement[i]->tag != AST_ELEMENT_ITEM) {
         print_tabs();
         print_node(statement_list->statement[i]);
         emit("\n");
      }
   }
}

static void
print_compound_statement(struct ast_compound_statement *compound_statement)
{
   // print_tabs();
   emit("{\n");
   ntabs++;
   print_statement_list(compound_statement->statement_list);
   ntabs--;
   print_tabs();
   emit("}");
}

static void
print_selection_statement(struct ast_selection_statement *selection_statement)
{
   emit("if(");
   print_expression(selection_statement->condition);
   //emit(")\n");
   emit(") ");

   print_compound_statement(selection_statement->then_body);

   if (selection_statement->else_body) {
      //print_tabs();
      emit(" else ");
      print_compound_statement(selection_statement->else_body);
   }
}


static void print_function_call(struct ast_function_call *function_call)
{
   emit(function_call->name);
   emit("(");
   for(int i=0;i<function_call->expressions->number_of_expressions;i++) {
      print_expression((struct ast_expression *)function_call->expressions->expression[i]);
      if(i+1 != function_call->expressions->number_of_expressions) {
         emit(", ");
      }
   }
   emit(");");
}


 
static void
print_function(struct ast_function *function)
{
   if(strcmp(function->name, "main") ==0) {
      state=0;
//      ntabs++;
      //emit("int ");
      emit("int main(int argc, char ** argv)");
   }
   else {
      state=1;
      print_type(function->type);
      emit(" ");
      // // printf("type==>%d\n", function->type);
      // if(function->type == AST_VALUE_INT32) {
      //    emit("int ");
      // }
      // else if(function->type == AST_VALUE_FLOAT32) {
      //    emit("float ");
      // }
      // else if(function->type == AST_VALUE_BOOLEAN) {
      //    emit("boolean ");
      // }
      // else if(function->type == AST_VALUE_NULL) {
      //    emit("null ");
      // }
      // else if(function->type == AST_VALUE_VOID) {
      //    emit("void ");
      // }
      // else {
      //    emit("none_type ");
      // }
//   }
//   else {
      emit(function->name);
      emit("(");
      print_function_arguments(function->arguments);
      emit(") ");
      //emit(")\n");
   }
   print_compound_statement(function->body);
   if(strcmp(function->name, "main") ==0) {
//      emit("\treturn 0;\n");
//      ntabs--;
   }
}

static void //string
print_function_expressions(struct ast_expression_list *expressions)
{
   for(int i=0;i<expressions->number_of_expressions;i++) {
      struct ast_expression *exp=(struct ast_expression *)expressions->expression[i];
      print_expression(exp);
      if(i + 1 != expressions->number_of_expressions) {
         emit(", ");
      }
   }
}

static void //string
print_function_arguments(struct ast_function_argument_list *arguments)
{
   for(int i=0;i<arguments->number_of_arguments;i++) {
      struct ast_function_argument *arg=(struct ast_function_argument *)arguments->argument[i];
      print_type(arg->type);
      // emit_int32(arg->type->type);
      emit(" ");
      emit(arg->name);
      if(i + 1 != arguments->number_of_arguments) {
         emit(", ");
      }
   }
}

static void
print_return_statement(struct ast_return_statement *return_statement)
{
   emit("return(");
   print_expression(return_statement->value);
   emit(");");
}

static void
print_print_statement(struct ast_print_statement *print_statement)
{
   emit("printf(");
   print_expression(print_statement->value);
   emit(");");
   if(print_statement->newLine == TRUE) {
      emit("\n");
      print_tabs();
      emit("printf(\"\\n\");");
   }
}

static void
print_element_statement(struct ast_element_statement *element_statement)
{
	string nameParam=randomIdent(15);
	// char *nameParam=malloc(5*sizeof(char));
   // strcpy(nameParam, "a");
	struct ast_statement_list *items=element_statement->body->statement_list;
   // printf("==>%d\n", items->number_of_statements);
   emit("/*\n");
   print_tabs();

   emit("helper_params *");
   emit(nameParam);
   emit(" = helper_new();\n");
   print_tabs();
   int size=items->number_of_statements;
   for(int i=0;i<size;i++) {
      if(items->statement[i]->tag == AST_ELEMENT_ITEM) {
         size--;
         emit(nameParam);
         emit("[\"");
         emit(((struct ast_element_item*)items->statement[i])->name);
         emit("\"] = ");
         print_expression(((struct ast_element_item*)items->statement[i])->value);
         emit(";\n");
         print_tabs();
      }
   }

   emit("*/\n");
   print_tabs();

   emit("BEGIN_HELPER_");
   emit(element_statement->name);
   emit("();\n");

//   print_compound_statement(element_statement->body);
   if(size != 0) {
      ntabs++;
      print_statement_list(element_statement->body->statement_list);
      ntabs--;
   }
   print_tabs();
   emit("END_HELPER_");
   emit(element_statement->name);
   emit("();");
}

static void
print_while_statement(struct ast_while_statement *while_statement)
{
   print_tabs();
   emit("while (");
   print_expression(while_statement->condition);
   emit(")\n");

   print_compound_statement(while_statement->body);
   emit("\n");
}

static void
print_translation_unit(struct ast_translation_unit *translation_unit)
{
   print_statement_list(translation_unit->statement_list);
}

void
print_program(void *node)
{
    FILE *fp;
    source_main.p = malloc(1);
    source_main.p[0] = '\0';
    source_main.size = 1;
    source.p = malloc(1);
    source.p[0] = '\0';
    source.size = 1;
//   library = sdsempty();
//   source = sdsempty();
//   source_main = sdsempty();

//   library = malloc(sizeof(5000)*sizeof(char));
//   strcpy(library, "");

//   source = malloc(sizeof(5000)*sizeof(char));
//   source = strcpy(source, "");

//   source_main = malloc(sizeof(5000)*sizeof(char));
//   source_main = strcpy(source_main, "");

   print_translation_unit(node);

   fp  = fopen ("tmp-rand456456.c", "w");
   for (int i = 0; i< source.size-1; i++) fputc(source.p[i], fp);
   for (int i = 0; i< source_main.size-1; i++) fputc(source_main.p[i], fp);
   fclose (fp);

//   source[source_index]='\0';
//   source_main[source_main_index]='\0';
   
   /*
   printf("==>%d\n", source_main_index);
   for(int j=0;j<source_main_index;j++) {
      printf("-->%c\n", source_main[j]);
   }
   */

   /*
   printf("--------------------\n");
   printf("%s\n", source);
   printf("--------------------\n");
   printf("int main() {\n");
   printf("%s", source_main);
   printf("\treturn 0;\n");
   printf("}\n");
   */
   free(source_main.p);
   free(source.p);

}

void
print_node(struct ast_node *node)
{
   int tag = node->tag;
   void *nodep = node;

   switch (tag) {
      case AST_NODE:
         fprintf(stderr, "Request to print generic AST node.\n");
         exit(EXIT_FAILURE);

      case AST_FUNCTION:
         print_function(nodep);
         break;

      case AST_DECLARATION:
         print_declaration(nodep);
         break;

      case AST_EXPRESSION:
         print_expression(nodep);
         emit(";");
         break;

      case AST_STATEMENT_LIST:
         print_statement_list(nodep);
         break;

      case AST_COMPOUND_STATEMENT:
         print_compound_statement(nodep);
         break;

      case AST_SELECTION_STATEMENT:
         print_selection_statement(nodep);
         break;

      case AST_WHILE_STATEMENT:
         print_while_statement(nodep);
         break;

      case AST_PRINT_STATEMENT:
         print_print_statement(nodep);
         break;

      case AST_RETURN_STATEMENT:
         print_return_statement(nodep);
         break;
         
      case AST_ELEMENT_STATEMENT:
         print_element_statement(nodep);
         break;

      case AST_ELEMENT_ITEM:
         // skip
      break;

      default:
         fprintf(stderr, "Request to print unknown node type: %d\n", tag);
   }
}
