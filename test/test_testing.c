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

//test function getLongShortType
void test_function_getlongshortType_given_0x97_expect_short_16(void){
    OperandInfo operandInfo;
    Tokenizer *tokenizer = (Tokenizer *)0x0badface;

  	IntegerToken intToken = {TOKEN_INTEGER_TYPE,0,2,"0x97",0x97};
  	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);

  	getLongShortType(tokenizer, &operandInfo);
    TEST_ASSERT_EQUAL(16,operandInfo.type);
}
void test_function_getlongshortType_given_255_ff_expect_short_16(void){

    OperandInfo operandInfo;
    Tokenizer *tokenizer = (Tokenizer *)0x0badface;

  	IntegerToken intToken = {TOKEN_INTEGER_TYPE,0,3,"255",255};
  	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);

  	getLongShortType(tokenizer, &operandInfo);
    TEST_ASSERT_EQUAL(16,operandInfo.type);
}
void test_function_getlongshortType_given_0x9797_expect_long_15(void){

    OperandInfo operandInfo;
    Tokenizer *tokenizer = (Tokenizer *)0x0badface;

    IntegerToken intToken = {TOKEN_INTEGER_TYPE,0,4,"0x9797",0x9797};
    getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);

    getLongShortType(tokenizer, &operandInfo);
    TEST_ASSERT_EQUAL(15,operandInfo.type);
}
void test_function_getlongshortType_given_65535_ffff_expect_long_15(void){
    OperandInfo operandInfo;
    Tokenizer *tokenizer = (Tokenizer *)0x0badface;

    IntegerToken intToken = {TOKEN_INTEGER_TYPE,0,6,"0xffff",0xffff};
    getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);

    getLongShortType(tokenizer, &operandInfo);
    TEST_ASSERT_EQUAL(15,operandInfo.type);
}
void test_function_getlongshortType_given_0x9797f_expect_Exception_limit_exceeded(void){
  CEXCEPTION_T ex;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;

  IntegerToken intToken = {TOKEN_INTEGER_TYPE,0,5,"0x9797f",0x9797f};
  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);

  Try {
      getLongShortType(tokenizer, &operandInfo);
      }Catch(ex) {
      TEST_ASSERT_EQUAL(LIMIT_EXCEEDED, ex);
      }
}

//test function gettokenDotWBracket
void test_function_gettokenDotWBracket_given_comma_represent_dollar_expect_not_valid_operator(void){
  CEXCEPTION_T ex;
  OperandInfo operandInfo;
  operandInfo.value = 0x97;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;

  OperatorToken dotToken = {TOKEN_OPERATOR_TYPE,0,1,","};
  getToken_ExpectAndReturn(tokenizer, (Token *)&dotToken);

	Try {
    	gettokenDotWBracket(tokenizer, &operandInfo);
      }Catch(ex) {
                  TEST_ASSERT_EQUAL(NOT_VALID_OPERATOR, ex);
                 }
}
void test_function_gettokenDotWBracket_given_dot_X_represent_W_expect_Not_valid_identifier(void){
  CEXCEPTION_T ex;
  OperandInfo operandInfo;
  operandInfo.value = 0x97;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;

  OperatorToken dotToken = {TOKEN_OPERATOR_TYPE,0,1,"."};
  IdentifierToken WToken = {TOKEN_IDENTIFIER_TYPE,0,1,"X"};
  getToken_ExpectAndReturn(tokenizer, (Token *)&dotToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WToken);

	Try {
    	gettokenDotWBracket(tokenizer, &operandInfo);
      }Catch(ex) {
                  TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER, ex);
                 }
}
void test_function_gettokenDotWBracket_given_dot_W_dot_expect_Exception_Not_valid_operator(void){
  CEXCEPTION_T ex;
  OperandInfo operandInfo;
  operandInfo.value = 0x97;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;

  OperatorToken dotToken = {TOKEN_OPERATOR_TYPE,0,1,"."};
  IdentifierToken WToken = {TOKEN_IDENTIFIER_TYPE,0,1,"W"};
  OperatorToken SquareBracketToken = {TOKEN_OPERATOR_TYPE,0,1,"."};
  getToken_ExpectAndReturn(tokenizer, (Token *)&dotToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&SquareBracketToken);

	Try {
    	gettokenDotWBracket(tokenizer, &operandInfo);
      }Catch(ex) {
                  TEST_ASSERT_EQUAL(NOT_VALID_OPERATOR, ex);
                 }
}
void test_function_gettokenDotWBracket_given_dot_W_bracket_expect_not_exception(void){
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
                  TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER, ex);
                 }
}

