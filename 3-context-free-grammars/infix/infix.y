 /* Reverse polish notation calculator.  */

%{
  #define YYDEBUG 1
  #define YYSTYPE double
  #include <stdio.h>
  #include <ctype.h>
  #include <math.h>
  #include <stdlib.h>
  #include <string.h>
  int yylex (void);
  void yyerror (char const *);
%}

%token NUM
%left '-' '+'
%left '*' '/'
%left NEG
%right '^'

%% /* Grammar rules and actions follow.  */
input:    /* empty */
        | input line
;

line:     '\n'
        | exp '\n'      { printf ("\t%.10g\n", $1); }
        | error '\n'    { yyerrok; }
;

exp:      NUM               { $$ = $1;           }
        | exp '+' exp       { $$ = $1 + $3;      }
        | exp '-' exp       { $$ = $1 - $3;      }
        | exp '*' exp       { $$ = $1 * $3;      }
        | exp '/' exp       { $$ = $1 / $3;      }
        | '-' exp %prec NEG { $$ = -$2;      }
        | exp '^' exp       { $$ = pow ($1, $3); }
        | '(' exp ')'       { $$ = $2;          }
;
%%

  /* The lexical analyzer returns a double floating point
   number on the stack and the token NUM, or the numeric code
   of the character read if not a number.  It skips all blanks
   and tabs, and returns 0 for end-of-input.  */

int
yylex (void)
{
  int c;

  /* Skip white space.  */
  while ((c = getchar ()) == ' ' || c == '\t')
    ;
  /* Process numbers.  */
  if (c == '.' || isdigit (c)) {
      ungetc (c, stdin);
      scanf ("%lf", &yylval);
      return NUM;
  }
  /* Return end-of-input.  */
  if (c == EOF)
    return 0;
  /* Return a single char.  */
  return c;
}

int main (int argc, char *argv[]) {
  if (argc > 1 && 0 == strcmp(argv[1], "debug")) {
    yydebug = 1;
  }
  return yyparse ();
}
 
/* Called by yyparse on error.  */
void yyerror (char const *s) {
  fprintf (stderr, "error: %s\n", s);
}
