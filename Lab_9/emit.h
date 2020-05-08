#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

#ifndef EMIT_H
#define EMIT_H

#include "ast.h"
#include "symtable.h"
#define WSIZE 4  // number of bytes in a word
#define LOGWSIZE 2  // number of shifts to get to WSIZE

char * genlabel();

void emitStrings(FILE *fp, ASTNode *p);
void emitGlobals(FILE *fp, ASTNode *p);
void emit(FILE *fp, char *label, char *command, char*comment);
void emitAST(ASTNode *p, FILE *fp);
void emitFunctionHead(ASTNode *p, FILE *fp);
void emitIf(ASTNode *p, FILE *fp);
#endif  // of EMIT.h