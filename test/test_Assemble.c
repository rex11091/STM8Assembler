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

void test_function_getcomma_given_comma_expect_notexception(void){
  CEXCEPTION_T ex;
  OperandInfo operandInfo;

  char *str = ",";
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  OperatorToken CBracketToken = {TOKEN_OPERATOR_TYPE,0,1,",",str};
  getToken_ExpectAndReturn(tokenizer, (Token *)&CBracketToken);

  Try {
    getCommaSymbol(tokenizer, &operandInfo);
  }Catch(ex) {
    dumpErrorMessage(ex, 1);
    TEST_ASSERT_EQUAL(NOT_VALID_OPERATOR,ex->errorCode);
  }
    //freeException(ex);
}
void test_function_getcomma_given_dollar_expect_exception(void){
  CEXCEPTION_T ex;
  OperandInfo operandInfo;

  char *str = "$";
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  OperatorToken CBracketToken = {TOKEN_OPERATOR_TYPE,0,1,"$",str};
  getToken_ExpectAndReturn(tokenizer, (Token *)&CBracketToken);

  Try {
    getCommaSymbol(tokenizer, &operandInfo);
  }Catch(ex) {
    dumpErrorMessage(ex, 1);
    TEST_ASSERT_EQUAL(NOT_VALID_OPERATOR,ex->errorCode);
  }
    freeException(ex);
}

void test_handledirect_indexXY_given_CPLW_X_expect_0x53(void){
    CEXCEPTION_T ex;
    uint8_t buffer[4] = {0,0,0,0};
    char *memoryToWriteCode = buffer;
    OperandInfo operandInfo;
    Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char str[] = "CPLW X";

    IdentifierToken idToken = {TOKEN_IDENTIFIER_TYPE,0 ,4,"CPLW",str};
    IdentifierToken AToken = {TOKEN_IDENTIFIER_TYPE,5 ,1,"X",str};

    initTokenizer_ExpectAndReturn(str,tokenizer);
    getToken_ExpectAndReturn(tokenizer, (Token *)&idToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&AToken);

    handleDirect_X_Y_index(str, &memoryToWriteCode);
    TEST_ASSERT_EQUAL_HEX(0x53,*(uint32_t *)buffer);
    TEST_ASSERT_EQUAL_PTR(&buffer[1],memoryToWriteCode);
    printf("0x%02x\n",buffer[0]);
  }
void test_handledirect_indexXY_given_CPLW_Y_expect_0x9053(void){
  CEXCEPTION_T ex;
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "CPLW Y";

  IdentifierToken idToken = {TOKEN_IDENTIFIER_TYPE,0 ,4,"CPLW",str};
  IdentifierToken AToken = {TOKEN_IDENTIFIER_TYPE,5 ,1,"Y",str};

  initTokenizer_ExpectAndReturn(str,tokenizer);
  getToken_ExpectAndReturn(tokenizer, (Token *)&idToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&AToken);

  handleDirect_X_Y_index(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x5390,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[2],memoryToWriteCode);
  printf("0x%02x%02x\n",buffer[0],buffer[1]);
}
void test_handledirect_indexXY_given_Z_expect_not_valid_identifier(void){
  CEXCEPTION_T ex;
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "CPLW Z";

  IdentifierToken idToken = {TOKEN_IDENTIFIER_TYPE,0 ,4,"CPLW",str};
  IdentifierToken AToken = {TOKEN_IDENTIFIER_TYPE,5 ,1,"Z",str};

  initTokenizer_ExpectAndReturn(str,tokenizer);
  getToken_ExpectAndReturn(tokenizer, (Token *)&idToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&AToken);

  Try {
  handleDirect_X_Y_index(str, &memoryToWriteCode);
  }Catch(ex) {
    dumpErrorMessage(ex,1);
    TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER,ex->errorCode);
  }
    freeException(ex);
}
void test_handledirect_indexXY_given_CPLW_integerType_expect_Wrong_token_type(void){
  CEXCEPTION_T ex;
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "CPLW Y";
  IdentifierToken idToken = {TOKEN_INTEGER_TYPE,0 ,4,"CPLW",str};
  initTokenizer_ExpectAndReturn(str,tokenizer);
  getToken_ExpectAndReturn(tokenizer, (Token *)&idToken);
  Try {
    handleDirect_X_Y_index(str, &memoryToWriteCode);
  }Catch(ex) {
    dumpErrorMessage(ex,1);
    TEST_ASSERT_EQUAL(WRONG_TOKEN_TYPE,ex->errorCode);
  }
    freeException(ex);
}
void test_handledirect_indexXY_given_X_integerType_expect_Wrong_token_type(void){
  CEXCEPTION_T ex;
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "CPLW Y";
  IdentifierToken idToken = {TOKEN_IDENTIFIER_TYPE,0 ,4,"CPLW",str};
  IdentifierToken AToken = {TOKEN_INTEGER_TYPE,5 ,1,"Y",str};

  initTokenizer_ExpectAndReturn(str,tokenizer);
  getToken_ExpectAndReturn(tokenizer, (Token *)&idToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&AToken);

  Try {
    handleDirect_X_Y_index(str, &memoryToWriteCode);
  }Catch(ex) {
    dumpErrorMessage(ex,1);
    TEST_ASSERT_EQUAL(WRONG_TOKEN_TYPE,ex->errorCode);
  }
    freeException(ex);
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

  IntegerToken intToken = {TOKEN_OPERATOR_TYPE,0,6,"0x9797",str,0x9797};
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
void test_function_handleByteOrWord_given_comma_replace_dollarSymbol_expect_NOT_VALID_OEPERATOR(void){
    CEXCEPTION_T ex;
    OperandInfo operandInfo;
    Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char *str = ",0x1000";
    OperatorToken   dollarToken = {TOKEN_OPERATOR_TYPE, 0,1,",",str};
    getToken_ExpectAndReturn(tokenizer, (Token *)&dollarToken);

    Try {
      handleByteOrWord(tokenizer, &operandInfo);
    }Catch(ex) {
      dumpErrorMessage(ex, 1);
      TEST_ASSERT_EQUAL(NOT_VALID_OPERATOR,ex->errorCode);
    }
      freeException(ex);
}
void test_function_handleByteOrWord_given_0xFFdd1_expect_Limit_EXCEEDED(void){
    CEXCEPTION_T ex;
    OperandInfo operandInfo;
    Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char *str = "$0xffdd1";

    OperatorToken   dollarToken = {TOKEN_OPERATOR_TYPE, 0,1,"$",str};
    IntegerToken intToken = {TOKEN_INTEGER_TYPE,1,5,"0xffdd1",str,0xffdd1};
    getToken_ExpectAndReturn(tokenizer, (Token *)&dollarToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);

    Try {
      handleByteOrWord(tokenizer, &operandInfo);
    }Catch(ex) {
      dumpErrorMessage(ex, 1);
      TEST_ASSERT_EQUAL(LIMIT_EXCEEDED,ex->errorCode);
    }
      freeException(ex);
  }
void test_function_handleByteOrWord_given_identifierTokenType_expect_Wrong_Token_type(void){
      CEXCEPTION_T ex;
      OperandInfo operandInfo;
      Tokenizer *tokenizer = (Tokenizer *)0x0badface;
      char *str = "$0xff1";

      OperatorToken   dollarToken = {TOKEN_OPERATOR_TYPE, 0,1,"$",str};
      IntegerToken intToken = {TOKEN_IDENTIFIER_TYPE,1,5,"0xff1",str,0xff1};
      getToken_ExpectAndReturn(tokenizer, (Token *)&dollarToken);
      getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);

      Try {
        handleByteOrWord(tokenizer, &operandInfo);
      }Catch(ex) {
        dumpErrorMessage(ex, 1);
        TEST_ASSERT_EQUAL(WRONG_TOKEN_TYPE,ex->errorCode);
      }
        freeException(ex);
    }
