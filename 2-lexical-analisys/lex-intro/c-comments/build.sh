#!/bin/sh

flex comments.lex && gcc -DYY_MAIN -o comments.exe lex.yy.c
