/* strsplit.c */
/* 
Adam Reid
March 17, 2015
*/

/* Used to separate a string based on a tokenizer */

#include "strsplit.h"

/** strsplit
 *  Makes a SplitString variable type containing all of the tokens of a given string
 *  Parameters: str - the string to be tokenized
                split - the "tokenizer"
 *  Return: The tokens of the string in a SplitString variable type
 */
SplitString strsplit(char * str, char * split)
{
    char * temp;
    char * token;
    SplitString strings;
    int i;

    i = 1;

    temp = malloc(sizeof(char) * (strlen(str)+1));
    strcpy(temp, str);
   
    strings.splitString = malloc(sizeof(char *));
 
    token = strtok(temp, split);
    while(token != NULL)
    {
        strings.splitString = realloc(strings.splitString, sizeof(char *) * i);
        strings.splitString[i-1] = malloc(sizeof(char) * (strlen(token) + 1));
        
        strcpy(strings.splitString[i-1], token);

        token = strtok(NULL, split);

        i++;
    }

    strings.size = i-1;

    return(strings);
}

/** getSize
 *  Gets the number of tokens in the SplitString variable (ie the length of the SplitString variable)
 *  Parameters: strings - the SplitString variable containing the tokens
 *  Return: the number of tokens in the SplitString variable
 */
int getSize(SplitString strings)
{
    return(strings.size);
}

/** freeSplitStr
 * Frees all of the memory allocated for the SplitString variable
 * Parameters: strings - the SplitString to be freed
 * Return: 1 on success
 */ 
int freeSplitStr(SplitString strings)
{
    int count;
    int i;

    count = getSize(strings);
    i = 0;

    for(i = 0; i < count; i++)
    {
        free(strings.splitString[i]);
    }

    free(strings.splitString);

    return(1);
}
