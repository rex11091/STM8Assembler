#include "ADDShortoff.h"
#include <string.h>
#include <stdio.h>
#include "Tokenizer.h"
#include "Token.h"
#include "error.h"
#include "CException.h"
#include "touppercase.h"


int ADDShortoffX(char *assemblyCode){
  assemblyCode = convertToUpperCase(assemblyCode);
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
                      if(token->type == TOKEN_OPERATOR_TYPE){
                      opToken = (OperatorToken *)token;
                      if(strcmp(opToken->str,"$") == 0){
                      token = getToken(tokenizer);
                      if(token->type == TOKEN_INTEGER_TYPE){
                      IntegerToken *intToken = (IntegerToken *)token;
     			              if(intToken->value > 0xff) {
                          printf("Error: Limit exceeded: Allowed range is 0xffffffffffffff80 - 0xff (-128 - 255)\n");
                          //printf("Warning Argument out of range.Least significant bits used.\n");
                           printf("ADD A,#$%d\n       ^", intToken->value);
                           Throw(LIMIT_EXCEEDED);
                          }
                      token = getToken(tokenizer);
                      if(token->type == TOKEN_OPERATOR_TYPE){
                      opToken = (OperatorToken *)token;
                      if(strcmp(opToken->str,",") == 0){
                       token = getToken(tokenizer);
                      if(token->type == TOKEN_IDENTIFIER_TYPE){
                        idToken = (IdentifierToken *)token;
                        if(strcmp(idToken->str, "X") == 0){
                           token = getToken(tokenizer);
                            if(token->type == TOKEN_OPERATOR_TYPE){
                               opToken = (OperatorToken *)token;
                               if(strcmp(opToken->str,")" )== 0){
              /*                 //  printf("asdasdas");
                */            }
                            else{
                                Throw(NOT_VALID_OPERATOR);
                               }
                            return 0xEB00 + (intToken->value & 0xff);
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



int ADDShortoffY(char *assemblyCode){
  assemblyCode = convertToUpperCase(assemblyCode);
 Tokenizer *tokenizer = initTokenizer(assemblyCode);
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
                    if(strcmp(opToken->str,"(") == 0){
                      token = getToken(tokenizer);
                      if(token->type == TOKEN_OPERATOR_TYPE){
                      opToken = (OperatorToken *)token;
                      if(strcmp(opToken->str,"$") == 0){
                      token = getToken(tokenizer);
                      if(token->type == TOKEN_INTEGER_TYPE){
                      IntegerToken *intToken = (IntegerToken *)token;
     			              if(intToken->value > 0xff) {
                          printf("Error: Limit exceeded: Allowed range is 0xffffffffffffff80 - 0xff (-128 - 255)\n");
                          //printf("Warning Argument out of range.Least significant bits used.\n");
                           printf("ADD A,#$%d\n       ^", intToken->value);
                           Throw(LIMIT_EXCEEDED);
                          }
                      token = getToken(tokenizer);
                      if(token->type == TOKEN_OPERATOR_TYPE){
                      opToken = (OperatorToken *)token;
                      if(strcmp(opToken->str,",") == 0){
                       token = getToken(tokenizer);
                      if(token->type == TOKEN_IDENTIFIER_TYPE){
                        idToken = (IdentifierToken *)token;
                        if(strcmp(idToken->str, "Y") == 0){
                           token = getToken(tokenizer);
                            if(token->type == TOKEN_OPERATOR_TYPE){
                               opToken = (OperatorToken *)token;
                               if(strcmp(opToken->str,")" )== 0){
              /*                 //  printf("asdasdas");
                */            }
                            else{
                                Throw(NOT_VALID_OPERATOR);
                               }
                            return 0x90EB00 + (intToken->value & 0xff);
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

int ADDShortoffSP(char *assemblyCode){
  assemblyCode = convertToUpperCase(assemblyCode);
 Tokenizer *tokenizer = initTokenizer(assemblyCode);
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
                    if(strcmp(opToken->str,"(") == 0){
                      token = getToken(tokenizer);
                      if(token->type == TOKEN_OPERATOR_TYPE){
                      opToken = (OperatorToken *)token;
                      if(strcmp(opToken->str,"$") == 0){
                      token = getToken(tokenizer);
                      if(token->type == TOKEN_INTEGER_TYPE){
                      IntegerToken *intToken = (IntegerToken *)token;
     			              if(intToken->value > 0xff) {
                          printf("Error: Limit exceeded: Allowed range is 0xffffffffffffff80 - 0xff (-128 - 255)\n");
                          //printf("Warning Argument out of range.Least significant bits used.\n");
                           printf("ADD A,#$%d\n       ^", intToken->value);
                           Throw(LIMIT_EXCEEDED);
                          }
                      token = getToken(tokenizer);
                      if(token->type == TOKEN_OPERATOR_TYPE){
                      opToken = (OperatorToken *)token;
                      if(strcmp(opToken->str,",") == 0){
                       token = getToken(tokenizer);
                      if(token->type == TOKEN_IDENTIFIER_TYPE){
                        idToken = (IdentifierToken *)token;
                        if(strcmp(idToken->str, "S") == 0){
                          token = getToken(tokenizer);
                          if(token->type == TOKEN_IDENTIFIER_TYPE){
                            idToken = (IdentifierToken *)token;
                            if(strcmp(idToken->str, "P") == 0){
                           token = getToken(tokenizer);
                            if(token->type == TOKEN_OPERATOR_TYPE){
                               opToken = (OperatorToken *)token;
                               if(strcmp(opToken->str,")" )== 0){
              /*                 //  printf("asdasdas");
                */            }
                            else{
                                Throw(NOT_VALID_OPERATOR);
                               }
                            return 0x1B00 + (intToken->value & 0xff);
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
