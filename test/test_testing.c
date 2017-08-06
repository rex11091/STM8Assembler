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

    IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,1,"X"};
    OperatorToken   CBracketToken = {TOKEN_OPERATOR_TYPE,0,1,","};

    getToken_ExpectAndReturn(tokenizer, (Token *)&ADDToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&CBracketToken);
  	Try {
  		handleIndexXandY(tokenizer, &operandInfo);
      printf("%d\n",operandInfo.type);
  	}Catch(ex) {
  	  dumpException(ex);
  	}
    freeException(ex);
  }
*/
void xtest_function_handleShortLongPtrorWithIndex_given_0x97_X_expect_short(void){
        CEXCEPTION_T ex;
        OperandInfo operandInfo;
        Tokenizer *tokenizer = (Tokenizer *)0x0badface;

        OperatorToken dollarToken = {TOKEN_OPERATOR_TYPE,0,1,"$"};
      	IntegerToken intToken = {TOKEN_INTEGER_TYPE,0,2,"0x97",0x97};
        OperatorToken dotToken = {TOKEN_OPERATOR_TYPE,0,1,"."};
        IdentifierToken WToken = {TOKEN_IDENTIFIER_TYPE,0,1,"W"};
        OperatorToken SquareBracketToken = {TOKEN_OPERATOR_TYPE,0,1,"]"};
        OperatorToken commaToken = {TOKEN_OPERATOR_TYPE,0,1,","};
        IdentifierToken W1Token = {TOKEN_IDENTIFIER_TYPE,0,1,"X"};
        OperatorToken CloseBracketToken = {TOKEN_OPERATOR_TYPE,0,1,")"};

        getToken_ExpectAndReturn(tokenizer, (Token *)&dollarToken);
        getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);
        getToken_ExpectAndReturn(tokenizer, (Token *)&dotToken);
        getToken_ExpectAndReturn(tokenizer, (Token *)&WToken);
        getToken_ExpectAndReturn(tokenizer, (Token *)&SquareBracketToken);
        getToken_ExpectAndReturn(tokenizer, (Token *)&commaToken);
        getToken_ExpectAndReturn(tokenizer, (Token *)&W1Token);
        getToken_ExpectAndReturn(tokenizer, (Token *)&CloseBracketToken);

      	Try {
      		handleShortLongPtrorWithIndex(tokenizer, &operandInfo);
          printf("%d\n",operandInfo.type);
      	}Catch(ex) {
      	TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
      	}
      }

void xtest_function_getlongshortType_given_0x97_expect_short(void){
    CEXCEPTION_T ex;
    OperandInfo operandInfo;
    Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  	IntegerToken intToken = {TOKEN_INTEGER_TYPE,0,2,"0x97",0x97};

  	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);

  	Try {
  		getLongShortType(tokenizer, &operandInfo);
      printf("%d\n",operandInfo.type);
  	}Catch(ex) {
  	TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
  	}
  }
void xtest_function_getlongshortType_given_0x9797_expect_short(void){
      CEXCEPTION_T ex;
      OperandInfo operandInfo;
      Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    	IntegerToken intToken = {TOKEN_INTEGER_TYPE,0,4,"0x9797",0x9797};

    	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);

    	Try {
    		getLongShortType(tokenizer, &operandInfo);
        printf("%d\n",operandInfo.type);
    	}Catch(ex) {
    	TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
    	}
    }
void xtest_function_gettokenDotWBracket_given_dot_W_bracket_expect_no_Exception(void){
  CEXCEPTION_T ex;
  OperandInfo operandInfo;
  operandInfo.value = 0x97;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;

  OperatorToken dotToken = {TOKEN_OPERATOR_TYPE,0,1,"."};
  IdentifierToken WToken = {TOKEN_IDENTIFIER_TYPE,0,1,"W"};
  OperatorToken SquareBracketToken = {TOKEN_OPERATOR_TYPE,0,1,"]"};
  getToken_ExpectAndReturn(tokenizer, (Token *)&dotToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&SquareBracketToken);

	Try {
    	gettokenDotWBracket(tokenizer, &operandInfo);
      }Catch(ex) {
                  TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
                 }
}
void xtest_function_handleshorlongtptr_given_0x97_expect_short(void){
        CEXCEPTION_T ex;
        OperandInfo operandInfo;
        Tokenizer *tokenizer = (Tokenizer *)0x0badface;

        OperatorToken dollarToken = {TOKEN_OPERATOR_TYPE,0,1,"$"};
      	IntegerToken intToken = {TOKEN_INTEGER_TYPE,0,2,"0x97",0x97};
        OperatorToken dotToken = {TOKEN_OPERATOR_TYPE,0,1,"."};
        IdentifierToken WToken = {TOKEN_IDENTIFIER_TYPE,0,1,"W"};
        OperatorToken SquareBracketToken = {TOKEN_OPERATOR_TYPE,0,1,"]"};

        getToken_ExpectAndReturn(tokenizer, (Token *)&dollarToken);
        getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);
        getToken_ExpectAndReturn(tokenizer, (Token *)&dotToken);
        getToken_ExpectAndReturn(tokenizer, (Token *)&WToken);
        getToken_ExpectAndReturn(tokenizer, (Token *)&SquareBracketToken);

      	Try {
      		handleShortLongPtr(tokenizer, &operandInfo);
      	}Catch(ex) {
      	TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
      	}
      }


