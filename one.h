#ifndef ONE_H
#define ONE_H

#include <stdio.h>
// #include <std.h>
#include "parser.tab.h"
#include "ast.h"

void set_input_string(const char *);
void end_lexical_scan(void); // in lexer.l
int parse_string(const char *);

#endif /* ONE_H */
