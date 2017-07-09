#include "unity.h"
#include "ADDShortMem.h"
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

void test_assemble_ADDShortmem_ADD_ShortMem__expect_exception(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 3,3,"ADD"};
	IdentifierToken AToken = {TOKEN_IDENTIFIER_TYPE, 7,1,"A"};
	OperatorToken   CommaToken ={TOKEN_OPERATOR_TYPE, 8,1,","};
	OperatorToken   dollarToken ={TOKEN_OPERATOR_TYPE, 9,1,"$"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,10,2,"ss",55};
	//IdentifierToken fffToken = {TOKEN_IDENTIFIER_TYPE, 17, 3,7 "fff"};

	initTokenizer_ExpectAndReturn("   ADD A,$55",tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&ADDToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&AToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&CommaToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&dollarToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);

	Try {
		machineCode = ADDShortMem("   ADD A,$55");
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
