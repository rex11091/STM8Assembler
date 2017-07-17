#include "testing.h"
#include <string.h>
#include <stdio.h>
#include "Tokenizer.h"
#include "Token.h"
#include "error.h"
#include "CException.h"
#include "touppercase.h"
#include "symbol.h"


int ADDByte(char *instruct){
 //char *result;
 instruct = convertToUpperCase(instruct);
 Tokenizer *tokenizer = initTokenizer(instruct);
 Token *token = getToken(tokenizer);
 IdentifierToken *idToken;
 IntegerToken *intToken;
 OperatorToken *opToken;
                  if(token->type == TOKEN_IDENTIFIER_TYPE){
	                idToken = (IdentifierToken *)token;
	                if(strcmp(idToken->str, "ADD A ,") == 0){
                //  token = getToken(tokenizer);
                //  if(token->type == TOKEN_IDENTIFIER_TYPE){
                //  idToken = (IdentifierToken *)token;
                //  if(AInstruction(idToken->str) == 0);
                //  token = getToken(tokenizer);
                //  if(token->type == TOKEN_OPERATOR_TYPE){
                //  opToken = (OperatorToken *)token;
                //  if(commasymbol(opToken->str) == 0);
                  token = getToken(tokenizer);
                  if(token->type == TOKEN_OPERATOR_TYPE){
                  opToken = (OperatorToken *)token;
                  if(HashTagsymbol(opToken->str) == 0);
                  token = getToken(tokenizer);
                  if(token->type == TOKEN_OPERATOR_TYPE){
                  opToken = (OperatorToken *)token;
                  if(dollarsymbol(opToken->str)== 0){
		              token = getToken(tokenizer);
		              if(token->type == TOKEN_INTEGER_TYPE){
			            IntegerToken *intToken = (IntegerToken *)token;
			            if(intToken->value > 0xff) {
                    printf("Error: Limit exceeded: Allowed range is 0xffffffffffffff80 - 0xff (-128 - 255)\n");
                    printf("ADD A,#$%d\n       ^", intToken->value);
                           Throw(LIMIT_EXCEEDED);
			            }
                  return 0xAB00 + (intToken->value & 0xff);
		              }else
                  {
			            Throw(NOT_VALID_OPERAND);
		               }

               }
               }
               }
               }
               }
	             }
               else
               {
                 Throw(NOT_VALID_INSTRUCTION);
               }
               }

}
