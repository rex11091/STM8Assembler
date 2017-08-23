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

/*--------- Function displayOpcodeAA---------
  *example: give baseOpcode = 0x09
  baseOpcode is depends on instruction
  test something which not in operandtype
*/
void test_FUNCTION_displayOpcodeA_given_0x97_Shortptr_expect_0x97D992(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  operandInfo.type = SHORTPTR_X;
  operandInfo.value = 0x97;
  operandInfo.baseOpcode = 0x09;

  displayOpcodeA(&memoryToWriteCode,&operandInfo);
  TEST_ASSERT_EQUAL_HEX(0x97D992,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[3],memoryToWriteCode);
}
void test_FUNCTION_displayOpcodeA_given_0x97ff_longptr_expect_0xff97D972(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  operandInfo.type = LONGPTR_X;
  operandInfo.value = 0x97ff;
  operandInfo.baseOpcode = 0x09;

  displayOpcodeA(&memoryToWriteCode,&operandInfo);
  TEST_ASSERT_EQUAL_HEX(0xff97D972,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[4],memoryToWriteCode);

}
void test_FUNCTION_displayOpcodeA_given_0x97B9_shortmem_expect_0x97B9(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  operandInfo.type = SHORT_MEM;
  operandInfo.value = 0x97;
  operandInfo.baseOpcode = 0x09;

  displayOpcodeA(&memoryToWriteCode,&operandInfo);
  TEST_ASSERT_EQUAL_HEX(0x97B9,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[2],memoryToWriteCode);
}

void test_FUNCTION_displayOpcodeA_given_0x5597B9_longmem_expect_0x5597C9(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  operandInfo.type = LONG_MEM;
  operandInfo.value = 0x9755;
  operandInfo.baseOpcode = 0x09;

  displayOpcodeA(&memoryToWriteCode,&operandInfo);
  TEST_ASSERT_EQUAL_HEX(0x5597C9,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[3],memoryToWriteCode);
}

