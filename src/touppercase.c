#include "touppercase.h"
#include <stdio.h>
char *convertToUpperCase(char *instruction)
{
  int i = 0;

  while(instruction[i] != '\0')
  {
    instruction[i] = toupper(instruction[i]);
    ++i;
  }
  return instruction;
}
