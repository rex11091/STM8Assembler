#include "Assemble.h"
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include "Tokenizer.h"
#include "Token.h"
#include "error.h"
#include "CException.h"
#include "touppercase.h"
#include "Exception.h"




/*
void trt(Tokenizer *tokenizer,OperandInfo *operandInfo){
  OperatorToken   *opToken;
  IdentifierToken *idToken;

  opToken = (OperatorToken *)getToken(tokenizer);
    if(opToken->type ==TOKEN_OPERATOR_TYPE && (strcmp(opToken->str,".") ==0)){
  idToken = (IdentifierToken *)getToken(tokenizer);
    if(idToken->type ==TOKEN_IDENTIFIER_TYPE && (strcmp(idToken->str,"W") ==0)){
  opToken = (OperatorToken *)getToken(tokenizer);
    if(opToken->type !=TOKEN_OPERATOR_TYPE || (strcmp(opToken->str,"]") !=0)){
       throwException(NOT_VALID_OPERATOR, (void *)opToken,                     \
                         "Invalid operand, expecting a ']', but received '%s'\n", \
                          opToken->str);
      }
    }
    else
    throwException(NOT_VALID_OPERATOR, (void *)idToken,                     \
                   "Invalid operand, expecting a 'W', but received '%s'\n", \
                    idToken->str);
    }
    else
    throwException(NOT_VALID_OPERATOR, (void *)opToken,                     \
                   "Invalid operand, expecting a '.', but received '%s'\n", \
                    opToken->str);
}


instructionTable[]= {
  {"ADD", add},
  {"ADC", adc},
};

void add(){
  printf("AAAn");
}

void testABC(){
  strcmp("ADD",instructionTable);
}
*/


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
        throwException(LIMIT_EXCEEDED, (void *)intToken,                                          \
                       "LIMIT_EXCEEDED, expecting ( value <= 0xffff ) , but received '%04x'\n", \
                        intToken->value);
          }
    }
    else
    throwException(WRONG_TOKEN_TYPE, (void *)intToken,                                       \
                   "WRONG_TOKEN_TYPE, expecting a 'TOKEN_INTEGER_TYPE', but received '%d'\n", \
                    intToken->type);
}

void getCloseBracketSymbol(Tokenizer *tokenizer,OperandInfo *operandInfo){
  OperatorToken   *opToken;
  opToken = (OperatorToken *)getToken(tokenizer);
  if(opToken->type != TOKEN_OPERATOR_TYPE || (strcmp(opToken->str,")") !=0))
     throwException(NOT_VALID_OPERATOR, (void *)opToken,                     \
                       "NOT_VALID_OPERATOR, expecting a ')', but received '%s'\n", \
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
    if(opToken->type ==TOKEN_OPERATOR_TYPE && (strcmp(opToken->str,"]") ==0)){}
    else
      throwException(NOT_VALID_OPERATOR, (void *)opToken,                           \
                        "NOT_VALID_OPERATOR, expecting a ']', but received '%s'\n", \
                         opToken->str);
    }
    else
    throwException(NOT_VALID_IDENTIFIER, (void *)idToken,                           \
                      "NOT_VALID_IDENTIFIER, expecting a 'W', but received '%s'\n", \
                       idToken->str);
    }
    else
    throwException(NOT_VALID_OPERATOR, (void *)opToken,                           \
                      "NOT_VALID_OPERATOR, expecting a '.', but received '%s'\n", \
                       opToken->str);
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
   Throw(createException("wrong operandInfo type expect is ShortPTR/longPTR " \
                          ,NOT_VALID_OPREANDINFO_TYPE));
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
      throwException(NOT_VALID_OPERATOR, (void *)opToken,                           \
                        "NOT_VALID_OPERATOR, expecting a '$', but received '%s'\n", \
                         opToken->str);
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
              Throw(createException("wrong operandInfo type , no operandInfo type is LONGPTR_Y " \
                                     ,NOT_VALID_OPREANDINFO_TYPE));
            }
            else
            throwException(NOT_VALID_IDENTIFIER, (void *)idToken,                           \
                              "NOT_VALID_OPERATOR, expecting a 'X/Y', but received '%s'\n", \
                               idToken->str);
          }
          getCloseBracketSymbol(tokenizer,operandInfo);
      }
      else
      throwException(NOT_VALID_OPERATOR, (void *)opToken,                           \
                        "NOT_VALID_OPERATOR, expecting a ',', but received '%s'\n", \
                         opToken->str);
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
    if(idToken->type == TOKEN_IDENTIFIER_TYPE){
      if(strcmp(idToken->str,"X")==0)
        operandInfo->type = SHORTOFF_X;
      else if(strcmp(idToken->str,"Y")==0)
        operandInfo->type = SHORTOFF_Y;
      else if(strcmp(idToken->str,"SP")==0)
        operandInfo->type = SHORTOFF_SP;
      else
        throwException(NOT_VALID_IDENTIFIER, (void *)idToken,                           \
                        "NOT_VALID_IDENTIFIER, expecting a 'X/Y/SP', but received '%s'\n", \
                         idToken->str);
    }
    else
    throwException(WRONG_TOKEN_TYPE, (void *)idToken,                                       \
                   "WRONG_TOKEN_TYPE, expecting a 'TOKEN_IDENTIFIER_TYPE', but received '%d'\n", \
                    idToken->type);
  }
  else
    throwException(NOT_VALID_OPERATOR, (void *)opToken,                           \
                    "NOT_VALID_OPERATOR, expecting a ',', but received '%s'\n", \
                     opToken->str);
}

