#ifndef _TESTING_H
#define _TESTING_H
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Tokenizer.h"
#include "Token.h"
/*
typedef char *(*FuncPtr)(Tokenizer *tokenizer, char *codeMem);
typedef struct operandInfo operandInfo;
struct operandInfo {
  int value;
};
*/

//int byteOperand(Tokenizer *tokenizer,char *codeMem);
//int byteOperand(Tokenizer *tokenizer,operandInfo operandInfo);
//int ADDByte(char *instruct,uint8_t buffer[]);
//int hexaOrDecimal(char *symbol);
int assemble(char *assemblyName, char **memoryToWriteCode);


#endif // _TESTING_H