//test function getCloseBracketSymbol
void test_function_getCloseBracket_given_comma_expect_exception_not_valid_operator(void){
  CEXCEPTION_T ex;
  OperandInfo operandInfo;
  operandInfo.type = SHORTOFF_X;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  OperatorToken CBracketToken = {TOKEN_OPERATOR_TYPE,0,1,","};
  getToken_ExpectAndReturn(tokenizer, (Token *)&CBracketToken);
    Try {
        getCloseBracketSymbol(tokenizer, &operandInfo);
        }Catch(ex) {
        TEST_ASSERT_EQUAL(NOT_VALID_OPERATOR,ex);
        }
}
void test_function_getCloseBracket_given_bracket_expect_not_exception(void){
  CEXCEPTION_T ex;
  OperandInfo operandInfo;
  operandInfo.type = SHORTOFF_X;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  OperatorToken CBracketToken = {TOKEN_OPERATOR_TYPE,0,1,")"};
  getToken_ExpectAndReturn(tokenizer, (Token *)&CBracketToken);
    Try {
        getCloseBracketSymbol(tokenizer, &operandInfo);
        }Catch(ex) {
        TEST_ASSERT_EQUAL(NOT_VALID_OPERATOR,ex);
        }
}

//test function convertShortLongPtrType
void test_function_convertShortLongPtrType_given_Short_expect_shortptr_10(void){
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  OperandInfo operandInfo;
  operandInfo.type = Short;
  convertShortLongPtrType(tokenizer,&operandInfo);
  TEST_ASSERT_EQUAL(10,operandInfo.type);
}
void test_function_convertShortLongPtrType_given_Long_expect_Longptr_11(void){
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  OperandInfo operandInfo;
  operandInfo.type = Long;
  convertShortLongPtrType(tokenizer,&operandInfo);
  TEST_ASSERT_EQUAL(11,operandInfo.type);
}
void test_function_convertShortLongPtrType_given_shortoff_X_expect_exception(void){
  CEXCEPTION_T ex;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  OperandInfo operandInfo;
  operandInfo.type =SHORTOFF_X;
  Try {
      convertShortLongPtrType(tokenizer, &operandInfo);
      }Catch(ex) {
                  TEST_ASSERT_EQUAL(NOT_VALID_OPREANDINFO_TYPE, ex);
                 }
}

/*
  ----test function handleShortLongPtr-----
  -test given 0x97 get shortPtr
  -test given 0x97ff get LONGPTR
  -test change the operator $ to , only ->others already test in previous(use previous function)
*/
void test_function_handleshorlongtptr_given_0x97_expect_shortptr_10(void){
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

    handleShortLongPtr(tokenizer, &operandInfo);
    TEST_ASSERT_EQUAL(10,operandInfo.type);

}
void test_function_handleshorlongtptr_given_0x97ff_expect_longptr_11(void){
    OperandInfo operandInfo;
    Tokenizer *tokenizer = (Tokenizer *)0x0badface;

    OperatorToken dollarToken = {TOKEN_OPERATOR_TYPE,0,1,"$"};
    IntegerToken intToken = {TOKEN_INTEGER_TYPE,0,4,"0x97ff",0x97ff};
    OperatorToken dotToken = {TOKEN_OPERATOR_TYPE,0,1,"."};
    IdentifierToken WToken = {TOKEN_IDENTIFIER_TYPE,0,1,"W"};
    OperatorToken SquareBracketToken = {TOKEN_OPERATOR_TYPE,0,1,"]"};

    getToken_ExpectAndReturn(tokenizer, (Token *)&dollarToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&dotToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&WToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&SquareBracketToken);

    handleShortLongPtr(tokenizer, &operandInfo);
    TEST_ASSERT_EQUAL(11,operandInfo.type);

}
void test_function_handleshorlongtptr_use_comma_represent_dollar_expect_Exception(void){
    CEXCEPTION_T ex;
    OperandInfo operandInfo;
    Tokenizer *tokenizer = (Tokenizer *)0x0badface;

    OperatorToken dollarToken = {TOKEN_OPERATOR_TYPE,0,1,","};
    getToken_ExpectAndReturn(tokenizer, (Token *)&dollarToken);



    Try {
      	handleShortLongPtr(tokenizer, &operandInfo);
        }Catch(ex) {
                    TEST_ASSERT_EQUAL(NOT_VALID_OPERATOR, ex);
                   }
}

