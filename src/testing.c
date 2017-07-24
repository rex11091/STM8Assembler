#include "testing.h"
#include <string.h>
#include <stdio.h>
#include "Tokenizer.h"
#include "Token.h"
#include "error.h"
#include "CException.h"
#include "touppercase.h"
#include "symbol.h"




FuncPtr SyntaxOperand[256]= {
  ['#'] = {byteOperand},
  //['$'] = LongShortMemOperand,
};



int ADDByte(char *instruct,uint8_t codeMem[]){
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

int byteOperand(Tokenizer *tokenizer,char *codeMem)
{
   Token *token = getToken(tokenizer);
   OperatorToken *opToken;
   IntegerToken *intToken;
        if(token->type == TOKEN_OPERATOR_TYPE){
        opToken = (OperatorToken *)token;
        hexaOrDecimal(opToken->str);
        token = getToken(tokenizer);
        if(token->type == TOKEN_INTEGER_TYPE){
        intToken = (IntegerToken *)token;
        hexaNumber(intToken->value);
        return 0x90FB;


}
}
}




//char* assembler (Tokenizer *tokenizer)
//{
//  SyntaxOperand[token].execute(token);
//}
