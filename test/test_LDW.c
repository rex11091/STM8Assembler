#include "unity.h"
#include "Assemble.h"
#include "mock_Tokenizer.h"
#include <stdio.h>
#include "Token.h"
#include "error.h"
#include "Exception.h"
#include "touppercase.h"
//test AND
void setUp(void)
{
}

void tearDown(void)
{
}

//test LDW X
void test_asesemble_given_CPW_WORD_0xAA55_expect_0x55AAAE(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "LDW X,#$AA55";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"LDW",str};
  IdentifierToken AToken = {TOKEN_IDENTIFIER_TYPE,4 ,1,"X",str};
  OperatorToken   CommaToken ={TOKEN_OPERATOR_TYPE, 5,1,",",str};
  OperatorToken   HashToken ={TOKEN_OPERATOR_TYPE, 6,1,"#",str};
  OperatorToken   dollarToken ={TOKEN_OPERATOR_TYPE, 7,1,"$",str};
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,8,4,"0xAA55",str,0xAA55};

  initTokenizer_ExpectAndReturn(str,tokenizer);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ADDToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&AToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&CommaToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&HashToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&dollarToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);

  assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x55AAAE,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[3],memoryToWriteCode);
  printf("0x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2]);
}
void test_asesemble_given_LDW_long_mem_0xff555_expect_Exception(void){
  CEXCEPTION_T ex;
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "LDW X,$555ff";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"LDW",str};
  IdentifierToken AToken = {TOKEN_IDENTIFIER_TYPE,4 ,1,"X",str};
  OperatorToken   CommaToken ={TOKEN_OPERATOR_TYPE, 5,1,",",str};
  OperatorToken   dollarToken ={TOKEN_OPERATOR_TYPE, 6,1,"$",str};
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,7,5,"0x555ff",str,0x555ff};

  initTokenizer_ExpectAndReturn(str,tokenizer);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ADDToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&AToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&CommaToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&dollarToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);

  Try {
  assemble(str, &memoryToWriteCode);
  }Catch(ex) {
  dumpErrorMessage(ex, 1);
  }
  freeException(ex);
}
void test_asesemble_given_LDW_long_mem_0xff55_expect_0xff55CE(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "LDW X,$55ff";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"LDW",str};
  IdentifierToken AToken = {TOKEN_IDENTIFIER_TYPE,4 ,1,"X",str};
  OperatorToken   CommaToken ={TOKEN_OPERATOR_TYPE, 5,1,",",str};
  OperatorToken   dollarToken ={TOKEN_OPERATOR_TYPE, 6,1,"$",str};
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,8,4,"0x55ff",str,0x55ff};

  initTokenizer_ExpectAndReturn(str,tokenizer);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ADDToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&AToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&CommaToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&dollarToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);

  assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0xff55CE,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[3],memoryToWriteCode);
  printf("0x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2]);
}
void test_asesemble_given_LDW_short_mem_0x55_expect_0x55BE(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "LDW X,$55";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"LDW",str};
  IdentifierToken AToken = {TOKEN_IDENTIFIER_TYPE,4 ,1,"X",str};
  OperatorToken   CommaToken ={TOKEN_OPERATOR_TYPE, 5,1,",",str};
  OperatorToken   dollarToken ={TOKEN_OPERATOR_TYPE, 6,1,"$",str};
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,8,2,"0x55",str,0x55};

  initTokenizer_ExpectAndReturn(str,tokenizer);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ADDToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&AToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&CommaToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&dollarToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);

  assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x55BE,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[2],memoryToWriteCode);
  printf("0x%02x%02x\n",buffer[0],buffer[1]);
}
void test_asesemble_given_LDW_index_X_expect_0xFE(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "LDW X,(X)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"LDW",str};
	IdentifierToken AToken = {TOKEN_IDENTIFIER_TYPE,4 ,1,"X",str};
	OperatorToken   CommaToken ={TOKEN_OPERATOR_TYPE, 5,1,",",str};
	OperatorToken   OBracketToken ={TOKEN_OPERATOR_TYPE, 7,1,"(",str};
  IdentifierToken XToken = {TOKEN_IDENTIFIER_TYPE,4 ,1,"X",str};
  OperatorToken   CBracketToken ={TOKEN_OPERATOR_TYPE, 7,1,")",str};

	initTokenizer_ExpectAndReturn(str,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&ADDToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&AToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&CommaToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&OBracketToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&XToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&CBracketToken);

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0xFE,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[1],memoryToWriteCode);
  printf("0x%02x\n",buffer[0]);
}
void test_asesemble_given_LDW_shortoff_index_X_expect_0x10EE(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "LDW X,($10,X)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"LDW",str};
	IdentifierToken AToken = {TOKEN_IDENTIFIER_TYPE,4 ,1,"X",str};
	OperatorToken   CommaToken ={TOKEN_OPERATOR_TYPE, 5,1,",",str};
	OperatorToken   OBracketToken ={TOKEN_OPERATOR_TYPE, 7,1,"(",str};
  OperatorToken   dollarToken ={TOKEN_OPERATOR_TYPE, 8,1,"$",str};
  IntegerToken    intToken = {TOKEN_INTEGER_TYPE,9,2,"0x10",str,0x10};
  OperatorToken   comma1Token ={TOKEN_OPERATOR_TYPE, 8,1,",",str};
  IdentifierToken WToken = {TOKEN_IDENTIFIER_TYPE,4 ,1,"X",str};
  OperatorToken   CBracketToken ={TOKEN_OPERATOR_TYPE, 7,1,")",str};

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
  TEST_ASSERT_EQUAL_HEX(0x10EE,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[2],memoryToWriteCode);
  printf("0x%02x%02x\n",buffer[0],buffer[1]);
}
void test_asesemble_given_LDW_longoff_index_X_expect_0x8810DE(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "LDW X,($1088,X)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"LDW",str};
	IdentifierToken AToken = {TOKEN_IDENTIFIER_TYPE,4 ,1,"X",str};
	OperatorToken   CommaToken ={TOKEN_OPERATOR_TYPE, 5,1,",",str};
	OperatorToken   OBracketToken ={TOKEN_OPERATOR_TYPE, 6,1,"(",str};
  OperatorToken   dollarToken ={TOKEN_OPERATOR_TYPE, 7,1,"$",str};
  IntegerToken    intToken = {TOKEN_INTEGER_TYPE, 8,4,"0x1088",str,0x1088};
  OperatorToken   comma1Token ={TOKEN_OPERATOR_TYPE, 12,1,",",str};
  IdentifierToken WToken = {TOKEN_IDENTIFIER_TYPE, 13,1,"X",str};
  OperatorToken   CBracketToken ={TOKEN_OPERATOR_TYPE, 14,1,")",str};

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
  TEST_ASSERT_EQUAL_HEX(0x8810DE,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[3],memoryToWriteCode);
  printf("0x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2]);
}
void test_asesemble_given_LDW_shortoff_index_SP_expect_0x881E(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "LDW X,($88,SP)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"LDW",str};
  IdentifierToken AToken = {TOKEN_IDENTIFIER_TYPE,4 ,1,"X",str};
  OperatorToken   CommaToken ={TOKEN_OPERATOR_TYPE, 5,1,",",str};
  OperatorToken   OBracketToken ={TOKEN_OPERATOR_TYPE, 6,1,"(",str};
  OperatorToken   dollarToken ={TOKEN_OPERATOR_TYPE, 7,1,"$",str};
  IntegerToken    intToken = {TOKEN_INTEGER_TYPE, 8,2,"0x88",str,0x88};
  OperatorToken   comma1Token ={TOKEN_OPERATOR_TYPE, 12,1,",",str};
  IdentifierToken WToken = {TOKEN_IDENTIFIER_TYPE, 13,2,"SP",str};
  OperatorToken   CBracketToken ={TOKEN_OPERATOR_TYPE, 15,1,")",str};

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
  TEST_ASSERT_EQUAL_HEX(0x881E,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[2],memoryToWriteCode);
  printf("0x%02x%02x\n",buffer[0],buffer[1]);
}
void test_asesemble_given_LDW_shortptr_expect_0x55cE92(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "LDW X,[$55.w]";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"LDW",str};
  IdentifierToken AToken = {TOKEN_IDENTIFIER_TYPE,4 ,1,"X",str};
  OperatorToken   CommaToken ={TOKEN_OPERATOR_TYPE, 5,1,",",str};
  OperatorToken   OBracketToken ={TOKEN_OPERATOR_TYPE, 6,1,"[",str};
  OperatorToken   dollarToken ={TOKEN_OPERATOR_TYPE, 7,1,"$",str};
  IntegerToken    intToken = {TOKEN_INTEGER_TYPE, 8,2,"0x55",str,0x55};
  OperatorToken   dotToken ={TOKEN_OPERATOR_TYPE, 10,1,".",str};
  IdentifierToken WToken = {TOKEN_IDENTIFIER_TYPE, 11,2,"W",str};
  OperatorToken   CBracketToken ={TOKEN_OPERATOR_TYPE, 12,1,"]",str};

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
  TEST_ASSERT_EQUAL_HEX(0x55cE92,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[3],memoryToWriteCode);
  printf("0x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2]);
}
void test_asesemble_given_LDW_longptr_expect_0x4455cE72(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "LDW X,[$0x5544.w]";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"LDW",str};
  IdentifierToken AToken = {TOKEN_IDENTIFIER_TYPE, 4,1,"X",str};
  OperatorToken   CommaToken ={TOKEN_OPERATOR_TYPE, 5,1,",",str};
  OperatorToken   OBracketToken ={TOKEN_OPERATOR_TYPE, 6,1,"[",str};
  OperatorToken   dollarToken ={TOKEN_OPERATOR_TYPE, 7,1,"$",str};
  IntegerToken    intToken = {TOKEN_INTEGER_TYPE, 8,6,"0x5544",str,0x5544};
  OperatorToken   dotToken ={TOKEN_OPERATOR_TYPE,14 ,1,".",str};
  IdentifierToken WToken = {TOKEN_IDENTIFIER_TYPE, 15,2,"W",str};
  OperatorToken   CBracketToken ={TOKEN_OPERATOR_TYPE, 16,1,"]",str};

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
  TEST_ASSERT_EQUAL_HEX(0x4455cE72,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[4],memoryToWriteCode);
  printf("0x%02x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2],buffer[3]);
}
void test_asesemble_given_LDW_shortptr_index_X_expect_0x45DE92(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "LDW X,([$45.w],X)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"LDW",str};
	IdentifierToken AToken = {TOKEN_IDENTIFIER_TYPE,4 ,1,"X",str};
	OperatorToken   CommaToken ={TOKEN_OPERATOR_TYPE, 5,1,",",str};
  OperatorToken   ORndBracketToken ={TOKEN_OPERATOR_TYPE, 6,1,"(",str};
	OperatorToken   OSqrBracketToken ={TOKEN_OPERATOR_TYPE, 7,1,"[",str};
  OperatorToken   dollarToken ={TOKEN_OPERATOR_TYPE, 8,1,"$",str};
  IntegerToken    intToken = {TOKEN_INTEGER_TYPE, 9,2,"0x45",str,0x45};
  OperatorToken   dotToken ={TOKEN_OPERATOR_TYPE, 11,1,".",str};
  IdentifierToken WToken = {TOKEN_IDENTIFIER_TYPE, 12,1,"W",str};
  OperatorToken   CSqrBracketToken ={TOKEN_OPERATOR_TYPE, 13,1,"]",str};
  OperatorToken   comma1Token ={TOKEN_OPERATOR_TYPE, 14,1,",",str};
  IdentifierToken W1Token = {TOKEN_IDENTIFIER_TYPE, 15,1,"X",str};
  OperatorToken   CRndBracketToken ={TOKEN_OPERATOR_TYPE, 16,1,")",str};

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
  TEST_ASSERT_EQUAL_HEX(0x45DE92,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[3],memoryToWriteCode);
  printf("0x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2]);
}
void test_asesemble_given_LDW_longptr_index_X_expect_0x5545DE72(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "LDW X,([$4555.w],X)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"LDW",str};
	IdentifierToken AToken = {TOKEN_IDENTIFIER_TYPE,4 ,1,"X",str};
	OperatorToken   CommaToken ={TOKEN_OPERATOR_TYPE, 5,1,",",str};
  OperatorToken   ORndBracketToken ={TOKEN_OPERATOR_TYPE, 6,1,"(",str};
	OperatorToken   OSqrBracketToken ={TOKEN_OPERATOR_TYPE, 7,1,"[",str};
  OperatorToken   dollarToken ={TOKEN_OPERATOR_TYPE, 8,1,"$",str};
  IntegerToken    intToken = {TOKEN_INTEGER_TYPE, 9,4,"0x4555",str,0x4555};
  OperatorToken   dotToken ={TOKEN_OPERATOR_TYPE, 13,1,".",str};
  IdentifierToken WToken = {TOKEN_IDENTIFIER_TYPE, 14,1,"W",str};
  OperatorToken   CSqrBracketToken ={TOKEN_OPERATOR_TYPE, 15,1,"]",str};
  OperatorToken   comma1Token ={TOKEN_OPERATOR_TYPE, 16,1,",",str};
  IdentifierToken W1Token = {TOKEN_IDENTIFIER_TYPE, 17,1,"X",str};
  OperatorToken   CRndBracketToken ={TOKEN_OPERATOR_TYPE, 18,1,")",str};

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
  TEST_ASSERT_EQUAL_HEX(0x5545DE72,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[4],memoryToWriteCode);
  printf("0x%02x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2],buffer[3]);

}

//test LDW Y
void test_asesemble_given_LDW_Y_WORD_0xAA55_expect_0x55AAAE90(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "LDW Y,#$AA55";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"LDW",str};
  IdentifierToken AToken = {TOKEN_IDENTIFIER_TYPE,4 ,1,"Y",str};
  OperatorToken   CommaToken ={TOKEN_OPERATOR_TYPE, 5,1,",",str};
  OperatorToken   HashToken ={TOKEN_OPERATOR_TYPE, 6,1,"#",str};
  OperatorToken   dollarToken ={TOKEN_OPERATOR_TYPE, 7,1,"$",str};
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,8,4,"0xAA55",str,0xAA55};

  initTokenizer_ExpectAndReturn(str,tokenizer);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ADDToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&AToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&CommaToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&HashToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&dollarToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);

  assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x55AAAE90,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[4],memoryToWriteCode);
  printf("0x%02x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2],buffer[3]);
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
	OperatorToken   dollarToken ={TOKEN_OPERATOR_TYPE, 6,1,"$",str};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,7,4,"0x55ff",str,0x55ff};


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
void test_asesemble_given_LDW_Y_short_mem_0x55_expect_0x55BE90(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "LDW Y,$55";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"LDW",str};
	IdentifierToken AToken = {TOKEN_IDENTIFIER_TYPE,4 ,1,"Y",str};
	OperatorToken   CommaToken ={TOKEN_OPERATOR_TYPE, 5,1,",",str};
	OperatorToken   dollarToken ={TOKEN_OPERATOR_TYPE, 6,1,"$",str};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,7,2,"0x55",str,0x55};


	initTokenizer_ExpectAndReturn(str,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&ADDToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&AToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&CommaToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&dollarToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);

	assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x55BE90,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[3],memoryToWriteCode);
  printf("0x%02x%02x\n",buffer[0],buffer[1],buffer[2]);
}
void test_asesemble_given_LDW_index_Y_expect_0xFE(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "LDW Y,(Y)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"LDW",str};
  IdentifierToken AToken = {TOKEN_IDENTIFIER_TYPE,4 ,1,"Y",str};
  OperatorToken   CommaToken ={TOKEN_OPERATOR_TYPE, 5,1,",",str};
  OperatorToken   OBracketToken ={TOKEN_OPERATOR_TYPE, 6,1,"(",str};
  IdentifierToken YToken = {TOKEN_IDENTIFIER_TYPE,7 ,1,"Y",str};
  OperatorToken   CBracketToken ={TOKEN_OPERATOR_TYPE, 8,1,")",str};

  initTokenizer_ExpectAndReturn(str,tokenizer);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ADDToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&AToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&CommaToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&OBracketToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&YToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&CBracketToken);

  assemble(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0xFE90,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[2],memoryToWriteCode);
  printf("0x%02x%02x\n",buffer[0],buffer[1]);
}
void test_asesemble_given_LDW_Y_shortoff_index_Y_expect_0x10EE90(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "LDW Y,($10,Y)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"LDW",str};
  IdentifierToken AToken = {TOKEN_IDENTIFIER_TYPE,4 ,1,"Y",str};
  OperatorToken   CommaToken ={TOKEN_OPERATOR_TYPE, 5,1,",",str};
  OperatorToken   OBracketToken ={TOKEN_OPERATOR_TYPE, 7,1,"(",str};
  OperatorToken   dollarToken ={TOKEN_OPERATOR_TYPE, 8,1,"$",str};
  IntegerToken    intToken = {TOKEN_INTEGER_TYPE,9,2,"0x10",str,0x10};
  OperatorToken   comma1Token ={TOKEN_OPERATOR_TYPE, 10,1,",",str};
  IdentifierToken WToken = {TOKEN_IDENTIFIER_TYPE,11 ,1,"Y",str};
  OperatorToken   CBracketToken ={TOKEN_OPERATOR_TYPE, 12,1,")",str};

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
  TEST_ASSERT_EQUAL_HEX(0x10EE90,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[3],memoryToWriteCode);
  printf("0x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2]);
}
void test_asesemble_given_LDW_Y_longoff_index_Y_expect_0x8810DE90(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "LDW Y,($1088,Y)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"LDW",str};
  IdentifierToken AToken = {TOKEN_IDENTIFIER_TYPE,4 ,1,"Y",str};
  OperatorToken   CommaToken ={TOKEN_OPERATOR_TYPE, 5,1,",",str};
  OperatorToken   OBracketToken ={TOKEN_OPERATOR_TYPE, 6,1,"(",str};
  OperatorToken   dollarToken ={TOKEN_OPERATOR_TYPE, 7,1,"$",str};
  IntegerToken    intToken = {TOKEN_INTEGER_TYPE, 8,4,"0x1088",str,0x1088};
  OperatorToken   comma1Token ={TOKEN_OPERATOR_TYPE, 12,1,",",str};
  IdentifierToken WToken = {TOKEN_IDENTIFIER_TYPE, 13,1,"Y",str};
  OperatorToken   CBracketToken ={TOKEN_OPERATOR_TYPE, 14,1,")",str};

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
  TEST_ASSERT_EQUAL_HEX(0x8810DE90,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[4],memoryToWriteCode);
  printf("0x%02x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2],buffer[3]);
}
void test_asesemble_given_LDW_Y_shortptr_expect_0x55cE91(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "LDW Y,[$55.w]";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"LDW",str};
  IdentifierToken AToken = {TOKEN_IDENTIFIER_TYPE,4 ,1,"Y",str};
  OperatorToken   CommaToken ={TOKEN_OPERATOR_TYPE, 5,1,",",str};
  OperatorToken   OBracketToken ={TOKEN_OPERATOR_TYPE, 6,1,"[",str};
  OperatorToken   dollarToken ={TOKEN_OPERATOR_TYPE, 7,1,"$",str};
  IntegerToken    intToken = {TOKEN_INTEGER_TYPE, 8,2,"0x55",str,0x55};
  OperatorToken   dotToken ={TOKEN_OPERATOR_TYPE, 10,1,".",str};
  IdentifierToken WToken = {TOKEN_IDENTIFIER_TYPE, 11,2,"W",str};
  OperatorToken   CBracketToken ={TOKEN_OPERATOR_TYPE, 12,1,"]",str};

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
  TEST_ASSERT_EQUAL_HEX(0x55cE91,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[3],memoryToWriteCode);
  printf("0x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2]);
}
void test_asesemble_given_LDW_Y_shortptr_index_Y_expect_0x45DE91(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "LDW Y,([$45.w],Y)";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"LDW",str};
  IdentifierToken AToken = {TOKEN_IDENTIFIER_TYPE,4 ,1,"Y",str};
  OperatorToken   CommaToken ={TOKEN_OPERATOR_TYPE, 5,1,",",str};
  OperatorToken   ORndBracketToken ={TOKEN_OPERATOR_TYPE, 6,1,"(",str};
  OperatorToken   OSqrBracketToken ={TOKEN_OPERATOR_TYPE, 7,1,"[",str};
  OperatorToken   dollarToken ={TOKEN_OPERATOR_TYPE, 8,1,"$",str};
  IntegerToken    intToken = {TOKEN_INTEGER_TYPE, 9,2,"0x45",str,0x45};
  OperatorToken   dotToken ={TOKEN_OPERATOR_TYPE, 11,1,".",str};
  IdentifierToken WToken = {TOKEN_IDENTIFIER_TYPE, 12,1,"W",str};
  OperatorToken   CSqrBracketToken ={TOKEN_OPERATOR_TYPE, 13,1,"]",str};
  OperatorToken   comma1Token ={TOKEN_OPERATOR_TYPE, 14,1,",",str};
  IdentifierToken W1Token = {TOKEN_IDENTIFIER_TYPE, 15,1,"Y",str};
  OperatorToken   CRndBracketToken ={TOKEN_OPERATOR_TYPE, 16,1,")",str};

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
  TEST_ASSERT_EQUAL_HEX(0x45DE91,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[3],memoryToWriteCode);
  printf("0x%02x%02x%02x\n",buffer[0],buffer[1],buffer[2]);
}