/*
  ------test function handleShortLongPtrorWithIndex---------
  *test change the index to another alphabert
  *test change the comma symbol to dollarToken
  *test get SHORTPTR_X/SHORTPTR_Y/LONGPTR_X by convert it from SHORTPTR/LONGPTR
  *test given LONGPTR_Y but get Exception cause not LONGPTR_Y
  *others test has been done previous
*/
void test_function_handleShortLongPtrorWithIndex_given_0x97_W_expect_exception_not_valid_identifier(void){
  CEXCEPTION_T ex;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;

  OperatorToken dollarToken = {TOKEN_OPERATOR_TYPE,0,1,"$"};
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,0,2,"0x97",0x97};
  OperatorToken dotToken = {TOKEN_OPERATOR_TYPE,0,1,"."};
  IdentifierToken WToken = {TOKEN_IDENTIFIER_TYPE,0,1,"W"};
  OperatorToken SquareBracketToken = {TOKEN_OPERATOR_TYPE,0,1,"]"};
  OperatorToken commaToken = {TOKEN_OPERATOR_TYPE,0,1,","};
  IdentifierToken W1Token = {TOKEN_IDENTIFIER_TYPE,0,1,"W"};

  getToken_ExpectAndReturn(tokenizer, (Token *)&dollarToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&dotToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&SquareBracketToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&commaToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&W1Token);

	Try {
      handleShortLongPtrorWithIndex(tokenizer, &operandInfo);
      printf("%d\n",operandInfo.type);
      }Catch(ex) {
        TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER, ex);
      }
}
void test_function_handleShortLongPtrorWithIndex_given_comma_chg_dollar_expect_exception_not_valid_operator(void){
  CEXCEPTION_T ex;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;

  OperatorToken dollarToken = {TOKEN_OPERATOR_TYPE,0,1,"$"};
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,0,2,"0x97",0x97};
  OperatorToken dotToken = {TOKEN_OPERATOR_TYPE,0,1,"."};
  IdentifierToken WToken = {TOKEN_IDENTIFIER_TYPE,0,1,"W"};
  OperatorToken SquareBracketToken = {TOKEN_OPERATOR_TYPE,0,1,"]"};
  OperatorToken commaToken = {TOKEN_OPERATOR_TYPE,0,1,"$"};

  getToken_ExpectAndReturn(tokenizer, (Token *)&dollarToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&dotToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&SquareBracketToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&commaToken);

	Try {
      handleShortLongPtrorWithIndex(tokenizer, &operandInfo);
      }Catch(ex) {
        TEST_ASSERT_EQUAL(NOT_VALID_OPERATOR, ex);
      }
}
void test_function_handleShortLongPtrorWithIndex_given_0x97_Y_expect_shortPtr_Y_13(void){
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;

  OperatorToken dollarToken = {TOKEN_OPERATOR_TYPE,0,1,"$"};
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,0,2,"0x97",0x97};
  OperatorToken dotToken = {TOKEN_OPERATOR_TYPE,0,1,"."};
  IdentifierToken WToken = {TOKEN_IDENTIFIER_TYPE,0,1,"W"};
  OperatorToken SquareBracketToken = {TOKEN_OPERATOR_TYPE,0,1,"]"};
  OperatorToken commaToken = {TOKEN_OPERATOR_TYPE,0,1,","};
  IdentifierToken W1Token = {TOKEN_IDENTIFIER_TYPE,0,1,"Y"};
  OperatorToken CloseBracketToken = {TOKEN_OPERATOR_TYPE,0,1,")"};

  getToken_ExpectAndReturn(tokenizer, (Token *)&dollarToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&dotToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&SquareBracketToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&commaToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&W1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&CloseBracketToken);

  handleShortLongPtrorWithIndex(tokenizer, &operandInfo);
  TEST_ASSERT_EQUAL(SHORTPTR_Y,operandInfo.type);
}
void test_function_handleShortLongPtrorWithIndex_given_0x97_X_expect_shortPtr_X_12(void){
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

  handleShortLongPtrorWithIndex(tokenizer, &operandInfo);
  TEST_ASSERT_EQUAL(SHORTPTR_X,operandInfo.type);
}
void test_function_handleShortLongPtrorWithIndex_given_0x1000_X_expect_longtPtr_X_14(void){
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;

  OperatorToken dollarToken = {TOKEN_OPERATOR_TYPE,0,1,"$"};
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,0,6,"0x1000",0x1000};
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

  handleShortLongPtrorWithIndex(tokenizer, &operandInfo);
  TEST_ASSERT_EQUAL(LONGPTR_X,operandInfo.type);
}
void test_function_handleShortLongPtrorWithIndex_given_0x1000_Y_expect_Not_valid_operandinfo_type(void){
  CEXCEPTION_T ex;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;

  OperatorToken dollarToken = {TOKEN_OPERATOR_TYPE,0,1,"$"};
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,0,2,"0x1000",0x1000};
  OperatorToken dotToken = {TOKEN_OPERATOR_TYPE,0,1,"."};
  IdentifierToken WToken = {TOKEN_IDENTIFIER_TYPE,0,1,"W"};
  OperatorToken SquareBracketToken = {TOKEN_OPERATOR_TYPE,0,1,"]"};
  OperatorToken commaToken = {TOKEN_OPERATOR_TYPE,0,1,","};
  IdentifierToken W1Token = {TOKEN_IDENTIFIER_TYPE,0,1,"Y"};

  getToken_ExpectAndReturn(tokenizer, (Token *)&dollarToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&dotToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&SquareBracketToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&commaToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&W1Token);
  Try {
      handleShortLongPtrorWithIndex(tokenizer, &operandInfo);
      }Catch(ex) {
        TEST_ASSERT_EQUAL(NOT_VALID_OPREANDINFO_TYPE, ex);
      }
}

