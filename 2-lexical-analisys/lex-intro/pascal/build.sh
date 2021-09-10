#!/bin/sh

flex pascal.lex && gcc -o pascal.exe lex.yy.c && echo 123 + 123.456 begin hello end { comment }| ./pascal.exe
