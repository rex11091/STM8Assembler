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
void test_function_try_given_dot_W_bracket_expect_not_exception(void){
  CEXCEPTION_T ex;
  OperandInfo operandInfo;
  operandInfo.value = 0x97;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;

  OperatorToken dotToken = {TOKEN_OPERATOR_TYPE,0,1,".",".W]"};
  IdentifierToken WToken = {TOKEN_IDENTIFIER_TYPE,1,1,"W",".W]"};
  OperatorToken SquareBracketToken = {TOKEN_OPERATOR_TYPE,2,1,"]",".W]"};
  getToken_ExpectAndReturn(tokenizer, (Token *)&dotToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&SquareBracketToken);
  Try {
    trt(tokenizer, &operandInfo);
    //printf("%d\n",operandInfo.type);
  }Catch(ex) {
    dumpErrorMessage(ex, 1);
  }
  freeException(ex);
}

void test_function_handleIndexXandY_given_XorY_expect_exception(void){
    CEXCEPTION_T ex;
    OperandInfo operandInfo;

    Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    OperatorToken ADDToken = {TOKEN_INTEGER_TYPE, 0,1,"Z",")"};
    getToken_ExpectAndReturn(tokenizer, (Token *)&ADDToken);

  	Try {
  		handleIndexXandY(tokenizer, &operandInfo);
      printf("%d\n",operandInfo.type);
  	}Catch(ex) {
  	  dumpErrorMessage(ex, 1);
  	}
    freeException(ex);
  }
*/

//test function getLongShortType
void test_function_getlongshortType_given_0x97_expect_short_16(void){
    OperandInfo operandInfo;
    Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char *str = "Ox97";
  	IntegerToken intToken = {TOKEN_INTEGER_TYPE,0,2,"0x97",str,0x97};
  	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);

  	getLongShortType(tokenizer, &operandInfo);
    TEST_ASSERT_EQUAL(16,operandInfo.type);
}
void test_function_getlongshortType_given_255_ff_expect_short_16(void){

    OperandInfo operandInfo;
    Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char *str = "255";
  	IntegerToken intToken = {TOKEN_INTEGER_TYPE,0,3,"255",str,255};
  	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);

  	getLongShortType(tokenizer, &operandInfo);
    TEST_ASSERT_EQUAL(16,operandInfo.type);
}
void test_function_getlongshortType_given_0x9797_expect_long_15(void){

    OperandInfo operandInfo;
    Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char *str = "Ox9797";
    IntegerToken intToken = {TOKEN_INTEGER_TYPE,0,6,"0x9797",str,0x9797};
    getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);

    getLongShortType(tokenizer, &operandInfo);
    TEST_ASSERT_EQUAL(15,operandInfo.type);
}
void test_function_getlongshortType_given_65535_ffff_expect_long_15(void){
    OperandInfo operandInfo;
    Tokenizer *tokenizer = (Tokenizer *)0x0badface;
      char *str = "Oxffff";
    IntegerToken intToken = {TOKEN_INTEGER_TYPE,0,6,"0xffff",str,0xffff};
    getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);

    getLongShortType(tokenizer, &operandInfo);
    TEST_ASSERT_EQUAL(15,operandInfo.type);
}
void test_function_getlongshortType_given_0x9797f_expect_Exception_limit_exceeded(void){
  CEXCEPTION_T ex;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char *str = "0x9797f";

  IntegerToken intToken = {TOKEN_INTEGER_TYPE,0,7,"0x9797f","0x9797f",0x9797f};
  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);

  Try {
    getLongShortType(tokenizer, &operandInfo);
  }Catch(ex) {
    dumpErrorMessage(ex, 1);
  }
    freeException(ex);
}
void test_function_getlongshortType_given_operatorTokenType_expect_Exception_WrongTokenType(void){
  CEXCEPTION_T ex;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char *str = "0x9797";

  IntegerToken intToken = {TOKEN_OPERATOR_TYPE,0,7,"0x9797",str,0x9797};
  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);

  Try {
    getLongShortType(tokenizer, &operandInfo);
  }Catch(ex) {
    dumpErrorMessage(ex, 1);
  }
    freeException(ex);
}
//test function gettokenDotWBracket
void test_function_gettokenDotWBracket_given_comma_represent_dollar_expect_not_valid_operator(void){
  CEXCEPTION_T ex;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char *str = ".W]";
  OperatorToken dotToken = {TOKEN_OPERATOR_TYPE,0,1,",",str};
  getToken_ExpectAndReturn(tokenizer, (Token *)&dotToken);

  Try {
    gettokenDotWBracket(tokenizer, &operandInfo);
  }Catch(ex) {
    dumpErrorMessage(ex, 1);
  }
  freeException(ex);
}
void test_function_gettokenDotWBracket_given_dot_X_represent_W_expect_Not_valid_identifier(void){
  CEXCEPTION_T ex;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char *str = ".W]";
  OperatorToken dotToken = {TOKEN_OPERATOR_TYPE,0,1,".",str};;
  IdentifierToken WToken = {TOKEN_IDENTIFIER_TYPE,1,1,"X",str};
  getToken_ExpectAndReturn(tokenizer, (Token *)&dotToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WToken);

  Try {
    gettokenDotWBracket(tokenizer, &operandInfo);
      }Catch(ex) {
    dumpErrorMessage(ex, 1);
      }
  freeException(ex);
}
void test_function_gettokenDotWBracket_given_dot_W_dot_expect_Exception_Not_valid_operator(void){
  CEXCEPTION_T ex;
  OperandInfo operandInfo;
  operandInfo.value = 0x97;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char *str = ".W]";
  OperatorToken dotToken = {TOKEN_OPERATOR_TYPE,0,1,".",str};;
  IdentifierToken WToken = {TOKEN_IDENTIFIER_TYPE,1,1,"W",str};
  OperatorToken SquareBracketToken = {TOKEN_OPERATOR_TYPE,2,1,".",str};
  getToken_ExpectAndReturn(tokenizer, (Token *)&dotToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&SquareBracketToken);

  Try {
    gettokenDotWBracket(tokenizer, &operandInfo);
      }Catch(ex) {
    dumpErrorMessage(ex, 1);
      }
    freeException(ex);
}
void test_function_gettokenDotWBracket_given_dot_W_bracket_expect_not_exception(void){
  CEXCEPTION_T ex;
  OperandInfo operandInfo;
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
    dumpErrorMessage(ex, 1);
      }
  //freeException(ex);
}

