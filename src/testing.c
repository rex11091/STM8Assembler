#include "testing.h"
#include <string.h>
#include <stdio.h>
#include "Tokenizer.h"
#include "Token.h"
#include "error.h"
#include "CException.h"
#include "touppercase.h"
#include "Exception.h"

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
        throwException(NOT_VALID_INSTRUCTION,                                   \
                       "Invalid operand, expecting a ',', but received '%s'\n", \
                        idToken->str);
    }
    opToken = (OperatorToken *)getToken(tokenizer);
    if(opToken->type != TOKEN_OPERATOR_TYPE || (strcmp(")",opToken->str )!=0))
    throwException(NOT_VALID_OPERATOR,                                     \
                   "Invalid operand, expecting a ',', but received '%s'\n", \
                    opToken->str);
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
        Throw(LIMIT_EXCEEDED);
          }
    }
    else
    Throw(NOT_VALID_OPERAND);
}*/

void getLongShortType(Tokenizer *tokenizer,OperandInfo *operandInfo){
    IntegerToken *intToken;
    intToken = (IntegerToken *)getToken(tokenizer);
    if(intToken->type == TOKEN_INTEGER_TYPE)
    {
      operandInfo->value = intToken->value;
      if(operandInfo->value <=0xff)
        operandInfo->type = Short; // 1
      else if(operandInfo->value <=0xffff)
        operandInfo->type = Long; // 0
      else{
        Throw(LIMIT_EXCEEDED);
          }
    }
    else
    Throw(NOT_VALID_OPERAND);
}

void getCloseBracketSymbol(Tokenizer *tokenizer,OperandInfo *operandInfo){
  OperatorToken   *opToken;
  opToken = (OperatorToken *)getToken(tokenizer);
  if(opToken->type !=TOKEN_OPERATOR_TYPE || (strcmp(opToken->str,")") !=0))
  Throw(NOT_VALID_OPERATOR);
  //  throwException(NOT_VALID_OPERATOR,                                 \
                 "Invalid operand, expecting a ')', but received '%s'\n", \
                  opToken->str);
}

void gettokenDotWBracket(Tokenizer *tokenizer,OperandInfo *operandInfo){
  OperatorToken   *opToken;
  IdentifierToken *idToken;

  opToken = (OperatorToken *)getToken(tokenizer);
    if(opToken->type ==TOKEN_OPERATOR_TYPE && (strcmp(opToken->str,".") ==0)){
  idToken = (IdentifierToken *)getToken(tokenizer);
    if(idToken->type ==TOKEN_IDENTIFIER_TYPE && (strcmp(idToken->str,"W") ==0)){
  opToken = (OperatorToken *)getToken(tokenizer);
    if(opToken->type !=TOKEN_OPERATOR_TYPE && (strcmp(opToken->str,"]") !=0)){
        Throw(NOT_VALID_OPERATOR);
      }
    }
    else
    Throw(NOT_VALID_IDENTIFIER);
    }
    else
    Throw(NOT_VALID_OPERATOR);
}

