#!/bin/sh

flex username.lex && gcc -DYY_MAIN -o username.exe lex.yy.c
