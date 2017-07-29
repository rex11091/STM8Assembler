#include "testing.h"
#include <string.h>
#include <stdio.h>
#include "Tokenizer.h"
#include "Token.h"
#include "error.h"
#include "CException.h"
#include "touppercase.h"

void handleLongShortMem(Tokenizer *tokenizer,OperandInfo *operandInfo){
    Token *token = getToken(tokenizer);
    if(token->type == TOKEN_INTEGER_TYPE){
    operandInfo->value = ((IntegerToken *)token)->value;
    if(operandInfo->value > 0xff){
    operandInfo->type = LONG_MEM;
    }
    else{
    operandInfo->type = SHORT_MEM;
    }
    }
    else
   Throw(NOT_VALID_OPERAND);

}


void  handleNEXTOperandMain(Tokenizer *tokenizer,OperandInfo *operandInfo){
    OperatorToken *opToken;
    Token *token = getToken(tokenizer);
    if(token->type == TOKEN_OPERATOR_TYPE)
    {
    opToken = (OperatorToken *)token;
    if((strcmp("$",opToken->str)==0)||(strcmp(" ",opToken->str)==0))
    handleLongShortMem(tokenizer,&operandInfo);
    else
    Throw(NOT_VALID_OPERATOR);
    }
    else
    Throw(NOT_VALID_OPERATOR);
  }

void displayOpcode(char **memoryToWriteCode,OperandInfo *operandInfo){
  uint8_t *code = *memoryToWriteCode;
  switch (operandInfo->type) {
    case LONG_MEM:
    code[0] = operandInfo->baseOpcode + 0xc0;
    code[1] = (operandInfo->value >> 8 )+ 0xff;
    code[2] = operandInfo->value & 0xff;
    *memoryToWriteCode +=3;
    break;
    case SHORT_MEM:
    code[0] = operandInfo->baseOpcode + 0xc0;
    code[2] = operandInfo->value & 0xff;
    *memoryToWriteCode +=2;
    break;

    default:
    Throw(ERR_SYNTAX);
  }

}

/*this function is get the 1st 3 token to identify them
  such as ADD A, ADC A, SUB A,
*/
int assemble(char *assemblyName, char **memoryToWriteCode){
  Tokenizer *tokenizer = initTokenizer(assemblyName);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  OperatorToken *opToken;
  OperandInfo operandInfo;
  //1st token
  if(token->type == TOKEN_IDENTIFIER_TYPE)
  idToken = (IdentifierToken *)token;
  else
  Throw(NOT_VALID_INSTRUCTION);
  //2nd token
  token   = getToken(tokenizer);
  if(token->type == TOKEN_IDENTIFIER_TYPE)
  idToken = (IdentifierToken *)token;
  else
  Throw(NOT_VALID_INSTRUCTION);
  //3rd token
  opToken = (OperatorToken *)getToken(tokenizer);
  if(opToken->type == TOKEN_OPERATOR_TYPE && (strcmp(",",opToken->str )==0))
  {
  handleNEXTOperandMain(tokenizer,&operandInfo);
  displayOpcode(memoryToWriteCode,&operandInfo);
  }
  else
  Throw(NOT_VALID_OPERATOR);
  //handleNEXTOperandMain(tokenizer,OperandInfo *operandInfo)



}
