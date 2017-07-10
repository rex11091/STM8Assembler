#include "unity.h"
#include "ADDLongMem.h"
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

void test_assemble_ADDLongMem_ADD_LongMem_0x5678__expect_exception(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 3,3,"add"};
	IdentifierToken AToken = {TOKEN_IDENTIFIER_TYPE, 7,1,"a"};
	OperatorToken   CommaToken ={TOKEN_OPERATOR_TYPE, 8,1,","};
	OperatorToken   dollarToken ={TOKEN_OPERATOR_TYPE, 9,1,"$"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,10,6,"0x5678",0x5678};


	initTokenizer_ExpectAndReturn("   ADD A,$5678",tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&ADDToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&AToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&CommaToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&dollarToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);

	Try {
		machineCode = ADDLongMem("   ADD A,$5678");
    printf("the instruction [   ADD A,$5678   ] Opcode is %#4x\n",machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
