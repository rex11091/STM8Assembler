#include "touppercase.h"
#include <stdio.h>
char *convertToUpperCase(char *instruction)
{
  int i = 0;

  printf("before convert To UpperCase %s\n",instruction);
  while(instruction[i] != '\0')
  {
    instruction[i] = toupper(instruction[i]);
    ++i;
  }
  printf("after convert To UpperCase %s\n",instruction);
  return instruction;
}
