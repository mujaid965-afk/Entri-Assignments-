/*  Write a C program that takes a string from the user and replaces every sequence of 
multiple consecutive spaces with a single space. 
Description: The program should prompt the user to enter a sentence that may 
contain several spaces between words. It must then process the string to ensure that 
any instance where two or more blank spaces appear together is reduced to just one 
blank space. The final cleaned string should be displayed on the screen. 
Pre-requisites:  Loops, Strings, Conditional Statements, ASCII, Operators */

#include <stdio.h>

int main()
{
    char str[200], result[200];
    int i = 0, j = 0;

    printf("enter string: ");
    fgets(str, sizeof(str), stdin);

    while(str[i] != '\0') 
    {
        if(!(str[i] == ' ' && str[i + 1] == ' ')) 
        {
            result[j++] = str[i];
        }
        i++;
    }

    result[j] = '\0';
    printf("Result: %s", result);
    return 0;
}