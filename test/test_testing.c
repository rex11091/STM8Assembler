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

/*
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
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,7,2,"97",97};


	initTokenizer_ExpectAndReturn(str,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&ADDToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&AToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&CommaToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&dollarToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);

 printf("%d",*(uint32_t *)buffer);
	Try {
		assemble(str, &memoryToWriteCode);
    //printf("%d",*(uint32_t *)buffer);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
*/

void test_asesemble_given_0x97_expect_exception(void){
CEXCEPTION_T ex;
OperandInfo operandInfo;
operandInfo.value = 0x97;
Tokenizer *tokenizer = (Tokenizer *)0x0badface;
//operandInfo *operandInfo;
char *str = "97";
IntegerToken intToken = {TOKEN_INTEGER_TYPE,0,2,"97",97};

initTokenizer_ExpectAndReturn(str,tokenizer);
getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);

Try {
handleLongShortMem(tokenizer,&operandInfo);
   }Catch(ex) {
  TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
}
}
