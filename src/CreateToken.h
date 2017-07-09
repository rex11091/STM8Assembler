#ifndef _CREATETOKEN_H
#define _CREATETOKEN_H
#include "Token.h"

Token *createInteger(int value);
Token *createOperator(char *symbol);
Token *createIdentifier(char *str); 

#endif // _CREATETOKEN_H
