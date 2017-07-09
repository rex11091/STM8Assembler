#include "ADDShortMem.h"
#include <string.h>
#include <stdio.h>
#include "Tokenizer.h"
#include "Token.h"
#include "error.h"
#include "CException.h"


int ADDShortMem(char *assemblyCode){
 Tokenizer *tokenizer = initTokenizer(assemblyCode);
 Token *token = getToken(tokenizer);
 IdentifierToken *idToken;
 IntegerToken *intToken;
 OperatorToken *opToken;
  if(token->type == TOKEN_IDENTIFIER_TYPE){
	   idToken = (IdentifierToken *)token;
	    if(strcmp(idToken->str, "ADD") == 0) {
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
                      if(strcmp(opToken->str,"$" )== 0){
		                token = getToken(tokenizer);
		            if(token->type == TOKEN_INTEGER_TYPE){
			           IntegerToken *intToken = (IntegerToken *)token;
			              if(intToken->value > 0xff) {
				                  printf("Warning Argument out of range.Least significant bits used.\n");
				                      printf("ADD A,$%d\n       ^", intToken->value);
			                         }
			                           return 0xB900 + (intToken->value & 0xff);
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
      Throw(NOT_VALID_INSTRUCTION);
    }
   }
	}
  else{
    Throw(NOT_VALID_INSTRUCTION);
  }
}

}
