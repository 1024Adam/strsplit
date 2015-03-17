/* testmain.c */
/*
Adam Reid 
March 17, 2015
*/

#include "strsplit.h"

int main()
{
    char * testStr = "Apples;Oranges";
    char * tokenizer = "/";
    SplitString tokens;
    int length;
    int i;

    length = 0;
    i = 0;

    tokens = strsplit(testStr, tokenizer);
    
    length = getSize(tokens);
    printf("%d\n", length);

    printf("Test String: %s\n", testStr);
    for(i = 0; i < length; i++)
    {
        printf("Token %d: %s\n", i, tokens.splitString[i]);
    }
   
    freeSplitStr(tokens);    
 
    return(0);
}
