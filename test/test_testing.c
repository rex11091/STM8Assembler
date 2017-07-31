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
void xtest_function_handleIndexXandY_given_XorY_expect_exception(void){
    CEXCEPTION_T ex;
    OperandInfo operandInfo;
    Tokenizer *tokenizer = (Tokenizer *)0x0badface;

    IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,1,"Y"};
    OperatorToken   CBracketToken = {TOKEN_OPERATOR_TYPE,0,1,"z"};

    getToken_ExpectAndReturn(tokenizer, (Token *)&ADDToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&CBracketToken);
  	Try {
  		handleIndexXandY(tokenizer, &operandInfo);
      printf("%d\n",operandInfo.type);
  	}Catch(ex) {
  	TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
  	}
  }
*/
void xtest_function_handleLongShortoff_given_shortoff_0x10_X_expect_not_exception(void){
    CEXCEPTION_T ex;
    OperandInfo operandInfo;
    Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  //  str = "10,X)"
  	IntegerToken intToken = {TOKEN_INTEGER_TYPE,0,2,"0x10",0x10};
    OperatorToken commaToken = {TOKEN_OPERATOR_TYPE,0,1,","};
    IdentifierToken WToken = {TOKEN_IDENTIFIER_TYPE,0,1,"X"};
    OperatorToken CBracketToken = {TOKEN_OPERATOR_TYPE,0,1,")"};

    getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&commaToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&WToken);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&CBracketToken);


  	Try {
  		handleShortLongoff(tokenizer, &operandInfo);
      printf("%d\n",operandInfo.type);
  	}Catch(ex) {
  	TEST_ASSERT_EQUAL(NOT_VALID_INSTRUCTION, ex);
  	}
  }
void xtest_function_handleLongShortoff_given_shortoff_0x10_Y_expect_not_exception(void){
      CEXCEPTION_T ex;
      OperandInfo operandInfo;
      Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    //  str = "10,X)"
    	IntegerToken intToken = {TOKEN_INTEGER_TYPE,0,2,"0x10",0x10};
      OperatorToken commaToken = {TOKEN_OPERATOR_TYPE,0,1,","};
      IdentifierToken WToken = {TOKEN_IDENTIFIER_TYPE,0,1,"Y"};
      OperatorToken CBracketToken = {TOKEN_OPERATOR_TYPE,0,1,")"};

      getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);
      getToken_ExpectAndReturn(tokenizer, (Token *)&commaToken);
      getToken_ExpectAndReturn(tokenizer, (Token *)&WToken);
    	getToken_ExpectAndReturn(tokenizer, (Token *)&CBracketToken);


    	Try {
    		handleShortLongoff(tokenizer, &operandInfo);
        printf("%d\n",operandInfo.type);
    	}Catch(ex) {
    	TEST_ASSERT_EQUAL(NOT_VALID_INSTRUCTION, ex);
    	}
    }
void xtest_function_handleLongShortoff_given_longoff_0x1000_X_expect_not_exception(void){
    CEXCEPTION_T ex;
    OperandInfo operandInfo;
    Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    //  str = "1000,X)"
    IntegerToken intToken = {TOKEN_INTEGER_TYPE,0,2,"0x1000",0x1000};
    OperatorToken commaToken = {TOKEN_OPERATOR_TYPE,0,1,","};
    IdentifierToken WToken = {TOKEN_IDENTIFIER_TYPE,0,1,"X"};
    OperatorToken CBracketToken = {TOKEN_OPERATOR_TYPE,0,1,")"};

    getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&commaToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&WToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&CBracketToken);


    Try {
      handleShortLongoff(tokenizer, &operandInfo);
      printf("%d\n",operandInfo.type);
      }Catch(ex) {
      TEST_ASSERT_EQUAL(NOT_VALID_INSTRUCTION, ex);
      }
}
void test_function_handleLongShortoff_given_Lonfoff_0x1000_Y_expect_not_exception(void){
    CEXCEPTION_T ex;
    OperandInfo operandInfo;
    Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  //  str = "1000,Y)"
  	IntegerToken intToken = {TOKEN_INTEGER_TYPE,0,2,"0x1000",0x1000};
    OperatorToken commaToken = {TOKEN_OPERATOR_TYPE,0,1,","};
    IdentifierToken WToken = {TOKEN_IDENTIFIER_TYPE,0,1,"Z"};
    OperatorToken CBracketToken = {TOKEN_OPERATOR_TYPE,0,1,")"};

    getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&commaToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&WToken);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&CBracketToken);


  	Try {
  		handleShortLongoff(tokenizer, &operandInfo);
      printf("%d\n",operandInfo.type);
  	}Catch(ex) {
  	TEST_ASSERT_EQUAL(NOT_VALID_INSTRUCTION, ex);
  	}
  }