//test function getShortlongoffIndexX_Y_SP
void test_function_getShortLongoffIndexX_Y_SP_given__Y_expect_Shortoff_Y(void){
    OperandInfo operandInfo;
    Tokenizer *tokenizer = (Tokenizer *)0x0badface;

    OperatorToken commaToken = {TOKEN_OPERATOR_TYPE,0,1,","};
    IdentifierToken WToken = {TOKEN_IDENTIFIER_TYPE,0,1,"Y"};
    getToken_ExpectAndReturn(tokenizer, (Token *)&commaToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&WToken);

  	getShortlongoffIndexX_Y_SP(tokenizer, &operandInfo);
  	TEST_ASSERT_EQUAL(SHORTOFF_Y, operandInfo.type);
}
void test_function_getShortLongoffIndexX_Y_SP_given__SP_expect_Shortoff_SP(void){
    OperandInfo operandInfo;
    Tokenizer *tokenizer = (Tokenizer *)0x0badface;

    OperatorToken commaToken = {TOKEN_OPERATOR_TYPE,0,1,","};
    IdentifierToken WToken = {TOKEN_IDENTIFIER_TYPE,0,1,"SP"};
    getToken_ExpectAndReturn(tokenizer, (Token *)&commaToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&WToken);

  	getShortlongoffIndexX_Y_SP(tokenizer, &operandInfo);
  	TEST_ASSERT_EQUAL(SHORTOFF_SP, operandInfo.type);
}
void test_function_getShortLongoffIndexX_Y_SP_given__X_expect_Shortoff_X(void){
    OperandInfo operandInfo;
    Tokenizer *tokenizer = (Tokenizer *)0x0badface;

    OperatorToken commaToken = {TOKEN_OPERATOR_TYPE,0,1,","};
    IdentifierToken WToken = {TOKEN_IDENTIFIER_TYPE,0,1,"X"};
    getToken_ExpectAndReturn(tokenizer, (Token *)&commaToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&WToken);

  	getShortlongoffIndexX_Y_SP(tokenizer, &operandInfo);
  	TEST_ASSERT_EQUAL(SHORTOFF_X, operandInfo.type);
}
void test_function_getShortLongoffIndexX_Y_SP_given_comma_to_anotherSymbols_expect_exception_not_valid_operator(void){
    CEXCEPTION_T ex;
    OperandInfo operandInfo;
    Tokenizer *tokenizer = (Tokenizer *)0x0badface;

    OperatorToken commaToken = {TOKEN_OPERATOR_TYPE,0,1,"$"};
    getToken_ExpectAndReturn(tokenizer, (Token *)&commaToken);

    Try {
  		getShortlongoffIndexX_Y_SP(tokenizer, &operandInfo);
  	}Catch(ex) {
  	  TEST_ASSERT_EQUAL(NOT_VALID_OPERATOR, ex);
    }
}
void test_function_getShortLongoffIndexX_Y_SP_given_alphaberts_other_than_XYSP_expect_exception_not_valid_identifier(void){
    CEXCEPTION_T ex;
    OperandInfo operandInfo;
    Tokenizer *tokenizer = (Tokenizer *)0x0badface;

    OperatorToken commaToken = {TOKEN_OPERATOR_TYPE,0,1,","};
    IdentifierToken WToken = {TOKEN_IDENTIFIER_TYPE,0,2,"Z"};
    getToken_ExpectAndReturn(tokenizer, (Token *)&commaToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&WToken);

    Try {
  		getShortlongoffIndexX_Y_SP(tokenizer, &operandInfo);
  	}Catch(ex) {
  	  TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER, ex);
    }
}

//test function convertShortoffToLongoff
void test_function_convert_ShortOff_to_LongOFF_given_Shortoff_X_expect_Longoff_X(void){
    OperandInfo operandInfo;
    operandInfo.type = SHORTOFF_X;
    Tokenizer *tokenizer = (Tokenizer *)0x0badface;

  	convertShortoffToLongoff(tokenizer, &operandInfo);
  	TEST_ASSERT_EQUAL(LONGOFF_X,operandInfo.type );
}
void test_function_convert_ShortOff_to_LongOFF_given_Shortoff_Y_expect_Longoff_Y(void){
    OperandInfo operandInfo;
    operandInfo.type = SHORTOFF_Y;
    Tokenizer *tokenizer = (Tokenizer *)0x0badface;

  	convertShortoffToLongoff(tokenizer, &operandInfo);
  	TEST_ASSERT_EQUAL(LONGOFF_Y,operandInfo.type );
}
void test_function_convert_ShortOff_to_LongOFF_given_Shortoff_SP_expect_not_valid_operandInfoType(void){
      CEXCEPTION_T ex;
      OperandInfo operandInfo;
      operandInfo.type = SHORTOFF_SP;
      Tokenizer *tokenizer = (Tokenizer *)0x0badface;

    	Try {
    		convertShortoffToLongoff(tokenizer, &operandInfo);
    	}Catch(ex) {
    	TEST_ASSERT_EQUAL(NOT_VALID_OPREANDINFO_TYPE,ex);
    	}
    }