void convertShortoffToLongoff(Tokenizer *tokenizer,OperandInfo *operandInfo){
  if(operandInfo->type == SHORTOFF_X)
    operandInfo->type = LONGOFF_X;
  else if(operandInfo->type == SHORTOFF_Y)
    operandInfo->type = LONGOFF_Y;
  else if(operandInfo->type == SHORTOFF_SP)
  Throw(createException("wrong operandInfo type, no operandInfo type is LONGOFF SP" \
                         ,NOT_VALID_OPREANDINFO_TYPE));
  else
  Throw(createException("wrong operandInfo type, expect is LONGOFF Y/X " \
                         ,NOT_VALID_OPREANDINFO_TYPE));
}

void handleShortLongoff(Tokenizer *tokenizer,OperandInfo *operandInfo){
  IntegerToken *intToken;
  intToken = (IntegerToken *)getToken(tokenizer);
  if(intToken->type == TOKEN_INTEGER_TYPE)
  {
    operandInfo->value = intToken->value;
    if(operandInfo->value <= 0xff){
      getShortlongoffIndexX_Y_SP(tokenizer,operandInfo);
      getCloseBracketSymbol(tokenizer,operandInfo);
    }
    else if(operandInfo->value <= 0xffff){
      getShortlongoffIndexX_Y_SP(tokenizer,operandInfo);
      convertShortoffToLongoff(tokenizer,operandInfo);
      getCloseBracketSymbol(tokenizer,operandInfo);
    }
    else{
       throwException(LIMIT_EXCEEDED, (void *)intToken,                                          \
                     "LIMIT_EXCEEDED, expecting (value <= 0xffff ) , but received '%04x'\n", \
                      intToken->value);
      }
  }
}