/*
 -----long/shortPtr-----
 *start with handleShortLongPtr
 *then determine either long or short through function getLongShortType
 *convert long/short to long/short pointer by function convertLongShortptrType;
 *get following operand by getCloseBracketSymbol
 ----long/shortPtr With index---
 *start with function handleShortLongPtr because have same content
 *convert the operandInfo.type in function handleShortLongPtr
 *get bracket from getCloseBracketSymbol
*/
void convertShortLongPtrType(Tokenizer *tokenizer,OperandInfo *operandInfo){
  if(operandInfo->type == Long)
    operandInfo->type = LONGPTR;
  else if(operandInfo->type == Short)
    operandInfo->type = SHORTPTR;
  else
   Throw(NOT_VALID_OPREANDINFO_TYPE);
}
void handleShortLongPtr(Tokenizer *tokenizer,OperandInfo *operandInfo){
  OperatorToken   *opToken;
  opToken = (OperatorToken *)getToken(tokenizer);
    if(opToken->type ==TOKEN_OPERATOR_TYPE && (strcmp(opToken->str,"$") ==0)){
      getLongShortType(tokenizer,operandInfo);
      convertShortLongPtrType(tokenizer,operandInfo);
      gettokenDotWBracket(tokenizer,operandInfo);
      }
    else
    Throw(NOT_VALID_OPERATOR);
}
void handleShortLongPtrorWithIndex(Tokenizer *tokenizer,OperandInfo *operandInfo){
    IdentifierToken *idToken;
    OperatorToken *opToken;
    handleShortLongPtr(tokenizer,operandInfo);
    opToken = (OperatorToken *)getToken(tokenizer);
      if(opToken->type ==TOKEN_OPERATOR_TYPE && (strcmp(opToken->str,",") ==0)){
        idToken = (IdentifierToken *)getToken(tokenizer);
          if(idToken->type ==TOKEN_IDENTIFIER_TYPE){
            if(strcmp(idToken->str,"X")==0){
              if(operandInfo->type == SHORTPTR)
                operandInfo->type = SHORTPTR_X;
              else if(operandInfo->type == LONGPTR)
                operandInfo->type = LONGPTR_X;
            }
            else if(strcmp(idToken->str,"Y")==0){
              if(operandInfo->type == SHORTPTR)
                operandInfo->type = SHORTPTR_Y;
              else if(operandInfo->type == LONGPTR)
                Throw(NOT_VALID_OPREANDINFO_TYPE);
            }
            else
              Throw(NOT_VALID_IDENTIFIER);
          }
          getCloseBracketSymbol(tokenizer,operandInfo);
      }
      else
      Throw(NOT_VALID_OPERATOR);
}
/*
-start with handleShortLongoff
-then x,y,sp from function getShortlongoffIndexX_Y_SP
-use convertShortoffToLongoff function if needed
-get CloseBracket from getCloseBracketSymbol
*/
void getShortlongoffIndexX_Y_SP(Tokenizer *tokenizer,OperandInfo *operandInfo){
  IdentifierToken *idToken;
  OperatorToken   *opToken;
  opToken = (OperatorToken *)getToken(tokenizer);
    if(opToken->type == TOKEN_OPERATOR_TYPE && (strcmp(opToken->str,",")==0)){
  idToken = (IdentifierToken *)getToken(tokenizer);
    if(idToken->type == TOKEN_IDENTIFIER_TYPE)
      if(strcmp(idToken->str,"X")==0)
        operandInfo->type = SHORTOFF_X;
      else if(strcmp(idToken->str,"Y")==0)
        operandInfo->type = SHORTOFF_Y;
      else if(strcmp(idToken->str,"SP")==0)
        operandInfo->type = SHORTOFF_SP;
      else
        Throw(NOT_VALID_IDENTIFIER);
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
    if(operandInfo->value <= 0xff){
      getShortlongoffIndexX_Y_SP(tokenizer,operandInfo);
      getCloseBracketSymbol(tokenizer,operandInfo);
    }
    else if(operandInfo->value <= 0xffff){
      getShortlongoffIndexX_Y_SP(tokenizer,operandInfo);
      convertShortoffToLongoff(tokenizer,operandInfo);
      getCloseBracketSymbol(tokenizer,operandInfo);
    }
    else
    Throw(LIMIT_EXCEEDED);
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
              if(operandInfo->value <= 0xff)
                operandInfo->type = BYTE; // 0
              else
                Throw(LIMIT_EXCEEDED);
              }
          else
            Throw(NOT_VALID_OPERATOR);
          }
      else
    Throw(NOT_VALID_OPERATOR);
}