void xtest_function_handleLongShortoff_given_shortoff_0x10_Z_expect_exception(void){

      CEXCEPTION_T ex;
      OperandInfo operandInfo;
      Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    //  str = "10,Z)"
    	IntegerToken intToken = {TOKEN_INTEGER_TYPE,0,2,"0x10",0x10};
      OperatorToken commaToken = {TOKEN_OPERATOR_TYPE,0,1,","};
      IdentifierToken WToken = {TOKEN_IDENTIFIER_TYPE,0,1,"Z"};
      OperatorToken CBracketToken = {TOKEN_OPERATOR_TYPE,0,1,")"};

      getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);
      getToken_ExpectAndReturn(tokenizer, (Token *)&commaToken);
      getToken_ExpectAndReturn(tokenizer, (Token *)&WToken);
    	getToken_ExpectAndReturn(tokenizer, (Token *)&CBracketToken);


    	Try {
    		handleShortLongoff(tokenizer, &operandInfo);
        printf("%d\n",operandInfo.type);
    	}Catch(ex) {
    	TEST_ASSERT_EQUAL(NOT_VALID_INSTRUCTION, ex);
    	}
}



void xtest_function_handleLongShortoff_given_longoff_0x1000_Y_expect_exception(void){
      CEXCEPTION_T ex;
      OperandInfo operandInfo;
      Tokenizer *tokenizer = (Tokenizer *)0x0badface;
      char *str = "1000,X)";
    	IntegerToken intToken = {TOKEN_INTEGER_TYPE,0,2,"0x1000",0x1000};
      OperatorToken commaToken = {TOKEN_OPERATOR_TYPE,0,1,"z"};
      IdentifierToken WToken = {TOKEN_IDENTIFIER_TYPE,0,1,"X"};
      OperatorToken CBracketToken = {TOKEN_OPERATOR_TYPE,0,1,")"};

      getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);
      getToken_ExpectAndReturn(tokenizer, (Token *)&commaToken);
      getToken_ExpectAndReturn(tokenizer, (Token *)&WToken);
    	getToken_ExpectAndReturn(tokenizer, (Token *)&CBracketToken);


    	Try {
    		handleShortLongoff(tokenizer, &operandInfo);
        printf("%d\n",operandInfo.type);
    	}Catch(ex) {
    	TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
    	}
    }

void xtest_function_handlebyte_given_0x97_expect_exception(void){
    CEXCEPTION_T ex;
    OperandInfo operandInfo;
    operandInfo.value = 0x97;
    Tokenizer *tokenizer = (Tokenizer *)0x0badface;

    OperatorToken   dollarToken = {TOKEN_OPERATOR_TYPE, 0,1,"$"};
    IntegerToken intToken = {TOKEN_INTEGER_TYPE,1,2,"0xff",0xff};

    getToken_ExpectAndReturn(tokenizer, (Token *)&dollarToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);

  	Try {
  		handleByte(tokenizer, &operandInfo);
  	}Catch(ex) {
  	TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
  	}
  }

void xtest_function_handleLongShortMem_given_0x97_expect_exception(void){
    CEXCEPTION_T ex;
    OperandInfo operandInfo;
    operandInfo.value = 0x97;
    Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char *str = "0xff97";
  	IntegerToken intToken = {TOKEN_INTEGER_TYPE,0,2,"0xff97",0xff97};

  	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);

  	Try {
  		handleLongShortMem(tokenizer, &operandInfo);
  	}Catch(ex) {
  	TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
  	}
  }

  void xtest_function_handleNEXTOperandMain_given_ADC_A_comma_dollar_0x97_expect_exception(void){
      CEXCEPTION_T ex;
      OperandInfo operandInfo;
      operandInfo.value = 0x97;
      Tokenizer *tokenizer = (Tokenizer *)0x0badface;
      //char *str = "$97";

      OperatorToken   dollarToken = {TOKEN_OPERATOR_TYPE, 0,1,"$"};
      IntegerToken intToken = {TOKEN_INTEGER_TYPE,1,2,"0xfffff",0xfffff};

      getToken_ExpectAndReturn(tokenizer, (Token *)&dollarToken);
      getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);
    	Try {
    		handleNEXTOperandMain(tokenizer, &operandInfo);
    	}Catch(ex) {
    	TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
    	}
    }

