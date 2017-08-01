#include "testing.h"
#include <string.h>
#include <stdio.h>
#include "Tokenizer.h"
#include "Token.h"
#include "error.h"
#include "CException.h"
#include "touppercase.h"


/*
void handleIndexXandY(Tokenizer *tokenizer,OperandInfo *operandInfo){
    IdentifierToken *idToken;
    OperatorToken *opToken;
    Token *token = getToken(tokenizer);
    if(token->type == TOKEN_IDENTIFIER_TYPE)
    {
      idToken = (IdentifierToken *)token;
        if(strcmp(idToken->str,"X")==0)
          operandInfo->type = IndexX;
        else if(strcmp(idToken->str,"Y")==0)
          operandInfo->type = IndexY;
        else
          Throw(NOT_VALID_INSTRUCTION);
    }
    else
    Throw(NOT_VALID_INSTRUCTION);

    opToken = (OperatorToken *)getToken(tokenizer);
    if(opToken->type != TOKEN_OPERATOR_TYPE || (strcmp(")",opToken->str )!=0))
    Throw(NOT_VALID_OPERATOR);
}
*/




void handleShortLongPtrorWithIndex(Tokenizer *tokenizer,OperandInfo *operandInfo){}
/*
-start with handleShortLongoff
-then x,y,sp from function getShortlongoffIndexX_Y_SP
-use convertShortoffToLongoff function if needed
*/
void getShortlongoffIndexX_Y_SP(Tokenizer *tokenizer,OperandInfo *operandInfo){
  IdentifierToken *idToken;
  OperatorToken   *opToken;
  opToken = (OperatorToken *)getToken(tokenizer);
    if(opToken->type == TOKEN_OPERATOR_TYPE && (strcmp(opToken->str,",")==0)){
  idToken = (IdentifierToken *)getToken(tokenizer);
    if(idToken->type == TOKEN_IDENTIFIER_TYPE){
      if(strcmp(idToken->str,"X")==0)
        operandInfo->type = SHORTOFF_X;
      else if(strcmp(idToken->str,"Y")==0)
        operandInfo->type = SHORTOFF_Y;
      else if(strcmp(idToken->str,"SP")==0)
        operandInfo->type = SHORTOFF_SP;
      else
        Throw(NOT_VALID_OPERAND);
    }
  opToken = (OperatorToken *)getToken(tokenizer);
    if(opToken->type !=TOKEN_OPERATOR_TYPE ||(strcmp(opToken->str,")") !=0))
      Throw(NOT_VALID_OPERATOR);
  }else
  Throw(NOT_VALID_OPERATOR);
}

void convertShortoffToLongoff(Tokenizer *tokenizer,OperandInfo *operandInfo){
  if(operandInfo->type == SHORTOFF_X)
    operandInfo->type = LONGOFF_X;
  else if(operandInfo->type == SHORTOFF_Y)
    operandInfo->type = LONGOFF_Y;
  else if(operandInfo->type == SHORTOFF_SP)
    Throw(NOT_VALID_OPREANDINFO_TYPE);
  else
    Throw(NOT_VALID_OPREANDINFO_TYPE);
}

void handleShortLongoff(Tokenizer *tokenizer,OperandInfo *operandInfo){
  OperatorToken *opToken;
  IntegerToken *intToken;
  Token *token = getToken(tokenizer);
  if(token->type == TOKEN_INTEGER_TYPE)
  {
    operandInfo->value = ((IntegerToken *)token)->value;
    if(operandInfo->value < 0xff || operandInfo->value < 256){
      getShortlongoffIndexX_Y_SP(tokenizer,operandInfo);
    }
    else if(operandInfo->value < 0xffff || operandInfo->value < 65535){
      getShortlongoffIndexX_Y_SP(tokenizer,operandInfo);
      convertShortoffToLongoff(tokenizer,operandInfo);
    }
  }
}


void handleByte(Tokenizer *tokenizer,OperandInfo *operandInfo){
    OperatorToken *opToken;
    Token *token = getToken(tokenizer);
    if(token->type == TOKEN_OPERATOR_TYPE)
      opToken = (OperatorToken *)token;
      if(strcmp("$",opToken->str)==0){
        token = getToken(tokenizer);
          if(token->type == TOKEN_INTEGER_TYPE){
            operandInfo->value = ((IntegerToken *)token)->value;
              if(operandInfo->value < 0xff || operandInfo->value < 256)
                operandInfo->type = BYTE; // 0
              else
                Throw(NOT_VALID_OPERAND);}
          else
            Throw(NOT_VALID_OPERATOR);
          }
      else
    Throw(NOT_VALID_OPERATOR);
}

void handleLongShortMem(Tokenizer *tokenizer,OperandInfo *operandInfo){
    Token *token = getToken(tokenizer);
    if(token->type == TOKEN_INTEGER_TYPE)
    {
      operandInfo->value = ((IntegerToken *)token)->value;
      if(operandInfo->value < 0xff || operandInfo->value < 256)
      operandInfo->type = SHORT_MEM; // 1
      else if(operandInfo->value < 0xffff || operandInfo->value < 65535)
      operandInfo->type = LONG_MEM; // 0
      else{
        Throw(NOT_VALID_OPERAND);
          }
    }
    else
    Throw(NOT_VALID_OPERAND);
}