void test_function_handleByteOrWord_given_0xFFff_expect_WORD(void){
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;

  char *str = "$0xffff";
  OperatorToken   dollarToken = {TOKEN_OPERATOR_TYPE, 0,1,"$",str};
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,1,5,"0xffff",str,0xffff};
  getToken_ExpectAndReturn(tokenizer, (Token *)&dollarToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);

  handleByteOrWord(tokenizer, &operandInfo);
  TEST_ASSERT_EQUAL(WORD, operandInfo.type);
}
void test_function_handleByteOrWord_given_0xFF_expect_BYTE(void){
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;

  char *str = "$0xff";
  OperatorToken   dollarToken = {TOKEN_OPERATOR_TYPE, 0,1,"$",str};
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,1,5,"0xff",str,0xff};
  getToken_ExpectAndReturn(tokenizer, (Token *)&dollarToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);

  handleByteOrWord(tokenizer, &operandInfo);
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
void test_handleNext_2_OperandMain_given_Not_operator_IdentifierToken_type_expect_Wrong_token_type(void){
  CEXCEPTION_T ex;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char *str = "($0x10,X)";
  OperatorToken typeToken = {TOKEN_INTEGER_TYPE,1,1,"$",str};
  getToken_ExpectAndReturn(tokenizer, (Token *)&typeToken);

  Try {
    handleNEXTOperandMain(tokenizer, &operandInfo);
  }Catch(ex) {
    dumpErrorMessage(ex, 1);
    TEST_ASSERT_EQUAL(WRONG_TOKEN_TYPE,ex->errorCode);
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
  OperatorToken typeToken = {TOKEN_INTEGER_TYPE,0,1,"$",str};
  getToken_ExpectAndReturn(tokenizer, (Token *)&typeToken);

  Try {
    handleNEXTOperandMain(tokenizer, &operandInfo);
  }Catch(ex) {
    dumpErrorMessage(ex, 1);
    TEST_ASSERT_EQUAL(WRONG_TOKEN_TYPE,ex->errorCode);
  }
    freeException(ex);
}

//test function assemble
void test_asesemble_given_operator_type_expect_wrong_token_type(void){
  CEXCEPTION_T ex;
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "aDd A,#$55";
  IdentifierToken ADDToken = {TOKEN_OPERATOR_TYPE, 0,3,"ADD",str};

	initTokenizer_ExpectAndReturn(str,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&ADDToken);

  Try {
    assemble(str, &memoryToWriteCode);
  }Catch(ex)
    {
    dumpErrorMessage(ex,1);
    TEST_ASSERT_EQUAL(WRONG_TOKEN_TYPE,ex->errorCode);
    }
    freeException(ex);
}