//test function getCloseBracketSymbol
void test_function_getCloseBracket_given_comma_expect_exception_not_valid_operator(void){
  CEXCEPTION_T ex;
  OperandInfo operandInfo;

  char *str = ")";
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  OperatorToken CBracketToken = {TOKEN_OPERATOR_TYPE,0,1,",",str};
  getToken_ExpectAndReturn(tokenizer, (Token *)&CBracketToken);

  Try {
    getCloseBracketSymbol(tokenizer, &operandInfo);
  }Catch(ex) {
    dumpErrorMessage(ex, 1);
  }
    freeException(ex);
}
void test_function_getCloseBracket_given_bracket_expect_not_exception(void){
  CEXCEPTION_T ex;
  OperandInfo operandInfo;
  char *str = ")";
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  OperatorToken CBracketToken = {TOKEN_OPERATOR_TYPE,0,1,")",str};
  getToken_ExpectAndReturn(tokenizer, (Token *)&CBracketToken);
  Try {
    getCloseBracketSymbol(tokenizer, &operandInfo);
  }Catch(ex) {
    dumpErrorMessage(ex, 1);
  }
  //  freeException(ex);
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
      }Catch(ex)
      {
      dumpException(ex);
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
    char *str = "$0x97.W]";
    OperatorToken dollarToken = {TOKEN_OPERATOR_TYPE,0,1,"$",str};
    IntegerToken intToken = {TOKEN_INTEGER_TYPE,1,4,"0x97",str,0x97};
    OperatorToken dotToken = {TOKEN_OPERATOR_TYPE,5,1,".",str};
    IdentifierToken WToken = {TOKEN_IDENTIFIER_TYPE,6,1,"W",str};
    OperatorToken SquareBracketToken = {TOKEN_OPERATOR_TYPE,7,1,"]",str};

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
    char *str = "$0x97ff.W]";
    OperatorToken dollarToken = {TOKEN_OPERATOR_TYPE,0,1,"$",str};
    IntegerToken intToken = {TOKEN_INTEGER_TYPE,1,6,"0x97ff",str,0x97ff};
    OperatorToken dotToken = {TOKEN_OPERATOR_TYPE,7,1,".",str};
    IdentifierToken WToken = {TOKEN_IDENTIFIER_TYPE,8,1,"W",str};
    OperatorToken SquareBracketToken = {TOKEN_OPERATOR_TYPE,9,1,"]",str};

    getToken_ExpectAndReturn(tokenizer, (Token *)&dollarToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&dotToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&WToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&SquareBracketToken);

    handleShortLongPtr(tokenizer, &operandInfo);
    TEST_ASSERT_EQUAL(11,operandInfo.type);

}
void test_function_handleshorlongtptr_use_comma_represent_dollar_expect_not_valid_operator(void){
    CEXCEPTION_T ex;
    OperandInfo operandInfo;
    Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char *str = "$0x97.W]";
    OperatorToken dollarToken = {TOKEN_OPERATOR_TYPE,0,1,",",str};
    getToken_ExpectAndReturn(tokenizer, (Token *)&dollarToken);

    Try {
      handleShortLongPtr(tokenizer, &operandInfo);
    }Catch(ex) {
      dumpErrorMessage(ex, 1);
    }
      freeException(ex);
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

  char *str = "$0x97.W],X)";
  OperatorToken dollarToken = {TOKEN_OPERATOR_TYPE,0,1,"$",str};
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,1,4,"0x97",str,0x97};
  OperatorToken dotToken = {TOKEN_OPERATOR_TYPE,5,1,".",str};
  IdentifierToken WToken = {TOKEN_IDENTIFIER_TYPE,6,1,"W",str};
  OperatorToken SquareBracketToken = {TOKEN_OPERATOR_TYPE,7,1,"]",str};
  OperatorToken commaToken = {TOKEN_OPERATOR_TYPE,8,1,",",str};
  IdentifierToken W1Token = {TOKEN_IDENTIFIER_TYPE,9,1,"W",str};

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
      dumpErrorMessage(ex, 1);
    }
      freeException(ex);
}
void test_function_handleShortLongPtrorWithIndex_given_comma_chg_dollar_expect_exception_not_valid_operator(void){
  CEXCEPTION_T ex;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char *str = "$0x97.W],X)";

  OperatorToken dollarToken = {TOKEN_OPERATOR_TYPE,0,1,"$",str};
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,1,4,"0x97",str,0x97};
  OperatorToken dotToken = {TOKEN_OPERATOR_TYPE,5,1,".",str};
  IdentifierToken WToken = {TOKEN_IDENTIFIER_TYPE,6,1,"W",str};
  OperatorToken SquareBracketToken = {TOKEN_OPERATOR_TYPE,7,1,"]",str};
  OperatorToken commaToken = {TOKEN_OPERATOR_TYPE,8,1,"$",str};

  getToken_ExpectAndReturn(tokenizer, (Token *)&dollarToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&dotToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&SquareBracketToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&commaToken);

  Try {
    handleShortLongPtrorWithIndex(tokenizer, &operandInfo);
  }Catch(ex) {
    dumpErrorMessage(ex, 1);
  }
    freeException(ex);
}
void test_function_handleShortLongPtrorWithIndex_given_0x97_Y_expect_shortPtr_Y_13(void){
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;

  char *str = "$0x97.W],Y)";
  OperatorToken dollarToken = {TOKEN_OPERATOR_TYPE,0,1,"$",str};
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,0,2,"0x97",str,0x97};
  OperatorToken dotToken = {TOKEN_OPERATOR_TYPE,0,1,".",str};
  IdentifierToken WToken = {TOKEN_IDENTIFIER_TYPE,0,1,"W",str};
  OperatorToken SquareBracketToken = {TOKEN_OPERATOR_TYPE,0,1,"]",str};
  OperatorToken commaToken = {TOKEN_OPERATOR_TYPE,0,1,",",str};
  IdentifierToken W1Token = {TOKEN_IDENTIFIER_TYPE,0,1,"Y",str};
  OperatorToken CloseBracketToken = {TOKEN_OPERATOR_TYPE,0,1,")",str};

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

  char *str = "$0x97.W],X)";
  OperatorToken dollarToken = {TOKEN_OPERATOR_TYPE,0,1,"$",str};
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,0,2,"0x97",str,0x97};
  OperatorToken dotToken = {TOKEN_OPERATOR_TYPE,0,1,".",str};
  IdentifierToken WToken = {TOKEN_IDENTIFIER_TYPE,0,1,"W",str};
  OperatorToken SquareBracketToken = {TOKEN_OPERATOR_TYPE,0,1,"]",str};
  OperatorToken commaToken = {TOKEN_OPERATOR_TYPE,0,1,",",str};
  IdentifierToken W1Token = {TOKEN_IDENTIFIER_TYPE,0,1,"X",str};
  OperatorToken CloseBracketToken = {TOKEN_OPERATOR_TYPE,0,1,")",str};

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

    char *str = "$0x1000.W],X)";
  OperatorToken dollarToken = {TOKEN_OPERATOR_TYPE,0,1,"$",str};
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,0,6,"0x1000",str,0x1000};
  OperatorToken dotToken = {TOKEN_OPERATOR_TYPE,0,1,".",str};
  IdentifierToken WToken = {TOKEN_IDENTIFIER_TYPE,0,1,"W",str};
  OperatorToken SquareBracketToken = {TOKEN_OPERATOR_TYPE,0,1,"]",str};
  OperatorToken commaToken = {TOKEN_OPERATOR_TYPE,0,1,",",str};
  IdentifierToken W1Token = {TOKEN_IDENTIFIER_TYPE,0,1,"X",str};
  OperatorToken CloseBracketToken = {TOKEN_OPERATOR_TYPE,0,1,")",str};

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
  char *str = "$0x1000.W],Y)";
  OperatorToken dollarToken = {TOKEN_OPERATOR_TYPE,0,1,"$",str};
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,1,6,"0x1000",str,0x1000};
  OperatorToken dotToken = {TOKEN_OPERATOR_TYPE,7,1,".",str};
  IdentifierToken WToken = {TOKEN_IDENTIFIER_TYPE,8,1,"W",str};
  OperatorToken SquareBracketToken = {TOKEN_OPERATOR_TYPE,9,1,"]",str};
  OperatorToken commaToken = {TOKEN_OPERATOR_TYPE,10,1,",",str};
  IdentifierToken W1Token = {TOKEN_IDENTIFIER_TYPE,11,1,"Y",str};

  getToken_ExpectAndReturn(tokenizer, (Token *)&dollarToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&dotToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&SquareBracketToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&commaToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&W1Token);
  Try {
      handleShortLongPtrorWithIndex(tokenizer, &operandInfo);
      }Catch(ex)
      {
      dumpException(ex);
      }
      freeException1(ex);
}


//test function getShortlongoffIndexX_Y_SP

void test_function_getShortLongoffIndexX_Y_SP_given_Y_expect_Shortoff_Y(void){
    OperandInfo operandInfo;
    Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char *str = ",Y";
    OperatorToken commaToken = {TOKEN_OPERATOR_TYPE,0,1,",",str};
    IdentifierToken WToken = {TOKEN_IDENTIFIER_TYPE,0,1,"Y",str};
    getToken_ExpectAndReturn(tokenizer, (Token *)&commaToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&WToken);

    getShortlongoffIndexX_Y_SP(tokenizer, &operandInfo);
    TEST_ASSERT_EQUAL(SHORTOFF_Y,operandInfo.type);

}
void test_function_getShortLongoffIndexX_Y_SP_given_SP_expect_Shortoff_SP(void){
    OperandInfo operandInfo;
    Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char *str = ",SP";
    OperatorToken commaToken = {TOKEN_OPERATOR_TYPE,0,1,",",str};
    IdentifierToken WToken = {TOKEN_IDENTIFIER_TYPE,0,1,"SP",str};
    getToken_ExpectAndReturn(tokenizer, (Token *)&commaToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&WToken);

    getShortlongoffIndexX_Y_SP(tokenizer, &operandInfo);
    TEST_ASSERT_EQUAL(SHORTOFF_SP,operandInfo.type);
}
void test_function_getShortLongoffIndexX_Y_SP_given_X_expect_Shortoff_X(void){
    OperandInfo operandInfo;
    Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char *str = ",X";
    OperatorToken commaToken = {TOKEN_OPERATOR_TYPE,0,1,",",str};
    IdentifierToken WToken = {TOKEN_IDENTIFIER_TYPE,0,1,"X",str};
    getToken_ExpectAndReturn(tokenizer, (Token *)&commaToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&WToken);

    getShortlongoffIndexX_Y_SP(tokenizer, &operandInfo);
    TEST_ASSERT_EQUAL(SHORTOFF_X,operandInfo.type);
}
void test_function_getShortLongoffIndexX_Y_SP_given_comma_chg_to_anotherSymbols_expect_exception_not_valid_operator(void){
    CEXCEPTION_T ex;
    OperandInfo operandInfo;
    Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char *str = ",X";
    OperatorToken commaToken = {TOKEN_OPERATOR_TYPE,0,1,"$",str};
    getToken_ExpectAndReturn(tokenizer, (Token *)&commaToken);

    Try {
      getShortlongoffIndexX_Y_SP(tokenizer, &operandInfo);
    }Catch(ex) {
      dumpErrorMessage(ex, 1);
    }
      freeException(ex);
}
void test_function_getShortLongoffIndexX_Y_SP_given_alphaberts_other_than_XYSP_expect_exception_not_valid_identifier(void){
    CEXCEPTION_T ex;
    OperandInfo operandInfo;
    Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char *str = ",X";
    OperatorToken commaToken = {TOKEN_OPERATOR_TYPE,0,1,",",str};
    IdentifierToken WToken = {TOKEN_IDENTIFIER_TYPE,1,1,"Z",str};
    getToken_ExpectAndReturn(tokenizer, (Token *)&commaToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&WToken);

    Try {
      getShortlongoffIndexX_Y_SP(tokenizer, &operandInfo);
    }Catch(ex) {
      dumpErrorMessage(ex, 1);
    }
      freeException(ex);
}
void test_function_getShortLongoffIndexX_Y_SP_given_X_replace_operator_token_expect_exception_Wrong_token_type(void){
    CEXCEPTION_T ex;
    OperandInfo operandInfo;
    Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char *str = ",X";
    OperatorToken commaToken = {TOKEN_OPERATOR_TYPE,0,1,",",str};
    IdentifierToken WToken = {TOKEN_OPERATOR_TYPE,1,1,"X",str};
    getToken_ExpectAndReturn(tokenizer, (Token *)&commaToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&WToken);

    Try {
      getShortlongoffIndexX_Y_SP(tokenizer, &operandInfo);
    }Catch(ex) {
      dumpErrorMessage(ex, 1);
    }
      freeException(ex);
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
            }Catch(ex)
            {
            dumpException(ex);
            }
            freeException1(ex);
}
void test_function_convert_ShortOff_to_LongOFF_given_longptr_expect_not_valid_operandInfoType(void){
    CEXCEPTION_T ex;
    OperandInfo operandInfo;
    operandInfo.type = LONGPTR;
    Tokenizer *tokenizer = (Tokenizer *)0x0badface;
      Try {
          convertShortoffToLongoff(tokenizer, &operandInfo);
        }Catch(ex)
          {
          dumpException(ex);
          }
          freeException1(ex);
}
/*
  -------handlelongshortoff-------
  *test given 0x10,X get SHORTOFF_X
  *test given 0x1000,X get LONGPTROFF_X
  *test given 0x10,Y get SHORTOFF_Y
  *test given 0x1000,Y get LONGPTROFF_Y
  others posibilities may be wrong has been tried in previous function
*/
void test_function_handleLongShortoff_given_shortoff_0x10_X_expect_SHORTOFF_X(void){
    OperandInfo operandInfo;
    Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char *str = "0x10,X)";
  	IntegerToken intToken = {TOKEN_INTEGER_TYPE,0,4,"0x10",str,0x10};
    OperatorToken commaToken = {TOKEN_OPERATOR_TYPE,4,1,",",str};
    IdentifierToken WToken = {TOKEN_IDENTIFIER_TYPE,5,1,"X",str};
    OperatorToken CBracketToken = {TOKEN_OPERATOR_TYPE,6,1,")",str};

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
      char *str = "0x10,Y)";
    	IntegerToken intToken = {TOKEN_INTEGER_TYPE,0,4,"0x10",str,0x10};
      OperatorToken commaToken = {TOKEN_OPERATOR_TYPE,4,1,",",str};
      IdentifierToken WToken = {TOKEN_IDENTIFIER_TYPE,5,1,"Y",str};
      OperatorToken CBracketToken = {TOKEN_OPERATOR_TYPE,6,1,")",str};

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
    char *str = "0x1000,X)";
    IntegerToken intToken = {TOKEN_INTEGER_TYPE,0,6,"0x1000",str,0x1000};
    OperatorToken commaToken = {TOKEN_OPERATOR_TYPE,5,1,",",str};
    IdentifierToken WToken = {TOKEN_IDENTIFIER_TYPE,6,1,"X",str};
    OperatorToken CBracketToken = {TOKEN_OPERATOR_TYPE,7,1,")",str};

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
    char *str = "0x1000,Y)";
  	IntegerToken intToken = {TOKEN_INTEGER_TYPE,0,6,"0x1000",str,0x1000};
    OperatorToken commaToken = {TOKEN_OPERATOR_TYPE,5,1,",",str};
    IdentifierToken WToken = {TOKEN_IDENTIFIER_TYPE,6,1,"Y",str};
    OperatorToken CBracketToken = {TOKEN_OPERATOR_TYPE,7,1,")",str};

    getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&commaToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&WToken);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&CBracketToken);

  	handleShortLongoff(tokenizer, &operandInfo);
  	TEST_ASSERT_EQUAL(LONGOFF_Y, operandInfo.type);
}
void test_function_handleLongShortoff_given_Lonfoff_0xfffff_Y_expect_LIMIT_EXCEEDED(void){
    CEXCEPTION_T ex;
    OperandInfo operandInfo;
    Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char *str = "0xfffff,Y)";
  	IntegerToken intToken = {TOKEN_INTEGER_TYPE,0,7,"0xfffff",str,0xfffff};

    getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);
    Try {
      handleShortLongoff(tokenizer, &operandInfo);
    }Catch(ex) {
      dumpErrorMessage(ex, 1);
    }
      freeException(ex);
}


