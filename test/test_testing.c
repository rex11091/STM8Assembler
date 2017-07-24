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
  uint8_t buffer[16];
  char instruct[]= "   AdD a,# 25";
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 3,6,"ADD A ,"};
  OperatorToken   HashTagToken ={TOKEN_OPERATOR_TYPE, 9,1,"#"};
  OperatorToken   dollarToken ={TOKEN_OPERATOR_TYPE, 10,1,"$"};
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,3,"25",25};


  initTokenizer_ExpectAndReturn(instruct,tokenizer);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ADDToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&HashTagToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&dollarToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);

  Try {
    machineCode = ADDByte(instruct,buffer);
    printf("the instruction [    %s    ] opcode is %#4x",instruct,machineCode);
  }Catch(ex) {
    TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
  }
}