void handleLongShortMem(Tokenizer *tokenizer,OperandInfo *operandInfo){
  getLongShortType(tokenizer,operandInfo);
       if(operandInfo->type == Long)
         operandInfo->type = LONG_MEM;
       else if(operandInfo->type == Short)
         operandInfo->type = SHORT_MEM;
       else
        Throw(NOT_VALID_OPREANDINFO_TYPE);
}
/*
  *function handeleNext_2_Operandmain is Check the token.type either is IdentifierToken or OperatorToken
  *if token type = IdentifierToken,it goes to get IndexX or IndexY
  *if token type = OperatorToken, it goes to get SHort/longOff or ShortLongPtr with Index
*/
void handleNExt_2_OperandMain(Tokenizer *tokenizer,OperandInfo *operandInfo){
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
            Throw(NOT_VALID_IDENTIFIER);
            getCloseBracketSymbol(tokenizer,operandInfo);
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
/*
  function handleNEXTOperandMain
  ''#'' = get function handlebyte
  ''$''= get function handlelongshortmem
  ''('' = get functiom handleNExt_2_OperandMain
   -- get indexX/indexY/longshortoff/longshortptrwithindex
  ''['' = get function ShortLongPtr
*/
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
      else if((strcmp("(",opToken->str)==0)){
        handleNExt_2_OperandMain(tokenizer,operandInfo);
      }
      else if((strcmp("[",opToken->str)==0)){
        handleShortLongPtr(tokenizer,operandInfo);
      }
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
    code[1] = operandInfo->value & 0xff;
    *memoryToWriteCode +=2;
    break;

    case SHORTPTR:
    code[0] = 0x92;
    code[1] = operandInfo->baseOpcode + 0xC0;
    code[2] = operandInfo->value & 0xff;
    *memoryToWriteCode +=3;
    break;

    case LONGPTR:
    code[0] = 0x72;
    code[1] = operandInfo->baseOpcode + 0xC0;
    code[2] = (operandInfo->value >> 8 ) & 0xff;
    code[3] = operandInfo->value & 0xff;
    *memoryToWriteCode +=4;
    break;

    case SHORTPTR_X:
    code[0] = 0x92;
    code[1] = operandInfo->baseOpcode + 0xD0;
    code[2] = operandInfo->value & 0xff;
    *memoryToWriteCode +=3;
    break;

    case SHORTPTR_Y:
    code[0] = 0x91;
    code[1] = operandInfo->baseOpcode + 0xD0;
    code[2] = operandInfo->value & 0xff;
    *memoryToWriteCode +=3;
    break;

    case LONGPTR_X:
    code[0] = 0x72;
    code[1] = operandInfo->baseOpcode + 0xD0;
    code[2] = (operandInfo->value >> 8 ) & 0xff;
    code[3] = operandInfo->value & 0xff;
    *memoryToWriteCode +=4;
    break;
    default:
    Throw(ERR_SYNTAX);
  }

}

void identifyInstruction(char *instructionTocompare,OperandInfo *operandInfo){
    if(isTokenMatchesString(instructionTocompare,"ADC"))
      operandInfo->baseOpcode = 0x09;
    else if(isTokenMatchesString(instructionTocompare,"ADD"))
      operandInfo->baseOpcode = 0x0B;
    else if(isTokenMatchesString(instructionTocompare,"AND"))
      operandInfo->baseOpcode = 0x04;
    else
    Throw(NOT_VALID_INSTRUCTION);
}

/*this function is get the 1st 3 token to identify them
  use function identifyInstruction to change the baseOpcode
  such as ADD A, ADC A, SUB A, have different baseOpcode
*/
int assemble(char *assemblyName, char **memoryToWriteCode){
  assemblyName = convertToUpperCase(assemblyName);
  Tokenizer *tokenizer = initTokenizer(assemblyName);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  OperatorToken *opToken;
  OperandInfo operandInfo;
  //1st token
  if(token->type == TOKEN_IDENTIFIER_TYPE){
    idToken = (IdentifierToken *)token;
    identifyInstruction(idToken->str,&operandInfo);
  }
  else
    Throw(NOT_VALID_INSTRUCTION);
  //2nd token
  token   = getToken(tokenizer);
  if(token->type == TOKEN_IDENTIFIER_TYPE)
    idToken = (IdentifierToken *)token;
  else
    Throw(NOT_VALID_IDENTIFIER);
  //3rd token
  opToken = (OperatorToken *)getToken(tokenizer);
  if(opToken->type == TOKEN_OPERATOR_TYPE && (strcmp(",",opToken->str )==0))
  {
    handleNEXTOperandMain(tokenizer,&operandInfo);
    displayOpcode(memoryToWriteCode,&operandInfo);
  }
  else
    Throw(NOT_VALID_OPERATOR);
}