//test function handle byte
void test_function_handlebyte_given_comma_replace_dollarSymbol_expect_NOT_VALID_OEPERATOR(void){
    CEXCEPTION_T ex;
    OperandInfo operandInfo;
    Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char *str = "$0x1000";
    OperatorToken   dollarToken = {TOKEN_OPERATOR_TYPE, 0,1,",",str};
    getToken_ExpectAndReturn(tokenizer, (Token *)&dollarToken);

    Try {
      handleByte(tokenizer, &operandInfo);
    }Catch(ex) {
      dumpErrorMessage(ex, 1);
    }
      freeException(ex);
}
void test_function_handlebyte_given_0xFF1_expect_Limit_EXCEEDED(void){
    CEXCEPTION_T ex;
    OperandInfo operandInfo;
    Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char *str = "$0xff1";

    OperatorToken   dollarToken = {TOKEN_OPERATOR_TYPE, 0,1,"$",str};
    IntegerToken intToken = {TOKEN_INTEGER_TYPE,1,5,"0xff1",str,0xff1};
    getToken_ExpectAndReturn(tokenizer, (Token *)&dollarToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);

    Try {
      handleByte(tokenizer, &operandInfo);
    }Catch(ex) {
      dumpErrorMessage(ex, 1);
    }
      freeException(ex);
  }
void test_function_handlebyte_given_identifierTokenType_expect_Wrong_Token_type(void){
      CEXCEPTION_T ex;
      OperandInfo operandInfo;
      Tokenizer *tokenizer = (Tokenizer *)0x0badface;
      char *str = "$0xff1";

      OperatorToken   dollarToken = {TOKEN_OPERATOR_TYPE, 0,1,"$",str};
      IntegerToken intToken = {TOKEN_IDENTIFIER_TYPE,1,5,"0xff1",str,0xff1};
      getToken_ExpectAndReturn(tokenizer, (Token *)&dollarToken);
      getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);

      Try {
        handleByte(tokenizer, &operandInfo);
      }Catch(ex) {
        dumpErrorMessage(ex, 1);
      }
        freeException(ex);
    }
void test_function_handlebyte_given_0xFF_expect_BYTE(void){
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;

  char *str = "$0xff";
  OperatorToken   dollarToken = {TOKEN_OPERATOR_TYPE, 0,1,"$",str};
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,1,5,"0xff",str,0xff};
  getToken_ExpectAndReturn(tokenizer, (Token *)&dollarToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);

  handleByte(tokenizer, &operandInfo);
  TEST_ASSERT_EQUAL(BYTE, operandInfo.type);
}

//test functionLongShortMem
void test_function_handleLongShortMem_given_0x97_expect_shortMem(void){
    OperandInfo operandInfo;
    Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char *str = "0x97";
  	IntegerToken intToken = {TOKEN_INTEGER_TYPE,0,4,"0x97",str,0x97};

  	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);

  	handleLongShortMem(tokenizer, &operandInfo);
  	TEST_ASSERT_EQUAL(SHORT_MEM, operandInfo.type);

}
void test_function_handleLongShortMem_given_0x9700_expect_longtMem(void){
    OperandInfo operandInfo;
    Tokenizer *tokenizer = (Tokenizer *)0x0badface;

    char *str = "0x9700";
  	IntegerToken intToken = {TOKEN_INTEGER_TYPE,0,6,"0x9700",str,0x9700};
  	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);

  	handleLongShortMem(tokenizer, &operandInfo);
  	TEST_ASSERT_EQUAL(LONG_MEM, operandInfo.type);
}
void test_function_handleLongShortMem_given_0x97fff_expect_LIMIT_EXCEEDED(void){
    CEXCEPTION_T ex;
    OperandInfo operandInfo;
    Tokenizer *tokenizer = (Tokenizer *)0x0badface;

    char *str = "0x97fff";
  	IntegerToken intToken = {TOKEN_INTEGER_TYPE,0,7,"0x97fff",str,0x97fff};
  	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);

      Try {
        handleLongShortMem(tokenizer, &operandInfo);
      }Catch(ex) {
        dumpErrorMessage(ex, 1);
      }
        freeException(ex);
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
  char *str = "($0x10,X)";
  OperatorToken dollarToken = {TOKEN_OPERATOR_TYPE,1,1,"$",str};
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,2,4,"0x10",str,0x10};
  OperatorToken commaToken = {TOKEN_OPERATOR_TYPE,6,1,",",str};
  IdentifierToken WToken = {TOKEN_IDENTIFIER_TYPE,7,1,"X",str};
  OperatorToken CBracketToken = {TOKEN_OPERATOR_TYPE,8,1,")",str};

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
  char *str = "([$0x10.w],X)";

  OperatorToken OpenSquareBracketToken = {TOKEN_OPERATOR_TYPE,1,1,"[",str};
  OperatorToken dollarToken = {TOKEN_OPERATOR_TYPE,2,1,"$",str};
  IntegerToken  intToken = {TOKEN_INTEGER_TYPE,3,4,"0x10",str,0x97};
  OperatorToken dotToken = {TOKEN_OPERATOR_TYPE,7,1,".",str};
  IdentifierToken WToken = {TOKEN_IDENTIFIER_TYPE,8,1,"W",str};
  OperatorToken CloseSquareBracketToken = {TOKEN_OPERATOR_TYPE,9,1,"]",str};
  OperatorToken commaToken = {TOKEN_OPERATOR_TYPE,10,1,",",str};
  IdentifierToken W1Token = {TOKEN_IDENTIFIER_TYPE,11,1,"X",str};
  OperatorToken CBracketToken = {TOKEN_OPERATOR_TYPE,12,1,")",str};

  getToken_ExpectAndReturn(tokenizer, (Token *)&OpenSquareBracketToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&dollarToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&dotToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&CloseSquareBracketToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&commaToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&W1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&CBracketToken);


  handleNExt_2_OperandMain(tokenizer, &operandInfo);
  TEST_ASSERT_EQUAL(SHORTPTR_X, operandInfo.type);
}
void test_handleNext_2_OperandMain_given_symbols_others_than_dollarAndSquareBracket_expect_Not_valid_operator(void){
  CEXCEPTION_T ex;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char *str = "($10,X)";
  OperatorToken othersToken = {TOKEN_OPERATOR_TYPE,1,1,",",str};
  getToken_ExpectAndReturn(tokenizer, (Token *)&othersToken);

  Try {
    handleNExt_2_OperandMain(tokenizer, &operandInfo);
  }Catch(ex) {
    dumpErrorMessage(ex, 1);
  }
    freeException(ex);
}
void test_handleNext_2_OperandMain_given_index_of_Y_expect_indexY(void){
  CEXCEPTION_T ex;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char *str = "(Y)";
  IdentifierToken WToken = {TOKEN_IDENTIFIER_TYPE,1,1,"Y",str};
  OperatorToken CBracketToken = {TOKEN_OPERATOR_TYPE,2,1,")",str};

  getToken_ExpectAndReturn(tokenizer, (Token *)&WToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&CBracketToken);


  handleNExt_2_OperandMain(tokenizer, &operandInfo);
  TEST_ASSERT_EQUAL(IndexY, operandInfo.type);
}
void test_handleNext_2_OperandMain_given_index_of_X_expect_indexX(void){
  CEXCEPTION_T ex;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char *str = "(X)";
  IdentifierToken WToken = {TOKEN_IDENTIFIER_TYPE,1,1,"X",str};
  OperatorToken CBracketToken = {TOKEN_OPERATOR_TYPE,2,1,")",str};

  getToken_ExpectAndReturn(tokenizer, (Token *)&WToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&CBracketToken);


    handleNExt_2_OperandMain(tokenizer, &operandInfo);
    TEST_ASSERT_EQUAL(IndexX, operandInfo.type);
}
void test_handleNext_2_OperandMain_given_another_alphaberts_replace_XorY_expect_Not_valid_identifier(void){
  CEXCEPTION_T ex;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char *str = "(X)";
  IdentifierToken WToken = {TOKEN_IDENTIFIER_TYPE,1,1,"Z",str};
  getToken_ExpectAndReturn(tokenizer, (Token *)&WToken);

  Try {
    handleNExt_2_OperandMain(tokenizer, &operandInfo);
  }Catch(ex) {
    dumpErrorMessage(ex, 1);
  }
    freeException(ex);
}

