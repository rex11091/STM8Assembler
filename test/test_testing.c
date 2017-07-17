#include "unity.h"
#include "testing.h"
#include "mock_Tokenizer.h"
#include <stdio.h>
#include "Token.h"
#include "error.h"
#include "Exception.h"
#include "touppercase.h"
#include "symbol.h"
void setUp(void)
{
}

void tearDown(void)
{
}





void test_asesemble_ADDByte_ADD_A_50_expect_exception(void){
  CEXCEPTION_T ex;
  int machineCode;

  char instruct[]= "    AdD a,#$50";
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 3,3,("ADD")};
  IdentifierToken AToken = {TOKEN_IDENTIFIER_TYPE, 7,1,"A"};
  OperatorToken   CommaToken ={TOKEN_OPERATOR_TYPE, 8,1,","};
  OperatorToken   HashTagToken ={TOKEN_OPERATOR_TYPE, 9,1,"#"};
  OperatorToken   dollarToken ={TOKEN_OPERATOR_TYPE, 10,1,"$"};
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x50",0x50};
  //IdentifierToken fffToken = {TOKEN_IDENTIFIER_TYPE, 17, 3,7 "fff"};

  initTokenizer_ExpectAndReturn(instruct,tokenizer);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ADDToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&AToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&CommaToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&HashTagToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&dollarToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);

  Try {
    machineCode = ADDByte(instruct);
    printf("the instruction [    ADD A,#$50    ] opcode is %#4x",machineCode);
  }Catch(ex) {
    TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
  }
}
