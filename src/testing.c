#include "testing.h"
#include <string.h>
#include <stdio.h>
#include "Tokenizer.h"
#include "Token.h"
#include "error.h"
#include "CException.h"
#include "touppercase.h"

void handleNEXTOperandMain(Tokenizer *tokenizedr,OperandInfo *operandInfo){
    Token *token = getToken(tokenizer);

    if(token->type != TOKEN_INTEGER_TYPE)
    Throw(NOT_VALID_OPERAND;

    info->value = ((IntegerToken *)token->value);
    if(info->value>0xff)
    info->type = LONG_MEM;
    else
    info->type = SHORT_MEM;
}


void  handleNEXTOperandMain(Tokenizer *tokenizedr,OperandInfo *operandInfo){
    Token *token = getToken(tokenizer);

    if(token->type != TOKEN_OPERATOR_TYPE)
    Throw(NOT_VALID_OPERATOR);
    opToken = (OperatorToken *)token;
    if((strcmp("$",opToken->str)==0)||(strcmp(" ",opToken->str)==0))
    handleLongShortMem(tokenizedr,&OperandInfo);
  }

void displayOpcode(char **memoryToWriteCode,OperandInfo *operandInfo){
  uint8_t *code = *memoryToWriteCode;
  switch (operandInfo->type) {
    case LONG_MEM:
    code[0] = OperandInfo->baseOpcode + 0xc0;
    code[1] = (OperandInfo->value >> 8 )+ 0xff;
    code[2] = OperandInfo->value & 0xff;
    *memoryToWriteCode +=3;
    break;
    case SHORT_MEM:
    code[0] = OperandInfo->baseOpcode + 0xc0;
    code[2] = OperandInfo->value & 0xff;
    *memoryToWriteCode +=2;
    break;

    default:
    Throw(ERR_SYNTAX)
  }

}


int assemble(char *assemblyName, char **memoryToWriteCode){
  Tokenizer tokenizer = initTokenizer(assemblyName);
  IdentifierToken *idToken;
  OperatorToken *opToken;
  OperandInfo operandinfo;

  if(token->type != TOKEN_IDENTIFIER_TYPE)
    Throw(NOT_VALID_INSTRUCTION);
  idtoken = (IdentifierToken *)token;
  token   = getToken(tokenizer);
  if(token->type != TOKEN_IDENTIFIER_TYPE)
  Throw(NOT_VALID_INSTRUCTION);
//idtoken = (IdentifierToken *)token;
  opToken = (OperatorToken *)getToken(token);
  if(opToken->type != TOKEN_OPERATOR_TYPE && (strcmp(",",optoken->str )==0))
  Throw(NOT_VALID_OPERATOR);
  handleNEXTOperandMain(tokenizedr,&operandInfo);

  printf(" sadsadsad");
  displayOpcode(memoryToWriteCode,operandInfo);

}
