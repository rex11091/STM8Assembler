#include "symbol.h"
#include <string.h>
#include <stdio.h>
#include "Tokenizer.h"
#include "Token.h"
#include "error.h"
#include "CException.h"
#include "touppercase.h"


char *nextSyntax(char *symbol)
{
    if(strcmp(symbol,"#")==0){
    printf("# is detected !! is a byte instruction\n");
    }
    else if(strcmp(symbol,"(")==0){
    printf("( is detected !! either is (X/Y) , (Shortoff / Longoff ) , ( Shortptr / longptr )\n ");
    return symbol;
    }
    else
    {
    Throw(NOT_VALID_OPERATOR);
    }

}

char *hexaOrDecimal(char *symbol)
{
    if(strcmp(symbol,"$")==0)
    printf("$ is detected is a hexa number\n");
    else if(strcmp(symbol," ")==0)
    printf("is a decimal number\n");
    else
    {
    Throw(NOT_VALID_OPERATOR);
    }

}

int hexaNumber(int value)
{
    if(value >0xff)
    {
    printf("Error: Limit exceeded: Allowed range is 0xffffffffffffff80 - 0xff (-128 - 255)\n");
    printf("value = %d\n",value);
    Throw(LIMIT_EXCEEDED);
    }
    else if(value <=0xff)
    {
    printf("value = %d\n",value);
    return value;
    }
    else{
    Throw(NOT_VALID_OPERAND);
    }
}


int decimalNumber(int value)
{
    if(value >255)
    {
    printf("Error: Limit exceeded: Allowed range is 0xffffffffffffff80 - 0xff (-128 - 255)\n");
    printf("value = %d\n       ^",value);
    Throw(LIMIT_EXCEEDED);
    }
    else if(value <=0xff)
    {
    printf("value = %d\n       ^",value);
    return value;
    }
    else{
    Throw(NOT_VALID_OPERAND);
    }
}