void xtest_function_handleNEXTOperandMain_given_hashtoken_expect_exception(void){
  CEXCEPTION_T ex;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;

  OperatorToken HashToken = {TOKEN_OPERATOR_TYPE,0,1,"#"};
  OperatorToken dollarToken = {TOKEN_OPERATOR_TYPE,0,1,"$"};
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,0,2,"0x97",0x97};

  getToken_ExpectAndReturn(tokenizer, (Token *)&HashToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&dollarToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);

  Try {
    handleNEXTOperandMain(tokenizer, &operandInfo);
  }Catch(ex) {
  TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
  }
}

void xtest_FUNCTION_DISPLAYOPCODE_given_0x97B9_shortmem_expect_0x97B9(void){
      uint8_t buffer[4] = {0,0,0,0};
      char *memoryToWriteCode = buffer;
      OperandInfo operandInfo;
      operandInfo.type = SHORT_MEM;
      operandInfo.value = 0x97;
      operandInfo.baseOpcode = 0x09;

     displayOpcode(&memoryToWriteCode,&operandInfo);
     TEST_ASSERT_EQUAL_HEX(0x97B9,*(uint32_t *)buffer);
     TEST_ASSERT_EQUAL_PTR(&buffer[2],memoryToWriteCode);
    }

void xtest_FUNCTION_DISPLAYOPCODE_given_0x5597B9_longmem_expect_0x5597B9(void){
      uint8_t buffer[4] = {0,0,0,0};
      char *memoryToWriteCode = buffer;
      OperandInfo operandInfo;
      operandInfo.type = LONG_MEM;
      operandInfo.value = 0x9755;
      operandInfo.baseOpcode = 0x09;

     displayOpcode(&memoryToWriteCode,&operandInfo);
     TEST_ASSERT_EQUAL_HEX(0x5597B9,*(uint32_t *)buffer);
     TEST_ASSERT_EQUAL_PTR(&buffer[3],memoryToWriteCode);
    }

void xtest_asesemble_given_adc_byte_0x55_expect_0x55A9(void){
  CEXCEPTION_T ex;
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char *str = "adc A,#97";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"adc"};
	IdentifierToken AToken = {TOKEN_IDENTIFIER_TYPE,4 ,1,"A"};
	OperatorToken   CommaToken ={TOKEN_OPERATOR_TYPE, 5,1,","};
  OperatorToken   HashToken ={TOKEN_OPERATOR_TYPE, 6,1,"#"};
	OperatorToken   dollarToken ={TOKEN_OPERATOR_TYPE, 7,1,"$"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,8,4,"55",55};


	initTokenizer_ExpectAndReturn(str,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&ADDToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&AToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&CommaToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&HashToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&dollarToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);

	Try {
		assemble(str, &memoryToWriteCode);
    TEST_ASSERT_EQUAL_HEX(0x55A9,*(uint32_t *)buffer);
    TEST_ASSERT_EQUAL_PTR(&buffer[2],memoryToWriteCode);
    printf("0x%02x%02x\n",buffer[0],buffer[1]);
	}Catch(ex) {
	TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}

