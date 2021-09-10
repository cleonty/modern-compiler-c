#!/bin/sh

flex linecount.lex && gcc -o linecount.exe lex.yy.c