void handleByte(Tokenizer *tokenizer,OperandInfo *operandInfo){
    OperatorToken *opToken;
    IntegerToken *intToken;
    opToken = (OperatorToken *)getToken(tokenizer);
      if(opToken->type ==TOKEN_OPERATOR_TYPE && (strcmp(opToken->str,"$") ==0)){
        intToken = (IntegerToken *)getToken(tokenizer);
          if(intToken->type == TOKEN_INTEGER_TYPE){
            operandInfo->value = intToken->value;
              if(operandInfo->value <= 0xff)
                operandInfo->type = BYTE; // 0
              else
              throwException(LIMIT_EXCEEDED, (void *)intToken,                                          \
                            "LIMIT_EXCEEDED, BYTE src only (0xff <= value) , but received '%04x'\n", \
                             intToken->value);
              }
          else
          throwException(WRONG_TOKEN_TYPE, (void *)intToken,                                       \
                         "WRONG_TOKEN_TYPE, expecting a 'TOKEN_INTEGER_TYPE', but received '%d'\n", \
                          intToken->type);
          }
      else
      throwException(NOT_VALID_OPERATOR, (void *)opToken,                     \
                        "NOT_VALID_OPERATOR, expecting a '$', but received '%s'\n", \
                         opToken->str);
}

void handleLongShortMem(Tokenizer *tokenizer,OperandInfo *operandInfo){
  getLongShortType(tokenizer,operandInfo);
       if(operandInfo->type == Long)
         operandInfo->type = LONG_MEM;
       else if(operandInfo->type == Short)
         operandInfo->type = SHORT_MEM;
       else
       Throw(createException("wrong operandInfo type, expect is LONG/SHORT MEM " \
                              ,NOT_VALID_OPREANDINFO_TYPE));
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
          else{
          throwException(NOT_VALID_IDENTIFIER, (void *)idToken,                           \
                          "NOT_VALID_IDENTIFIER, expecting a 'X/Y', but received '%s'\n", \
                           idToken->str);
          }
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
        throwException(NOT_VALID_OPERATOR, (void *)opToken,                           \
                        "NOT_VALID_OPERATOR, expecting a '$/[', but received '%s'\n", \
                         opToken->str);
        }
    else
      Throw(WRONG_TOKEN_TYPE);
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
    opToken = (OperatorToken *)getToken(tokenizer);
    if(opToken->type == TOKEN_OPERATOR_TYPE)
    {
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
      throwException(NOT_VALID_OPERATOR, (void *)opToken,                           \
                      "NOT_VALID_OPERATOR, expecting a '$' / '#' / '(' / ']' , but received '%s'\n", \
                       opToken->str);
    }
    else
    throwException(WRONG_TOKEN_TYPE, (void *)opToken,                                       \
                   "WRONG_TOKEN_TYPE, expecting a 'TOKEN_OPERATOR_TYPE', but received '%d'\n", \
                    opToken->type);
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

    case Inherent:
    code[0] = operandInfo->baseOpcode;
    *memoryToWriteCode +=1;
    break;

    default:
    Throw(createException("wrong operandInfo type (enum) < 25" \
                           ,NOT_VALID_OPREANDINFO_TYPE));
  }

}

