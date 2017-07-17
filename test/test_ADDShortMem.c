#include "unity.h"
#include "ADDShortMem.h"
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

void test_assemble_ADDShortmem_ADD_ShortMem__A_55_expect_exception(void){
	CEXCEPTION_T ex;
	int machineCode;
	char instruct[] = "   AdD A,$55";
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 3,3,"ADD"};
	IdentifierToken AToken = {TOKEN_IDENTIFIER_TYPE, 7,1,"A"};
	OperatorToken   CommaToken ={TOKEN_OPERATOR_TYPE, 8,1,","};
	OperatorToken   dollarToken ={TOKEN_OPERATOR_TYPE, 9,1,"$"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,10,2,"55",55};
	//IdentifierToken fffToken = {TOKEN_IDENTIFIER_TYPE, 17, 3,7 "fff"};

	initTokenizer_ExpectAndReturn(instruct,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&ADDToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&AToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&CommaToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&dollarToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);

	Try {
		machineCode = ADDShortMem(instruct);
		printf("the instruction [   ADD A,$55       ] opcode is %#4x",machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
