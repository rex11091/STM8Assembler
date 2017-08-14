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

void test_handleinherentInstruction_given_Break_expect_8B(void){
  CEXCEPTION_T ex;
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "BREAK";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,5,"BREAK",str};

	initTokenizer_ExpectAndReturn(str,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&ADDToken);

  handleInherentInstruction(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x8B,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[1],memoryToWriteCode);
  printf("0x%02x\n",buffer[0]);
}

void test_handleinherentInstruction_given_CCF_expect_8C(void){
  CEXCEPTION_T ex;
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "CCF";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"CCF",str};

	initTokenizer_ExpectAndReturn(str,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&ADDToken);

  handleInherentInstruction(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x8C,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[1],memoryToWriteCode);
  printf("0x%02x\n",buffer[0]);
}

void test_handleinherentInstruction_given_HALT_expect_8E(void){
  CEXCEPTION_T ex;
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "HALT";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,4,"HALT",str};

	initTokenizer_ExpectAndReturn(str,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&ADDToken);

  handleInherentInstruction(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x8E,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[1],memoryToWriteCode);
  printf("0x%02x\n",buffer[0]);
}

void test_handleinherentInstruction_given_IRET_expect_80(void){
  CEXCEPTION_T ex;
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "IRET";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,4,"IRET",str};

	initTokenizer_ExpectAndReturn(str,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&ADDToken);

  handleInherentInstruction(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x80,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[1],memoryToWriteCode);
  printf("0x%02x\n",buffer[0]);
}

void test_handleinherentInstruction_given_NOP_expect_9D(void){
  CEXCEPTION_T ex;
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "NOP";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"NOP",str};

	initTokenizer_ExpectAndReturn(str,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&ADDToken);

  handleInherentInstruction(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x9D,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[1],memoryToWriteCode);
  printf("0x%02x\n",buffer[0]);
}

void test_handleinherentInstruction_given_RCF_expect_98(void){
  CEXCEPTION_T ex;
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "RCF";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"RCF",str};

	initTokenizer_ExpectAndReturn(str,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&ADDToken);

  handleInherentInstruction(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x98,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[1],memoryToWriteCode);
  printf("0x%02x\n",buffer[0]);
}

void test_handleinherentInstruction_given_RET_expect_81(void){
  CEXCEPTION_T ex;
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "RET";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"RET",str};

	initTokenizer_ExpectAndReturn(str,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&ADDToken);

  handleInherentInstruction(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x81,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[1],memoryToWriteCode);
  printf("0x%02x\n",buffer[0]);
}

void test_handleinherentInstruction_given_RETF_expect_87(void){
  CEXCEPTION_T ex;
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "RETF";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,4,"RETF",str};

	initTokenizer_ExpectAndReturn(str,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&ADDToken);

  handleInherentInstruction(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x87,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[1],memoryToWriteCode);
  printf("0x%02x\n",buffer[0]);
}

void test_handleinherentInstruction_given_RIM_expect_9A(void){
  CEXCEPTION_T ex;
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "RIM";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"RIM",str};

	initTokenizer_ExpectAndReturn(str,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&ADDToken);

  handleInherentInstruction(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x9A,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[1],memoryToWriteCode);
  printf("0x%02x\n",buffer[0]);
}

void test_handleinherentInstruction_given_RVF_expect_9C(void){
  CEXCEPTION_T ex;
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "RVF";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"RVF",str};

	initTokenizer_ExpectAndReturn(str,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&ADDToken);

  handleInherentInstruction(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x9C,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[1],memoryToWriteCode);
  printf("0x%02x\n",buffer[0]);
}

void test_handleinherentInstruction_given_SCF_expect_99(void){
  CEXCEPTION_T ex;
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "SCF";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"SCF",str};

	initTokenizer_ExpectAndReturn(str,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&ADDToken);

  handleInherentInstruction(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x99,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[1],memoryToWriteCode);
  printf("0x%02x\n",buffer[0]);
}

void test_handleinherentInstruction_given_SIM_expect_9B(void){
  CEXCEPTION_T ex;
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "SIM";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"SIM",str};

	initTokenizer_ExpectAndReturn(str,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&ADDToken);

  handleInherentInstruction(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x9B,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[1],memoryToWriteCode);
  printf("0x%02x\n",buffer[0]);
}

void test_handleinherentInstruction_given_WFI_expect_8F(void){
  CEXCEPTION_T ex;
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "WFI";
  IdentifierToken ADDToken = {TOKEN_IDENTIFIER_TYPE, 0,3,"WFI",str};

	initTokenizer_ExpectAndReturn(str,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&ADDToken);

  handleInherentInstruction(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x8f,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[1],memoryToWriteCode);
  printf("0x%02x\n",buffer[0]);
}
void test_handleinherentInstruction_given_integertokentype_expect_Wrongtoken_Type(void){
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
    handleInherentInstruction(str, &memoryToWriteCode);
  }Catch(ex) {
    dumpErrorMessage(ex, 1);
    TEST_ASSERT_EQUAL(WRONG_TOKEN_TYPE,ex->errorCode);
  }
    freeException(ex);
}
