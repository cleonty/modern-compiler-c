%{
  #include <stdio.h>
  #include <math.h>
%}

%option noyywrap

DIGIT [0-9]
ID    [a-z][a-z0-9]*

%%

{DIGIT}+                             { printf ("An integer: %s (%d)\n", yytext, atoi(yytext)); }

{DIGIT}+"."{DIGIT}*                  { printf ("A float: %s (%g)\n", yytext, atof(yytext)); }

if|then|begin|end|procedure|function { printf ("A Keyword: %s\n", yytext); }

{ID}                                 { printf ("An identifier: %s\n", yytext);}

"+"|"-"|"*"|"/"                       { printf ("An operator: %s\n", yytext);}

"{"[^}\n]*"}"                         { printf ("A comment: %s\n", yytext);}

[ \t\n]+                              { printf ("Whitespace\n"); }

.                                    { printf ("An unknown character: '%s'\n", yytext);}

%%

int main(int argc, char *argv[]) {
  if (argc > 1) {
    yyin = fopen(argv[1], "r");
    if (!yyin) {
      perror("failed to open file");
      return 1;
    }
  } else {
    yyin = stdin;
  }
  yylex();
  return 0;
}