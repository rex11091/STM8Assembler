#include "unity.h"
#include "ADDShortPtr.h"
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

//instruction OF ADD A,[$10.w] TESTING
void test_asesemble_ADDshortPtr_ADD_A_0x10_expect_exception(void){
  CEXCEPTION_T ex;
  int machineCode;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 3,3,"ADD"};
  IdentifierToken AToken = {TOKEN_IDENTIFIER_TYPE, 7,1,"A"};
  OperatorToken   CommaToken ={TOKEN_OPERATOR_TYPE, 8,1,","};
  OperatorToken   SquareBracket1Token ={TOKEN_OPERATOR_TYPE, 9,1,"["};
  OperatorToken   DollarToken ={TOKEN_OPERATOR_TYPE, 10,1,"$"};
  IntegerToken    intToken = {TOKEN_INTEGER_TYPE,11,4,"0x10",0x10};
  OperatorToken   DotToken ={TOKEN_OPERATOR_TYPE, 13,1,"."};
  IdentifierToken WToken = {TOKEN_IDENTIFIER_TYPE, 14,1,"W"};
  OperatorToken   SquareBracket2Token ={TOKEN_OPERATOR_TYPE, 15,1,"]"};

  initTokenizer_ExpectAndReturn("   ADD A,[$10.w]",tokenizer);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ADDToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&AToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&CommaToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&SquareBracket1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&DollarToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&DotToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&SquareBracket2Token);
  Try {
    machineCode = ADDShortPtr("   ADD A,[$10.w]");
    printf("the instruction [   ADD A,[$10.w]       ] opcode is %#4x",machineCode);
  }Catch(ex) {
    TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
  }
}

// instruction OF ADD A,([$10.w],X) TESTING
void test_asesemble_ADDshortPtrX_ADD_A_0x10_expect_exception(void){
  CEXCEPTION_T ex;
  int machineCode;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 3,3,"ADD"};
  IdentifierToken AToken = {TOKEN_IDENTIFIER_TYPE, 7,1,"A"};
  OperatorToken   CommaToken ={TOKEN_OPERATOR_TYPE, 8,1,","};
  OperatorToken   NormalBracketToken ={TOKEN_OPERATOR_TYPE, 9,1,"("};
  OperatorToken   SquareBracket1Token ={TOKEN_OPERATOR_TYPE, 10,1,"["};
  OperatorToken   DollarToken ={TOKEN_OPERATOR_TYPE, 11,1,"$"};
  IntegerToken    intToken = {TOKEN_INTEGER_TYPE,12,4,"0x10",0x10};
  OperatorToken   DotToken ={TOKEN_OPERATOR_TYPE, 14,1,"."};
  IdentifierToken WToken = {TOKEN_IDENTIFIER_TYPE, 15,1,"W"};
  OperatorToken   SquareBracket2Token = {TOKEN_OPERATOR_TYPE, 16,1,"]"};
  OperatorToken   Comma2Token = {TOKEN_OPERATOR_TYPE, 17,1,","};
  IdentifierToken XToken = {TOKEN_IDENTIFIER_TYPE, 18,1,"X"};
  OperatorToken   NormalBracket2Token = {TOKEN_OPERATOR_TYPE, 19,1,")"};


  initTokenizer_ExpectAndReturn("   ADD A,([$10.w],X)",tokenizer);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ADDToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&AToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&CommaToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&NormalBracketToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&SquareBracket1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&DollarToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&DotToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&SquareBracket2Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&Comma2Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&XToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&NormalBracket2Token);
  Try {
    machineCode = ADDShortPtrXIndexFile("   ADD A,([$10.w],X)");
    printf("the instruction [   ADD A,([$10.w],X)   ] opcode is %#4x",machineCode);
  }Catch(ex) {
    TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
  }
}



// instruction OF ADD A,([$10.w],Y) TESTING
void test_asesemble_ADDshortPtrY_ADD_A_0x10_expect_exception(void){
  CEXCEPTION_T ex;
  int machineCode;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 3,3,"ADD"};
  IdentifierToken AToken = {TOKEN_IDENTIFIER_TYPE, 7,1,"A"};
  OperatorToken   CommaToken ={TOKEN_OPERATOR_TYPE, 8,1,","};
  OperatorToken   NormalBracketToken ={TOKEN_OPERATOR_TYPE, 9,1,"("};
  OperatorToken   SquareBracket1Token ={TOKEN_OPERATOR_TYPE, 10,1,"["};
  OperatorToken   DollarToken ={TOKEN_OPERATOR_TYPE, 11,1,"$"};
  IntegerToken    intToken = {TOKEN_INTEGER_TYPE,12,4,"0x10",0x10};
  OperatorToken   DotToken ={TOKEN_OPERATOR_TYPE, 14,1,"."};
  IdentifierToken WToken = {TOKEN_IDENTIFIER_TYPE, 15,1,"W"};
  OperatorToken   SquareBracket2Token = {TOKEN_OPERATOR_TYPE, 16,1,"]"};
  OperatorToken   Comma2Token = {TOKEN_OPERATOR_TYPE, 17,1,","};
  IdentifierToken YToken = {TOKEN_IDENTIFIER_TYPE, 18,1,"Y"};
  OperatorToken   NormalBracket2Token = {TOKEN_OPERATOR_TYPE, 19,1,")"};


  initTokenizer_ExpectAndReturn("   ADD A,([$10.w],Y)",tokenizer);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ADDToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&AToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&CommaToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&NormalBracketToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&SquareBracket1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&DollarToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&DotToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&SquareBracket2Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&Comma2Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&YToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&NormalBracket2Token);
  Try {
    machineCode = ADDShortPtrYIndexFile("   ADD A,([$10.w],Y)");
    printf("the instruction [   ADD A,([$10.w],Y)   ] opcode is %#4x",machineCode);
  }Catch(ex) {
    TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
  }
}