void handleNEXTOperandMain(Tokenizer *tokenizer,OperandInfo *operandInfo){
    OperatorToken *opToken;
    Token *token = getToken(tokenizer);
    if(token->type == TOKEN_OPERATOR_TYPE)
    {
      opToken = (OperatorToken *)token;
      if(strcmp("$",opToken->str)==0)
        handleLongShortMem(tokenizer,operandInfo);
      else if((strcmp("#",opToken->str)==0))
        handleByte(tokenizer,operandInfo);
      else if((strcmp("(",opToken->str)==0)){}
        //handleIndexXandY(tokenizer,operandInfo);
      else
      Throw(NOT_VALID_OPERATOR);
    }
    else
    Throw(NOT_VALID_OPERATOR);
  }

void handleINExt_2_OperandMain(Tokenizer *tokenizer,OperandInfo *operandInfo){
  IdentifierToken *idToken;
  OperatorToken *opToken;
  Token *token = getToken(tokenizer);
    if(token->type == TOKEN_IDENTIFIER_TYPE)
        {
          idToken = (IdentifierToken *)token;
          if(strcmp(idToken->str,"X")==0)
            operandInfo->type = IndexX;
          else if(strcmp(idToken->str,"Y")==0)
            operandInfo->type = IndexY;
          else
            Throw(NOT_VALID_INSTRUCTION);
          opToken = (OperatorToken *)getToken(tokenizer);
          if(opToken->type != TOKEN_OPERATOR_TYPE || (strcmp(")",opToken->str )!=0))
            Throw(NOT_VALID_OPERATOR);
        }
    else if(token->type == TOKEN_OPERATOR_TYPE)
        {
        opToken = (OperatorToken *)token;
        if(strcmp(opToken->str,"$")==0)
        handleShortLongoff(tokenizer,operandInfo);
        else if(strcmp(opToken->str,"[")==0)
        handleShortLongPtrorWithIndex(tokenizer,operandInfo);
        else
        Throw(NOT_VALID_OPERATOR);
        }
    else
      Throw(ERR_SYNTAX);
}

void displayOpcode(char **memoryToWriteCode,OperandInfo *operandInfo){
  uint8_t *code = *memoryToWriteCode;
  printf("%d\n",operandInfo->type);
  switch (operandInfo->type) {
    case LONG_MEM:
    code[0] = operandInfo->baseOpcode + 0xC0;
    code[1] = (operandInfo->value >> 8 ) & 0xff;
    code[2] = operandInfo->value & 0xff;
    *memoryToWriteCode +=3;
    break;
    case SHORT_MEM:
    code[0] = operandInfo->baseOpcode + 0xB0;
    code[1] = operandInfo->value & 0xff;
    *memoryToWriteCode +=2;
    break;

    case BYTE:
    code[0] = operandInfo->baseOpcode + 0xA0;
    code[1] = operandInfo->value & 0xff;
    *memoryToWriteCode +=2;
    break;

    case IndexX:
    code[0] = operandInfo->baseOpcode + 0xF0;
    *memoryToWriteCode +=1;
    break;

    case IndexY:
    code[0] = 0x90;
    code[1] = operandInfo->baseOpcode + 0xF0;
    *memoryToWriteCode +=2;
    break;

    case SHORTOFF_X:
    code[0] = operandInfo->baseOpcode + 0xE0;
    code[1] = operandInfo->value & 0xff;
    *memoryToWriteCode +=2;
    break;

    case SHORTOFF_Y:
    code[0] = 0x90;
    code[1] = operandInfo->baseOpcode + 0xE0;
    code[2] = operandInfo->value & 0xff;
    *memoryToWriteCode +=3;
    break;

    case LONGOFF_X:
    code[0] = operandInfo->baseOpcode + 0xD0;
    code[1] = (operandInfo->value >> 8 ) & 0xff;
    code[2] = operandInfo->value & 0xff;
    *memoryToWriteCode +=3;
    break;

    case LONGOFF_Y:
    code[0] = 0x90;
    code[1] = operandInfo->baseOpcode + 0xD0;
    code[2] = (operandInfo->value >> 8 ) & 0xff;
    code[3] = operandInfo->value & 0xff;
    *memoryToWriteCode +=4;
    break;

    case SHORTOFF_SP:
    code[0] = operandInfo->baseOpcode + 0x10;
    code[0] = operandInfo->value & 0xff;
    *memoryToWriteCode +=1;
    break;
    default:
    Throw(ERR_SYNTAX);
  }

}

/*
void handleIndexXandY(Tokenizer *tokenizer,OperandInfo *operandInfo){
    IdentifierToken *idToken;
    OperatorToken *opToken;
    Token *token = getToken(tokenizer);
    if(token->type == TOKEN_IDENTIFIER_TYPE){
      idToken = (IdentifierToken *)token;
        if(strcmp(idToken->str,"X")==0)
          operandInfo->type = IndexX;
        else if(strcmp(idToken->str,"Y")==0)
          operandInfo->type = IndexY;
        else
          Throw(NOT_VALID_INSTRUCTION);
    opToken = (OperatorToken *)getToken(tokenizer);
    if(opToken->type != TOKEN_OPERATOR_TYPE || (strcmp(")",opToken->str )!=0))
    Throw(NOT_VALID_OPERATOR);
    }
    else if(Token->type == TOKEN_OPERATOR_TYPE)

}
*/

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
  operandInfo.baseOpcode=0x09;
  displayOpcode(memoryToWriteCode,&operandInfo);
  }
  else
  Throw(NOT_VALID_OPERATOR);
  //handleNEXTOperandMain(tokenizer,OperandInfo *operandInfo)



}
