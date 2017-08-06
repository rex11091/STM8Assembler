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
}OperandType;

typedef struct OperandInfo OperandInfo;
struct OperandInfo{
  OperandType type;
  int baseOpcode;
  int value;
};
void handleLongShortMem(Tokenizer *tokenizer,OperandInfo *operandInfo);
int assemble(char *assemblyName, char **memoryToWriteCode);


#endif // _TESTING_H
