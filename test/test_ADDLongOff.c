#include "unity.h"
#include "ADDLongOff.h"
#include "mock_Tokenizer.h"
#include <stdio.h>
#include "Token.h"
#include "error.h"
#include "Exception.h"
void setUp(void)
{
}

void tearDown(void)
{
}

void test_asesemble_ADDLongOffX_ADD_A_10_expect_exception(void){
  CEXCEPTION_T ex;
  int machineCode;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 3,3,"ADD"};
  IdentifierToken AToken = {TOKEN_IDENTIFIER_TYPE, 7,1,"A"};
  OperatorToken   CommaToken ={TOKEN_OPERATOR_TYPE, 8,1,","};
  OperatorToken   FrontBracketToken ={TOKEN_OPERATOR_TYPE, 9,1,"("};
  OperatorToken   DollarToken ={TOKEN_OPERATOR_TYPE, 10,1,"$"};
  IntegerToken    intToken = {TOKEN_INTEGER_TYPE,11,6,"0x1000",0x1000};
  OperatorToken   Comma2Token ={TOKEN_OPERATOR_TYPE, 13,1,","};
  IdentifierToken XToken = {TOKEN_IDENTIFIER_TYPE, 14,1,"X"};
  OperatorToken   BackBracketToken ={TOKEN_OPERATOR_TYPE, 15,1,")"};

  //IdentifierToken fffToken = {TOKEN_IDENTIFIER_TYPE, 17, 3,7 "fff"};

  initTokenizer_ExpectAndReturn("   ADD A,($1000,X)",tokenizer);
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
    machineCode = ADDLongOffX("   ADD A,($1000,X)");
    printf("the instruction opcode is %#4x",machineCode);
  }Catch(ex) {
    TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
  }
}


void test_asesemble_ADDLongOffY_ADD_A_10_expect_exception(void){
  CEXCEPTION_T ex;
  int machineCode;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 3,3,"ADD"};
  IdentifierToken AToken = {TOKEN_IDENTIFIER_TYPE, 7,1,"A"};
  OperatorToken   CommaToken ={TOKEN_OPERATOR_TYPE, 8,1,","};
  OperatorToken   FrontBracketToken ={TOKEN_OPERATOR_TYPE, 9,1,"("};
  OperatorToken   DollarToken ={TOKEN_OPERATOR_TYPE, 10,1,"$"};
  IntegerToken    intToken = {TOKEN_INTEGER_TYPE,11,6,"0x1000",0x1000};
  OperatorToken   Comma2Token ={TOKEN_OPERATOR_TYPE, 13,1,","};
  IdentifierToken XToken = {TOKEN_IDENTIFIER_TYPE, 14,1,"Y"};
  OperatorToken   BackBracketToken ={TOKEN_OPERATOR_TYPE, 15,1,")"};

  //IdentifierToken fffToken = {TOKEN_IDENTIFIER_TYPE, 17, 3,7 "fff"};

  initTokenizer_ExpectAndReturn("   ADD A,($1000,Y)",tokenizer);
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
    machineCode = ADDLongOffY("   ADD A,($1000,Y)");
    printf("the instruction opcode is %#4x",machineCode);
  }Catch(ex) {
    TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
  }
}