/*
---------test Function handleNEXTOperandMain----------
*/
void test_function_handleNEXTOperandMain_given_dollar_symbol_0x97_expect_ShortMem(void){
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char *str = "$0xff";
  OperatorToken   dollarToken = {TOKEN_OPERATOR_TYPE, 0,1,"$",str};
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,1,4,"0xff",str,0xff};

  getToken_ExpectAndReturn(tokenizer, (Token *)&dollarToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);

  handleNEXTOperandMain(tokenizer, &operandInfo);
  TEST_ASSERT_EQUAL(SHORT_MEM,operandInfo.type);
  }
void test_function_handleNEXTOperandMain_given_hash__symbol_expect_operandtype_is_Byte(void){
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char *str = "#$0x97";
  OperatorToken HashToken = {TOKEN_OPERATOR_TYPE,0,1,"#"};
  OperatorToken dollarToken = {TOKEN_OPERATOR_TYPE,1,1,"$"};
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,2,4,"0x97",0x97};

  getToken_ExpectAndReturn(tokenizer, (Token *)&HashToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&dollarToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);


  handleNEXTOperandMain(tokenizer, &operandInfo);
  TEST_ASSERT_EQUAL(BYTE,operandInfo.type);

}
void test_function_handleNEXTOperandMain_given_roundBracketSymbol_expect_operandtype_is_indexX(void){
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char *str ="(X)";
  OperatorToken roundOpenBracketToken = {TOKEN_OPERATOR_TYPE,0,1,"(",str};
  IdentifierToken WToken = {TOKEN_IDENTIFIER_TYPE,0,1,"X",str};
  OperatorToken roundCloseBracketToken = {TOKEN_OPERATOR_TYPE,0,1,")",str};

  getToken_ExpectAndReturn(tokenizer, (Token *)&roundOpenBracketToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&roundCloseBracketToken);

  handleNEXTOperandMain(tokenizer, &operandInfo);
  TEST_ASSERT_EQUAL(IndexX,operandInfo.type);
}
void test_function_handleNEXTOperandMain_given_SquareBracketSymbol_expect_operandtype_is_shortptr(void){
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char *str = "[$0x10.W]";
  OperatorToken roundOpenBracketToken = {TOKEN_OPERATOR_TYPE,0,1,"[",str};
  OperatorToken dollarToken = {TOKEN_OPERATOR_TYPE,1,1,"$",str};
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,2,4,"0x10",str,0x10};
  OperatorToken dotToken = {TOKEN_OPERATOR_TYPE,6,1,".",str};
  IdentifierToken WToken = {TOKEN_IDENTIFIER_TYPE,7,1,"W",str};
  OperatorToken roundCloseBracketToken = {TOKEN_OPERATOR_TYPE,8,1,"]",str};

  getToken_ExpectAndReturn(tokenizer, (Token *)&roundOpenBracketToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&dollarToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&dotToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&roundCloseBracketToken);


  handleNEXTOperandMain(tokenizer, &operandInfo);
  TEST_ASSERT_EQUAL(SHORTPTR, operandInfo.type);
}
void test_function_handleNEXTOperandMain_given_comma_symbol_expect_not_valid_operator(void){
  CEXCEPTION_T ex;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char *str = "$";
  OperatorToken othersToken = {TOKEN_OPERATOR_TYPE,0,1,",",str};
  getToken_ExpectAndReturn(tokenizer, (Token *)&othersToken);

  Try {
    handleNEXTOperandMain(tokenizer, &operandInfo);
  }Catch(ex) {
    dumpErrorMessage(ex, 1);
  }
    freeException(ex);
}
void test_function_handleNEXTOperandMain_given_Not_operator_type_expect_not_valid_operator(void){
  CEXCEPTION_T ex;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char *str = "$";
  OperatorToken typeToken = {TOKEN_INTEGER_TYPE,0,1,"&",str};
  getToken_ExpectAndReturn(tokenizer, (Token *)&typeToken);

  Try {
    handleNEXTOperandMain(tokenizer, &operandInfo);
  }Catch(ex) {
    dumpErrorMessage(ex, 1);
  }
    freeException(ex);
}