/*
  -------handlelongshortoff-------
  *test given 0x10,X get SHORTOFF_X
  *test given 0x1000,X get LONGPTROFF_X
  *test given 0x10,Y get SHORTOFF_Y
  *test given 0x1000,Y get LONGPTROFF_Y
  others posibilities may be wrong has been tried in previous
*/
void test_function_handleLongShortoff_given_shortoff_0x10_X_expect_SHORTOFF_X(void){
    OperandInfo operandInfo;
    Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  //  str = "10,X"
  	IntegerToken intToken = {TOKEN_INTEGER_TYPE,0,2,"0x10",0x10};
    OperatorToken commaToken = {TOKEN_OPERATOR_TYPE,0,1,","};
    IdentifierToken WToken = {TOKEN_IDENTIFIER_TYPE,0,1,"X"};
    OperatorToken CBracketToken = {TOKEN_OPERATOR_TYPE,0,1,")"};

    getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&commaToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&WToken);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&CBracketToken);


  		handleShortLongoff(tokenizer, &operandInfo);
  	  TEST_ASSERT_EQUAL(SHORTOFF_X, operandInfo.type);
}
void test_function_handleLongShortoff_given_shortoff_0x10_Y_expect_SHORTOFF_Y(void){
      OperandInfo operandInfo;
      Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    //  str = "10,Y"
    	IntegerToken intToken = {TOKEN_INTEGER_TYPE,0,2,"0x10",0x10};
      OperatorToken commaToken = {TOKEN_OPERATOR_TYPE,0,1,","};
      IdentifierToken WToken = {TOKEN_IDENTIFIER_TYPE,0,1,"Y"};
      OperatorToken CBracketToken = {TOKEN_OPERATOR_TYPE,0,1,")"};

      getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);
      getToken_ExpectAndReturn(tokenizer, (Token *)&commaToken);
      getToken_ExpectAndReturn(tokenizer, (Token *)&WToken);
    	getToken_ExpectAndReturn(tokenizer, (Token *)&CBracketToken);


     handleShortLongoff(tokenizer, &operandInfo);
     TEST_ASSERT_EQUAL(SHORTOFF_Y,operandInfo.type);
}
void test_function_handleLongShortoff_given_longoff_0x1000_X_expect_LONGOFF_X(void){
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


    handleShortLongoff(tokenizer, &operandInfo);
    TEST_ASSERT_EQUAL(LONGOFF_X,operandInfo.type);
}
void test_function_handleLongShortoff_given_Lonfoff_0x1000_Y_expect_LONGOFF_Y(void){
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

  	handleShortLongoff(tokenizer, &operandInfo);
  	TEST_ASSERT_EQUAL(LONGOFF_Y, operandInfo.type);
}

//test function handle byte
void test_function_handlebyte_given_comma_replace_dollarSymbol_expect_NOT_VALID_OEPERATOR(void){
    CEXCEPTION_T ex;
    OperandInfo operandInfo;
    operandInfo.value = 0x97;
    Tokenizer *tokenizer = (Tokenizer *)0x0badface;

    OperatorToken   dollarToken = {TOKEN_OPERATOR_TYPE, 0,1,","};
    getToken_ExpectAndReturn(tokenizer, (Token *)&dollarToken);

  	Try {
  		handleByte(tokenizer, &operandInfo);
  	}Catch(ex) {
  	TEST_ASSERT_EQUAL(NOT_VALID_OPERATOR, ex);
  	}
}
void test_function_handlebyte_given_0xFF1_expect_Limit_EXCEEDED(void){
    CEXCEPTION_T ex;
    OperandInfo operandInfo;
    operandInfo.value = 0x97;
    Tokenizer *tokenizer = (Tokenizer *)0x0badface;

    OperatorToken   dollarToken = {TOKEN_OPERATOR_TYPE, 0,1,"$"};
    IntegerToken intToken = {TOKEN_INTEGER_TYPE,1,5,"0xff1",0xff1};
    getToken_ExpectAndReturn(tokenizer, (Token *)&dollarToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);

  	Try {
  		handleByte(tokenizer, &operandInfo);
  	}Catch(ex) {
  	TEST_ASSERT_EQUAL(LIMIT_EXCEEDED, ex);
  	}
  }
void test_function_handlebyte_given_0xFF_expect_BYTE(void){
  OperandInfo operandInfo;
  operandInfo.value = 0x97;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;

  OperatorToken   dollarToken = {TOKEN_OPERATOR_TYPE, 0,1,"$"};
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,1,5,"0xff",0xff};
  getToken_ExpectAndReturn(tokenizer, (Token *)&dollarToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);

  handleByte(tokenizer, &operandInfo);
  TEST_ASSERT_EQUAL(BYTE, operandInfo.type);
}

