/* Write a C program that takes a string input from the user and determines whether it is 
a pangram or not. 
Description: The program should prompt the user to enter a sentence or a string of 
characters. It must then verify if every letter of the alphabet from A to Z appears at 
least once within the provided text, regardless of whether the letters are uppercase or 
lowercase. The final output should state if the string is a pangram. 
Pre-requisites: Loops, Strings, Conditional Statements, ASCII, Operators */

#include <stdio.h>
#include <ctype.h>

int main()
{
    char str[500];
    int alpha[26] = {0};
    int i;

    printf("Enter sentence: ");
    fgets(str, sizeof(str), stdin);

    for(i=0; str[i] != '\0';i++)
    {
        if(isalpha(str[i]))
        {
            alpha[tolower(str[i]) - 'a'] = 1;
        }
    }
    for(i=0; i< 26; i++)
    {
        if(alpha[i] == 0)
        {
            printf("Not pangram\n");
            return 0;
        }
    }
    printf("pangram\n");
    return 0;
}