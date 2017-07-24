#include "testing.h"
#include <string.h>
#include <stdio.h>
#include "Tokenizer.h"
#include "Token.h"
#include "error.h"
#include "CException.h"
#include "touppercase.h"





//FuncPtr SyntaxOperand[256]= {
//  ['#'] = {byteOperand},
  //['$'] = LongShortMemOperand,
//};

int assemble(char *assemblyName, char **memoryToWriteCode);
Tokenizer *tokenizer = initTokenizer(assemblyName);
Token *token = getToken(tokenizer);
IdentifierToken *idToken;
OperatorToken *opToken;
OperandInfo operandInfo;


if(token->type != TOKEN_IDENTIFIER_TYPE)
  Throw(NOT_VALID_INSTRUCTION);
if(opToken->type != TOKEN_OPERATOR_TYPE && strcmp((",",opToken->str)==0)
  Throw(NOT_VALID_OPERATOR);


/*int hexaOrDecimal(char *instruct)
{
    Tokenizer *tokenizer = initTokenizer(instruct);
    Token *token = getToken(tokenizer);
    IntegerToken *intToken;
    if(token->type == TOKEN_INTEGER_TYPE){
      intToken = (IntegerToken *)token;
      if(strcmp(intToken->value,"$")==0){
      printf("$ is detected is a hexa number\n");
      token = getToken (tokenizer);
        if(intToken->value >0xff)
          {
            printf("Error: Limit exceeded: Allowed range is 0xffffffffffffff80 - 0xff (-128 - 255)\n");
            printf("value = %d\n",intToken->value);
            Throw(LIMIT_EXCEEDED);
          }
        else if(intToken->value <=0xff)
          {
            printf("value = %d\n",intToken->value);
          }
        else
          {
            Throw(NOT_VALID_OPERAND);
          }
      return intToken->value;
    }
    else if(strcmp(intToken->value," ")==0){
    printf("is a decimal number\n");
    //token = getToken (tokenizer);
      if(intToken->value >256)
        {
          printf("Error: Limit exceeded: Allowed range is 0xffffffffffffff80 - 0xff (-128 - 255)\n");
          printf("value = %d\n",intToken->value);
          Throw(LIMIT_EXCEEDED);
        }
      else if(intToken->value <=256)
        {
          printf("value = %d\n",intToken->value);
        }
      else
        {
          Throw(NOT_VALID_OPERAND);
        }
      return intToken->value;
    }
    else
    {
    Throw(NOT_VALID_OPERATOR);
    }

  }
}
*/

/*int ADDByte(char *instruct,uint8_t codeMem[]){
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
       token = getToken(tokenizer);
         if(token->type == TOKEN_OPERATOR_TYPE){
           opToken = (OperatorToken *)token;
           SyntaxOperand[opToken->str[0]](tokenizer,codeMem);


}
}
}
}
*/
