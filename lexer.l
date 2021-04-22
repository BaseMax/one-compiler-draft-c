%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parser.tab.h"
#include "ast.h"

//sds mystring;

struct charPtr
{
    size_t size;
    char *p;
};

struct charPtr mynewstring={.size = 0,.p=NULL};
 
%}

%x STRING COMMENT1 COMMENT2


LNUM	[0-9]+(_[0-9]+)*
DNUM	({LNUM}?"."{LNUM})|({LNUM}"."{LNUM}?)
EXPONENT_DNUM	(({LNUM}|{DNUM})[eE][+-]?{LNUM})
HNUM	"0x"[0-9a-fA-F]+(_[0-9a-fA-F]+)*
BNUM	"0b"[01]+(_[01]+)*
LABEL	[a-zA-Z_\x80-\xff][a-zA-Z0-9_\x80-\xff]*
WHITESPACE [ \n\r\t]+
TABS_AND_SPACES [ \t]*
TOKENS [;:,.|^&+-/*=%!~$<>?@]
ANY_CHAR [^]
NEWLINE ("\r"|"\n"|"\r\n")



%%



 /* math operators */
<INITIAL>"+"      { return OP_ADD;     }
<INITIAL>"-"      { return OP_SUB;     }
<INITIAL>"**"     { return OP_POW;     }
<INITIAL>"*"      { return OP_MUL;     }
<INITIAL>"/"      { return OP_DIV;     }
<INITIAL>"%"      { return OP_MOL;     }
<INITIAL>"^"      { return OP_SIGN;    }

 /* comparison operators */
<INITIAL>">"      { return OP_GT;      }
<INITIAL>"<"      { return OP_LT;      }
<INITIAL>"==="    { return OP_TEQ;     }
<INITIAL>"=="     { return OP_EQ;      }
<INITIAL>"!=="    { return OP_TNE;     }
<INITIAL>"!="     { return OP_NE;      }
<INITIAL>"<="     { return OP_LE;      }
<INITIAL>">="     { return OP_GE;      }

 /* assignment operator */
<INITIAL>"="      { return OP_ASSIGN;  }
<INITIAL>":"      { return OP_DOTDOT;  }
<INITIAL>"."      { return OP_DOT;  }
<INITIAL>".."      { return OP_DOTDOT;     }
<INITIAL>"..."      { return OP_DOTDOTDOT;  }

 /* statement terminator */
<INITIAL>";"      { return SEMICOLON;  }
<INITIAL>","      { return COLON;  }

 /* grouping operators */
<INITIAL>"{"      { return LBRACE;     }
<INITIAL>"}"      { return RBRACE;     }
<INITIAL>"["      { return LBRACKET;     }
<INITIAL>"]"      { return RBRACKET;     }
<INITIAL>"("      { return LPAREN;     }
<INITIAL>")"      { return RPAREN;     }
<INITIAL>"\""      {
   //mystring = sdsempty();
   mynewstring.p = malloc(1); 
   mynewstring.p[0] = '\0'; 
   mynewstring.size=1;
   // mystring = sdsnew("Hello World!");
   BEGIN(STRING);
}
<STRING>"\"" {
   //yylval.string_const = sdsdup(mystring);
   yylval.string_const = malloc(mynewstring.size);
   strcpy(yylval.string_const,mynewstring.p);
   free(mynewstring.p);
   //sdsfree(mystring);
   BEGIN(INITIAL);
   return STRING_CONSTANT;
}
<STRING>. {
   //mystring = sdscat(mystring, yytext);
   int length=0;
   while(yytext[length])length++;
   mynewstring.size = mynewstring.size + length;
   mynewstring.p = realloc(mynewstring.p,mynewstring.size);
   strcat(mynewstring.p, yytext);
   
}
<STRING>\n {
   //mystring = sdscat(mystring, "\\n");
   mynewstring.size = mynewstring.size + 2;
   mynewstring.p = realloc(mynewstring.p,mynewstring.size);
   strcat(mynewstring.p, "\\n");
}
<STRING>\t {
   //mystring = sdscat(mystring, "\\t");
   mynewstring.size = mynewstring.size + 2;
   mynewstring.p = realloc(mynewstring.p,mynewstring.size);
   strcat(mynewstring.p, "\\t");
}

<INITIAL>"/*"                    BEGIN(COMMENT1);
<COMMENT1>.             {}
<COMMENT1>\n            {}
<COMMENT1>"*/"          {BEGIN(INITIAL);}

<INITIAL>"//"                    BEGIN(COMMENT2);
<COMMENT2>.             {}
<COMMENT2>\n            {BEGIN(INITIAL);}

 /* data type keywords */
<INITIAL>"i8"    { return KW_INT8;     }
<INITIAL>"i16"    { return KW_INT16;     }
<INITIAL>"i32"    { return KW_INT32;     }
<INITIAL>"i64"    { return KW_INT64;     }
<INITIAL>"int"    { return KW_INT32;     }

<INITIAL>"u8"    { return KW_UINT8;     }
<INITIAL>"u16"    { return KW_UINT16;     }
<INITIAL>"u32"    { return KW_UINT32;     }
<INITIAL>"u64"    { return KW_UINT64;     }
<INITIAL>"uint"    { return KW_UINT32;     }

<INITIAL>"f32"  { return KW_FLOAT32;   }
<INITIAL>"f64"  { return KW_FLOAT64;   }
<INITIAL>"f128"  { return KW_FLOAT128;   }
<INITIAL>"float"  { return KW_FLOAT32;   }

<INITIAL>"null"  { return KW_NULL;   }

<INITIAL>"void"  { return KW_VOID;   }
<INITIAL>"bool"  { return KW_BOOL;   }
<INITIAL>"true"  { return KW_TRUE;   }
<INITIAL>"false"  { return KW_FALSE;   }

<INITIAL>"char"  { return KW_CHAR;   }
<INITIAL>"string"  { return KW_STRING;   }

 /* control flow keywords */
<INITIAL>"fn"    { return KW_FN;     }
<INITIAL>"if"     { return KW_IF;      }
<INITIAL>"else"   { return KW_ELSE;    }
<INITIAL>"while"  { return KW_WHILE;   }
<INITIAL>"for"    { return KW_WHILE;   }
<INITIAL>"ret" { return KW_RETURN; }

<INITIAL>"*window" { return KW_WINDOW; }
<INITIAL>"*box" { return KW_WINDOW_BOX; }
<INITIAL>"*label" { return KW_WINDOW_LABEL; }
<INITIAL>"*field" { return KW_WINDOW_FIELD; }
<INITIAL>"*button" { return KW_WINDOW_BUTTON; }

<INITIAL>"__" { return KW_PRINTLN; }
<INITIAL>"_" { return KW_PRINT; }

 /* regular expression for identifier names */
<INITIAL>[_a-zA-Z][_a-zA-Z0-9]* {
   yylval.identifier = strdup(yytext);
   return IDENTIFIER;
}

 /* regular expression for integer constants */
<INITIAL>[0-9]+ {
   yylval.int_const = atoi(yytext);
   return INT_CONSTANT;
}

<INITIAL>[0-9]+\.[0-9]+ {
   yylval.float_const = (float) atof(yytext);
   return FLOAT_CONSTANT;
}

 /* ignore whitespace */
<INITIAL>[ \r\t]+ { }

 /* ignore newlines */
<INITIAL>\n       { }

 /* ignore unknown characters */
<INITIAL>.        {
   printf("==>%s\n", yytext);
	yyerror("unknown character(s)\n");
}

%%

void
end_lexical_scan(void) {
  yy_delete_buffer(YY_CURRENT_BUFFER);
}
