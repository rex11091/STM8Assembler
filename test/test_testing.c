#include "unity.h"
#include "testing.h"
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


void test_asesemble_given_adc_A_0x97_expect_0x97B9(void){
  CEXCEPTION_T ex;
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char *str = "adc A,$97";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"adc"};
	IdentifierToken AToken = {TOKEN_IDENTIFIER_TYPE,4 ,1,"A"};
	OperatorToken   CommaToken ={TOKEN_OPERATOR_TYPE, 5,1,","};
	OperatorToken   dollarToken ={TOKEN_OPERATOR_TYPE, 6,1,"$"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,7,2,"0x97",0x97};


	initTokenizer_ExpectAndReturn(instruct,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&ADDToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&AToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&CommaToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&dollarToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);

	Try {
		assemble(str, &memoryToWriteCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}




/*void test_asesemble_ADDByte_ADD_A_50_expect_exception(void){
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
*/
