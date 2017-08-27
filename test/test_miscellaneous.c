#include "unity.h"
#include "Assemble.h"
#include "mock_Tokenizer.h"
#include <stdio.h>
#include "Token.h"
#include "error.h"
#include "Exception.h"
#include "touppercase.h"
//test ADC

void setUp(void)
{
}

void tearDown(void)
{
}

//test function getA_X_Y_index
void test_function_getA_X_Y_given_W_expect_NOT_VALID_IDENTIFIER(void){
  CEXCEPTION_T ex;
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "aDd W,#$55";
  IdentifierToken AToken = {TOKEN_IDENTIFIER_TYPE, 4,1,"W",str};

  getToken_ExpectAndReturn(tokenizer, (Token *)&AToken);

  Try {
      getA_X_Y_index(tokenizer,&operandInfo);
  }Catch(ex)
    {
    dumpErrorMessage(ex,1);
    TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER,ex->errorCode);
    }
    freeException(ex);
}
void test_function_getA_X_Y_given_NOt_identifier_Type_expect_Wrong_token_type_(void){
  CEXCEPTION_T ex;
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "aDd A,#$55";
  IdentifierToken AToken = {TOKEN_INTEGER_TYPE, 4,1,"A",str};

  getToken_ExpectAndReturn(tokenizer, (Token *)&AToken);

  Try {
    getA_X_Y_index(tokenizer,&operandInfo);
  }Catch(ex)
    {
    dumpErrorMessage(ex,1);
    TEST_ASSERT_EQUAL(WRONG_TOKEN_TYPE,ex->errorCode);
    }
    freeException(ex);
}
void test_asesemble_given_LDW_Y_long_mem_0xff55_expect_0xff55CE90(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "LDW Y,$55ff";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"LDW",str};
  IdentifierToken AToken = {TOKEN_IDENTIFIER_TYPE,4 ,1,"Y",str};
  OperatorToken   CommaToken ={TOKEN_OPERATOR_TYPE, 5,1,",",str};
  OperatorToken   dollarToken ={TOKEN_OPERATOR_TYPE, 7,1,"$",str};
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,8,4,"0x55ff",str,0x55ff};

  initTokenizer_ExpectAndReturn(str,tokenizer);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ADDToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&AToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&CommaToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&dollarToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);

  assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0xff55CE90,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[4],memoryToWriteCode);
  printf("0x%02x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2],buffer[3]);
}
void test_asesemble_given_CPW_X_long_mem_0xff55_expect_0xff55C3(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "CPW X,$55ff";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"CPW",str};
  IdentifierToken AToken = {TOKEN_IDENTIFIER_TYPE,4 ,1,"X",str};
  OperatorToken   CommaToken ={TOKEN_OPERATOR_TYPE, 5,1,",",str};
  OperatorToken   dollarToken ={TOKEN_OPERATOR_TYPE, 7,1,"$",str};
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,8,4,"0x55ff",str,0x55ff};

  initTokenizer_ExpectAndReturn(str,tokenizer);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ADDToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&AToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&CommaToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&dollarToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);

  assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0xff55C3,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[3],memoryToWriteCode);
  printf("0x%02x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2]);
}
void test_asesemble_given_adc_long_mem_0xff55_expect_0xff55C9(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "adc A,$55ff";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"ADC",str};
  IdentifierToken AToken = {TOKEN_IDENTIFIER_TYPE,4 ,1,"A",str};
  OperatorToken   CommaToken ={TOKEN_OPERATOR_TYPE, 5,1,",",str};
  OperatorToken   dollarToken ={TOKEN_OPERATOR_TYPE, 7,1,"$",str};
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,8,4,"0x55ff",str,0x55ff};

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

//test function ConvertOperandTypeOfYindex
void test_function_ConvertOperandTypeOfYindex_given_Shortmem_expect_Yshortmem_21(void){
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  OperandInfo operandInfo;
  operandInfo.type = SHORT_MEM;
  ConvertOperandTypeOfYindex(tokenizer,&operandInfo);
  TEST_ASSERT_EQUAL(21,operandInfo.type);
}
void test_function_ConvertOperandTypeOfYindex_given_longmem_expect_Ylongmem_20(void){
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  OperandInfo operandInfo;
  operandInfo.type = LONG_MEM;
  ConvertOperandTypeOfYindex(tokenizer,&operandInfo);
  TEST_ASSERT_EQUAL(20,operandInfo.type);
}
void test_function_ConvertOperandTypeOfYindex_given_Shorptr_expect_Yshortptr_22(void){
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  OperandInfo operandInfo;
  operandInfo.type = SHORTPTR;
  ConvertOperandTypeOfYindex(tokenizer,&operandInfo);
  TEST_ASSERT_EQUAL(22,operandInfo.type);
}
void test_function_ConvertOperandTypeOfYindex_given_WORD_expect_YWORD_23(void){
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  OperandInfo operandInfo;
  operandInfo.type = WORD;
  ConvertOperandTypeOfYindex(tokenizer,&operandInfo);
  TEST_ASSERT_EQUAL(YWORD,operandInfo.type);
}
void test_function_ConvertOperandTypeOfYindex_given_BYTE_expect_BYTE_2(void){
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  OperandInfo operandInfo;
  operandInfo.type = BYTE;
  ConvertOperandTypeOfYindex(tokenizer,&operandInfo);
  TEST_ASSERT_EQUAL(2,operandInfo.type);
}