//test functionLongShortMem
void test_function_handleLongShortMem_given_0x97_expect_shortMem(void){
    OperandInfo operandInfo;
    Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  	IntegerToken intToken = {TOKEN_INTEGER_TYPE,0,4,"0x97",0x97};

  	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);

  	handleLongShortMem(tokenizer, &operandInfo);
  	TEST_ASSERT_EQUAL(SHORT_MEM, operandInfo.type);

}
void test_function_handleLongShortMem_given_0x9700_expect_longtMem(void){
    OperandInfo operandInfo;
    Tokenizer *tokenizer = (Tokenizer *)0x0badface;

  	IntegerToken intToken = {TOKEN_INTEGER_TYPE,0,6,"0x9700",0x9700};
  	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);

  	handleLongShortMem(tokenizer, &operandInfo);
  	TEST_ASSERT_EQUAL(LONG_MEM, operandInfo.type);
}
void test_function_handleLongShortMem_given_0x97fff_expect_LIMIT_EXCEEDED(void){
    CEXCEPTION_T ex;
    OperandInfo operandInfo;
    Tokenizer *tokenizer = (Tokenizer *)0x0badface;

  	IntegerToken intToken = {TOKEN_INTEGER_TYPE,0,7,"0x97fff",0x97fff};
  	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);

    Try {
      handleLongShortMem(tokenizer, &operandInfo);
    }Catch(ex) {
    TEST_ASSERT_EQUAL(LIMIT_EXCEEDED, ex);
    }
}

/*
  -----test function handeleNext_2_Operandmain------
  *test given index X/Y get operandInfo.type = IndexX/IndexY;
  *test given dollarsymbol get into functionShortlongoff and get
   SHORTOFF_X/LONGOFF_X/SHORTOFF_Y/LONGOFF_Y
  *test given SquareBracketSymbol get into function shortlongptrwithIndex
   and get SHORTPTR_X/LONGPTR_X/SHORTPTR_Y
*/
void test_handleNext_2_OperandMain_given_DollarSymbol_0x97_X_expect_shortoff_X(void){
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  OperatorToken dollarToken = {TOKEN_OPERATOR_TYPE,0,1,"$"};
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,0,2,"0x10",0x10};
  OperatorToken commaToken = {TOKEN_OPERATOR_TYPE,0,1,","};
  IdentifierToken WToken = {TOKEN_IDENTIFIER_TYPE,0,1,"X"};
  OperatorToken CBracketToken = {TOKEN_OPERATOR_TYPE,0,1,")"};

  getToken_ExpectAndReturn(tokenizer, (Token *)&dollarToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&commaToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&CBracketToken);

  handleNExt_2_OperandMain(tokenizer, &operandInfo);
  TEST_ASSERT_EQUAL(SHORTOFF_X, operandInfo.type);
}
void test_handleNext_2_OperandMain_given_SquareBracketrSymbol_0x97_X_expect_ShortPtr_X(void){
  CEXCEPTION_T ex;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
   //ADC A,([$10.w],X)

  OperatorToken OpenSquareBracketToken = {TOKEN_OPERATOR_TYPE,0,1,"["};
  OperatorToken dollarToken = {TOKEN_OPERATOR_TYPE,0,1,"$"};
  IntegerToken  intToken = {TOKEN_INTEGER_TYPE,0,4,"0x97",0x97};
  OperatorToken dotToken = {TOKEN_OPERATOR_TYPE,0,1,"."};
  IdentifierToken WToken = {TOKEN_IDENTIFIER_TYPE,0,1,"W"};
  OperatorToken CloseSquareBracketToken = {TOKEN_OPERATOR_TYPE,0,1,"]"};
  OperatorToken commaToken = {TOKEN_OPERATOR_TYPE,0,1,","};
  IdentifierToken W1Token = {TOKEN_IDENTIFIER_TYPE,0,1,"X"};
  OperatorToken CBracketToken = {TOKEN_OPERATOR_TYPE,0,1,")"};

  getToken_ExpectAndReturn(tokenizer, (Token *)&OpenSquareBracketToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&dollarToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&dotToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&CloseSquareBracketToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&commaToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&W1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&CBracketToken);

  Try {
    handleNExt_2_OperandMain(tokenizer, &operandInfo);
  }Catch(ex) {
  TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
  }
}
void test_handleNext_2_OperandMain_given_symbols_others_than_dollarAndSquareBracket_expect_exception(void){
  CEXCEPTION_T ex;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;

  OperatorToken othersToken = {TOKEN_OPERATOR_TYPE,0,1,","};
  getToken_ExpectAndReturn(tokenizer, (Token *)&othersToken);

  Try {
    handleNExt_2_OperandMain(tokenizer, &operandInfo);
  }Catch(ex) {
  TEST_ASSERT_EQUAL(NOT_VALID_OPERATOR, ex);
  }
}
void test_handleNext_2_OperandMain_given_index_of_Y_expect_indexY(void){
  CEXCEPTION_T ex;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;

  IdentifierToken WToken = {TOKEN_IDENTIFIER_TYPE,0,1,"Y"};
  OperatorToken CBracketToken = {TOKEN_OPERATOR_TYPE,0,1,")"};

  getToken_ExpectAndReturn(tokenizer, (Token *)&WToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&CBracketToken);


    handleNExt_2_OperandMain(tokenizer, &operandInfo);
    TEST_ASSERT_EQUAL(IndexY, operandInfo.type);
}
void test_handleNext_2_OperandMain_given_index_of_X_expect_indexX(void){
  CEXCEPTION_T ex;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;

  IdentifierToken WToken = {TOKEN_IDENTIFIER_TYPE,0,1,"X"};
  OperatorToken CBracketToken = {TOKEN_OPERATOR_TYPE,0,1,")"};

  getToken_ExpectAndReturn(tokenizer, (Token *)&WToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&CBracketToken);


    handleNExt_2_OperandMain(tokenizer, &operandInfo);
    TEST_ASSERT_EQUAL(IndexX, operandInfo.type);
}
void test_handleNext_2_OperandMain_given_another_alphaberts_replace_XorY_expect_Not_valid_identifier(void){
  CEXCEPTION_T ex;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;

  IdentifierToken WToken = {TOKEN_IDENTIFIER_TYPE,0,1,"Z"};
  getToken_ExpectAndReturn(tokenizer, (Token *)&WToken);

  Try {
    handleNExt_2_OperandMain(tokenizer, &operandInfo);
  }Catch(ex) {
  TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER, ex);
  }
}

