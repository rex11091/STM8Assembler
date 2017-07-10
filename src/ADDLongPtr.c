#include "ADDLongPtr.h"
#include <string.h>
#include <stdio.h>
#include "Tokenizer.h"
#include "Token.h"
#include "error.h"
#include "CException.h"


int ADDLongPtr(char *assemblyCode){
 Tokenizer *tokenizer = initTokenizer(assemblyCode);
 Token *token = getToken(tokenizer);
 IdentifierToken *idToken;
 IntegerToken *intToken;
 OperatorToken *opToken;
  if(token->type == TOKEN_IDENTIFIER_TYPE){
	   idToken = (IdentifierToken *)token;
	    if((strcmp(idToken->str, "ADD") == 0) || (strcmp(idToken->str, "add") == 0)){
        token = getToken(tokenizer);
        if(token->type == TOKEN_IDENTIFIER_TYPE){
          idToken = (IdentifierToken *)token;
          if((strcmp(idToken->str, "A") == 0) || (strcmp(idToken->str, "a") == 0)){
            token = getToken(tokenizer);
              if(token->type == TOKEN_OPERATOR_TYPE){
                opToken = (OperatorToken *)token;
                if(strcmp(opToken->str, ",") == 0){
                  token = getToken(tokenizer);
                  if(token->type == TOKEN_OPERATOR_TYPE){
                    opToken = (OperatorToken *)token;
                    if(strcmp(opToken->str,"[") == 0){
                      token = getToken(tokenizer);
                      if(token->type == TOKEN_OPERATOR_TYPE){
                      opToken = (OperatorToken *)token;
                      if(strcmp(opToken->str,"$") == 0){
                      token = getToken(tokenizer);
                      if(token->type == TOKEN_INTEGER_TYPE){
                      IntegerToken *intToken = (IntegerToken *)token;
     			              if(intToken->value > 0xffff) {
                          printf("Error:Limit exceeded: Allowed range is 0xffffffffffff8000 - 0xffff (-32768 - 65535)\n");
                          //printf("Warning Argument out of range.Least significant bits used.\n");
                           printf("ADD A,#$%d\n       ^", intToken->value);
                           Throw(LIMIT_EXCEEDED);
                          }
                      token = getToken(tokenizer);
                      if(token->type == TOKEN_OPERATOR_TYPE){
                      opToken = (OperatorToken *)token;
                      if(strcmp(opToken->str,".") == 0){
                       token = getToken(tokenizer);
                      if(token->type == TOKEN_IDENTIFIER_TYPE){
                        idToken = (IdentifierToken *)token;
                        if((strcmp(idToken->str, "W") == 0) || (strcmp(idToken->str, "w") == 0)){
                           token = getToken(tokenizer);
                            if(token->type == TOKEN_OPERATOR_TYPE){
                               opToken = (OperatorToken *)token;
                               if(strcmp(opToken->str,"]" )== 0){
              /*                 //  printf("asdasdas");
                */            }
                            else{
                                Throw(NOT_VALID_OPERATOR);
                               }
                            return 0x72CB0000 + (intToken->value & 0xffff);
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
        else{
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

int ADDLongPtrXIndexFile(char *assemblyCode){
 Tokenizer *tokenizer = initTokenizer(assemblyCode);
 Token *token = getToken(tokenizer);
 IdentifierToken *idToken;
 IntegerToken *intToken;
 OperatorToken *opToken;
  if(token->type == TOKEN_IDENTIFIER_TYPE){
	   idToken = (IdentifierToken *)token;
	    if((strcmp(idToken->str, "ADD") == 0) || (strcmp(idToken->str, "add") == 0)){
        token = getToken(tokenizer);
        if(token->type == TOKEN_IDENTIFIER_TYPE){
          idToken = (IdentifierToken *)token;
          if((strcmp(idToken->str, "A") == 0) || (strcmp(idToken->str, "a") == 0)){
            token = getToken(tokenizer);
              if(token->type == TOKEN_OPERATOR_TYPE){
                opToken = (OperatorToken *)token;
                if(strcmp(opToken->str, ",") == 0){
                  token = getToken(tokenizer);
                    if(token->type == TOKEN_OPERATOR_TYPE){
                      opToken = (OperatorToken *)token;
                      if(strcmp(opToken->str, "(") == 0){
                  token = getToken(tokenizer);
                  if(token->type == TOKEN_OPERATOR_TYPE){
                    opToken = (OperatorToken *)token;
                    if(strcmp(opToken->str,"[") == 0){
                      token = getToken(tokenizer);
                      if(token->type == TOKEN_OPERATOR_TYPE){
                      opToken = (OperatorToken *)token;
                      if(strcmp(opToken->str,"$") == 0){
                      token = getToken(tokenizer);
                      if(token->type == TOKEN_INTEGER_TYPE){
                      IntegerToken *intToken = (IntegerToken *)token;
     			              if(intToken->value > 0xffff) {
                          printf("Error:Limit exceeded: Allowed range is 0xffffffffffff8000 - 0xffff (-32768 - 65535)\n");
                          //printf("Warning Argument out of range.Least significant bits used.\n");
                           printf("ADD A,#$%d\n       ^", intToken->value);
                           Throw(LIMIT_EXCEEDED);
                          }
                      token = getToken(tokenizer);
                      if(token->type == TOKEN_OPERATOR_TYPE){
                      opToken = (OperatorToken *)token;
                      if(strcmp(opToken->str,".") == 0){
                       token = getToken(tokenizer);
                      if(token->type == TOKEN_IDENTIFIER_TYPE){
                        idToken = (IdentifierToken *)token;
                      if((strcmp(idToken->str, "W") == 0) || (strcmp(idToken->str, "w") == 0)){
                           token = getToken(tokenizer);
                            if(token->type == TOKEN_OPERATOR_TYPE){
                               opToken = (OperatorToken *)token;
                               if(strcmp(opToken->str,"]" )== 0){

                                 token = getToken(tokenizer);
                                  if(token->type == TOKEN_OPERATOR_TYPE){
                                     opToken = (OperatorToken *)token;
                                     if(strcmp(opToken->str,"," )== 0){

                                       token = getToken(tokenizer);
                                      if(token->type == TOKEN_IDENTIFIER_TYPE){
                                        idToken = (IdentifierToken *)token;
                                        if((strcmp(idToken->str, "X") == 0) || (strcmp(idToken->str, "x") == 0)){

                                          token = getToken(tokenizer);
                                           if(token->type == TOKEN_OPERATOR_TYPE){
                                              opToken = (OperatorToken *)token;
                                              if(strcmp(opToken->str,")" )== 0){

                                            }
                                            else{
                                              Throw(NOT_VALID_OPERATOR);
                                            }
                                                                              return 0x72DB00 + (intToken->value & 0xff);
                                          }

                                      }
                                          else {
                                            Throw(NOT_VALID_INSTRUCTION);
                                          }

                                        }
                                   }
                                   else {
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
        else{
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
