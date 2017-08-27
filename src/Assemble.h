#ifndef _TESTING_H
#define _TESTING_H
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Tokenizer.h"
#include "Token.h"

typedef enum{
  LONG_MEM,
  SHORT_MEM,
  BYTE,
  IndexX,
  IndexY,
  SHORTOFF_X,
  SHORTOFF_Y,
  LONGOFF_X,
  LONGOFF_Y,
  SHORTOFF_SP,
  SHORTPTR,
  LONGPTR,
  SHORTPTR_X,
  SHORTPTR_Y,
  LONGPTR_X,
  Long,
  Short,
  Inherent,
  DirectX,
  DirectY,
  YLONG_MEM,
  YSHORT_MEM,
  YSHORTPTR,
  WORD,
  YWORD,
}OperandType;
typedef struct OperandInfo OperandInfo;
struct OperandInfo{
  OperandType type;
  int baseOpcode;
  int value;
};
typedef struct CheckIdentifier CheckIdentifier;
struct CheckIdentifier{
  char name;
  char* (*execute)();    // a function
};

void convertShortLongPtrType(Tokenizer *tokenizer,OperandInfo *operandInfo);
void getLongShortType(Tokenizer *tokenizer,OperandInfo *operandInfo);
void getCloseBracketSymbol(Tokenizer *tokenizer,OperandInfo *operandInfo);
void gettokenDotWBracket(Tokenizer *tokenizer,OperandInfo *operandInfo);
void handleShortLongPtr(Tokenizer *tokenizer,OperandInfo *operandInfo);
void handleShortLongPtrorWithIndex(Tokenizer *tokenizer,OperandInfo *operandInfo);
void getShortlongoffIndexX_Y_SP(Tokenizer *tokenizer,OperandInfo *operandInfo);
void convertShortoffToLongoff(Tokenizer *tokenizer,OperandInfo *operandInfo);
void handleShortLongoff(Tokenizer *tokenizer,OperandInfo *operandInfo);
void handleByteOrWord(Tokenizer *tokenizer,OperandInfo *operandInfo);
void handleLongShortMem(Tokenizer *tokenizer,OperandInfo *operandInfo);
void handleNExt_2_OperandMain(Tokenizer *tokenizer,OperandInfo *operandInfo);
void handleNEXTOperandMain(Tokenizer *tokenizer,OperandInfo *operandInfo);
void displayOpcode(char **memoryToWriteCode,OperandInfo *operandInfo);
void identifyInstruction(char *instructionTocompare,OperandInfo *operandInfo);
int assemble(char *assemblyName, char **memoryToWriteCode);
int handleInherentInstruction(char *assemblyName, char **memoryToWriteCode);
int handleDirect_X_Y_index(char *assemblyName, char **memoryToWriteCode);
void CheckA_X_Y_index(Tokenizer *tokenizer,OperandInfo *operandInfo,char **memoryToWriteCode);
void getCommaSymbol(Tokenizer *tokenizer,OperandInfo *operandInfo);
void getA_X_Y_index(Tokenizer *tokenizer,OperandInfo *operandInfo);
void ConvertOperandTypeOfYindex(Tokenizer *tokenizer,OperandInfo *operandInfo);
#define isTokenMatchesString(token,str2cmp)  (strcmp(token,str2cmp )== 0)

#endif // _TESTING_H
