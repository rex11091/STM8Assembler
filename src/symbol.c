#include "symbol.h"
#include <string.h>
#include <stdio.h>
#include "error.h"
#include "CException.h"


/*
int *commasymbol(char *symbol)
{
    if(strcmp(symbol, ",") == 0)
    printf("symbol is correct\n");
    else{
    Throw(NOT_VALID_OPERATOR);
    }
    return 0;
}
*/

int *nextsymbol(char *symbol)
{
    if(strcmp(symbol, "#") == 0){
    printf("# is detected is a byte\n");
    else{
    Throw(NOT_VALID_OPERATOR);
    }
    return 0;
    }

    if(strcmp(symbol, "$") == 0){
    printf(" is detected is a hexa number")

    }

}

int *dollarsymbol(char *symbol)
{
    if(strcmp(symbol, "$") == 0)
    printf("symbol is correct\n");
    else{
    Throw(NOT_VALID_OPERATOR);
    }
    return 0;
}

int *AInstruction(char *instruction)
{
    if(strcmp(instruction, "A") == 0)
    printf("instruction is correct\n");
    else{
    Throw(NOT_VALID_INSTRUCTION);
    }
    return 0;
}
