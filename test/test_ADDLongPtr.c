#include "unity.h"
#include "ADDLongPtr.h"
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

void test_asesemble_ADDLongPtrW_ADD_A_0x1000_expect_exception(void){
  CEXCEPTION_T ex;
  int machineCode;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 3,3,"add"};
  IdentifierToken AToken = {TOKEN_IDENTIFIER_TYPE, 7,1,"a"};
  OperatorToken   CommaToken ={TOKEN_OPERATOR_TYPE, 8,1,","};
  OperatorToken   SquareBracket1Token ={TOKEN_OPERATOR_TYPE, 9,1,"["};
  OperatorToken   DollarToken ={TOKEN_OPERATOR_TYPE, 10,1,"$"};
  IntegerToken    intToken = {TOKEN_INTEGER_TYPE,11,4,"0x1000",0x1000};
  OperatorToken   DotToken ={TOKEN_OPERATOR_TYPE, 13,1,"."};
  IdentifierToken WToken = {TOKEN_IDENTIFIER_TYPE, 14,1,"w"};
  OperatorToken   SquareBracket2Token ={TOKEN_OPERATOR_TYPE, 15,1,"]"};


  initTokenizer_ExpectAndReturn("   ADD A,[$1000.w]",tokenizer);
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
    machineCode = ADDLongPtr("   ADD A,[$1000.w]");
    printf("the instruction [   ADD A,[$1000.w]       ] opcode is %#4x",machineCode);
  }Catch(ex) {
    TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
  }
}


// instruction OF ADD A,([$10.w],X) TESTING
void test_asesemble_ADDLongPtrX_ADD_A_0x1000_expect_exception(void){
  CEXCEPTION_T ex;
  int machineCode;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 3,3,"add"};
  IdentifierToken AToken = {TOKEN_IDENTIFIER_TYPE, 7,1,"a"};
  OperatorToken   CommaToken ={TOKEN_OPERATOR_TYPE, 8,1,","};
  OperatorToken   NormalBracketToken ={TOKEN_OPERATOR_TYPE, 9,1,"("};
  OperatorToken   SquareBracket1Token ={TOKEN_OPERATOR_TYPE, 10,1,"["};
  OperatorToken   DollarToken ={TOKEN_OPERATOR_TYPE, 11,1,"$"};
  IntegerToken    intToken = {TOKEN_INTEGER_TYPE,12,4,"0x1000",0x1000};
  OperatorToken   DotToken ={TOKEN_OPERATOR_TYPE, 14,1,"."};
  IdentifierToken WToken = {TOKEN_IDENTIFIER_TYPE, 15,1,"w"};
  OperatorToken   SquareBracket2Token = {TOKEN_OPERATOR_TYPE, 16,1,"]"};
  OperatorToken   Comma2Token = {TOKEN_OPERATOR_TYPE, 17,1,","};
  IdentifierToken XToken = {TOKEN_IDENTIFIER_TYPE, 18,1,"x"};
  OperatorToken   NormalBracket2Token = {TOKEN_OPERATOR_TYPE, 19,1,")"};


  initTokenizer_ExpectAndReturn("   ADD A,([$1000.w],X)",tokenizer);
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
    machineCode = ADDLongPtrXIndexFile("   ADD A,([$1000.w],X)");
    printf("the instruction [   ADD A,([$1000.w],X)   ] opcode is %#4x",machineCode);
  }Catch(ex) {
    TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
  }
}