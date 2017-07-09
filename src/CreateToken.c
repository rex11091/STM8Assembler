#include "CreateToken.h"
#include <malloc.h>


Token *createInteger(int value) {
  IntegerToken *intToken = malloc(sizeof(IntegerToken));
  intToken->type = TOKEN_INTEGER_TYPE;
  intToken->value = value;
  return (Token *)intToken;
}

Token *createOperator(char *symbol) {
  OperatorToken *opToken = malloc(sizeof(OperatorToken) + sizeof(Token *) * 2);
  opToken->type = TOKEN_OPERATOR_TYPE;
  opToken->str = symbol;
  return (Token *)opToken;
}


Token *createIdentifier(char *str) {
  IdentifierToken *idToken = malloc(sizeof(IdentifierToken));
  idToken->type = TOKEN_IDENTIFIER_TYPE;
  idToken->str = str;
  return (Token *)idToken;
}