/*--------- Function displayOpcode---------
  *give baseOpcode = 0x09
  baseOpcode is depends on instruction
  test something which not in operandtype
*/
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
void test_FUNCTION_DISPLAYOPCODE_given_shortoffY_expect_0x97E990(void){
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
void test_FUNCTION_DISPLAYOPCODE_given_shortoffX_expect_0x98E9(void){
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
void test_FUNCTION_DISPLAYOPCODE_given_longoffX_expect_0x9797D9(void){
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
void test_FUNCTION_DISPLAYOPCODE_given_byte_expect_0x10A9(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  operandInfo.type =BYTE;
  operandInfo.value = 0x10;
  operandInfo.baseOpcode = 0x09;
  displayOpcode(&memoryToWriteCode,&operandInfo);
  TEST_ASSERT_EQUAL_HEX(0x10A9,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[2],memoryToWriteCode);
}
void test_FUNCTION_DISPLAYOPCODE_given_IndexX_expect_0xF9(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  operandInfo.type =IndexX;
  operandInfo.baseOpcode = 0x09;
  displayOpcode(&memoryToWriteCode,&operandInfo);
  TEST_ASSERT_EQUAL_HEX(0xF9,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[1],memoryToWriteCode);
}
void test_FUNCTION_DISPLAYOPCODE_given_IndexY_expect_0xf990(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  operandInfo.type =IndexY;
  operandInfo.value = 0x10;
  operandInfo.baseOpcode = 0x09;
  displayOpcode(&memoryToWriteCode,&operandInfo);
  TEST_ASSERT_EQUAL_HEX(0xf990,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[2],memoryToWriteCode);
}
void test_FUNCTION_DISPLAYOPCODE_given_ShortptrX_expect_0x10D992(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  operandInfo.type =SHORTPTR_X;
  operandInfo.value = 0x10;
  operandInfo.baseOpcode = 0x09;
  displayOpcode(&memoryToWriteCode,&operandInfo);
  TEST_ASSERT_EQUAL_HEX(0x10D992,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[3],memoryToWriteCode);
}
void test_FUNCTION_DISPLAYOPCODE_given_ShortptrY_expect_0x11D991(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  operandInfo.type =SHORTPTR_Y;
  operandInfo.value = 0x11;
  operandInfo.baseOpcode = 0x09;
  displayOpcode(&memoryToWriteCode,&operandInfo);
  TEST_ASSERT_EQUAL_HEX(0x11D991,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[3],memoryToWriteCode);
}
void test_FUNCTION_DISPLAYOPCODE_given_LongPtrX_expect_0x1555D972(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  operandInfo.type =LONGPTR_X;
  operandInfo.value = 0x1555;
  operandInfo.baseOpcode = 0x09;
  displayOpcode(&memoryToWriteCode,&operandInfo);
  TEST_ASSERT_EQUAL_HEX(0x5515D972,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[4],memoryToWriteCode);
}
void test_FUNCTION_DISPLAYOPCODE_given_longptrY_expect_not_valid_operandtype(void){
  CEXCEPTION_T ex;
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  operandInfo.type = 25;
  Try {
      displayOpcode(&memoryToWriteCode,&operandInfo);
    }Catch(ex)
      {
      dumpException(ex);
      }
      freeException1(ex);
}


void test_function_identifyInstruction_given_ADC_expect_baseOpcode_9(void){
  char *str = "ADC";
  OperandInfo operandInfo;
  identifyInstruction(str,&operandInfo);
  printf("%d\n",operandInfo.baseOpcode );
}
void test_function_identifyInstruction_given_XOR_expect_baseOpcode_8(void){
  char *str = "XOR";
  OperandInfo operandInfo;
  identifyInstruction(str,&operandInfo);
  printf("%d\n",operandInfo.baseOpcode );
}
void test_function_identifyInstruction_given_SUB_expect_baseOpcode_0(void){
  char *str = "SUB";
  OperandInfo operandInfo;
  identifyInstruction(str,&operandInfo);
  printf("%d\n",operandInfo.baseOpcode );
}
void test_function_identifyInstruction_given_OR_expect_baseOpcode_A(void){
  char *str = "OR";
  OperandInfo operandInfo;
  identifyInstruction(str,&operandInfo);
  printf("%d\n",operandInfo.baseOpcode );
}
void test_function_identifyInstruction_given_LD_expect_baseOpcode_6(void){
  char *str = "LD";
  OperandInfo operandInfo;
  identifyInstruction(str,&operandInfo);
  printf("%d\n",operandInfo.baseOpcode );
}
void test_function_identifyInstruction_given_CP_expect_baseOpcode_1(void){
  char *str = "CP";
  OperandInfo operandInfo;
  identifyInstruction(str,&operandInfo);
  printf("%d\n",operandInfo.baseOpcode );
}
void test_function_identifyInstruction_given_BCP_expect_baseOpcode_5(void){
  char *str = "BCP";
  OperandInfo operandInfo;
  identifyInstruction(str,&operandInfo);
  printf("%d\n",operandInfo.baseOpcode );
}
void test_function_identifyInstruction_given_AND_expect_baseOpcode_4(void){
  char *str = "AND";
  OperandInfo operandInfo;
  identifyInstruction(str,&operandInfo);
  printf("%d\n",operandInfo.baseOpcode );
}
void test_function_identifyInstruction_given_ADD_expect_baseOpcode_B(void){
  char *str = "ADD";
  OperandInfo operandInfo;
  identifyInstruction(str,&operandInfo);
  printf("%d\n",operandInfo.baseOpcode );
}
void test_function_identifyInstruction_given_others_instruction_expect_Not_valid_instruction(void){
  CEXCEPTION_T ex;
  char *str = "ADD";
  OperandInfo operandInfo;
  Try {
    identifyInstruction(str,&operandInfo);
  }Catch(ex) {
  TEST_ASSERT_EQUAL(NOT_VALID_OPREANDINFO_TYPE, ex);
  }
}

void test_handleinherentInstruction_given_Break_expect_8B(void){
  CEXCEPTION_T ex;
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "BREAK";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,5,"BREAK"};

	initTokenizer_ExpectAndReturn(str,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&ADDToken);

  handleInherentInstruction(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x8B,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[1],memoryToWriteCode);
  printf("0x%02x\n",buffer[0]);

}
void test_asesemble_given_adc_byte_0x55_expect_0x55A9(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "adc A,#$97";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"ADC",str};
	IdentifierToken AToken = {TOKEN_IDENTIFIER_TYPE,4 ,1,"A",str};
	OperatorToken   CommaToken ={TOKEN_OPERATOR_TYPE, 5,1,",",str};
  OperatorToken   HashToken ={TOKEN_OPERATOR_TYPE, 6,1,"#",str};
	OperatorToken   dollarToken ={TOKEN_OPERATOR_TYPE, 7,1,"$",str};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,8,4,"0x55",str,0x55};


	initTokenizer_ExpectAndReturn(str,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&ADDToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&AToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&CommaToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&HashToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&dollarToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);

		assemble(str, &memoryToWriteCode);
    TEST_ASSERT_EQUAL_HEX(0x55A9,*(uint32_t *)buffer);
    TEST_ASSERT_EQUAL_PTR(&buffer[2],memoryToWriteCode);
    printf("0x%02x%02x\n",buffer[0],buffer[1]);
}

