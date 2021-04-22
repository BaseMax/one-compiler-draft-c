#include "one.h"

extern FILE *yyin;

void
set_input_string(const char* in) {
  yy_scan_string(in);
}

int
parse_string(const char* in) {
  set_input_string(in);
  int rv = yyparse();
  end_lexical_scan();
  return rv;
}

int
main(int argc, char *argv[])
{
    if(argc == 1) {
        // set_input_string("main{}");
        yyparse();
        // end_lexical_scan();
    }
    else {
        FILE *pt = fopen(argv[1], "r");
        if(!pt) {
            printf("Bad Input.No exist file!\n");
            return -1;
        }
        yyin = pt;
        do
        {
            yyparse();
        } while (!feof(yyin));      
    }

    return 0;
}