/*
---------test Function handleNEXTOperandMain----------
*/
void test_function_handleNEXTOperandMain_given_dollar_symbol_0x97_expect_ShortMem(void){
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  OperatorToken   dollarToken = {TOKEN_OPERATOR_TYPE, 0,1,"$"};
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,1,4,"0xff",0xff};

  getToken_ExpectAndReturn(tokenizer, (Token *)&dollarToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);

  handleNEXTOperandMain(tokenizer, &operandInfo);
  TEST_ASSERT_EQUAL(SHORT_MEM,operandInfo.type);
  }
void test_function_handleNEXTOperandMain_given_hash__symbol_expect_operandtype_is_Byte(void){
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;

  OperatorToken HashToken = {TOKEN_OPERATOR_TYPE,0,1,"#"};
  OperatorToken dollarToken = {TOKEN_OPERATOR_TYPE,0,1,"$"};
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,0,2,"0x97",0x97};

  getToken_ExpectAndReturn(tokenizer, (Token *)&HashToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&dollarToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);


  handleNEXTOperandMain(tokenizer, &operandInfo);
  TEST_ASSERT_EQUAL(BYTE,operandInfo.type);

}
void test_function_handleNEXTOperandMain_given_roundBracketSymbol_expect_operandtype_is_indexX(void){
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  OperatorToken roundOpenBracketToken = {TOKEN_OPERATOR_TYPE,0,1,"("};
  IdentifierToken WToken = {TOKEN_IDENTIFIER_TYPE,0,1,"X"};
  OperatorToken roundCloseBracketToken = {TOKEN_OPERATOR_TYPE,0,1,")"};

  getToken_ExpectAndReturn(tokenizer, (Token *)&roundOpenBracketToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&roundCloseBracketToken);

  handleNEXTOperandMain(tokenizer, &operandInfo);
  TEST_ASSERT_EQUAL(IndexX,operandInfo.type);
}
void test_function_handleNEXTOperandMain_given_SquareBracketSymbol_expect_operandtype_is_shortptr(void){
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  OperatorToken roundOpenBracketToken = {TOKEN_OPERATOR_TYPE,0,1,"["};
  OperatorToken dollarToken = {TOKEN_OPERATOR_TYPE,0,1,"$"};
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,0,4,"0x10",0x10};
  OperatorToken dotToken = {TOKEN_OPERATOR_TYPE,0,1,"."};
  IdentifierToken WToken = {TOKEN_IDENTIFIER_TYPE,0,1,"W"};
  OperatorToken roundCloseBracketToken = {TOKEN_OPERATOR_TYPE,0,1,"]"};

  getToken_ExpectAndReturn(tokenizer, (Token *)&roundOpenBracketToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&dollarToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&dotToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&roundCloseBracketToken);


  handleNEXTOperandMain(tokenizer, &operandInfo);
  TEST_ASSERT_EQUAL(SHORTPTR, operandInfo.type);
}
void test_function_handleNEXTOperandMain_given_symbol_comma_expect_not_valid_operator(void){
  CEXCEPTION_T ex;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;

  OperatorToken othersToken = {TOKEN_OPERATOR_TYPE,0,1,","};
  getToken_ExpectAndReturn(tokenizer, (Token *)&othersToken);

  Try {
    handleNEXTOperandMain(tokenizer, &operandInfo);
  }Catch(ex) {
  TEST_ASSERT_EQUAL(NOT_VALID_OPERATOR, ex);
  }
}