/*

  //test ADC

void test_asesemble_given_adc_byte_0x55_expect_0x55A9(void){
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

		assemble(str, &memoryToWriteCode);
    TEST_ASSERT_EQUAL_HEX(0x55A9,*(uint32_t *)buffer);
    TEST_ASSERT_EQUAL_PTR(&buffer[2],memoryToWriteCode);
    printf("0x%02x%02x\n",buffer[0],buffer[1]);
}
void test_asesemble_given_adc_long_mem_0xff55_expect_0xff55C9(void){
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0xff55C9,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[3],memoryToWriteCode);
  printf("0x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2]);
}
void test_asesemble_given_adc_short_mem_0x55_expect_0x55B9(void){
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x55B9,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[2],memoryToWriteCode);
  printf("0x%02x%02x\n",buffer[0],buffer[1]);
}
void test_asesemble_given_adc_index_X_expect_0xF9(void){
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0xF9,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[1],memoryToWriteCode);
  printf("0x%02x\n",buffer[0]);
}
void test_asesemble_given_adc_index_Y_expect_0xF990(void){
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0xF990,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[2],memoryToWriteCode);
  printf("0x%02x%02x\n",buffer[0],buffer[1]);

}
void test_asesemble_given_adc_shortoff_index_X_expect_0x10E9(void){
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


	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x10E9,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[2],memoryToWriteCode);
  printf("0x%02x%02x\n",buffer[0],buffer[1]);
}
void test_asesemble_given_adc_shortoff_index_Y_expect_0x10E990(void){
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x10E990,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[3],memoryToWriteCode);
  printf("0x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2]);

}
void test_asesemble_given_adc_longoff_index_X_expect_0x8810D9(void){
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x8810D9,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[3],memoryToWriteCode);
  printf("0x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2]);
}
void test_asesemble_given_adc_longoff_index_Y_expect_0x8810D990(void){
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x8810D990,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[4],memoryToWriteCode);
  printf("0x%02x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2],buffer[3]);

}
void test_asesemble_given_adc_shortoff_index_SP_expect_0x8819(void){
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x8819,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[2],memoryToWriteCode);
  printf("0x%02x%02x\n",buffer[0],buffer[1]);
}
void test_asesemble_given_adc_shortptr_expect_0x55c992(void){
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x55c992,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[3],memoryToWriteCode);
  printf("0x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2]);
}
void test_asesemble_given_adc_longptr_expect_0x4455c972(void){
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x4455c972,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[4],memoryToWriteCode);
  printf("0x%02x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2],buffer[3]);
}
void test_asesemble_given_adc_shortptr_index_X_expect_0x45D992(void){
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x45D992,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[3],memoryToWriteCode);
  printf("0x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2]);
}
void test_asesemble_given_adc_shortptr_index_Y_expect_0x45D991(void){
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x45D991,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[3],memoryToWriteCode);
  printf("0x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2]);
}
void test_asesemble_given_adc_longptr_index_X_expect_0x5545D972(void){
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x5545D972,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[4],memoryToWriteCode);
  printf("0x%02x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2],buffer[3]);

}
void test_asesemble_given_Not_comma_symbol_expect_not_valid_identifier(void){
  CEXCEPTION_T ex;
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "ADD A,";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"ADD"};
	IdentifierToken AToken = {TOKEN_IDENTIFIER_TYPE,4 ,1,"Z"};
  initTokenizer_ExpectAndReturn(str,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&ADDToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&AToken);
	Try {
		assemble(str, &memoryToWriteCode);
	}Catch(ex) {
	TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER, ex);
	}
}
void test_asesemble_given_TCC_Wrong_instruction_expect_not_valid_instruction(void){
  CEXCEPTION_T ex;
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "TCC";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"TCC"};
	initTokenizer_ExpectAndReturn(str,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&ADDToken);
	Try {
		assemble(str, &memoryToWriteCode);
	}Catch(ex) {
	TEST_ASSERT_EQUAL(NOT_VALID_INSTRUCTION, ex);
	}
}
void test_asesemble_given_Not_comma_symbol_expect_not_valid_operator(void){
  CEXCEPTION_T ex;
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "ADD A,";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"ADD"};
	IdentifierToken AToken = {TOKEN_IDENTIFIER_TYPE,4 ,1,"A"};
	OperatorToken   CommaToken ={TOKEN_OPERATOR_TYPE, 5,1,"["};
  initTokenizer_ExpectAndReturn(str,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&ADDToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&AToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&CommaToken);
	Try {
		assemble(str, &memoryToWriteCode);
	}Catch(ex) {
	TEST_ASSERT_EQUAL(NOT_VALID_OPERATOR, ex);
	}
}
/*
//test ADD
void test_asesemble_given_add_byte_0x55_expect_0x55AB(void){
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x55AB,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[2],memoryToWriteCode);
  printf("0x%02x%02x\n",buffer[0],buffer[1]);
}
void test_asesemble_given_add_long_mem_0xff55_expect_0xff55CB(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "add A,$55ff";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"ADD"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0xff55CB,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[3],memoryToWriteCode);
  printf("0x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2]);
}
void test_asesemble_given_add_short_mem_0x55_expect_0x55BB(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "add A,$55";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"ADD"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x55BB,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[2],memoryToWriteCode);
  printf("0x%02x%02x\n",buffer[0],buffer[1]);
}
void test_asesemble_given_add_index_X_expect_0xFB(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "add A,(X)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"ADD"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0xFB,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[1],memoryToWriteCode);
  printf("0x%02x\n",buffer[0]);
}
void test_asesemble_given_add_index_Y_expect_0xFB90(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "add A,(X)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"ADD"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0xFB90,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[2],memoryToWriteCode);
  printf("0x%02x%02x\n",buffer[0],buffer[1]);

}
void test_asesemble_given_add_shortoff_index_X_expect_0x10EB(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "ADD A,($10,X)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"ADD"};
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


	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x10EB,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[2],memoryToWriteCode);
  printf("0x%02x%02x\n",buffer[0],buffer[1]);
}
void test_asesemble_given_add_shortoff_index_Y_expect_0x10EB90(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "ADD A,($10,Y)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"ADD"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x10EB90,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[3],memoryToWriteCode);
  printf("0x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2]);

}
void test_asesemble_given_add_longoff_index_X_expect_0x8810DB(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "ADD A,($1088,X)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"ADD"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x8810DB,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[3],memoryToWriteCode);
  printf("0x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2]);
}
void test_asesemble_given_add_longoff_index_Y_expect_0x8810DB90(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "ADD A,($1088,Y)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"ADD"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x8810DB90,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[4],memoryToWriteCode);
  printf("0x%02x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2],buffer[3]);

}
void test_asesemble_given_add_shortoff_index_SP_expect_0x881B(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "ADD A,($88,SP)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"ADD"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x881B,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[2],memoryToWriteCode);
  printf("0x%02x%02x\n",buffer[0],buffer[1]);
}
void test_asesemble_given_add_shortptr_expect_0x55cB92(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "ADD A,[$55.w]";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"ADD"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x55cB92,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[3],memoryToWriteCode);
  printf("0x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2]);
}
void test_asesemble_given_add_longptr_expect_0x4455cB72(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "ADD A,[$5544.w]";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"ADD"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x4455cB72,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[4],memoryToWriteCode);
  printf("0x%02x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2],buffer[3]);
}
void test_asesemble_given_add_shortptr_index_X_expect_0x45DB92(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "ADD A,([$45.w],X)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"ADD"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x45DB92,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[3],memoryToWriteCode);
  printf("0x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2]);
}
void test_asesemble_given_add_shortptr_index_Y_expect_0x45DB91(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "ADD A,([$45.w],Y)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"ADD"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x45DB91,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[3],memoryToWriteCode);
  printf("0x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2]);
}
void test_asesemble_given_add_longptr_index_X_expect_0x5545DB72(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "ADD A,([$4555.w],X)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"ADD"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x5545DB72,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[4],memoryToWriteCode);
  printf("0x%02x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2],buffer[3]);

}
//test AND
void test_asesemble_given_and_byte_0x55_expect_0x55A4(void){
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x55A4,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[2],memoryToWriteCode);
  printf("0x%02x%02x\n",buffer[0],buffer[1]);
}
void test_asesemble_given_and_long_mem_0xff55_expect_0xff55C4(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "and A,$55ff";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"AND"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0xff55C4,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[3],memoryToWriteCode);
  printf("0x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2]);
}
void test_asesemble_given_and_short_mem_0x55_expect_0x55B4(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "and A,$55";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"AND"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x55B4,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[2],memoryToWriteCode);
  printf("0x%02x%02x\n",buffer[0],buffer[1]);
}
void test_asesemble_given_and_index_X_expect_0xF4(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "and A,(X)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"AND"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0xF4,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[1],memoryToWriteCode);
  printf("0x%02x\n",buffer[0]);
}
void test_asesemble_given_and_index_Y_expect_0xF490(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "and A,(X)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"AND"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0xF490,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[2],memoryToWriteCode);
  printf("0x%02x%02x\n",buffer[0],buffer[1]);

}
void test_asesemble_given_and_shortoff_index_X_expect_0x10E4(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "AND A,($10,X)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"AND"};
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


	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x10E4,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[2],memoryToWriteCode);
  printf("0x%02x%02x\n",buffer[0],buffer[1]);
}
void test_asesemble_given_and_shortoff_index_Y_expect_0x10E490(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "And A,($10,Y)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"AND"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x10E490,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[3],memoryToWriteCode);
  printf("0x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2]);

}
void test_asesemble_given_and_longoff_index_X_expect_0x8810D4(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "AND A,($1088,X)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"AND"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x8810D4,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[3],memoryToWriteCode);
  printf("0x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2]);
}
void test_asesemble_given_and_longoff_index_Y_expect_0x8810D490(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "AND A,($1088,Y)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"AND"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x8810D490,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[4],memoryToWriteCode);
  printf("0x%02x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2],buffer[3]);

}
void test_asesemble_given_and_shortoff_index_SP_expect_0x8814(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "AND A,($88,SP)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"AND"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x8814,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[2],memoryToWriteCode);
  printf("0x%02x%02x\n",buffer[0],buffer[1]);
}
void test_asesemble_given_and_shortptr_expect_0x55c492(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "And A,[$55.w]";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"AND"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x55c492,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[3],memoryToWriteCode);
  printf("0x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2]);
}
void test_asesemble_given_and_longptr_expect_0x4455c472(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "AND A,[$5544.w]";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"AND"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x4455c472,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[4],memoryToWriteCode);
  printf("0x%02x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2],buffer[3]);
}
void test_asesemble_given_and_shortptr_index_X_expect_0x45D492(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "And A,([$45.w],X)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"AND"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x45D492,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[3],memoryToWriteCode);
  printf("0x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2]);
}
void test_asesemble_given_and_shortptr_index_Y_expect_0x45D491(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "And A,([$45.w],Y)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"AND"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x45D491,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[3],memoryToWriteCode);
  printf("0x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2]);
}
void test_asesemble_given_and_longptr_index_X_expect_0x5545D472(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "AND A,([$4555.w],X)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"AND"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x5545D472,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[4],memoryToWriteCode);
  printf("0x%02x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2],buffer[3]);

}
//test BCP
void test_asesemble_given_BCP_byte_0x55_expect_0x55A5(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "BCP A,#$55";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"BCP"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x55A5,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[2],memoryToWriteCode);
  printf("0x%02x%02x\n",buffer[0],buffer[1]);
}
void test_asesemble_given_BCP_long_mem_0xff55_expect_0xff55C5(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "BCP A,$55ff";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"BCP"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0xff55C5,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[3],memoryToWriteCode);
  printf("0x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2]);
}
void test_asesemble_given_BCP_short_mem_0x55_expect_0x55B5(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "BCP A,$55";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"BCP"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x55B5,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[2],memoryToWriteCode);
  printf("0x%02x%02x\n",buffer[0],buffer[1]);
}
void test_asesemble_given_BCP_index_X_expect_0xF5(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "BCP A,(X)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"BCP"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0xF5,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[1],memoryToWriteCode);
  printf("0x%02x\n",buffer[0]);
}
void test_asesemble_given_BCP_index_Y_expect_0xF590(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "BCP A,(X)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"BCP"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0xF590,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[2],memoryToWriteCode);
  printf("0x%02x%02x\n",buffer[0],buffer[1]);

}
void test_asesemble_given_BCP_shortoff_index_X_expect_0x10E5(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "BCP A,($10,X)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"BCP"};
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


	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x10E5,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[2],memoryToWriteCode);
  printf("0x%02x%02x\n",buffer[0],buffer[1]);
}
void test_asesemble_given_BCP_shortoff_index_Y_expect_0x10E590(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "BCP A,($10,Y)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"BCP"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x10E590,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[3],memoryToWriteCode);
  printf("0x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2]);

}
void test_asesemble_given_BCP_longoff_index_X_expect_0x8810D5(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "BCPA,($1088,X)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"BCP"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x8810D5,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[3],memoryToWriteCode);
  printf("0x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2]);
}
void test_asesemble_given_BCP_longoff_index_Y_expect_0x8810D590(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "BCP A,($1088,Y)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"BCP"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x8810D590,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[4],memoryToWriteCode);
  printf("0x%02x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2],buffer[3]);

}
void test_asesemble_given_BCP_shortoff_index_SP_expect_0x8815(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "BCP A,($88,SP)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"BCP"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x8815,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[2],memoryToWriteCode);
  printf("0x%02x%02x\n",buffer[0],buffer[1]);
}
void test_asesemble_given_BCP_shortptr_expect_0x55c592(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "BCP A,[$55.w]";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"BCP"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x55c592,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[3],memoryToWriteCode);
  printf("0x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2]);
}
void test_asesemble_given_BCP_longptr_expect_0x4455c572(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "BCP A,[$5544.w]";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"BCP"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x4455c572,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[4],memoryToWriteCode);
  printf("0x%02x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2],buffer[3]);
}
void test_asesemble_given_BCP_shortptr_index_X_expect_0x45D592(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "BCP A,([$45.w],X)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"BCP"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x45D592,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[3],memoryToWriteCode);
  printf("0x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2]);
}
void test_asesemble_given_BCP_shortptr_index_Y_expect_0x45D591(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "BCP A,([$45.w],Y)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"BCP"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x45D591,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[3],memoryToWriteCode);
  printf("0x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2]);
}
void test_asesemble_given_BCP_longptr_index_X_expect_0x5545D572(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "BCP A,([$4555.w],X)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"BCP"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x5545D572,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[4],memoryToWriteCode);
  printf("0x%02x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2],buffer[3]);

}
// test CP
void test_asesemble_given_CP_byte_0x55_expect_0x55A1(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "CP A,#$55";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"CP"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x55A1,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[2],memoryToWriteCode);
  printf("0x%02x%02x\n",buffer[0],buffer[1]);
}
void test_asesemble_given_CP_long_mem_0xff55_expect_0xff55C1(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "CP A,$55ff";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"CP"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0xff55C1,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[3],memoryToWriteCode);
  printf("0x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2]);
}
void test_asesemble_given_CP_short_mem_0x55_expect_0x55B1(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "CP A,$55";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"CP"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x55B1,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[2],memoryToWriteCode);
  printf("0x%02x%02x\n",buffer[0],buffer[1]);
}
void test_asesemble_given_CP_index_X_expect_0xF1(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "CP A,(X)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"CP"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0xF1,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[1],memoryToWriteCode);
  printf("0x%02x\n",buffer[0]);
}
void test_asesemble_given_CP_index_Y_expect_0xF190(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "CP A,(X)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"CP"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0xF190,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[2],memoryToWriteCode);
  printf("0x%02x%02x\n",buffer[0],buffer[1]);

}
void test_asesemble_given_CP_shortoff_index_X_expect_0x10E1(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "CP A,($10,X)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"CP"};
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


	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x10E1,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[2],memoryToWriteCode);
  printf("0x%02x%02x\n",buffer[0],buffer[1]);
}
void test_asesemble_given_CP_shortoff_index_Y_expect_0x10E190(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "CP A,($10,Y)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"CP"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x10E190,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[3],memoryToWriteCode);
  printf("0x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2]);

}
void test_asesemble_given_CP_longoff_index_X_expect_0x8810D1(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "CP,($1088,X)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"CP"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x8810D1,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[3],memoryToWriteCode);
  printf("0x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2]);
}
void test_asesemble_given_CP_longoff_index_Y_expect_0x8810D190(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "CP A,($1088,Y)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"CP"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x8810D190,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[4],memoryToWriteCode);
  printf("0x%02x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2],buffer[3]);

}
void test_asesemble_given_CP_shortoff_index_SP_expect_0x8811(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "CP A,($88,SP)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"CP"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x8811,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[2],memoryToWriteCode);
  printf("0x%02x%02x\n",buffer[0],buffer[1]);
}
void test_asesemble_given_CP_shortptr_expect_0x55c192(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "CP A,[$55.w]";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"CP"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x55c192,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[3],memoryToWriteCode);
  printf("0x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2]);
}
void test_asesemble_given_CP_longptr_expect_0x4455c172(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "CP A,[$5544.w]";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"CP"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x4455c172,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[4],memoryToWriteCode);
  printf("0x%02x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2],buffer[3]);
}
void test_asesemble_given_CP_shortptr_index_X_expect_0x45D192(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "CP A,([$45.w],X)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"CP"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x45D192,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[3],memoryToWriteCode);
  printf("0x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2]);
}
void test_asesemble_given_CP_shortptr_index_Y_expect_0x45D191(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "CP A,([$45.w],Y)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"CP"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x45D191,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[3],memoryToWriteCode);
  printf("0x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2]);
}
void test_asesemble_given_CP_longptr_index_X_expect_0x5545D172(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "CP A,([$4555.w],X)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"CP"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x5545D172,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[4],memoryToWriteCode);
  printf("0x%02x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2],buffer[3]);

}
// test LD
void test_asesemble_given_LD_byte_0x55_expect_0x55A6(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "LD A,#$55";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"LD"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x55A6,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[2],memoryToWriteCode);
  printf("0x%02x%02x\n",buffer[0],buffer[1]);
}
void test_asesemble_given_LD_long_mem_0xff55_expect_0xff55C6(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "LD A,$55ff";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"LD"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0xff55C6,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[3],memoryToWriteCode);
  printf("0x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2]);
}
void test_asesemble_given_LD_short_mem_0x55_expect_0x55B6(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "LD A,$55";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"LD"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x55B6,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[2],memoryToWriteCode);
  printf("0x%02x%02x\n",buffer[0],buffer[1]);
}
void test_asesemble_given_LD_index_X_expect_0xF6(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "LD A,(X)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"LD"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0xF6,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[1],memoryToWriteCode);
  printf("0x%02x\n",buffer[0]);
}
void test_asesemble_given_LD_index_Y_expect_0xF690(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "LD A,(X)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"LD"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0xF690,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[2],memoryToWriteCode);
  printf("0x%02x%02x\n",buffer[0],buffer[1]);

}
void test_asesemble_given_LD_shortoff_index_X_expect_0x10E6(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "LD A,($10,X)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"LD"};
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


	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x10E6,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[2],memoryToWriteCode);
  printf("0x%02x%02x\n",buffer[0],buffer[1]);
}
void test_asesemble_given_LD_shortoff_index_Y_expect_0x10E690(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "LD A,($10,Y)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"LD"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x10E690,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[3],memoryToWriteCode);
  printf("0x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2]);

}
void test_asesemble_given_LD_longoff_index_X_expect_0x8810D6(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "LD,($1088,X)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"LD"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x8810D6,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[3],memoryToWriteCode);
  printf("0x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2]);
}
void test_asesemble_given_LD_longoff_index_Y_expect_0x8810D690(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "LD A,($1088,Y)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"LD"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x8810D690,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[4],memoryToWriteCode);
  printf("0x%02x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2],buffer[3]);

}
void test_asesemble_given_LD_shortoff_index_SP_expect_0x8816(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "LD A,($88,SP)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"LD"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x8816,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[2],memoryToWriteCode);
  printf("0x%02x%02x\n",buffer[0],buffer[1]);
}
void test_asesemble_given_LD_shortptr_expect_0x55C692(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "LD A,[$55.w]";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"LD"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x55c692,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[3],memoryToWriteCode);
  printf("0x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2]);
}
void test_asesemble_given_LD_longptr_expect_0x4455c672(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "LD A,[$5544.w]";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"LD"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x4455c672,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[4],memoryToWriteCode);
  printf("0x%02x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2],buffer[3]);
}
void test_asesemble_given_LD_shortptr_index_X_expect_0x45D692(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "LD A,([$45.w],X)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"LD"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x45D692,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[3],memoryToWriteCode);
  printf("0x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2]);
}
void test_asesemble_given_LD_shortptr_index_Y_expect_0x45D691(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "LD A,([$45.w],Y)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"LD"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x45D691,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[3],memoryToWriteCode);
  printf("0x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2]);
}
void test_asesemble_given_LD_longptr_index_X_expect_0x5545D672(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "LD A,([$4555.w],X)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"LD"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x5545D672,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[4],memoryToWriteCode);
  printf("0x%02x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2],buffer[3]);

}
// test or
void test_asesemble_given_or_byte_0x55_expect_0x55AA(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "OR A,#$55";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"OR"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x55AA,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[2],memoryToWriteCode);
  printf("0x%02x%02x\n",buffer[0],buffer[1]);
}
void test_asesemble_given_OR_long_mem_0xff55_expect_0xff55CA(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "OR A,$55ff";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"OR"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0xff55CA,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[3],memoryToWriteCode);
  printf("0x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2]);
}
void test_asesemble_given_OR_short_mem_0x55_expect_0x55BA(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "OR A,$55";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"OR"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x55BA,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[2],memoryToWriteCode);
  printf("0x%02x%02x\n",buffer[0],buffer[1]);
}
void test_asesemble_given_OR_index_X_expect_0xFA(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "OR A,(X)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"OR"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0xFA,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[1],memoryToWriteCode);
  printf("0x%02x\n",buffer[0]);
}
void test_asesemble_given_OR_index_Y_expect_0xFA90(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "OR A,(X)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"OR"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0xFA90,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[2],memoryToWriteCode);
  printf("0x%02x%02x\n",buffer[0],buffer[1]);

}
void test_asesemble_given_OR_shortoff_index_X_expect_0x10EA(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "OR A,($10,X)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"OR"};
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


	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x10EA,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[2],memoryToWriteCode);
  printf("0x%02x%02x\n",buffer[0],buffer[1]);
}
void test_asesemble_given_OR_shortoff_index_Y_expect_0x10EA90(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "OR A,($10,Y)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"OR"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x10EA90,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[3],memoryToWriteCode);
  printf("0x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2]);

}
void test_asesemble_given_OR_longoff_index_X_expect_0x8810DA(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "OR,($1088,X)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"OR"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x8810DA,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[3],memoryToWriteCode);
  printf("0x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2]);
}
void test_asesemble_given_OR_longoff_index_Y_expect_0x8810DA90(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "OR A,($1088,Y)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"OR"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x8810DA90,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[4],memoryToWriteCode);
  printf("0x%02x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2],buffer[3]);

}
void test_asesemble_given_OR_shortoff_index_SP_expect_0x881A(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "OR A,($88,SP)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"OR"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x881A,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[2],memoryToWriteCode);
  printf("0x%02x%02x\n",buffer[0],buffer[1]);
}
void test_asesemble_given_OR_shortptr_expect_0x55CA92(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "OR A,[$55.w]";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"OR"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x55cA92,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[3],memoryToWriteCode);
  printf("0x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2]);
}
void test_asesemble_given_OR_longptr_expect_0x4455cA72(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "OR A,[$5544.w]";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"OR"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x4455cA72,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[4],memoryToWriteCode);
  printf("0x%02x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2],buffer[3]);
}
void test_asesemble_given_OR_shortptr_index_X_expect_0x45DA92(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "OR A,([$45.w],X)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"OR"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x45DA92,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[3],memoryToWriteCode);
  printf("0x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2]);
}
void test_asesemble_given_OR_shortptr_index_Y_expect_0x45DA91(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "OR A,([$45.w],Y)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"OR"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x45DA91,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[3],memoryToWriteCode);
  printf("0x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2]);
}
void test_asesemble_given_OR_longptr_index_X_expect_0x5545DA72(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "OR A,([$4555.w],X)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"OR"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x5545DA72,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[4],memoryToWriteCode);
  printf("0x%02x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2],buffer[3]);

}

// test SBC
void test_asesemble_given_SBC_byte_0x55_expect_0x55A2(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "SBC A,#$55";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"SBC"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x55A2,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[2],memoryToWriteCode);
  printf("0x%02x%02x\n",buffer[0],buffer[1]);
}
void test_asesemble_given_SBC_long_mem_0xff55_expect_0xff55C2(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "SBC A,$55ff";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"SBC"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0xff55C2,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[3],memoryToWriteCode);
  printf("0x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2]);
}
void test_asesemble_given_SBC_short_mem_0x55_expect_0x55B2(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "SBC A,$55";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"SBC"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x55B2,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[2],memoryToWriteCode);
  printf("0x%02x%02x\n",buffer[0],buffer[1]);
}
void test_asesemble_given_SBC_index_X_expect_0xF2(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "SBC A,(X)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"SBC"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0xF2,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[1],memoryToWriteCode);
  printf("0x%02x\n",buffer[0]);
}
void test_asesemble_given_SBC_index_Y_expect_0xF290(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "SBC A,(X)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"SBC"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0xF290,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[2],memoryToWriteCode);
  printf("0x%02x%02x\n",buffer[0],buffer[1]);

}
void test_asesemble_given_SBC_shortoff_index_X_expect_0x10E2(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "SBC A,($10,X)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"SBC"};
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


	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x10E2,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[2],memoryToWriteCode);
  printf("0x%02x%02x\n",buffer[0],buffer[1]);
}
void test_asesemble_given_SBC_shortoff_index_Y_expect_0x10E290(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "SBC A,($10,Y)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"SBC"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x10E290,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[3],memoryToWriteCode);
  printf("0x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2]);

}
void test_asesemble_given_SBC_longoff_index_X_expect_0x8810D2(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "SBC,($1088,X)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"SBC"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x8810D2,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[3],memoryToWriteCode);
  printf("0x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2]);
}
void test_asesemble_given_SBC_longoff_index_Y_expect_0x8810D290(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "SBC A,($1088,Y)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"SBC"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x8810D290,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[4],memoryToWriteCode);
  printf("0x%02x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2],buffer[3]);

}
void test_asesemble_given_SBC_shortoff_index_SP_expect_0x8812(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "SBC A,($88,SP)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"SBC"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x8812,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[2],memoryToWriteCode);
  printf("0x%02x%02x\n",buffer[0],buffer[1]);
}
void test_asesemble_given_SBC_shortptr_expect_0x55C292(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "SBC A,[$55.w]";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"SBC"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x55c292,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[3],memoryToWriteCode);
  printf("0x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2]);
}
void test_asesemble_given_SBC_longptr_expect_0x4455c272(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "SBC A,[$5544.w]";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"SBC"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x4455c272,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[4],memoryToWriteCode);
  printf("0x%02x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2],buffer[3]);
}
void test_asesemble_given_SBC_shortptr_index_X_expect_0x45D292(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "OSBCR A,([$45.w],X)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"SBC"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x45D292,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[3],memoryToWriteCode);
  printf("0x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2]);
}
void test_asesemble_given_SBC_shortptr_index_Y_expect_0x45D291(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "SBC A,([$45.w],Y)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"SBC"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x45D291,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[3],memoryToWriteCode);
  printf("0x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2]);
}
void test_asesemble_given_SBC_longptr_index_X_expect_0x5545D272(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "SBC A,([$4555.w],X)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"SBC"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x5545D272,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[4],memoryToWriteCode);
  printf("0x%02x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2],buffer[3]);

}

// test XOR
void test_asesemble_given_Xor_byte_0x55_expect_0x55A8(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "XOR A,#$55";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"XOR"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x55A8,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[2],memoryToWriteCode);
  printf("0x%02x%02x\n",buffer[0],buffer[1]);
}
void test_asesemble_given_XOR_long_mem_0xff55_expect_0xff55C8(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "XOR A,$55ff";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"XOR"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0xff55C8,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[3],memoryToWriteCode);
  printf("0x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2]);
}
void test_asesemble_given_XOR_short_mem_0x55_expect_0x55B8(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "XOR A,$55";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"XOR"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x55B8,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[2],memoryToWriteCode);
  printf("0x%02x%02x\n",buffer[0],buffer[1]);
}
void test_asesemble_given_XOR_index_X_expect_0xF8(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "XOR A,(X)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"XOR"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0xF8,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[1],memoryToWriteCode);
  printf("0x%02x\n",buffer[0]);
}
void test_asesemble_given_XOR_index_Y_expect_0xF890(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "XOR A,(X)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"XOR"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0xF890,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[2],memoryToWriteCode);
  printf("0x%02x%02x\n",buffer[0],buffer[1]);

}
void test_asesemble_given_XOR_shortoff_index_X_expect_0x10E8(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "XOR A,($10,X)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"XOR"};
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


	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x10E8,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[2],memoryToWriteCode);
  printf("0x%02x%02x\n",buffer[0],buffer[1]);
}
void test_asesemble_given_XOR_shortoff_index_Y_expect_0x10E890(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "XOR A,($10,Y)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"XOR"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x10E890,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[3],memoryToWriteCode);
  printf("0x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2]);

}
void test_asesemble_given_XOR_longoff_index_X_expect_0x8810D8(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "XOR,($1088,X)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"XOR"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x8810D8,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[3],memoryToWriteCode);
  printf("0x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2]);
}
void test_asesemble_given_XOR_longoff_index_Y_expect_0x8810D890(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "XOR A,($1088,Y)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"XOR"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x8810D890,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[4],memoryToWriteCode);
  printf("0x%02x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2],buffer[3]);

}
void test_asesemble_given_XOR_shortoff_index_SP_expect_0x8818(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "XOR A,($88,SP)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"XOR"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x8818,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[2],memoryToWriteCode);
  printf("0x%02x%02x\n",buffer[0],buffer[1]);
}
void test_asesemble_given_XOR_shortptr_expect_0x55C892(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "XOR A,[$55.w]";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"XOR"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x55c892,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[3],memoryToWriteCode);
  printf("0x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2]);
}
void test_asesemble_given_XOR_longptr_expect_0x4455c872(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "XOR A,[$5544.w]";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"XOR"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x4455c872,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[4],memoryToWriteCode);
  printf("0x%02x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2],buffer[3]);
}
void test_asesemble_given_XOR_shortptr_index_X_expect_0x45D892(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "XOR A,([$45.w],X)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"XOR"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x45D892,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[3],memoryToWriteCode);
  printf("0x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2]);
}
void test_asesemble_given_XOR_shortptr_index_Y_expect_0x45D891(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "XOR A,([$45.w],Y)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"XOR"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x45D891,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[3],memoryToWriteCode);
  printf("0x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2]);
}
void test_asesemble_given_XOR_longptr_index_X_expect_0x5545D872(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "XOR A,([$4555.w],X)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"XOR"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x5545D872,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[4],memoryToWriteCode);
  printf("0x%02x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2],buffer[3]);

}

void test_asesemble_given_SUB_byte_0x55_expect_0x55A0(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "SUB A,#$55";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"SUB"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x55A0,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[2],memoryToWriteCode);
  printf("0x%02x%02x\n",buffer[0],buffer[1]);
}
void test_asesemble_given_SUB_long_mem_0xff55_expect_0xff55C0(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "SUB A,$55ff";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"SUB"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0xff55C0,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[3],memoryToWriteCode);
  printf("0x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2]);
}
void test_asesemble_given_SUB_short_mem_0x55_expect_0x55B0(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "SUB A,$55";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"SUB"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x55B0,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[2],memoryToWriteCode);
  printf("0x%02x%02x\n",buffer[0],buffer[1]);
}
void test_asesemble_given_SUB_index_X_expect_0xF0(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "SUB A,(X)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"SUB"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0xF0,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[1],memoryToWriteCode);
  printf("0x%02x\n",buffer[0]);
}
void test_asesemble_given_SUB_index_Y_expect_0xF090(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "SUB A,(X)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"SUB"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0xF090,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[2],memoryToWriteCode);
  printf("0x%02x%02x\n",buffer[0],buffer[1]);

}
void test_asesemble_given_SUB_shortoff_index_X_expect_0x10E0(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "SUB A,($10,X)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"SUB"};
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


	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x10E0,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[2],memoryToWriteCode);
  printf("0x%02x%02x\n",buffer[0],buffer[1]);
}
void test_asesemble_given_SUB_shortoff_index_Y_expect_0x10E090(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "SUB A,($10,Y)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"SUB"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x10E090,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[3],memoryToWriteCode);
  printf("0x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2]);

}
void test_asesemble_given_SUB_longoff_index_X_expect_0x8810D0(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "SUB,($1088,X)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"SUB"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x8810D0,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[3],memoryToWriteCode);
  printf("0x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2]);
}
void test_asesemble_given_SUB_longoff_index_Y_expect_0x8810D090(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "SUB A,($1088,Y)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"SUB"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x8810D090,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[4],memoryToWriteCode);
  printf("0x%02x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2],buffer[3]);

}
void test_asesemble_given_SUB_shortoff_index_SP_expect_0x8810(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "SUB A,($88,SP)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"SUB"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x8810,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[2],memoryToWriteCode);
  printf("0x%02x%02x\n",buffer[0],buffer[1]);
}
void test_asesemble_given_SUB_shortptr_expect_0x55C092(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "SUB A,[$55.w]";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"SUB"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x55c092,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[3],memoryToWriteCode);
  printf("0x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2]);
}
void test_asesemble_given_SUB_longptr_expect_0x4455c072(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "SUB A,[$5544.w]";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"SUB"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x4455c072,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[4],memoryToWriteCode);
  printf("0x%02x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2],buffer[3]);
}
void test_asesemble_given_SUB_shortptr_index_X_expect_0x45D092(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "SUB A,([$45.w],X)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"SUB"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x45D092,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[3],memoryToWriteCode);
  printf("0x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2]);
}
void test_asesemble_given_SUB_shortptr_index_Y_expect_0x45D091(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "SUB A,([$45.w],Y)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"SUB"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x45D091,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[3],memoryToWriteCode);
  printf("0x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2]);
}
void test_asesemble_given_SUB_longptr_index_X_expect_0x5545D072(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "SUB A,([$4555.w],X)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"SUB"};
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

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x5545D072,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[4],memoryToWriteCode);
  printf("0x%02x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2],buffer[3]);

}
*/