void identifyInstruction(char *instructionTocompare,OperandInfo *operandInfo){
    if(isTokenMatchesString(instructionTocompare,"ADC"))
      operandInfo->baseOpcode = 0x09;
    else if(isTokenMatchesString(instructionTocompare,"ADD"))
      operandInfo->baseOpcode = 0x0B;
    else if(isTokenMatchesString(instructionTocompare,"AND"))
      operandInfo->baseOpcode = 0x04;
    else if(isTokenMatchesString(instructionTocompare,"BCP"))
      operandInfo->baseOpcode = 0x05;
    else if(isTokenMatchesString(instructionTocompare,"CP"))
      operandInfo->baseOpcode = 0x01;
    else if(isTokenMatchesString(instructionTocompare,"LD"))
      operandInfo->baseOpcode = 0x06;
    else if(isTokenMatchesString(instructionTocompare,"OR"))
      operandInfo->baseOpcode = 0x0A;
    else if(isTokenMatchesString(instructionTocompare,"SBC"))
      operandInfo->baseOpcode = 0x02;
    else if(isTokenMatchesString(instructionTocompare,"SUB"))
      operandInfo->baseOpcode = 0x00;
    else if(isTokenMatchesString(instructionTocompare,"XOR"))
      operandInfo->baseOpcode = 0x08;
    else if(isTokenMatchesString(instructionTocompare,"BREAK"))
      operandInfo->baseOpcode = 0x8B;
    else if(isTokenMatchesString(instructionTocompare,"CCF"))
      operandInfo->baseOpcode = 0x8C;
    else if(isTokenMatchesString(instructionTocompare,"HALT"))
      operandInfo->baseOpcode = 0x8E;
    else if(isTokenMatchesString(instructionTocompare,"IRET"))
      operandInfo->baseOpcode = 0x80;
    else if(isTokenMatchesString(instructionTocompare,"NOP"))
      operandInfo->baseOpcode = 0x9D;
    else if(isTokenMatchesString(instructionTocompare,"RCF"))
      operandInfo->baseOpcode = 0x98;
    else if(isTokenMatchesString(instructionTocompare,"RET"))
      operandInfo->baseOpcode = 0x81;
    else if(isTokenMatchesString(instructionTocompare,"RETF"))
      operandInfo->baseOpcode = 0x87;
    else if(isTokenMatchesString(instructionTocompare,"RIM"))
      operandInfo->baseOpcode = 0x9A;
    else if(isTokenMatchesString(instructionTocompare,"RVF"))
      operandInfo->baseOpcode = 0x9C;
    else if(isTokenMatchesString(instructionTocompare,"SCF"))
      operandInfo->baseOpcode = 0x99;
    else if(isTokenMatchesString(instructionTocompare,"SIM"))
      operandInfo->baseOpcode = 0x9B;
    else if(isTokenMatchesString(instructionTocompare,"TRAP"))
      operandInfo->baseOpcode = 0x83;
    else if(isTokenMatchesString(instructionTocompare,"WFI"))
      operandInfo->baseOpcode = 0x8F;
    else
    Throw(createException("NOT_VALID_INSTRUCTION ,out of scope" \
                           ,NOT_VALID_INSTRUCTION));
}
/* this function is get build-in instruction
 like BREAK,CCF,HALT
*/
int handleInherentInstruction(char *assemblyName, char **memoryToWriteCode){
  assemblyName = convertToUpperCase(assemblyName);
  Tokenizer *tokenizer = initTokenizer(assemblyName);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  OperandInfo operandInfo;
  if(token->type == TOKEN_IDENTIFIER_TYPE){
    idToken = (IdentifierToken *)token;
    identifyInstruction(idToken->str,&operandInfo);
    operandInfo.type = Inherent;
    displayOpcode(memoryToWriteCode,&operandInfo);
  }
  else
  throwException(WRONG_TOKEN_TYPE, (void *)token,                           \
                "NOT_VALID_IDENTIFIER, expecting IdentifierToken.type , but received '%d'\n", \
                 token->type);
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
  //2nd token
  idToken =(IdentifierToken *)getToken(tokenizer);
  if(token->type == TOKEN_IDENTIFIER_TYPE && (strcmp(idToken->str,"A") == 0)){
  //3rd token
  opToken = (OperatorToken *)getToken(tokenizer);
  if(opToken->type == TOKEN_OPERATOR_TYPE && (strcmp(",",opToken->str )==0))
  {
    handleNEXTOperandMain(tokenizer,&operandInfo);
    displayOpcode(memoryToWriteCode,&operandInfo);
  }
  else
  throwException(NOT_VALID_OPERATOR, (void *)opToken,                           \
                  "NOT_VALID_OPERATOR, expecting a ',' , but received '%s'\n", \
                   opToken->str);
  }
  else
  throwException(NOT_VALID_IDENTIFIER, (void *)idToken,                           \
                  "NOT_VALID_IDENTIFIER, expecting a 'A' , but received '%s'\n", \
                   idToken->str);
  }
  else
    throwException(WRONG_TOKEN_TYPE, (void *)token,                           \
                  "NOT_VALID_IDENTIFIER, expecting IdentifierToken.type , but received '%d'\n", \
                   token->type);
}
