#ifndef _TESTING_H
#define _TESTING_H
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Tokenizer.h"
#include "Token.h"

typedef char *(*FuncPtr)(Tokenizer *tokenizer, char *codeMem);

int byteOperand(Tokenizer *tokenizer,char *codeMem);
int ADDByte(char *instruct,uint8_t buffer[]);
//char* assembler (Tokenizer *tokenizer);

//extern FuncPtr  SyntaxOperand[];

#endif // _TESTING_H
