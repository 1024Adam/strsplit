/* strsplit.h */
/*
Adam Reid
March 17, 2015
*/

/* Used to separate a string based on a tokenizer */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct SplitString
{
    char * * splitString;
    int size;
};
typedef struct SplitString SplitString;

SplitString strsplit(char * str, char * split);
int getSize(SplitString strings);
int freeSplitStr(SplitString strings);

