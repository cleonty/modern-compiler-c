%{
  #include <stdio.h>
  #include <stdlib.h>
  #include <strings.h>
  #include <math.h>  /* For math functions, cos(), sin(), etc.  */
  #include <ctype.h>
  #include <stdbool.h>
  #include "calc.h"  /* Contains definition of `symrec'.  */
  int yylex (void);
  void yyerror (char const *);
%}

%union {
  double    val;   /* For returning numbers.  */
  symrec  *tptr;   /* For returning symbol-table pointers.  */
}

%token <val>  NUM        /* Simple double precision number.  */
%token <tptr> VAR FNCT   /* Variable and Function.  */
%type  <val>  exp

%right '='
%left '-' '+'
%left '*' '/'
%left NEG ADD     /* negation--unary minus and plus */
%right '^'    /* exponentiation */
%% /* The grammar follows.  */

input:   /* empty */
        | input line
;
line:
          '\n'
        | exp '\n'   { printf ("\t%.10g\n", $1); }
        | error '\n' { yyerrok;                  }
;
exp:      NUM                { $$ = $1;                         }
        | VAR                { if ($1->value.initialized) $$ = $1->value.var; else { yyerror("unitialized var"); YYERROR; }  }
        | VAR '=' exp        { $$ = $3; $1->value.var = $3; $1->value.initialized = true; }
        | FNCT '(' exp ')'   { $$ = (*($1->value.fnctptr))($3); }
        | exp '+' exp        { $$ = $1 + $3;                    }
        | exp '-' exp        { $$ = $1 - $3;                    }
        | exp '*' exp        { $$ = $1 * $3;                    }
        | exp '/' exp        { $$ = $1 / $3;                    }
        | '-' exp  %prec NEG { $$ = -$2;                        }
        | '+' exp  %prec ADD { $$ = +$2;                        }
        | exp '^' exp        { $$ = pow ($1, $3);               }
        | '(' exp ')'        { $$ = $2;                         }
;
/* End of grammar.  */
%%

/* Called by yyparse on error.  */
void
yyerror (char const *s)
{
  printf ("%s\n", s);
}
struct init
{
  char const *fname;
  double (*fnct) (double);
};
struct init const arith_fncts[] =
{
  "sin",   sin,
  "cos",   cos,
  "atan",  atan,
  "ln",    log,
  "exp",   exp,
  "sqrt",  sqrt,
  "abs",   fabs,
  "ceil",  ceil,
  "floor", floor,
  0, 0
};

struct init_constants {
  const char *name;
  double value;
};

struct init_constants const constants[] =
{
  "pi",   M_PI,
  "e",    M_E,
  0, 0
};
/* The symbol table: a chain of `struct symrec'.  */
symrec *sym_table;
/* Put arithmetic functions in table.  */
void
init_table (void)
{
  int i;
  symrec *ptr;
  for (i = 0; arith_fncts[i].fname != 0; i++)
    {
      ptr = putsym (arith_fncts[i].fname, FNCT);
      ptr->value.fnctptr = arith_fncts[i].fnct;
    }
  for (i = 0; constants[i].name != 0; i++)
    {
      ptr = putsym (constants[i].name, VAR);
      ptr->value.var = constants[i].value;
    }
}
int
main (void)
{
  init_table ();
  return yyparse ();
}

symrec *
putsym (char const *sym_name, int sym_type)
{
  symrec *ptr;
  ptr = (symrec *) malloc (sizeof (symrec));
  ptr->name = (char *) malloc (strlen (sym_name) + 1);
  strcpy (ptr->name,sym_name);
  ptr->type = sym_type;
  ptr->value.var = 0; /* Set value to 0 even if fctn.  */
  ptr->next = (struct symrec *)sym_table;
  sym_table = ptr;
  return ptr;
}

symrec *
getsym (char const *sym_name)
{
  symrec *ptr;
  for (ptr = sym_table; ptr != (symrec *) 0;
       ptr = (symrec *)ptr->next)
    if (strcmp (ptr->name,sym_name) == 0)
      return ptr;
  return 0;
}

int
yylex (void)
{
  int c;

  /* Ignore white space, get first nonwhite character.  */
  while ((c = getchar ()) == ' ' || c == '\t');

  if (c == EOF)
    return 0;
  /* Char starts a number => parse the number.         */
  if (c == '.' || isdigit (c))
    {
      ungetc (c, stdin);
      scanf ("%lf", &yylval.val);
      return NUM;
    }
  /* Char starts an identifier => read the name.       */
  if (isalpha (c))
    {
      symrec *s;
      static char *symbuf = 0;
      static int length = 0;
      int i;
      /* Initially make the buffer long enough
         for a 40-character symbol name.  */
      if (length == 0)
        length = 40, symbuf = (char *)malloc (length + 1);

      i = 0;
      do
        {
          /* If buffer is full, make it bigger.        */
          if (i == length)
            {
              length *= 2;
              symbuf = (char *) realloc (symbuf, length + 1);
            }
          /* Add this character to the buffer.         */
          symbuf[i++] = c;
          /* Get another character.                    */
          c = getchar ();
        }
      while (isalnum (c));

      ungetc (c, stdin);
      symbuf[i] = '\0';
      s = getsym (symbuf);
      if (s == 0) {
        s = putsym (symbuf, VAR);
      }
      yylval.tptr = s;
      return s->type;
    }

  /* Any other character is a token by itself.        */
  return c;
}


  

