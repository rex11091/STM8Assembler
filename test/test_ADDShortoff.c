#include "unity.h"
#include "ADDShortoff.h"
#include "mock_Tokenizer.h"
#include <stdio.h>
#include "Token.h"
#include "error.h"
#include "Exception.h"
#include "touppercase.h"
void setUp(void)
{
}

void tearDown(void)
{
}

void test_asesemble_ADDshortOffX_ADD_A_10_expect_exception(void){
  CEXCEPTION_T ex;
  int machineCode;
  char instruct[] = "   ADD A,($10,y)";
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 3,3,"ADD"};
  IdentifierToken AToken = {TOKEN_IDENTIFIER_TYPE, 7,1,"A"};
  OperatorToken   CommaToken ={TOKEN_OPERATOR_TYPE, 8,1,","};
  OperatorToken   FrontBracketToken ={TOKEN_OPERATOR_TYPE, 9,1,"("};
  OperatorToken   DollarToken ={TOKEN_OPERATOR_TYPE, 10,1,"$"};
  IntegerToken    intToken = {TOKEN_INTEGER_TYPE,11,4,"0x10",0x10};
  OperatorToken   Comma2Token ={TOKEN_OPERATOR_TYPE, 13,1,","};
  IdentifierToken XToken = {TOKEN_IDENTIFIER_TYPE, 14,1,"X"};
  OperatorToken   BackBracketToken ={TOKEN_OPERATOR_TYPE, 15,1,")"};

  //IdentifierToken fffToken = {TOKEN_IDENTIFIER_TYPE, 17, 3,7 "fff"};

  initTokenizer_ExpectAndReturn(instruct,tokenizer);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ADDToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&AToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&CommaToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&FrontBracketToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&DollarToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&Comma2Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&XToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BackBracketToken);
  Try {
    machineCode = ADDShortoffX(instruct);
    printf("the instruction [   ADD A,($10,X)] opcode is %#4x",machineCode);
  }Catch(ex) {
    TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
  }
}


void test_asesemble_ADDShortoffY_ADD_A_10_expect_exception(void){
  CEXCEPTION_T ex;
  int machineCode;
  char instruct[] = "   AdD A,($10,y)";
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 3,3,"ADD"};
  IdentifierToken AToken = {TOKEN_IDENTIFIER_TYPE, 7,1,"A"};
  OperatorToken   CommaToken ={TOKEN_OPERATOR_TYPE, 8,1,","};
  OperatorToken   FrontBracketToken ={TOKEN_OPERATOR_TYPE, 9,1,"("};
  OperatorToken   DollarToken ={TOKEN_OPERATOR_TYPE, 10,1,"$"};
  IntegerToken    intToken = {TOKEN_INTEGER_TYPE,11,4,"0x10",0x10};
  OperatorToken   Comma2Token ={TOKEN_OPERATOR_TYPE, 13,1,","};
  IdentifierToken XToken = {TOKEN_IDENTIFIER_TYPE, 14,1,"Y"};
  OperatorToken   BackBracketToken ={TOKEN_OPERATOR_TYPE, 15,1,")"};

  //IdentifierToken fffToken = {TOKEN_IDENTIFIER_TYPE, 17, 3,7 "fff"};

  initTokenizer_ExpectAndReturn(instruct,tokenizer);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ADDToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&AToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&CommaToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&FrontBracketToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&DollarToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&Comma2Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&XToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BackBracketToken);
  Try {
    machineCode = ADDShortoffY(instruct);
    printf("the instruction [   ADD A,($10,Y)   ] opcode is %#4x",machineCode);
  }Catch(ex) {
    TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
  }
}

void test_asesemble_ADDShortoffSP_ADD_A_10_expect_exception(void){
  CEXCEPTION_T ex;
  int machineCode;
  char instruct[] = "   Add A,($10,sP)";
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 3,3,"ADD"};
  IdentifierToken AToken = {TOKEN_IDENTIFIER_TYPE, 7,1,"A"};
  OperatorToken   CommaToken ={TOKEN_OPERATOR_TYPE, 8,1,","};
  OperatorToken   FrontBracketToken ={TOKEN_OPERATOR_TYPE, 9,1,"("};
  OperatorToken   DollarToken ={TOKEN_OPERATOR_TYPE, 10,1,"$"};
  IntegerToken    intToken = {TOKEN_INTEGER_TYPE,11,4,"0x10",0x10};
  OperatorToken   Comma2Token ={TOKEN_OPERATOR_TYPE, 13,1,","};
  IdentifierToken SToken = {TOKEN_IDENTIFIER_TYPE, 14,1,"S"};
  IdentifierToken PToken = {TOKEN_IDENTIFIER_TYPE, 15,1,"P"};
  OperatorToken   BackBracketToken ={TOKEN_OPERATOR_TYPE, 16,1,")"};

  //IdentifierToken fffToken = {TOKEN_IDENTIFIER_TYPE, 17, 3,7 "fff"};

  initTokenizer_ExpectAndReturn(instruct,tokenizer);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ADDToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&AToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&CommaToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&FrontBracketToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&DollarToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&Comma2Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&SToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&PToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BackBracketToken);
  Try {
    machineCode = ADDShortoffSP(instruct);
    printf("the instruction [   ADD A,($10,SP)  ] opcode is %#4x",machineCode);
  }Catch(ex) {
    TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
  }
}
