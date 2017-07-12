#include "ADDByte.h"
#include <string.h>
#include <stdio.h>
#include "Tokenizer.h"
#include "Token.h"
#include "error.h"
#include "CException.h"





char *convertToUpperCase(char *name)
{
  int i = 0;
  char *buffer;
  buffer = (char*)malloc(strlen(name)+1);
  strcpy(buffer,name);
  printf("before convertToUpperCase %s\n",buffer);
  while(buffer[i] != '\0')
  {
    buffer[i] = toupper(buffer[i]);
    ++i;
  }
  printf("after convertToUpperCase %s\n",buffer);
  return buffer;
  free(buffer);
}


int ADDByte(char *assemblyCode){
  char *result;
 result = convertToUpperCase(assemblyCode);
 Tokenizer *tokenizer = initTokenizer(result);
 Token *token = getToken(tokenizer);
 IdentifierToken *idToken;
 IntegerToken *intToken;
 OperatorToken *opToken;
  if(token->type == TOKEN_IDENTIFIER_TYPE){
	   idToken = (IdentifierToken *)token;
	    if(strcmp(idToken->str, "ADD") == 0){
        token = getToken(tokenizer);
        if(token->type == TOKEN_IDENTIFIER_TYPE){
          idToken = (IdentifierToken *)token;
          if(strcmp(idToken->str, "A") == 0){
            token = getToken(tokenizer);
              if(token->type == TOKEN_OPERATOR_TYPE){
                opToken = (OperatorToken *)token;
                if(strcmp(opToken->str, ",") == 0){
                  token = getToken(tokenizer);
                  if(token->type == TOKEN_OPERATOR_TYPE){
                    opToken = (OperatorToken *)token;
                    if(strcmp(opToken->str,"#") == 0){
                  token = getToken(tokenizer);
                    if(token->type == TOKEN_OPERATOR_TYPE){
                      opToken = (OperatorToken *)token;
                      if(strcmp(opToken->str,"$" )== 0){
		                token = getToken(tokenizer);
		            if(token->type == TOKEN_INTEGER_TYPE){
			           IntegerToken *intToken = (IntegerToken *)token;
			              if(intToken->value > 0xff) {
                          printf("Error: Limit exceeded: Allowed range is 0xffffffffffffff80 - 0xff (-128 - 255)\n");
				                  //printf("Warning Argument out of range.Least significant bits used.\n");
				                   printf("ADD A,#$%d\n       ^", intToken->value);
                           Throw(LIMIT_EXCEEDED);
			                         }

			                           return 0xAB00 + (intToken->value & 0xff);
		          }else{
			           Throw(NOT_VALID_OPERAND);
		             }
               }
               else{
                 Throw(NOT_VALID_OPERATOR);
               }
               }
             }
             else{
               Throw(NOT_VALID_OPERATOR);
             }
             }
          }
            else{
              Throw(NOT_VALID_OPERATOR);
            }
          }
        }
        else{
      Throw(NOT_VALID_INSTRUCTION);
    }
   }
	}
  else{
    Throw(NOT_VALID_INSTRUCTION);
  }
}

}
