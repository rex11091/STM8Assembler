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

//test CP
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