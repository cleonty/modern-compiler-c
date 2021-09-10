%{
#include <string.h>
#include "util.h"
#include "tokens.h"
#include "errormsg.h"

int charPos=1;

int yywrap(void)
{
 charPos=1;
 return 1;
}


void adjust(void)
{
 EM_tokPos=charPos;
 charPos+=yyleng;
}

%}

%x comment

%%

"/*"         BEGIN(comment);

<comment>[^*\n]*        {adjust(); continue;}/* eat anything that's not a '*' */
<comment>"*"+[^*/\n]*   {adjust(); continue;} /* eat up '*'s not followed by '/'s */
<comment>\n             {adjust(); EM_newline(); continue;}
<comment>"*"+"/"        {adjust(); BEGIN(INITIAL); continue;}

" "	 {adjust(); continue;}
\n	 {adjust(); EM_newline(); continue;}
","	 {adjust(); return COMMA;}
for  	 {adjust(); return FOR;}
let  {adjust(); return LET;}
to  {adjust(); return TO;}
[0-9]+	 {adjust(); yylval.ival=atoi(yytext); return INT;}
.	 {adjust(); EM_error(EM_tokPos,"illegal token");}

%%


