#include "unity.h"
#include "Assemble.h"
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
    TEST_ASSERT_EQUAL(LIMIT_EXCEEDED,ex->errorCode);
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
    TEST_ASSERT_EQUAL(WRONG_TOKEN_TYPE,ex->errorCode);
  }
    freeException(ex);
}
//test function gettokenDotWBracket
void test_function_gettokenDotWBracket_given_comma_represent_dollar_expect_not_valid_operator(void){
  CEXCEPTION_T ex;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char *str = ",W]";
  OperatorToken dotToken = {TOKEN_OPERATOR_TYPE,0,1,",",str};
  getToken_ExpectAndReturn(tokenizer, (Token *)&dotToken);

  Try {
    gettokenDotWBracket(tokenizer, &operandInfo);
  }Catch(ex) {
    dumpErrorMessage(ex, 1);
    TEST_ASSERT_EQUAL(NOT_VALID_OPERATOR,ex->errorCode);
  }
  freeException(ex);
}
void test_function_gettokenDotWBracket_given_dot_X_represent_W_expect_Not_valid_identifier(void){
  CEXCEPTION_T ex;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char *str = ".X]";
  OperatorToken dotToken = {TOKEN_OPERATOR_TYPE,0,1,".",str};;
  IdentifierToken WToken = {TOKEN_IDENTIFIER_TYPE,1,1,"X",str};
  getToken_ExpectAndReturn(tokenizer, (Token *)&dotToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WToken);

  Try {
    gettokenDotWBracket(tokenizer, &operandInfo);
      }Catch(ex) {
    dumpErrorMessage(ex, 1);
    TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER,ex->errorCode);
      }
  freeException(ex);
}
void test_function_gettokenDotWBracket_given_dot_W_dot_expect_Exception_Not_valid_operator(void){
  CEXCEPTION_T ex;
  OperandInfo operandInfo;
  operandInfo.value = 0x97;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char *str = ".W.";
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
    TEST_ASSERT_EQUAL(NOT_VALID_OPERATOR,ex->errorCode);
      }
    freeException(ex);
}
void test_function_gettokenDotWBracket_given_dot_W_bracket_expect_not_exception(void){
  CEXCEPTION_T ex;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char *str = ".W]";
  OperatorToken dotToken = {TOKEN_OPERATOR_TYPE,0,1,".",str};
  IdentifierToken WToken = {TOKEN_IDENTIFIER_TYPE,0,1,"W",str};
  OperatorToken SquareBracketToken = {TOKEN_OPERATOR_TYPE,0,1,"]",str};

  getToken_ExpectAndReturn(tokenizer, (Token *)&dotToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&SquareBracketToken);
  Try {
    gettokenDotWBracket(tokenizer, &operandInfo);
      }Catch(ex) {
    dumpErrorMessage(ex, 1);
      }
  //  freeException(ex);
}