//--------- Function displayOpcode---------

void test_FUNCTION_DISPLAYOPCODE_given_0x97_Shortptr_expect_0x97D992(void){
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
void test_FUNCTION_DISPLAYOPCODE_given_0x97ff_longptr_expect_0xff97D972(void){
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
void test_FUNCTION_DISPLAYOPCODE_given_0x97B9_shortmem_expect_0x97B9(void){
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
void test_FUNCTION_DISPLAYOPCODE_given_0x5597B9_longmem_expect_0x5597C9(void){
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
void test_FUNCTION_DISPLAYOPCODE_given_longoffY_expect_0x5597D990(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  operandInfo.type = LONGOFF_Y;
  operandInfo.value = 0x9755;
  operandInfo.baseOpcode = 0x09;
  displayOpcode(&memoryToWriteCode,&operandInfo);
  TEST_ASSERT_EQUAL_HEX(0x5597D990,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[4],memoryToWriteCode);
}
void test_FUNCTION_DISPLAYOPCODE_given_shortffY_expect_0x97E990(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  operandInfo.type = SHORTOFF_Y;
  operandInfo.value = 0x97;
  operandInfo.baseOpcode = 0x09;
  displayOpcode(&memoryToWriteCode,&operandInfo);
  TEST_ASSERT_EQUAL_HEX(0x97E990,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[3],memoryToWriteCode);
}
void test_FUNCTION_DISPLAYOPCODE_given_shortffX_expect_0x98E9(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  operandInfo.type = SHORTOFF_X;
  operandInfo.value = 0x98;
  operandInfo.baseOpcode = 0x09;
  displayOpcode(&memoryToWriteCode,&operandInfo);
  TEST_ASSERT_EQUAL_HEX(0x98E9,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[2],memoryToWriteCode);
}
void test_FUNCTION_DISPLAYOPCODE_given_longffX_expect_0x9797D9(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  operandInfo.type =LONGOFF_X;
  operandInfo.value = 0x9797;
  operandInfo.baseOpcode = 0x09;
  displayOpcode(&memoryToWriteCode,&operandInfo);
  TEST_ASSERT_EQUAL_HEX(0x9797D9,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[3],memoryToWriteCode);
}
void test_FUNCTION_DISPLAYOPCODE_given_shortoffSP_expect_0x5519(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  operandInfo.type =SHORTOFF_SP;
  operandInfo.value = 0x55;
  operandInfo.baseOpcode = 0x09;
  displayOpcode(&memoryToWriteCode,&operandInfo);
  TEST_ASSERT_EQUAL_HEX(0x5519,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[2],memoryToWriteCode);
}


void test_function_identifyInstruction_given_ADC_expect_baseOpcode_9(void){
  char *str = "ADC";
  OperandInfo operandInfo;
  identifyInstruction(str,&operandInfo);
  printf("%d\n",operandInfo.baseOpcode );
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
  char str[] = "adc A,#$97";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"ADC"};
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
  char str[] = "adc A,$55ff";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"ADC"};
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
  char str[] = "adc A,$55";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"ADC"};
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
  char str[] = "adc A,(X)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"ADC"};
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
void test_asesemble_given_adc_index_Y_expect_0xF990(void){
  CEXCEPTION_T ex;
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "adc A,(X)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"ADC"};
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
  char str[] = "ADC A,($10,X)";
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
  char str[] = "ADC A,($10,Y)";
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
  char str[] = "ADC A,($1088,X)";
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
  char str[] = "ADC A,($1088,Y)";
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
  char str[] = "ADC A,($88,SP)";
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
  char str[] = "ADC A,[$55.w]";
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
  char str[] = "ADC A,[$5544.w]";
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
  char str[] = "ADC A,([$45.w],X)";
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
  char str[] = "ADC A,([$45.w],Y)";
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
  char str[] = "ADC A,([$4555.w],X)";
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
//test ADD
void test_asesemble_given_add_byte_0x55_expect_0x55AB(void){
  CEXCEPTION_T ex;
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "aDd A,#$55";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"ADD"};
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
    TEST_ASSERT_EQUAL_HEX(0x55AB,*(uint32_t *)buffer);
    TEST_ASSERT_EQUAL_PTR(&buffer[2],memoryToWriteCode);
    printf("0x%02x%02x\n",buffer[0],buffer[1]);
	}Catch(ex) {
	TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void test_asesemble_given_and_byte_0x55_expect_0x55A4(void){
  CEXCEPTION_T ex;
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "and A,#$55";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"AND"};
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
    TEST_ASSERT_EQUAL_HEX(0x55A4,*(uint32_t *)buffer);
    TEST_ASSERT_EQUAL_PTR(&buffer[2],memoryToWriteCode);
    printf("0x%02x%02x\n",buffer[0],buffer[1]);
	}Catch(ex) {
	TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