void test_FUNCTION_displayOpcodeA_given_longoffY_expect_0x5597D990(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  operandInfo.type = LONGOFF_Y;
  operandInfo.value = 0x9755;
  operandInfo.baseOpcode = 0x09;
  displayOpcodeA(&memoryToWriteCode,&operandInfo);
  TEST_ASSERT_EQUAL_HEX(0x5597D990,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[4],memoryToWriteCode);
}
void test_FUNCTION_displayOpcodeA_given_shortoffY_expect_0x97E990(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  operandInfo.type = SHORTOFF_Y;
  operandInfo.value = 0x97;
  operandInfo.baseOpcode = 0x09;
  displayOpcodeA(&memoryToWriteCode,&operandInfo);
  TEST_ASSERT_EQUAL_HEX(0x97E990,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[3],memoryToWriteCode);
}
void test_FUNCTION_displayOpcodeA_given_shortoffX_expect_0x98E9(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  operandInfo.type = SHORTOFF_X;
  operandInfo.value = 0x98;
  operandInfo.baseOpcode = 0x09;
  displayOpcodeA(&memoryToWriteCode,&operandInfo);
  TEST_ASSERT_EQUAL_HEX(0x98E9,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[2],memoryToWriteCode);
}
void test_FUNCTION_displayOpcodeA_given_longoffX_expect_0x9797D9(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  operandInfo.type =LONGOFF_X;
  operandInfo.value = 0x9797;
  operandInfo.baseOpcode = 0x09;
  displayOpcodeA(&memoryToWriteCode,&operandInfo);
  TEST_ASSERT_EQUAL_HEX(0x9797D9,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[3],memoryToWriteCode);
}
void test_FUNCTION_displayOpcodeA_given_shortoffSP_expect_0x5519(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  operandInfo.type =SHORTOFF_SP;
  operandInfo.value = 0x55;
  operandInfo.baseOpcode = 0x09;
  displayOpcodeA(&memoryToWriteCode,&operandInfo);
  TEST_ASSERT_EQUAL_HEX(0x5519,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[2],memoryToWriteCode);
}
void test_FUNCTION_displayOpcodeA_given_byte_expect_0x10A9(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  operandInfo.type =BYTE;
  operandInfo.value = 0x10;
  operandInfo.baseOpcode = 0x09;
  displayOpcodeA(&memoryToWriteCode,&operandInfo);
  TEST_ASSERT_EQUAL_HEX(0x10A9,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[2],memoryToWriteCode);
}
void test_FUNCTION_displayOpcodeA_given_IndexX_expect_0xF9(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  operandInfo.type =IndexX;
  operandInfo.baseOpcode = 0x09;
  displayOpcodeA(&memoryToWriteCode,&operandInfo);
  TEST_ASSERT_EQUAL_HEX(0xF9,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[1],memoryToWriteCode);
}
void test_FUNCTION_displayOpcodeA_given_IndexY_expect_0xf990(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  operandInfo.type =IndexY;
  operandInfo.value = 0x10;
  operandInfo.baseOpcode = 0x09;
  displayOpcodeA(&memoryToWriteCode,&operandInfo);
  TEST_ASSERT_EQUAL_HEX(0xf990,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[2],memoryToWriteCode);
}
void test_FUNCTION_displayOpcodeA_given_ShortptrX_expect_0x10D992(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  operandInfo.type =SHORTPTR_X;
  operandInfo.value = 0x10;
  operandInfo.baseOpcode = 0x09;
  displayOpcodeA(&memoryToWriteCode,&operandInfo);
  TEST_ASSERT_EQUAL_HEX(0x10D992,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[3],memoryToWriteCode);
}
void test_FUNCTION_displayOpcodeA_given_ShortptrY_expect_0x11D991(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  operandInfo.type =SHORTPTR_Y;
  operandInfo.value = 0x11;
  operandInfo.baseOpcode = 0x09;
  displayOpcodeA(&memoryToWriteCode,&operandInfo);
  TEST_ASSERT_EQUAL_HEX(0x11D991,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[3],memoryToWriteCode);
}
void test_FUNCTION_displayOpcodeA_given_LongPtrX_expect_0x1555D972(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  operandInfo.type =LONGPTR_X;
  operandInfo.value = 0x1555;
  operandInfo.baseOpcode = 0x09;
  displayOpcodeA(&memoryToWriteCode,&operandInfo);
  TEST_ASSERT_EQUAL_HEX(0x5515D972,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[4],memoryToWriteCode);
}
void test_FUNCTION_displayOpcodeA_given_Inherent_break_baseOpcode_0x8b_expect_0x8b(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  operandInfo.type =Inherent;
  operandInfo.baseOpcode = 0x8b;
  displayOpcodeA(&memoryToWriteCode,&operandInfo);
  TEST_ASSERT_EQUAL_HEX(0x8b,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[1],memoryToWriteCode);
}
void test_FUNCTION_displayOpcodeA_given_directX_baseOpcode_0x53_expect_0x53(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  operandInfo.type =DirectX;
  operandInfo.baseOpcode = 0x53;
  displayOpcodeA(&memoryToWriteCode,&operandInfo);
  TEST_ASSERT_EQUAL_HEX(0x53,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[1],memoryToWriteCode);
}
void test_FUNCTION_displayOpcodeA_given_directX_baseOpcode_0x55_expect_0x55(void){
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  operandInfo.type =DirectY;
  operandInfo.baseOpcode = 0x55;
  displayOpcodeA(&memoryToWriteCode,&operandInfo);
  TEST_ASSERT_EQUAL_HEX(0x5590,*(uint32_t *)buffer);
  TEST_ASSERT_EQUAL_PTR(&buffer[2],memoryToWriteCode);
}
void test_FUNCTION_displayOpcodeA_given_longptrY_expect_not_valid_operandtype(void){
  CEXCEPTION_T ex;
  uint8_t buffer[4] = {0,0,0,0};
  char *memoryToWriteCode = buffer;
  OperandInfo operandInfo;
  operandInfo.type = 25;
  Try {
      displayOpcodeA(&memoryToWriteCode,&operandInfo);
    }Catch(ex)
      {
      dumpException(ex);
      TEST_ASSERT_EQUAL(NOT_VALID_OPREANDINFO_TYPE,ex->errorCode);
      }
      freeException1(ex);
}
