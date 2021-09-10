%{
#include <stdio.h>

char *getlogin();
%}

%option noyywrap

%%
username    printf( "%s", getlogin() );

%%

