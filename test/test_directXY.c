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


void test_handleDirect_X_Y_index_directX_CPLW_X_expect_0x53(void){
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
void test_handleDirect_X_Y_index_directX_CPLW_Y_expect_0x9053(void){
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
void test_handleDirect_X_Y_index_directX_DECW_X_expect_0x5A(void){
  CEXCEPTION_T ex;
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "DECW X";

  IdentifierToken idToken = {TOKEN_IDENTIFIER_TYPE,0 ,4,"DECW",str};
  IdentifierToken AToken = {TOKEN_IDENTIFIER_TYPE,5 ,1,"X",str};

  initTokenizer_ExpectAndReturn(str,tokenizer);
  getToken_ExpectAndReturn(tokenizer, (Token *)&idToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&AToken);

  handleDirect_X_Y_index(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x5A,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[1],memoryToWriteCode);
  printf("0x%02x\n",buffer[0]);
}
void test_handleDirect_X_Y_index_directX_DECW_X_expect_0x905A(void){
  CEXCEPTION_T ex;
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "DECW Y";

  IdentifierToken idToken = {TOKEN_IDENTIFIER_TYPE,0 ,4,"DECW",str};
  IdentifierToken AToken = {TOKEN_IDENTIFIER_TYPE,5 ,1,"Y",str};

  initTokenizer_ExpectAndReturn(str,tokenizer);
  getToken_ExpectAndReturn(tokenizer, (Token *)&idToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&AToken);

  handleDirect_X_Y_index(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x5A90,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[2],memoryToWriteCode);
  printf("0x%02x%02x\n",buffer[0],buffer[1]);
}
void test_handleDirect_X_Y_index_directX_INCW_X_expect_0x5C(void){
  CEXCEPTION_T ex;
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "INCW X";

  IdentifierToken idToken = {TOKEN_IDENTIFIER_TYPE,0 ,4,"INCW",str};
  IdentifierToken AToken = {TOKEN_IDENTIFIER_TYPE,5 ,1,"X",str};

  initTokenizer_ExpectAndReturn(str,tokenizer);
  getToken_ExpectAndReturn(tokenizer, (Token *)&idToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&AToken);

  handleDirect_X_Y_index(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x5C,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[1],memoryToWriteCode);
  printf("0x%02x\n",buffer[0]);
}
void test_handleDirect_X_Y_index_directX_INCW_Y_expect_0x5C90(void){
  CEXCEPTION_T ex;
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "INCW Y";

  IdentifierToken idToken = {TOKEN_IDENTIFIER_TYPE,0 ,4,"INCW",str};
  IdentifierToken AToken = {TOKEN_IDENTIFIER_TYPE,5 ,1,"Y",str};

  initTokenizer_ExpectAndReturn(str,tokenizer);
  getToken_ExpectAndReturn(tokenizer, (Token *)&idToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&AToken);

  handleDirect_X_Y_index(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x5C90,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[2],memoryToWriteCode);
  printf("0x%02x%02x\n",buffer[0],buffer[1]);
}
void test_handleDirect_X_Y_index_directX_NEGW_X_expect_0x50(void){
  CEXCEPTION_T ex;
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "NEGW X";

  IdentifierToken idToken = {TOKEN_IDENTIFIER_TYPE,0 ,4,"NEGW",str};
  IdentifierToken AToken = {TOKEN_IDENTIFIER_TYPE,5 ,1,"X",str};

  initTokenizer_ExpectAndReturn(str,tokenizer);
  getToken_ExpectAndReturn(tokenizer, (Token *)&idToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&AToken);

  handleDirect_X_Y_index(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x50,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[1],memoryToWriteCode);
  printf("0x%02x\n",buffer[0]);
}
void test_handleDirect_X_Y_index_directX_NEGW_Y_expect_0x9050(void){
  CEXCEPTION_T ex;
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "NEGW Y";

  IdentifierToken idToken = {TOKEN_IDENTIFIER_TYPE,0 ,4,"NEGW",str};
  IdentifierToken AToken = {TOKEN_IDENTIFIER_TYPE,5 ,1,"Y",str};

  initTokenizer_ExpectAndReturn(str,tokenizer);
  getToken_ExpectAndReturn(tokenizer, (Token *)&idToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&AToken);

  handleDirect_X_Y_index(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x5090,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[2],memoryToWriteCode);
  printf("0x%02x%02x\n",buffer[0],buffer[1]);
}

void test_handleDirect_X_Y_index_directX_POPW_X_expect_0x85(void){
  CEXCEPTION_T ex;
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "POPW X";

  IdentifierToken idToken = {TOKEN_IDENTIFIER_TYPE,0 ,4,"POPW",str};
  IdentifierToken AToken = {TOKEN_IDENTIFIER_TYPE,5 ,1,"X",str};

  initTokenizer_ExpectAndReturn(str,tokenizer);
  getToken_ExpectAndReturn(tokenizer, (Token *)&idToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&AToken);

  handleDirect_X_Y_index(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x85,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[1],memoryToWriteCode);
  printf("0x%02x\n",buffer[0]);
}
void test_handleDirect_X_Y_index_directX_POPW_Y_expect_0x9085(void){
  CEXCEPTION_T ex;
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "POPW Y";

  IdentifierToken idToken = {TOKEN_IDENTIFIER_TYPE,0 ,4,"POPW",str};
  IdentifierToken AToken = {TOKEN_IDENTIFIER_TYPE,5 ,1,"Y",str};

  initTokenizer_ExpectAndReturn(str,tokenizer);
  getToken_ExpectAndReturn(tokenizer, (Token *)&idToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&AToken);

  handleDirect_X_Y_index(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x8590,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[2],memoryToWriteCode);
  printf("0x%02x%02x\n",buffer[0],buffer[1]);
}
void test_handleDirect_X_Y_index_directX_PUSH_X_expect_0x89(void){
  CEXCEPTION_T ex;
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "PUSH X";

  IdentifierToken idToken = {TOKEN_IDENTIFIER_TYPE,0 ,4,"PUSH",str};
  IdentifierToken AToken = {TOKEN_IDENTIFIER_TYPE,5 ,1,"X",str};

  initTokenizer_ExpectAndReturn(str,tokenizer);
  getToken_ExpectAndReturn(tokenizer, (Token *)&idToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&AToken);

  handleDirect_X_Y_index(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x89,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[1],memoryToWriteCode);
  printf("0x%02x\n",buffer[0]);
}
void test_handleDirect_X_Y_index_directX_PUSH_Y_expect_0x9089(void){
  CEXCEPTION_T ex;
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "PUSH Y";

  IdentifierToken idToken = {TOKEN_IDENTIFIER_TYPE,0 ,4,"PUSH",str};
  IdentifierToken AToken = {TOKEN_IDENTIFIER_TYPE,5 ,1,"Y",str};

  initTokenizer_ExpectAndReturn(str,tokenizer);
  getToken_ExpectAndReturn(tokenizer, (Token *)&idToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&AToken);

  handleDirect_X_Y_index(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x8990,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[2],memoryToWriteCode);
  printf("0x%02x%02x\n",buffer[0],buffer[1]);
}
void test_handleDirect_X_Y_index_directX_RLCW_X_expect_0x59(void){
  CEXCEPTION_T ex;
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "PLCW X";

  IdentifierToken idToken = {TOKEN_IDENTIFIER_TYPE,0 ,4,"RLCW",str};
  IdentifierToken AToken = {TOKEN_IDENTIFIER_TYPE,5 ,1,"X",str};

  initTokenizer_ExpectAndReturn(str,tokenizer);
  getToken_ExpectAndReturn(tokenizer, (Token *)&idToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&AToken);

  handleDirect_X_Y_index(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x59,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[1],memoryToWriteCode);
  printf("0x%02x\n",buffer[0]);
}
void test_handleDirect_X_Y_index_directX_RLCW_Y_expect_0x9059(void){
  CEXCEPTION_T ex;
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "RLCW Y";

  IdentifierToken idToken = {TOKEN_IDENTIFIER_TYPE,0 ,4,"RLCW",str};
  IdentifierToken AToken = {TOKEN_IDENTIFIER_TYPE,5 ,1,"Y",str};

  initTokenizer_ExpectAndReturn(str,tokenizer);
  getToken_ExpectAndReturn(tokenizer, (Token *)&idToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&AToken);

  handleDirect_X_Y_index(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x5990,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[2],memoryToWriteCode);
  printf("0x%02x%02x\n",buffer[0],buffer[1]);
}
void test_handleDirect_X_Y_index_directX_RLWA_X_expect_0x02(void){
  CEXCEPTION_T ex;
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "RLWA X";

  IdentifierToken idToken = {TOKEN_IDENTIFIER_TYPE,0 ,4,"RLWA",str};
  IdentifierToken AToken = {TOKEN_IDENTIFIER_TYPE,5 ,1,"X",str};

  initTokenizer_ExpectAndReturn(str,tokenizer);
  getToken_ExpectAndReturn(tokenizer, (Token *)&idToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&AToken);

  handleDirect_X_Y_index(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x02,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[1],memoryToWriteCode);
  printf("0x%02x\n",buffer[0]);
}
void test_handleDirect_X_Y_index_directX_RLWA_Y_expect_0x9002(void){
  CEXCEPTION_T ex;
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "RLWA Y";

  IdentifierToken idToken = {TOKEN_IDENTIFIER_TYPE,0 ,4,"RLWA",str};
  IdentifierToken AToken = {TOKEN_IDENTIFIER_TYPE,5 ,1,"Y",str};

  initTokenizer_ExpectAndReturn(str,tokenizer);
  getToken_ExpectAndReturn(tokenizer, (Token *)&idToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&AToken);

  handleDirect_X_Y_index(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x0290,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[2],memoryToWriteCode);
  printf("0x%02x%02x\n",buffer[0],buffer[1]);
}
void test_handleDirect_X_Y_index_directX_RRCW_X_expect_0x56(void){
  CEXCEPTION_T ex;
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "RRCW X";

  IdentifierToken idToken = {TOKEN_IDENTIFIER_TYPE,0 ,4,"RRCW",str};
  IdentifierToken AToken = {TOKEN_IDENTIFIER_TYPE,5 ,1,"X",str};

  initTokenizer_ExpectAndReturn(str,tokenizer);
  getToken_ExpectAndReturn(tokenizer, (Token *)&idToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&AToken);

  handleDirect_X_Y_index(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x56,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[1],memoryToWriteCode);
  printf("0x%02x\n",buffer[0]);
}
void test_handleDirect_X_Y_index_directX_RRCW_Y_expect_0x9056(void){
  CEXCEPTION_T ex;
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "RRCW Y";

  IdentifierToken idToken = {TOKEN_IDENTIFIER_TYPE,0 ,4,"RRCW",str};
  IdentifierToken AToken = {TOKEN_IDENTIFIER_TYPE,5 ,1,"Y",str};

  initTokenizer_ExpectAndReturn(str,tokenizer);
  getToken_ExpectAndReturn(tokenizer, (Token *)&idToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&AToken);

  handleDirect_X_Y_index(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x5690,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[2],memoryToWriteCode);
  printf("0x%02x%02x\n",buffer[0],buffer[1]);
}
void test_handleDirect_X_Y_index_directX_RRWA_X_expect_0x01(void){
  CEXCEPTION_T ex;
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "RRWA X";

  IdentifierToken idToken = {TOKEN_IDENTIFIER_TYPE,0 ,4,"RRWA",str};
  IdentifierToken AToken = {TOKEN_IDENTIFIER_TYPE,5 ,1,"X",str};

  initTokenizer_ExpectAndReturn(str,tokenizer);
  getToken_ExpectAndReturn(tokenizer, (Token *)&idToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&AToken);

  handleDirect_X_Y_index(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x01,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[1],memoryToWriteCode);
  printf("0x%02x\n",buffer[0]);
}
void test_handleDirect_X_Y_index_directX_RRWA_Y_expect_0x9001(void){
  CEXCEPTION_T ex;
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "RRWA Y";

  IdentifierToken idToken = {TOKEN_IDENTIFIER_TYPE,0 ,4,"RRWA",str};
  IdentifierToken AToken = {TOKEN_IDENTIFIER_TYPE,5 ,1,"Y",str};

  initTokenizer_ExpectAndReturn(str,tokenizer);
  getToken_ExpectAndReturn(tokenizer, (Token *)&idToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&AToken);

  handleDirect_X_Y_index(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x0190,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[2],memoryToWriteCode);
  printf("0x%02x%02x\n",buffer[0],buffer[1]);
}
void test_handleDirect_X_Y_index_directX_SLAW_X_expect_0x58(void){
  CEXCEPTION_T ex;
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "SLAW X";

  IdentifierToken idToken = {TOKEN_IDENTIFIER_TYPE,0 ,4,"SLAW",str};
  IdentifierToken AToken = {TOKEN_IDENTIFIER_TYPE,5 ,1,"X",str};

  initTokenizer_ExpectAndReturn(str,tokenizer);
  getToken_ExpectAndReturn(tokenizer, (Token *)&idToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&AToken);

  handleDirect_X_Y_index(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x58,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[1],memoryToWriteCode);
  printf("0x%02x\n",buffer[0]);
}
void test_handleDirect_X_Y_index_directX_SLAW_Y_expect_0x9058(void){
  CEXCEPTION_T ex;
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "SLAW Y";

  IdentifierToken idToken = {TOKEN_IDENTIFIER_TYPE,0 ,4,"SLAW",str};
  IdentifierToken AToken = {TOKEN_IDENTIFIER_TYPE,5 ,1,"Y",str};

  initTokenizer_ExpectAndReturn(str,tokenizer);
  getToken_ExpectAndReturn(tokenizer, (Token *)&idToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&AToken);

  handleDirect_X_Y_index(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x5890,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[2],memoryToWriteCode);
  printf("0x%02x%02x\n",buffer[0],buffer[1]);
}
void test_handleDirect_X_Y_index_directX_SLLW_X_expect_0x58(void){
  CEXCEPTION_T ex;
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "SLLW X";

  IdentifierToken idToken = {TOKEN_IDENTIFIER_TYPE,0 ,4,"SLLW",str};
  IdentifierToken AToken = {TOKEN_IDENTIFIER_TYPE,5 ,1,"X",str};

  initTokenizer_ExpectAndReturn(str,tokenizer);
  getToken_ExpectAndReturn(tokenizer, (Token *)&idToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&AToken);

  handleDirect_X_Y_index(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x58,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[1],memoryToWriteCode);
  printf("0x%02x\n",buffer[0]);
}
void test_handleDirect_X_Y_index_directX_SLLW_Y_expect_0x9058(void){
  CEXCEPTION_T ex;
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "SLLW Y";

  IdentifierToken idToken = {TOKEN_IDENTIFIER_TYPE,0 ,4,"SLLW",str};
  IdentifierToken AToken = {TOKEN_IDENTIFIER_TYPE,5 ,1,"Y",str};

  initTokenizer_ExpectAndReturn(str,tokenizer);
  getToken_ExpectAndReturn(tokenizer, (Token *)&idToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&AToken);

  handleDirect_X_Y_index(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x5890,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[2],memoryToWriteCode);
  printf("0x%02x%02x\n",buffer[0],buffer[1]);

}void test_handleDirect_X_Y_index_directX_SRAW_X_expect_0x57(void){
  CEXCEPTION_T ex;
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "SRAW X";

  IdentifierToken idToken = {TOKEN_IDENTIFIER_TYPE,0 ,4,"SRAW",str};
  IdentifierToken AToken = {TOKEN_IDENTIFIER_TYPE,5 ,1,"X",str};

  initTokenizer_ExpectAndReturn(str,tokenizer);
  getToken_ExpectAndReturn(tokenizer, (Token *)&idToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&AToken);

  handleDirect_X_Y_index(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x57,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[1],memoryToWriteCode);
  printf("0x%02x\n",buffer[0]);
}
void test_handleDirect_X_Y_index_directX_SRAW_Y_expect_0x9057(void){
  CEXCEPTION_T ex;
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "SRAW Y";

  IdentifierToken idToken = {TOKEN_IDENTIFIER_TYPE,0 ,4,"SRAW",str};
  IdentifierToken AToken = {TOKEN_IDENTIFIER_TYPE,5 ,1,"Y",str};

  initTokenizer_ExpectAndReturn(str,tokenizer);
  getToken_ExpectAndReturn(tokenizer, (Token *)&idToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&AToken);

  handleDirect_X_Y_index(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x5790,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[2],memoryToWriteCode);
  printf("0x%02x%02x\n",buffer[0],buffer[1]);
}
void test_handleDirect_X_Y_index_directX_SRLW_X_expect_0x54(void){
  CEXCEPTION_T ex;
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "SRLW X";

  IdentifierToken idToken = {TOKEN_IDENTIFIER_TYPE,0 ,4,"SRLW",str};
  IdentifierToken AToken = {TOKEN_IDENTIFIER_TYPE,5 ,1,"X",str};

  initTokenizer_ExpectAndReturn(str,tokenizer);
  getToken_ExpectAndReturn(tokenizer, (Token *)&idToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&AToken);

  handleDirect_X_Y_index(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x54,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[1],memoryToWriteCode);
  printf("0x%02x\n",buffer[0]);
}
void test_handleDirect_X_Y_index_directX_CPLW_Y_expect_0x9054(void){
  CEXCEPTION_T ex;
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "SRLW Y";

  IdentifierToken idToken = {TOKEN_IDENTIFIER_TYPE,0 ,4,"SRLW",str};
  IdentifierToken AToken = {TOKEN_IDENTIFIER_TYPE,5 ,1,"Y",str};

  initTokenizer_ExpectAndReturn(str,tokenizer);
  getToken_ExpectAndReturn(tokenizer, (Token *)&idToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&AToken);

  handleDirect_X_Y_index(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x5490,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[2],memoryToWriteCode);
  printf("0x%02x%02x\n",buffer[0],buffer[1]);
}
void test_handleDirect_X_Y_index_directX_SWAPW_X_expect_0x5E(void){
  CEXCEPTION_T ex;
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "SWAPW X";

  IdentifierToken idToken = {TOKEN_IDENTIFIER_TYPE,0 ,4,"SWAPW",str};
  IdentifierToken AToken = {TOKEN_IDENTIFIER_TYPE,5 ,1,"X",str};

  initTokenizer_ExpectAndReturn(str,tokenizer);
  getToken_ExpectAndReturn(tokenizer, (Token *)&idToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&AToken);

  handleDirect_X_Y_index(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x5E,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[1],memoryToWriteCode);
  printf("0x%02x\n",buffer[0]);
}
void test_handleDirect_X_Y_index_directX_SWAPW_Y_expect_0x905E(void){
  CEXCEPTION_T ex;
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "SWAPW Y";

  IdentifierToken idToken = {TOKEN_IDENTIFIER_TYPE,0 ,4,"SWAPW",str};
  IdentifierToken AToken = {TOKEN_IDENTIFIER_TYPE,5 ,1,"Y",str};

  initTokenizer_ExpectAndReturn(str,tokenizer);
  getToken_ExpectAndReturn(tokenizer, (Token *)&idToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&AToken);

  handleDirect_X_Y_index(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x5E90,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[2],memoryToWriteCode);
  printf("0x%02x%02x\n",buffer[0],buffer[1]);
}
void test_handleDirect_X_Y_index_directX_TNZW_X_expect_0x5D(void){
  CEXCEPTION_T ex;
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "TNZW X";

  IdentifierToken idToken = {TOKEN_IDENTIFIER_TYPE,0 ,4,"TNZW",str};
  IdentifierToken AToken = {TOKEN_IDENTIFIER_TYPE,5 ,1,"X",str};

  initTokenizer_ExpectAndReturn(str,tokenizer);
  getToken_ExpectAndReturn(tokenizer, (Token *)&idToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&AToken);

  handleDirect_X_Y_index(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x5D,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[1],memoryToWriteCode);
  printf("0x%02x\n",buffer[0]);
}
void test_handleDirect_X_Y_index_directX_TNZW_Y_expect_0x905D(void){
  CEXCEPTION_T ex;
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char str[] = "TNZW Y";

  IdentifierToken idToken = {TOKEN_IDENTIFIER_TYPE,0 ,4,"TNZW",str};
  IdentifierToken AToken = {TOKEN_IDENTIFIER_TYPE,5 ,1,"Y",str};

  initTokenizer_ExpectAndReturn(str,tokenizer);
  getToken_ExpectAndReturn(tokenizer, (Token *)&idToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&AToken);

  handleDirect_X_Y_index(str, &memoryToWriteCode);
  TEST_ASSERT_EQUAL_HEX(0x5D90,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[2],memoryToWriteCode);
  printf("0x%02x%02x\n",buffer[0],buffer[1]);
}