//test function getCloseBracketSymbol
void test_function_getCloseBracket_given_comma_expect_exception_not_valid_operator(void){
  CEXCEPTION_T ex;
  OperandInfo operandInfo;

  char *str = ",";
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  OperatorToken CBracketToken = {TOKEN_OPERATOR_TYPE,0,1,",",str};
  getToken_ExpectAndReturn(tokenizer, (Token *)&CBracketToken);

  Try {
    getCloseBracketSymbol(tokenizer, &operandInfo);
  }Catch(ex) {
    dumpErrorMessage(ex, 1);
    TEST_ASSERT_EQUAL(NOT_VALID_OPERATOR,ex->errorCode);
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
      TEST_ASSERT_EQUAL(NOT_VALID_OPREANDINFO_TYPE,ex->errorCode);
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
    char *str = ",0x97.W]";
    OperatorToken dollarToken = {TOKEN_OPERATOR_TYPE,0,1,",",str};
    getToken_ExpectAndReturn(tokenizer, (Token *)&dollarToken);

    Try {
      handleShortLongPtr(tokenizer, &operandInfo);
    }Catch(ex) {
      dumpErrorMessage(ex, 1);
      TEST_ASSERT_EQUAL(NOT_VALID_OPERATOR,ex->errorCode);
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

  char *str = "$0x97.W],W)";
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
      TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER,ex->errorCode);
    }
      freeException(ex);
}
void test_function_handleShortLongPtrorWithIndex_given_comma_chg_dollar_expect_exception_not_valid_operator(void){
  CEXCEPTION_T ex;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char *str = "$0x97.W]$X)";

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
    TEST_ASSERT_EQUAL(NOT_VALID_OPERATOR,ex->errorCode);
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
      TEST_ASSERT_EQUAL(NOT_VALID_OPREANDINFO_TYPE,ex->errorCode);
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
    char *str = "$X";
    OperatorToken commaToken = {TOKEN_OPERATOR_TYPE,0,1,"$",str};
    getToken_ExpectAndReturn(tokenizer, (Token *)&commaToken);

    Try {
      getShortlongoffIndexX_Y_SP(tokenizer, &operandInfo);
    }Catch(ex) {
      dumpErrorMessage(ex, 1);
      TEST_ASSERT_EQUAL(NOT_VALID_OPERATOR,ex->errorCode);
    }
      freeException(ex);
}
void test_function_getShortLongoffIndexX_Y_SP_given_alphaberts_other_than_XYSP_expect_exception_not_valid_identifier(void){
    CEXCEPTION_T ex;
    OperandInfo operandInfo;
    Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char *str = ",Z";
    OperatorToken commaToken = {TOKEN_OPERATOR_TYPE,0,1,",",str};
    IdentifierToken WToken = {TOKEN_IDENTIFIER_TYPE,1,1,"Z",str};
    getToken_ExpectAndReturn(tokenizer, (Token *)&commaToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&WToken);

    Try {
      getShortlongoffIndexX_Y_SP(tokenizer, &operandInfo);
    }Catch(ex) {
      dumpErrorMessage(ex, 1);
      TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER,ex->errorCode);
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
      TEST_ASSERT_EQUAL(WRONG_TOKEN_TYPE,ex->errorCode);
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
            TEST_ASSERT_EQUAL(NOT_VALID_OPREANDINFO_TYPE,ex->errorCode);
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
          TEST_ASSERT_EQUAL(NOT_VALID_OPREANDINFO_TYPE,ex->errorCode);
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
      TEST_ASSERT_EQUAL(LIMIT_EXCEEDED,ex->errorCode);
    }
      freeException(ex);
}