void xtest_functiong_getCloseBracket_given_comma_expect_exception(void){
    CEXCEPTION_T ex;
    OperandInfo operandInfo;
    operandInfo.type = SHORTOFF_X;
    Tokenizer *tokenizer = (Tokenizer *)0x0badface;
        OperatorToken CBracketToken = {TOKEN_OPERATOR_TYPE,0,1,","};
        getToken_ExpectAndReturn(tokenizer, (Token *)&CBracketToken);
        Try {
      		getCloseBracketSymbol(tokenizer, &operandInfo);
      	}Catch(ex) {
      	  dumpException(ex);
      	}
        freeException(ex);
}

void xtest_function_convert_ShortOff_to_LongOFF_given_Shortoff_expect_Longoff(void){
    CEXCEPTION_T ex;
    OperandInfo operandInfo;
    operandInfo.type = SHORTOFF_X;
    Tokenizer *tokenizer = (Tokenizer *)0x0badface;

  	Try {
  		convertShortoffToLongoff(tokenizer, &operandInfo);
      printf("%d\n",operandInfo.type);
  	}Catch(ex) {
  	TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
  	}
  }
void xtest_function_getShortLongoffIndexX_Y_SP_given_XorY_SP_expect_No_exception(void){
    CEXCEPTION_T ex;
    OperandInfo operandInfo;
    Tokenizer *tokenizer = (Tokenizer *)0x0badface;

    OperatorToken commaToken = {TOKEN_OPERATOR_TYPE,0,1,","};
    IdentifierToken WToken = {TOKEN_IDENTIFIER_TYPE,0,1,"Z"};

    getToken_ExpectAndReturn(tokenizer, (Token *)&commaToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&WToken);
    Try {
  		getShortlongoffIndexX_Y_SP(tokenizer, &operandInfo);
  	}Catch(ex) {
  	  dumpException(ex);
  	}
    freeException(ex);
  }
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
void xtest_function_handleLongShortoff_given_Lonfoff_0x1000_Y_expect_not_exception(void){
    CEXCEPTION_T ex;
    OperandInfo operandInfo;
    Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  //  str = "1000,Y)"
  	IntegerToken intToken = {TOKEN_INTEGER_TYPE,0,4,"0x1000",0x1000};
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
void xtest_function_handleLongShortoff_given_shortoff_0x10_Z_expect_exception(void){

      CEXCEPTION_T ex;
      OperandInfo operandInfo;
      Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    //  str = "10,Z)"
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
void xtest_function_handleLongShortMem_given_0x97_expect_shortMem(void){
    CEXCEPTION_T ex;
    OperandInfo operandInfo;
    Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  	IntegerToken intToken = {TOKEN_INTEGER_TYPE,0,2,"0x97",0x97};

  	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);

  	Try {
  		handleLongShortMem(tokenizer, &operandInfo);
      printf("%d\n",operandInfo.type );
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
void xtest_handleNext_2_OperandMain_given_shortoff_SP_expect_exception(void){
  CEXCEPTION_T ex;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;

  OperatorToken dollarToken = {TOKEN_OPERATOR_TYPE,0,1,"$"};
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,0,2,"0x10",0x10};
  OperatorToken commaToken = {TOKEN_OPERATOR_TYPE,0,1,","};
  IdentifierToken WToken = {TOKEN_IDENTIFIER_TYPE,0,1,"SP"};
  OperatorToken CBracketToken = {TOKEN_OPERATOR_TYPE,0,1,")"};

  getToken_ExpectAndReturn(tokenizer, (Token *)&dollarToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&commaToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&CBracketToken);


  Try {
    handleINExt_2_OperandMain(tokenizer, &operandInfo);
    printf("%d\n",operandInfo.type);
  }Catch(ex) {
  TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
  }
}
void xtest_handleNext_2_OperandMain_given_indexX_expect_exception(void){
  CEXCEPTION_T ex;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;

  IdentifierToken WToken = {TOKEN_IDENTIFIER_TYPE,0,1,"Y"};
  OperatorToken CBracketToken = {TOKEN_OPERATOR_TYPE,0,1,")"};

  getToken_ExpectAndReturn(tokenizer, (Token *)&WToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&CBracketToken);


  Try {
    handleINExt_2_OperandMain(tokenizer, &operandInfo);
    printf("%d\n",operandInfo.type);
  }Catch(ex) {
  TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
  }
}

void xtest_FUNCTION_DISPLAYOPCODE_given_0x97_Shortptr_expect_0x97D992(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  operandInfo.type = SHORTPTR_X;
  operandInfo.value = 0x97;
  operandInfo.baseOpcode = 0x09;

  displayOpcode(&memoryToWriteCode,&operandInfo);
  TEST_ASSERT_EQUAL_HEX(0x97D992,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[3],memoryToWriteCode);
}
void xtest_FUNCTION_DISPLAYOPCODE_given_0x97ff_longptr_expect_0xff97D972(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  operandInfo.type = LONGPTR_X;
  operandInfo.value = 0x97ff;
  operandInfo.baseOpcode = 0x09;

  displayOpcode(&memoryToWriteCode,&operandInfo);
  TEST_ASSERT_EQUAL_HEX(0xff97D972,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[4],memoryToWriteCode);

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
void xtest_FUNCTION_DISPLAYOPCODE_given_0x5597B9_longmem_expect_0x5597C9(void){
      uint8_t buffer[4] = {0,0,0,0};
      char *memoryToWriteCode = buffer;
      OperandInfo operandInfo;
      operandInfo.type = LONG_MEM;
      operandInfo.value = 0x9755;
      operandInfo.baseOpcode = 0x09;

     displayOpcode(&memoryToWriteCode,&operandInfo);
     TEST_ASSERT_EQUAL_HEX(0x5597C9,*(uint32_t *)buffer);
     TEST_ASSERT_EQUAL_PTR(&buffer[3],memoryToWriteCode);
    }
void xtest_FUNCTION_DISPLAYOPCODE_given_longoffY_expect_0x5597C9(void){
          uint8_t buffer[4] = {0,0,0,0};
          char *memoryToWriteCode = buffer;
          OperandInfo operandInfo;
          operandInfo.type = LONGOFF_Y;
          operandInfo.value = 0x9755;
          operandInfo.baseOpcode = 0x09;

         displayOpcode(&memoryToWriteCode,&operandInfo);
         TEST_ASSERT_EQUAL_HEX(0x5597C9,*(uint32_t *)buffer);
         TEST_ASSERT_EQUAL_PTR(&buffer[4],memoryToWriteCode);
        }

/*
  test ADC
*/
void test_asesemble_given_adc_byte_0x55_expect_0x55A9(void){
  CEXCEPTION_T ex;
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char *str = "adc A,#$97";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"adc"};
	IdentifierToken AToken = {TOKEN_IDENTIFIER_TYPE,4 ,1,"A"};
	OperatorToken   CommaToken ={TOKEN_OPERATOR_TYPE, 5,1,","};
  OperatorToken   HashToken ={TOKEN_OPERATOR_TYPE, 6,1,"#"};
	OperatorToken   dollarToken ={TOKEN_OPERATOR_TYPE, 7,1,"$"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,8,4,"0x55",0x55};


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
void test_asesemble_given_adc_long_mem_0xff55_expect_0xff55C9(void){
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
void test_asesemble_given_adc_short_mem_0x55_expect_0x55B9(void){
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
void test_asesemble_given_adc_index_X_expect_0xF9(void){
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
void test_asesemble_given_adc_index_Y_expect_0x90F9(void){
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
    TEST_ASSERT_EQUAL_PTR(&buffer[2],memoryToWriteCode);
    printf("0x%02x%02x\n",buffer[0],buffer[1]);
	}Catch(ex) {
	TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void test_asesemble_given_adc_shortoff_index_X_expect_0x10E9(void){
  CEXCEPTION_T ex;
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char *str = "ADC A,($10,X)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"ADC"};
	IdentifierToken AToken = {TOKEN_IDENTIFIER_TYPE,4 ,1,"A"};
	OperatorToken   CommaToken ={TOKEN_OPERATOR_TYPE, 5,1,","};
	OperatorToken   OBracketToken ={TOKEN_OPERATOR_TYPE, 7,1,"("};
  OperatorToken   dollarToken ={TOKEN_OPERATOR_TYPE, 8,1,"$"};
  IntegerToken    intToken = {TOKEN_INTEGER_TYPE,9,2,"0x10",0x10};
  OperatorToken   comma1Token ={TOKEN_OPERATOR_TYPE, 8,1,","};
  IdentifierToken WToken = {TOKEN_IDENTIFIER_TYPE,4 ,1,"X"};
  OperatorToken   CBracketToken ={TOKEN_OPERATOR_TYPE, 7,1,")"};

	initTokenizer_ExpectAndReturn(str,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&ADDToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&AToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&CommaToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&OBracketToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&dollarToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&comma1Token);
	getToken_ExpectAndReturn(tokenizer, (Token *)&WToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&CBracketToken);

	Try {
		assemble(str, &memoryToWriteCode);
    TEST_ASSERT_EQUAL_HEX(0x10E9,*(uint32_t *)buffer);
    TEST_ASSERT_EQUAL_PTR(&buffer[2],memoryToWriteCode);
    printf("0x%02x%02x\n",buffer[0],buffer[1]);
	}Catch(ex) {
	TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void test_asesemble_given_adc_shortoff_index_Y_expect_0x10E990(void){
  CEXCEPTION_T ex;
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char *str = "ADC A,($10,Y)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"ADC"};
	IdentifierToken AToken = {TOKEN_IDENTIFIER_TYPE,4 ,1,"A"};
	OperatorToken   CommaToken ={TOKEN_OPERATOR_TYPE, 5,1,","};
	OperatorToken   OBracketToken ={TOKEN_OPERATOR_TYPE, 7,1,"("};
  OperatorToken   dollarToken ={TOKEN_OPERATOR_TYPE, 8,1,"$"};
  IntegerToken    intToken = {TOKEN_INTEGER_TYPE,9,2,"0x10",0x10};
  OperatorToken   comma1Token ={TOKEN_OPERATOR_TYPE, 8,1,","};
  IdentifierToken WToken = {TOKEN_IDENTIFIER_TYPE,4 ,1,"Y"};
  OperatorToken   CBracketToken ={TOKEN_OPERATOR_TYPE, 7,1,")"};

	initTokenizer_ExpectAndReturn(str,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&ADDToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&AToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&CommaToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&OBracketToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&dollarToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&comma1Token);
	getToken_ExpectAndReturn(tokenizer, (Token *)&WToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&CBracketToken);

	Try {
		assemble(str, &memoryToWriteCode);
    TEST_ASSERT_EQUAL_HEX(0x10E990,*(uint32_t *)buffer);
    TEST_ASSERT_EQUAL_PTR(&buffer[3],memoryToWriteCode);
    printf("0x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2]);
	}Catch(ex) {
	TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void test_asesemble_given_adc_longoff_index_X_expect_0x8810D9(void){
  CEXCEPTION_T ex;
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char *str = "ADC A,($1088,X)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"ADC"};
	IdentifierToken AToken = {TOKEN_IDENTIFIER_TYPE,4 ,1,"A"};
	OperatorToken   CommaToken ={TOKEN_OPERATOR_TYPE, 5,1,","};
	OperatorToken   OBracketToken ={TOKEN_OPERATOR_TYPE, 6,1,"("};
  OperatorToken   dollarToken ={TOKEN_OPERATOR_TYPE, 7,1,"$"};
  IntegerToken    intToken = {TOKEN_INTEGER_TYPE, 8,4,"0x1088",0x1088};
  OperatorToken   comma1Token ={TOKEN_OPERATOR_TYPE, 12,1,","};
  IdentifierToken WToken = {TOKEN_IDENTIFIER_TYPE, 13,1,"X"};
  OperatorToken   CBracketToken ={TOKEN_OPERATOR_TYPE, 14,1,")"};

	initTokenizer_ExpectAndReturn(str,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&ADDToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&AToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&CommaToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&OBracketToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&dollarToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&comma1Token);
	getToken_ExpectAndReturn(tokenizer, (Token *)&WToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&CBracketToken);

	Try {
		assemble(str, &memoryToWriteCode);
    TEST_ASSERT_EQUAL_HEX(0x8810D9,*(uint32_t *)buffer);
    TEST_ASSERT_EQUAL_PTR(&buffer[3],memoryToWriteCode);
    printf("0x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2]);
	}Catch(ex) {
	TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void test_asesemble_given_adc_longoff_index_Y_expect_0x8810D990(void){
  CEXCEPTION_T ex;
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char *str = "ADC A,($1088,Y)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"ADC"};
	IdentifierToken AToken = {TOKEN_IDENTIFIER_TYPE,4 ,1,"A"};
	OperatorToken   CommaToken ={TOKEN_OPERATOR_TYPE, 5,1,","};
	OperatorToken   OBracketToken ={TOKEN_OPERATOR_TYPE, 6,1,"("};
  OperatorToken   dollarToken ={TOKEN_OPERATOR_TYPE, 7,1,"$"};
  IntegerToken    intToken = {TOKEN_INTEGER_TYPE, 8,4,"0x1088",0x1088};
  OperatorToken   comma1Token ={TOKEN_OPERATOR_TYPE, 12,1,","};
  IdentifierToken WToken = {TOKEN_IDENTIFIER_TYPE, 13,1,"Y"};
  OperatorToken   CBracketToken ={TOKEN_OPERATOR_TYPE, 14,1,")"};

	initTokenizer_ExpectAndReturn(str,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&ADDToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&AToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&CommaToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&OBracketToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&dollarToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&comma1Token);
	getToken_ExpectAndReturn(tokenizer, (Token *)&WToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&CBracketToken);

	Try {
		assemble(str, &memoryToWriteCode);
    TEST_ASSERT_EQUAL_HEX(0x8810D990,*(uint32_t *)buffer);
    TEST_ASSERT_EQUAL_PTR(&buffer[4],memoryToWriteCode);
    printf("0x%02x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2],buffer[3]);
	}Catch(ex) {
	TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void test_asesemble_given_adc_shortoff_index_SP_expect_0x8819(void){
  CEXCEPTION_T ex;
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char *str = "ADC A,($88,SP)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"ADC"};
	IdentifierToken AToken = {TOKEN_IDENTIFIER_TYPE,4 ,1,"A"};
	OperatorToken   CommaToken ={TOKEN_OPERATOR_TYPE, 5,1,","};
	OperatorToken   OBracketToken ={TOKEN_OPERATOR_TYPE, 6,1,"("};
  OperatorToken   dollarToken ={TOKEN_OPERATOR_TYPE, 7,1,"$"};
  IntegerToken    intToken = {TOKEN_INTEGER_TYPE, 8,2,"0x88",0x88};
  OperatorToken   comma1Token ={TOKEN_OPERATOR_TYPE, 12,1,","};
  IdentifierToken WToken = {TOKEN_IDENTIFIER_TYPE, 13,2,"SP"};
  OperatorToken   CBracketToken ={TOKEN_OPERATOR_TYPE, 15,1,")"};

	initTokenizer_ExpectAndReturn(str,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&ADDToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&AToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&CommaToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&OBracketToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&dollarToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&comma1Token);
	getToken_ExpectAndReturn(tokenizer, (Token *)&WToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&CBracketToken);

	Try {
		assemble(str, &memoryToWriteCode);
    TEST_ASSERT_EQUAL_HEX(0x8819,*(uint32_t *)buffer);
    TEST_ASSERT_EQUAL_PTR(&buffer[2],memoryToWriteCode);
    printf("0x%02x%02x\n",buffer[0],buffer[1]);
	}Catch(ex) {
	TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void test_asesemble_given_adc_shortptr_expect_0x55c992(void){
  CEXCEPTION_T ex;
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char *str = "ADC A,[$55.w]";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"ADC"};
	IdentifierToken AToken = {TOKEN_IDENTIFIER_TYPE,4 ,1,"A"};
	OperatorToken   CommaToken ={TOKEN_OPERATOR_TYPE, 5,1,","};
	OperatorToken   OBracketToken ={TOKEN_OPERATOR_TYPE, 6,1,"["};
  OperatorToken   dollarToken ={TOKEN_OPERATOR_TYPE, 7,1,"$"};
  IntegerToken    intToken = {TOKEN_INTEGER_TYPE, 8,2,"0x55",0x55};
  OperatorToken   dotToken ={TOKEN_OPERATOR_TYPE, 10,1,"."};
  IdentifierToken WToken = {TOKEN_IDENTIFIER_TYPE, 11,2,"W"};
  OperatorToken   CBracketToken ={TOKEN_OPERATOR_TYPE, 12,1,"]"};

	initTokenizer_ExpectAndReturn(str,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&ADDToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&AToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&CommaToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&OBracketToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&dollarToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&dotToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&WToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&CBracketToken);

	Try {
		assemble(str, &memoryToWriteCode);
    TEST_ASSERT_EQUAL_HEX(0x55c992,*(uint32_t *)buffer);
    TEST_ASSERT_EQUAL_PTR(&buffer[3],memoryToWriteCode);
    printf("0x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2]);
	}Catch(ex) {
	TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void test_asesemble_given_adc_longptr_expect_0x4455c972(void){
  CEXCEPTION_T ex;
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char *str = "ADC A,[$5544.w]";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"ADC"};
	IdentifierToken AToken = {TOKEN_IDENTIFIER_TYPE,4 ,1,"A"};
	OperatorToken   CommaToken ={TOKEN_OPERATOR_TYPE, 5,1,","};
	OperatorToken   OBracketToken ={TOKEN_OPERATOR_TYPE, 6,1,"["};
  OperatorToken   dollarToken ={TOKEN_OPERATOR_TYPE, 7,1,"$"};
  IntegerToken    intToken = {TOKEN_INTEGER_TYPE, 8,2,"0x5544",0x5544};
  OperatorToken   dotToken ={TOKEN_OPERATOR_TYPE, 10,1,"."};
  IdentifierToken WToken = {TOKEN_IDENTIFIER_TYPE, 11,2,"W"};
  OperatorToken   CBracketToken ={TOKEN_OPERATOR_TYPE, 12,1,"]"};

	initTokenizer_ExpectAndReturn(str,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&ADDToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&AToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&CommaToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&OBracketToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&dollarToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&dotToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&WToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&CBracketToken);

	Try {
		assemble(str, &memoryToWriteCode);
    TEST_ASSERT_EQUAL_HEX(0x4455c972,*(uint32_t *)buffer);
    TEST_ASSERT_EQUAL_PTR(&buffer[4],memoryToWriteCode);
    printf("0x%02x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2],buffer[3]);
	}Catch(ex) {
	TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void test_asesemble_given_adc_shortptr_index_X_expect_0x45D992(void){
  CEXCEPTION_T ex;
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char *str = "ADC A,([$45.w],X)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"ADC"};
	IdentifierToken AToken = {TOKEN_IDENTIFIER_TYPE,4 ,1,"A"};
	OperatorToken   CommaToken ={TOKEN_OPERATOR_TYPE, 5,1,","};
  OperatorToken   ORndBracketToken ={TOKEN_OPERATOR_TYPE, 6,1,"("};
	OperatorToken   OSqrBracketToken ={TOKEN_OPERATOR_TYPE, 7,1,"["};
  OperatorToken   dollarToken ={TOKEN_OPERATOR_TYPE, 8,1,"$"};
  IntegerToken    intToken = {TOKEN_INTEGER_TYPE, 9,2,"0x45",0x45};
  OperatorToken   dotToken ={TOKEN_OPERATOR_TYPE, 11,1,"."};
  IdentifierToken WToken = {TOKEN_IDENTIFIER_TYPE, 12,1,"W"};
  OperatorToken   CSqrBracketToken ={TOKEN_OPERATOR_TYPE, 13,1,"]"};
  OperatorToken   comma1Token ={TOKEN_OPERATOR_TYPE, 14,1,","};
  IdentifierToken W1Token = {TOKEN_IDENTIFIER_TYPE, 15,1,"X"};
  OperatorToken   CRndBracketToken ={TOKEN_OPERATOR_TYPE, 16,1,")"};

	initTokenizer_ExpectAndReturn(str,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&ADDToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&AToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&CommaToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&ORndBracketToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&OSqrBracketToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&dollarToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&dotToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&WToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&CSqrBracketToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&comma1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&W1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&CRndBracketToken);

	Try {
		assemble(str, &memoryToWriteCode);
    TEST_ASSERT_EQUAL_HEX(0x45D992,*(uint32_t *)buffer);
    TEST_ASSERT_EQUAL_PTR(&buffer[3],memoryToWriteCode);
    printf("0x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2]);
	}Catch(ex) {
	TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void test_asesemble_given_adc_shortptr_index_Y_expect_0x45D991(void){
  CEXCEPTION_T ex;
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char *str = "ADC A,([$45.w],Y)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"ADC"};
	IdentifierToken AToken = {TOKEN_IDENTIFIER_TYPE,4 ,1,"A"};
	OperatorToken   CommaToken ={TOKEN_OPERATOR_TYPE, 5,1,","};
  OperatorToken   ORndBracketToken ={TOKEN_OPERATOR_TYPE, 6,1,"("};
	OperatorToken   OSqrBracketToken ={TOKEN_OPERATOR_TYPE, 7,1,"["};
  OperatorToken   dollarToken ={TOKEN_OPERATOR_TYPE, 8,1,"$"};
  IntegerToken    intToken = {TOKEN_INTEGER_TYPE, 9,2,"0x45",0x45};
  OperatorToken   dotToken ={TOKEN_OPERATOR_TYPE, 11,1,"."};
  IdentifierToken WToken = {TOKEN_IDENTIFIER_TYPE, 12,1,"W"};
  OperatorToken   CSqrBracketToken ={TOKEN_OPERATOR_TYPE, 13,1,"]"};
  OperatorToken   comma1Token ={TOKEN_OPERATOR_TYPE, 14,1,","};
  IdentifierToken W1Token = {TOKEN_IDENTIFIER_TYPE, 15,1,"Y"};
  OperatorToken   CRndBracketToken ={TOKEN_OPERATOR_TYPE, 16,1,")"};

	initTokenizer_ExpectAndReturn(str,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&ADDToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&AToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&CommaToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&ORndBracketToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&OSqrBracketToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&dollarToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&dotToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&WToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&CSqrBracketToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&comma1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&W1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&CRndBracketToken);

	Try {
		assemble(str, &memoryToWriteCode);
    TEST_ASSERT_EQUAL_HEX(0x45D991,*(uint32_t *)buffer);
    TEST_ASSERT_EQUAL_PTR(&buffer[3],memoryToWriteCode);
    printf("0x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2]);
	}Catch(ex) {
	TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void test_asesemble_given_adc_longptr_index_X_expect_0x5545D972(void){
  CEXCEPTION_T ex;
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char *str = "ADC A,([$4555.w],X)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"ADC"};
	IdentifierToken AToken = {TOKEN_IDENTIFIER_TYPE,4 ,1,"A"};
	OperatorToken   CommaToken ={TOKEN_OPERATOR_TYPE, 5,1,","};
  OperatorToken   ORndBracketToken ={TOKEN_OPERATOR_TYPE, 6,1,"("};
	OperatorToken   OSqrBracketToken ={TOKEN_OPERATOR_TYPE, 7,1,"["};
  OperatorToken   dollarToken ={TOKEN_OPERATOR_TYPE, 8,1,"$"};
  IntegerToken    intToken = {TOKEN_INTEGER_TYPE, 9,4,"0x4555",0x4555};
  OperatorToken   dotToken ={TOKEN_OPERATOR_TYPE, 13,1,"."};
  IdentifierToken WToken = {TOKEN_IDENTIFIER_TYPE, 14,1,"W"};
  OperatorToken   CSqrBracketToken ={TOKEN_OPERATOR_TYPE, 15,1,"]"};
  OperatorToken   comma1Token ={TOKEN_OPERATOR_TYPE, 16,1,","};
  IdentifierToken W1Token = {TOKEN_IDENTIFIER_TYPE, 17,1,"X"};
  OperatorToken   CRndBracketToken ={TOKEN_OPERATOR_TYPE, 18,1,")"};

	initTokenizer_ExpectAndReturn(str,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&ADDToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&AToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&CommaToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&ORndBracketToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&OSqrBracketToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&dollarToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&dotToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&WToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&CSqrBracketToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&comma1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&W1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&CRndBracketToken);

	Try {
		assemble(str, &memoryToWriteCode);
    TEST_ASSERT_EQUAL_HEX(0x5545D972,*(uint32_t *)buffer);
    TEST_ASSERT_EQUAL_PTR(&buffer[4],memoryToWriteCode);
    printf("0x%02x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2],buffer[3]);
	}Catch(ex) {
	TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
