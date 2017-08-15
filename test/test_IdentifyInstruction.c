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

//test function identifyInstruction
void test_function_identifyInstruction_given_ADC_expect_baseOpcode_9(void){
  char *str = "ADC";
  OperandInfo operandInfo;
  identifyInstruction(str,&operandInfo);
  printf("0x%02x\n",operandInfo.baseOpcode );
  TEST_ASSERT_EQUAL_HEX(0x9,operandInfo.baseOpcode);
}
void test_function_identifyInstruction_given_XOR_expect_baseOpcode_8(void){
  char *str = "XOR";
  OperandInfo operandInfo;
  identifyInstruction(str,&operandInfo);
  printf("0x%02x\n",operandInfo.baseOpcode );
  TEST_ASSERT_EQUAL_HEX(0x8,operandInfo.baseOpcode);
}
void test_function_identifyInstruction_given_SUB_expect_baseOpcode_0(void){
  char *str = "SUB";
  OperandInfo operandInfo;
  identifyInstruction(str,&operandInfo);
  printf("0x%02x\n",operandInfo.baseOpcode );
  TEST_ASSERT_EQUAL_HEX(0x0,operandInfo.baseOpcode);
}
void test_function_identifyInstruction_given_OR_expect_baseOpcode_A(void){
  char *str = "OR";
  OperandInfo operandInfo;
  identifyInstruction(str,&operandInfo);
  printf("0x%02x\n",operandInfo.baseOpcode );
  TEST_ASSERT_EQUAL_HEX(0xA,operandInfo.baseOpcode);
}
void test_function_identifyInstruction_given_LD_expect_baseOpcode_6(void){
  char *str = "LD";
  OperandInfo operandInfo;
  identifyInstruction(str,&operandInfo);
  printf("0x%02x\n",operandInfo.baseOpcode );
  TEST_ASSERT_EQUAL_HEX(0x6,operandInfo.baseOpcode);
}
void test_function_identifyInstruction_given_CP_expect_baseOpcode_1(void){
  char *str = "CP";
  OperandInfo operandInfo;
  identifyInstruction(str,&operandInfo);
  printf("0x%02x\n",operandInfo.baseOpcode );
  TEST_ASSERT_EQUAL_HEX(0x1,operandInfo.baseOpcode);
}
void test_function_identifyInstruction_given_BCP_expect_baseOpcode_5(void){
  char *str = "BCP";
  OperandInfo operandInfo;
  identifyInstruction(str,&operandInfo);
  printf("0x%02x\n",operandInfo.baseOpcode );
  TEST_ASSERT_EQUAL_HEX(0x5,operandInfo.baseOpcode);
}
void test_function_identifyInstruction_given_AND_expect_baseOpcode_4(void){
  char *str = "AND";
  OperandInfo operandInfo;
  identifyInstruction(str,&operandInfo);
  printf("0x%02x\n",operandInfo.baseOpcode );
  TEST_ASSERT_EQUAL_HEX(0x4,operandInfo.baseOpcode);
}
void test_function_identifyInstruction_given_ADD_expect_baseOpcode_B(void){
  char *str = "ADD";
  OperandInfo operandInfo;
  identifyInstruction(str,&operandInfo);
  printf("0x%02x\n",operandInfo.baseOpcode );
  TEST_ASSERT_EQUAL_HEX(0xB,operandInfo.baseOpcode);
}
void test_function_identifyInstruction_given_SBC_expect_baseOpcode_2(void){
  char *str = "SBC";
  OperandInfo operandInfo;
  identifyInstruction(str,&operandInfo);
  printf("0x%02x\n",operandInfo.baseOpcode );
  TEST_ASSERT_EQUAL_HEX(0x2,operandInfo.baseOpcode);
}
void test_function_identifyInstruction_given_BREAK_expect_baseOpcode_8b(void){
  char *str = "BREAK";
  OperandInfo operandInfo;
  identifyInstruction(str,&operandInfo);
  printf("0x%02x\n",operandInfo.baseOpcode );
  TEST_ASSERT_EQUAL_HEX(0x8B,operandInfo.baseOpcode);
}
void test_function_identifyInstruction_given_CCF_expect_baseOpcode_8C(void){
  char *str = "CCF";
  OperandInfo operandInfo;
  identifyInstruction(str,&operandInfo);
  printf("0x%02x\n",operandInfo.baseOpcode );
  TEST_ASSERT_EQUAL_HEX(0x8C,operandInfo.baseOpcode);
}
void test_function_identifyInstruction_given_HALT_expect_baseOpcode_8E(void){
  char *str = "HALT";
  OperandInfo operandInfo;
  identifyInstruction(str,&operandInfo);
  printf("0x%02x\n",operandInfo.baseOpcode );
  TEST_ASSERT_EQUAL_HEX(0x8E,operandInfo.baseOpcode);
}
void test_function_identifyInstruction_given_IRET_expect_baseOpcode_80(void){
  char *str = "OR";
  OperandInfo operandInfo;
  identifyInstruction(str,&operandInfo);
  printf("0x%02x\n",operandInfo.baseOpcode );
  TEST_ASSERT_EQUAL_HEX(0xA,operandInfo.baseOpcode);
}
void test_function_identifyInstruction_given_NOP_expect_baseOpcode_9D(void){
  char *str = "NOP";
  OperandInfo operandInfo;
  identifyInstruction(str,&operandInfo);
  printf("0x%02x\n",operandInfo.baseOpcode );
  TEST_ASSERT_EQUAL_HEX(0x9D,operandInfo.baseOpcode);
}
void test_function_identifyInstruction_given_RCF_expect_baseOpcode_98(void){
  char *str = "RCF";
  OperandInfo operandInfo;
  identifyInstruction(str,&operandInfo);
  printf("0x%02x\n",operandInfo.baseOpcode );
  TEST_ASSERT_EQUAL_HEX(0x98,operandInfo.baseOpcode);
}
void test_function_identifyInstruction_given_RET_expect_baseOpcode_81(void){
  char *str = "RET";
  OperandInfo operandInfo;
  identifyInstruction(str,&operandInfo);
  printf("0x%02x\n",operandInfo.baseOpcode );
  TEST_ASSERT_EQUAL_HEX(0x81,operandInfo.baseOpcode);
}
void test_function_identifyInstruction_given_RETF_expect_baseOpcode_87(void){
  char *str = "RETF";
  OperandInfo operandInfo;
  identifyInstruction(str,&operandInfo);
  printf("0x%02x\n",operandInfo.baseOpcode );
  TEST_ASSERT_EQUAL_HEX(0x87,operandInfo.baseOpcode);
}
void test_function_identifyInstruction_given_RIM_expect_baseOpcode_9A(void){
  char *str = "RIM";
  OperandInfo operandInfo;
  identifyInstruction(str,&operandInfo);
  printf("0x%02x\n",operandInfo.baseOpcode );
  TEST_ASSERT_EQUAL_HEX(0x9A,operandInfo.baseOpcode);
}
void test_function_identifyInstruction_given_RVF_expect_baseOpcode_9C(void){
  char *str = "RVF";
  OperandInfo operandInfo;
  identifyInstruction(str,&operandInfo);
  printf("0x%02x\n",operandInfo.baseOpcode );
  TEST_ASSERT_EQUAL_HEX(0x9C,operandInfo.baseOpcode);
}
void test_function_identifyInstruction_given_SCF_expect_baseOpcode_99(void){
  char *str = "SCF";
  OperandInfo operandInfo;
  identifyInstruction(str,&operandInfo);
  printf("0x%02x\n",operandInfo.baseOpcode );
  TEST_ASSERT_EQUAL_HEX(0x99,operandInfo.baseOpcode);
}
void test_function_identifyInstruction_given_SIM_expect_baseOpcode_9B(void){
  char *str = "SIM";
  OperandInfo operandInfo;
  identifyInstruction(str,&operandInfo);
  printf("0x%02x\n",operandInfo.baseOpcode );
  TEST_ASSERT_EQUAL_HEX(0x9B,operandInfo.baseOpcode);
}
void test_function_identifyInstruction_given_TRAP_expect_baseOpcode_83(void){
  char *str = "TRAP";
  OperandInfo operandInfo;
  identifyInstruction(str,&operandInfo);
  printf("0x%02x\n",operandInfo.baseOpcode );
  TEST_ASSERT_EQUAL_HEX(0x83,operandInfo.baseOpcode);
}
void test_function_identifyInstruction_given_WFI_expect_baseOpcode_8f(void){
  char *str = "WFI";
  OperandInfo operandInfo;
  identifyInstruction(str,&operandInfo);
  printf("0x%02x\n",operandInfo.baseOpcode );
  TEST_ASSERT_EQUAL_HEX(0x8F,operandInfo.baseOpcode);
}
void test_function_identifyInstruction_given_CPLW_expect_baseOpcode_53(void){
  char *str = "CPLW";
  OperandInfo operandInfo;
  identifyInstruction(str,&operandInfo);
  printf("0x%02x\n",operandInfo.baseOpcode );
  TEST_ASSERT_EQUAL_HEX(0x53,operandInfo.baseOpcode);
}
void test_function_identifyInstruction_given_DECW_expect_baseOpcode_5A(void){
  char *str = "DECW";
  OperandInfo operandInfo;
  identifyInstruction(str,&operandInfo);
  printf("0x%02x\n",operandInfo.baseOpcode );
  TEST_ASSERT_EQUAL_HEX(0x5A,operandInfo.baseOpcode);
}
void test_function_identifyInstruction_given_INCW_expect_baseOpcode_5C(void){
  char *str = "INCW";
  OperandInfo operandInfo;
  identifyInstruction(str,&operandInfo);
  printf("0x%02x\n",operandInfo.baseOpcode );
  TEST_ASSERT_EQUAL_HEX(0x5C,operandInfo.baseOpcode);
}
void test_function_identifyInstruction_given_NEGW_expect_baseOpcode_50(void){
  char *str = "NEGW";
  OperandInfo operandInfo;
  identifyInstruction(str,&operandInfo);
  printf("0x%02x\n",operandInfo.baseOpcode );
  TEST_ASSERT_EQUAL_HEX(0x50,operandInfo.baseOpcode);
}
void test_function_identifyInstruction_given_POPW_expect_baseOpcode_85(void){
  char *str = "POPW";
  OperandInfo operandInfo;
  identifyInstruction(str,&operandInfo);
  printf("0x%02x\n",operandInfo.baseOpcode );
  TEST_ASSERT_EQUAL_HEX(0x85,operandInfo.baseOpcode);
}
void test_function_identifyInstruction_given_PUSH_expect_baseOpcode_89(void){
  char *str = "PUSH";
  OperandInfo operandInfo;
  identifyInstruction(str,&operandInfo);
  printf("0x%02x\n",operandInfo.baseOpcode );
  TEST_ASSERT_EQUAL_HEX(0x89,operandInfo.baseOpcode);
}
void test_function_identifyInstruction_given_RLCW_expect_baseOpcode_59(void){
  char *str = "RLCW";
  OperandInfo operandInfo;
  identifyInstruction(str,&operandInfo);
  printf("0x%02x\n",operandInfo.baseOpcode );
  TEST_ASSERT_EQUAL_HEX(0x59,operandInfo.baseOpcode);
}
void test_function_identifyInstruction_given_RLWA_expect_baseOpcode_20(void){
  char *str = "RLWA";
  OperandInfo operandInfo;
  identifyInstruction(str,&operandInfo);
  printf("0x%02x\n",operandInfo.baseOpcode );
  TEST_ASSERT_EQUAL_HEX(0x02,operandInfo.baseOpcode);
}
void test_function_identifyInstruction_given_RRCW_expect_baseOpcode_56(void){
  char *str = "RRCW";
  OperandInfo operandInfo;
  identifyInstruction(str,&operandInfo);
  printf("0x%02x\n",operandInfo.baseOpcode );
  TEST_ASSERT_EQUAL_HEX(0x56,operandInfo.baseOpcode);
}
void test_function_identifyInstruction_given_RRWA_expect_baseOpcode_01(void){
  char *str = "RRWA";
  OperandInfo operandInfo;
  identifyInstruction(str,&operandInfo);
  printf("0x%02x\n",operandInfo.baseOpcode );
  TEST_ASSERT_EQUAL_HEX(0x01,operandInfo.baseOpcode);
}
void test_function_identifyInstruction_given_SLAW_expect_baseOpcode_58(void){
  char *str = "SLAW";
  OperandInfo operandInfo;
  identifyInstruction(str,&operandInfo);
  printf("0x%02x\n",operandInfo.baseOpcode );
  TEST_ASSERT_EQUAL_HEX(0x58,operandInfo.baseOpcode);
}
void test_function_identifyInstruction_given_SLLW_expect_baseOpcode_58(void){
  char *str = "SLLW";
  OperandInfo operandInfo;
  identifyInstruction(str,&operandInfo);
  printf("0x%02x\n",operandInfo.baseOpcode );
  TEST_ASSERT_EQUAL_HEX(0x58,operandInfo.baseOpcode);
}
void test_function_identifyInstruction_given_SRAW_expect_baseOpcode_57(void){
  char *str = "SRAW";
  OperandInfo operandInfo;
  identifyInstruction(str,&operandInfo);
  printf("0x%02x\n",operandInfo.baseOpcode );
  TEST_ASSERT_EQUAL_HEX(0x57,operandInfo.baseOpcode);
}
void test_function_identifyInstruction_given_RLWA_expect_baseOpcode_54(void){
  char *str = "SRLW";
  OperandInfo operandInfo;
  identifyInstruction(str,&operandInfo);
  printf("0x%02x\n",operandInfo.baseOpcode );
  TEST_ASSERT_EQUAL_HEX(0x54,operandInfo.baseOpcode);
}
void test_function_identifyInstruction_given_SWAPW_expect_baseOpcode_5E(void){
  char *str = "SWAPW";
  OperandInfo operandInfo;
  identifyInstruction(str,&operandInfo);
  printf("0x%02x\n",operandInfo.baseOpcode );
  TEST_ASSERT_EQUAL_HEX(0x5E,operandInfo.baseOpcode);
}
void test_function_identifyInstruction_given_TNZW_expect_baseOpcode_5D(void){
  char *str = "TNZW";
  OperandInfo operandInfo;
  identifyInstruction(str,&operandInfo);
  printf("0x%02x\n",operandInfo.baseOpcode );
  TEST_ASSERT_EQUAL_HEX(0x5D,operandInfo.baseOpcode);
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
