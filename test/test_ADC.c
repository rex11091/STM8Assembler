#include "unity.h"
#include "testing.h"
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

