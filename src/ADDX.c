#include "ADDX.h"
#include <string.h>
#include <stdio.h>
#include "Tokenizer.h"
#include "Token.h"
#include "error.h"
#include "CException.h"


int ADDX(char *assemblyCode){
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
                    if(strcmp(opToken->str,"(") == 0){
                      token = getToken(tokenizer);
                      if(token->type == TOKEN_IDENTIFIER_TYPE){
                        idToken = (IdentifierToken *)token;
                        if(strcmp(idToken->str, "X") == 0){
                          token = getToken(tokenizer);
                            if(token->type == TOKEN_OPERATOR_TYPE){
                              opToken = (OperatorToken *)token;
                              if(strcmp(opToken->str,")" )== 0){
                              //  printf("asdasdas");
                            }else{
                                Throw(NOT_VALID_OPERATOR);
                                  }
                          return 0xFB;
               }
             }
             else{
           Throw(NOT_VALID_INSTRUCTION);
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
