#ifndef _TESTING_H
#define _TESTING_H
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Tokenizer.h"
#include "Token.h"


typedef enum  {
  LONG_MEM,
  SHORT_MEM,
}OperandType;

typedef struct OperandInfo OperandInfo;
struct OperandInfo{
  OperandType type;
  int baseOpcode;
  int value;
};

int assemble(char *assemblyName, char **memoryToWriteCode);


#endif // _TESTING_H