//test function handle byte
void test_function_handlebyte_given_comma_replace_dollarSymbol_expect_NOT_VALID_OEPERATOR(void){
    CEXCEPTION_T ex;
    OperandInfo operandInfo;
    Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char *str = ",0x1000";
    OperatorToken   dollarToken = {TOKEN_OPERATOR_TYPE, 0,1,",",str};
    getToken_ExpectAndReturn(tokenizer, (Token *)&dollarToken);

    Try {
      handleByte(tokenizer, &operandInfo);
    }Catch(ex) {
      dumpErrorMessage(ex, 1);
      TEST_ASSERT_EQUAL(NOT_VALID_OPERATOR,ex->errorCode);
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
      TEST_ASSERT_EQUAL(LIMIT_EXCEEDED,ex->errorCode);
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
        TEST_ASSERT_EQUAL(WRONG_TOKEN_TYPE,ex->errorCode);
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
        TEST_ASSERT_EQUAL(LIMIT_EXCEEDED,ex->errorCode);
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
  char *str = "(,10,X)";
  OperatorToken othersToken = {TOKEN_OPERATOR_TYPE,1,1,",",str};
  getToken_ExpectAndReturn(tokenizer, (Token *)&othersToken);

  Try {
    handleNExt_2_OperandMain(tokenizer, &operandInfo);
  }Catch(ex) {
    dumpErrorMessage(ex, 1);
    TEST_ASSERT_EQUAL(NOT_VALID_OPERATOR,ex->errorCode);
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
  char *str = "(Z)";
  IdentifierToken WToken = {TOKEN_IDENTIFIER_TYPE,1,1,"Z",str};
  getToken_ExpectAndReturn(tokenizer, (Token *)&WToken);

  Try {
    handleNExt_2_OperandMain(tokenizer, &operandInfo);
  }Catch(ex) {
    dumpErrorMessage(ex, 1);
    TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER,ex->errorCode);
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
  OperatorToken HashToken = {TOKEN_OPERATOR_TYPE,0,1,"#",str};
  OperatorToken dollarToken = {TOKEN_OPERATOR_TYPE,1,1,"$",str};
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,2,4,"0x97",str,0x97};

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
  char *str = ",";
  OperatorToken othersToken = {TOKEN_OPERATOR_TYPE,0,1,",",str};
  getToken_ExpectAndReturn(tokenizer, (Token *)&othersToken);

  Try {
    handleNEXTOperandMain(tokenizer, &operandInfo);
  }Catch(ex) {
    dumpErrorMessage(ex, 1);
    TEST_ASSERT_EQUAL(NOT_VALID_OPERATOR,ex->errorCode);
  }
    freeException(ex);
}
void test_function_handleNEXTOperandMain_given_Not_operator_type_expect_Wrong_token_type(void){
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
    TEST_ASSERT_EQUAL(WRONG_TOKEN_TYPE,ex->errorCode);
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
void test_FUNCTION_DISPLAYOPCODE_given_Inherent_break_expect_0x8b(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  operandInfo.type =Inherent;
  operandInfo.baseOpcode = 0x8b;
  displayOpcode(&memoryToWriteCode,&operandInfo);
  TEST_ASSERT_EQUAL_HEX(0x8b,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[1],memoryToWriteCode);
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
      TEST_ASSERT_EQUAL(NOT_VALID_OPREANDINFO_TYPE,ex->errorCode);
      }
      freeException1(ex);
}


//test function identifyInstruction
void test_function_identifyInstruction_given_ADC_expect_baseOpcode_9(void){
  char *str = "ADC";
  OperandInfo operandInfo;
  identifyInstruction(str,&operandInfo);
  printf("%d\n",operandInfo.baseOpcode );
  TEST_ASSERT_EQUAL_HEX(0x9,operandInfo.baseOpcode);
}
void test_function_identifyInstruction_given_XOR_expect_baseOpcode_8(void){
  char *str = "XOR";
  OperandInfo operandInfo;
  identifyInstruction(str,&operandInfo);
  printf("%d\n",operandInfo.baseOpcode );
  TEST_ASSERT_EQUAL_HEX(0x8,operandInfo.baseOpcode);
}
void test_function_identifyInstruction_given_SUB_expect_baseOpcode_0(void){
  char *str = "SUB";
  OperandInfo operandInfo;
  identifyInstruction(str,&operandInfo);
  printf("%d\n",operandInfo.baseOpcode );
  TEST_ASSERT_EQUAL_HEX(0x0,operandInfo.baseOpcode);
}
void test_function_identifyInstruction_given_OR_expect_baseOpcode_A(void){
  char *str = "OR";
  OperandInfo operandInfo;
  identifyInstruction(str,&operandInfo);
  printf("%d\n",operandInfo.baseOpcode );
  TEST_ASSERT_EQUAL_HEX(0xA,operandInfo.baseOpcode);
}
void test_function_identifyInstruction_given_LD_expect_baseOpcode_6(void){
  char *str = "LD";
  OperandInfo operandInfo;
  identifyInstruction(str,&operandInfo);
  printf("%d\n",operandInfo.baseOpcode );
  TEST_ASSERT_EQUAL_HEX(0x6,operandInfo.baseOpcode);
}
void test_function_identifyInstruction_given_CP_expect_baseOpcode_1(void){
  char *str = "CP";
  OperandInfo operandInfo;
  identifyInstruction(str,&operandInfo);
  printf("%d\n",operandInfo.baseOpcode );
  TEST_ASSERT_EQUAL_HEX(0x1,operandInfo.baseOpcode);
}
void test_function_identifyInstruction_given_BCP_expect_baseOpcode_5(void){
  char *str = "BCP";
  OperandInfo operandInfo;
  identifyInstruction(str,&operandInfo);
  printf("%d\n",operandInfo.baseOpcode );
  TEST_ASSERT_EQUAL_HEX(0x5,operandInfo.baseOpcode);
}
void test_function_identifyInstruction_given_AND_expect_baseOpcode_4(void){
  char *str = "AND";
  OperandInfo operandInfo;
  identifyInstruction(str,&operandInfo);
  printf("%d\n",operandInfo.baseOpcode );
  TEST_ASSERT_EQUAL_HEX(0x4,operandInfo.baseOpcode);
}
void test_function_identifyInstruction_given_ADD_expect_baseOpcode_B(void){
  char *str = "ADD";
  OperandInfo operandInfo;
  identifyInstruction(str,&operandInfo);
  printf("%d\n",operandInfo.baseOpcode );
  TEST_ASSERT_EQUAL_HEX(0xB,operandInfo.baseOpcode);
}
void test_function_identifyInstruction_given_SBC_expect_baseOpcode_2(void){
  char *str = "SBC";
  OperandInfo operandInfo;
  identifyInstruction(str,&operandInfo);
  printf("%d\n",operandInfo.baseOpcode );
  TEST_ASSERT_EQUAL_HEX(0x2,operandInfo.baseOpcode);
}
void test_function_identifyInstruction_given_BREAK_expect_baseOpcode_8b(void){
  char *str = "BREAK";
  OperandInfo operandInfo;
  identifyInstruction(str,&operandInfo);
  printf("%d\n",operandInfo.baseOpcode );
  TEST_ASSERT_EQUAL_HEX(0x8B,operandInfo.baseOpcode);
}
void test_function_identifyInstruction_given_CCF_expect_baseOpcode_8C(void){
  char *str = "CCF";
  OperandInfo operandInfo;
  identifyInstruction(str,&operandInfo);
  printf("%d\n",operandInfo.baseOpcode );
  TEST_ASSERT_EQUAL_HEX(0x8C,operandInfo.baseOpcode);
}
void test_function_identifyInstruction_given_HALT_expect_baseOpcode_8E(void){
  char *str = "HALT";
  OperandInfo operandInfo;
  identifyInstruction(str,&operandInfo);
  printf("%d\n",operandInfo.baseOpcode );
  TEST_ASSERT_EQUAL_HEX(0x8E,operandInfo.baseOpcode);
}
void test_function_identifyInstruction_given_IRET_expect_baseOpcode_80(void){
  char *str = "OR";
  OperandInfo operandInfo;
  identifyInstruction(str,&operandInfo);
  printf("%d\n",operandInfo.baseOpcode );
  TEST_ASSERT_EQUAL_HEX(0xA,operandInfo.baseOpcode);
}
void test_function_identifyInstruction_given_NOP_expect_baseOpcode_9D(void){
  char *str = "NOP";
  OperandInfo operandInfo;
  identifyInstruction(str,&operandInfo);
  printf("%d\n",operandInfo.baseOpcode );
  TEST_ASSERT_EQUAL_HEX(0x9D,operandInfo.baseOpcode);
}
void test_function_identifyInstruction_given_RCF_expect_baseOpcode_98(void){
  char *str = "RCF";
  OperandInfo operandInfo;
  identifyInstruction(str,&operandInfo);
  printf("%d\n",operandInfo.baseOpcode );
  TEST_ASSERT_EQUAL_HEX(0x98,operandInfo.baseOpcode);
}
void test_function_identifyInstruction_given_RET_expect_baseOpcode_81(void){
  char *str = "RET";
  OperandInfo operandInfo;
  identifyInstruction(str,&operandInfo);
  printf("%d\n",operandInfo.baseOpcode );
  TEST_ASSERT_EQUAL_HEX(0x81,operandInfo.baseOpcode);
}
void test_function_identifyInstruction_given_RETF_expect_baseOpcode_87(void){
  char *str = "RETF";
  OperandInfo operandInfo;
  identifyInstruction(str,&operandInfo);
  printf("%d\n",operandInfo.baseOpcode );
  TEST_ASSERT_EQUAL_HEX(0x87,operandInfo.baseOpcode);
}
void test_function_identifyInstruction_given_RIM_expect_baseOpcode_9A(void){
  char *str = "RIM";
  OperandInfo operandInfo;
  identifyInstruction(str,&operandInfo);
  printf("%d\n",operandInfo.baseOpcode );
  TEST_ASSERT_EQUAL_HEX(0x9A,operandInfo.baseOpcode);
}
void test_function_identifyInstruction_given_RVF_expect_baseOpcode_9C(void){
  char *str = "RVF";
  OperandInfo operandInfo;
  identifyInstruction(str,&operandInfo);
  printf("%d\n",operandInfo.baseOpcode );
  TEST_ASSERT_EQUAL_HEX(0x9C,operandInfo.baseOpcode);
}
void test_function_identifyInstruction_given_SCF_expect_baseOpcode_99(void){
  char *str = "SCF";
  OperandInfo operandInfo;
  identifyInstruction(str,&operandInfo);
  printf("%d\n",operandInfo.baseOpcode );
  TEST_ASSERT_EQUAL_HEX(0x99,operandInfo.baseOpcode);
}
void test_function_identifyInstruction_given_SIM_expect_baseOpcode_9B(void){
  char *str = "SIM";
  OperandInfo operandInfo;
  identifyInstruction(str,&operandInfo);
  printf("%d\n",operandInfo.baseOpcode );
  TEST_ASSERT_EQUAL_HEX(0x9B,operandInfo.baseOpcode);
}
void test_function_identifyInstruction_given_TRAP_expect_baseOpcode_83(void){
  char *str = "TRAP";
  OperandInfo operandInfo;
  identifyInstruction(str,&operandInfo);
  printf("%d\n",operandInfo.baseOpcode );
  TEST_ASSERT_EQUAL_HEX(0x83,operandInfo.baseOpcode);
}
void test_function_identifyInstruction_given_WFI_expect_baseOpcode_8f(void){
  char *str = "WFI";
  OperandInfo operandInfo;
  identifyInstruction(str,&operandInfo);
  printf("%d\n",operandInfo.baseOpcode );
  TEST_ASSERT_EQUAL_HEX(0x8F,operandInfo.baseOpcode);
}
void test_function_identifyInstruction_given_others_instruction_expect_Not_valid_instruction(void){
  CEXCEPTION_T ex;
  char *str = "ZZZ";
  OperandInfo operandInfo;
  Try {
    identifyInstruction(str,&operandInfo);
  }Catch(ex)
    {
    dumpException(ex);
    TEST_ASSERT_EQUAL(NOT_VALID_INSTRUCTION,ex->errorCode);
    }
    freeException1(ex);
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

void test_asesemble_given_Not_comma_symbol_expect_not_valid_identifier(void){
  CEXCEPTION_T ex;
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "ADD Z,";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"ADD",str};
  IdentifierToken AToken = {TOKEN_IDENTIFIER_TYPE,4 ,1,"Z",str};
  initTokenizer_ExpectAndReturn(str,tokenizer);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ADDToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&AToken);
  Try {
      assemble(str, &memoryToWriteCode);
    }Catch(ex)
      {
        dumpErrorMessage(ex, 1);
          TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER,ex->errorCode);
      }
        freeException(ex);
}
void test_asesemble_given_Not_comma_symbol_expect_not_valid_operator(void){
  CEXCEPTION_T ex;
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "ADD A[";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"ADD",str};
  IdentifierToken AToken = {TOKEN_IDENTIFIER_TYPE,4 ,1,"A",str};
  OperatorToken   CommaToken ={TOKEN_OPERATOR_TYPE, 5,1,"[",str};
  initTokenizer_ExpectAndReturn(str,tokenizer);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ADDToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&AToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&CommaToken);
  Try {
    assemble(str, &memoryToWriteCode);
  }Catch(ex) {
    dumpErrorMessage(ex, 1);
    TEST_ASSERT_EQUAL(NOT_VALID_OPERATOR,ex->errorCode);
  }
    freeException(ex);
}
void test_asesemble_given_integer_token_type_expect_wrong_token_type(void){
  CEXCEPTION_T ex;
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "ADD A,";
  IdentifierToken ADDToken = {TOKEN_INTEGER_TYPE, 0,3,"ADD",str};
  initTokenizer_ExpectAndReturn(str,tokenizer);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ADDToken);
  Try {
    assemble(str, &memoryToWriteCode);
  }Catch(ex) {
    dumpErrorMessage(ex, 1);
    TEST_ASSERT_EQUAL(WRONG_TOKEN_TYPE,ex->errorCode);
  }
    freeException(ex);
}