void xtest_asesemble_given_adc_long_mem_0xff55_expect_0xff55C9(void){
  CEXCEPTION_T ex;
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char *str = "adc A,$55ff";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"adc"};
	IdentifierToken AToken = {TOKEN_IDENTIFIER_TYPE,4 ,1,"A"};
	OperatorToken   CommaToken ={TOKEN_OPERATOR_TYPE, 5,1,","};
	OperatorToken   dollarToken ={TOKEN_OPERATOR_TYPE, 7,1,"$"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,8,4,"0x55ff",0x55ff};


	initTokenizer_ExpectAndReturn(str,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&ADDToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&AToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&CommaToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&dollarToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);

	Try {
		assemble(str, &memoryToWriteCode);
    TEST_ASSERT_EQUAL_HEX(0xff55C9,*(uint32_t *)buffer);
    TEST_ASSERT_EQUAL_PTR(&buffer[3],memoryToWriteCode);
    printf("0x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2]);
	}Catch(ex) {
	TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}

void xtest_asesemble_given_adc_short_mem_0x55_expect_0x55B9(void){
  CEXCEPTION_T ex;
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char *str = "adc A,$55";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"adc"};
	IdentifierToken AToken = {TOKEN_IDENTIFIER_TYPE,4 ,1,"A"};
	OperatorToken   CommaToken ={TOKEN_OPERATOR_TYPE, 5,1,","};
	OperatorToken   dollarToken ={TOKEN_OPERATOR_TYPE, 7,1,"$"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,8,2,"0x55",0x55};


	initTokenizer_ExpectAndReturn(str,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&ADDToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&AToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&CommaToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&dollarToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);

	Try {
		assemble(str, &memoryToWriteCode);
    TEST_ASSERT_EQUAL_HEX(0x55B9,*(uint32_t *)buffer);
    TEST_ASSERT_EQUAL_PTR(&buffer[2],memoryToWriteCode);
    printf("0x%02x%02x\n",buffer[0],buffer[1]);
	}Catch(ex) {
	TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}

void xtest_asesemble_given_adc_index_X_expect_0xF9(void){
  CEXCEPTION_T ex;
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char *str = "adc A,(X)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"adc"};
	IdentifierToken AToken = {TOKEN_IDENTIFIER_TYPE,4 ,1,"A"};
	OperatorToken   CommaToken ={TOKEN_OPERATOR_TYPE, 5,1,","};
	OperatorToken   OBracketToken ={TOKEN_OPERATOR_TYPE, 7,1,"("};
  IdentifierToken XToken = {TOKEN_IDENTIFIER_TYPE,4 ,1,"X"};
  OperatorToken   CBracketToken ={TOKEN_OPERATOR_TYPE, 7,1,")"};


	initTokenizer_ExpectAndReturn(str,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&ADDToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&AToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&CommaToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&OBracketToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&XToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&CBracketToken);

	Try {
		assemble(str, &memoryToWriteCode);
    TEST_ASSERT_EQUAL_HEX(0xF9,*(uint32_t *)buffer);
    TEST_ASSERT_EQUAL_PTR(&buffer[1],memoryToWriteCode);
    printf("0x%02x\n",buffer[0]);
	}Catch(ex) {
	TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}

void xtest_asesemble_given_adc_index_Y_expect_0x90F9(void){
  CEXCEPTION_T ex;
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char *str = "adc A,(X)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"adc"};
	IdentifierToken AToken = {TOKEN_IDENTIFIER_TYPE,4 ,1,"A"};
	OperatorToken   CommaToken ={TOKEN_OPERATOR_TYPE, 5,1,","};
	OperatorToken   OBracketToken ={TOKEN_OPERATOR_TYPE, 7,1,"("};
  IdentifierToken YToken = {TOKEN_IDENTIFIER_TYPE,4 ,1,"Y"};
  OperatorToken   CBracketToken ={TOKEN_OPERATOR_TYPE, 7,1,")"};


	initTokenizer_ExpectAndReturn(str,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&ADDToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&AToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&CommaToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&OBracketToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&YToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&CBracketToken);

	Try {
		assemble(str, &memoryToWriteCode);
    TEST_ASSERT_EQUAL_HEX(0xF990,*(uint32_t *)buffer);
    TEST_ASSERT_EQUAL_PTR(&buffer[1],memoryToWriteCode);
    printf("0x%02x%02x\n",buffer[0],buffer[1]);
	}Catch(ex) {
	TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
/*
void xtest_function_handleNEXT2OperandMain_given_XorY_expect_exception(void){
    CEXCEPTION_T ex;
    OperandInfo operandInfo;
    Tokenizer *tokenizer = (Tokenizer *)0x0badface;

    IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,1,"Y"};
    OperatorToken   CBracketToken = {TOKEN_OPERATOR_TYPE,0,1,")"};

    getToken_ExpectAndReturn(tokenizer, (Token *)&ADDToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&CBracketToken);
  	Try {
  		handleINEXT2OperandMain(tokenizer, &operandInfo);
      printf("%d\n",operandInfo.type);
  	}Catch(ex) {
  	TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
  	}
  }
*/
