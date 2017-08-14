#include "unity.h"
#include <stdio.h>
#include "touppercase.h"
void setUp(void)
{
}

void tearDown(void)
{
}

void test_given_WAt_the_HeavEn_expect_WAT_THE_HEAVEN(void){
  char str[] = "WAt the HeavEn";
  char *result = convertToUpperCase(str);
  TEST_ASSERT_EQUAL_STRING("WAT THE HEAVEN",result);
}

void test_given_sentenceWithSymbol_expect_upper_case(void){
  char str[] = "WAt,Are u talking About???";
  char *result = convertToUpperCase(str);
  TEST_ASSERT_EQUAL_STRING("WAT,ARE U TALKING ABOUT???",result);
}
