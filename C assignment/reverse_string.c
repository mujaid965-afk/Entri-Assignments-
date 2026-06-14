/*  Write a C program that takes a string from the user and reverses its characters using 
an iterative approach. 
Description: The program should prompt the user to enter a sequence of characters. It 
must then swap or move the characters within the string using a loop until the entire 
string is reversed. The final resulting string should be displayed on the screen. 
Pre-requisites: Loops, Strings. Operators. */

#include<stdio.h>
#include<string.h>

int main()
{
    char str[100];
    int i, len;

    printf("enter a string: ");
    scanf("%s", str);

    len = strlen(str);

    for(i=len-1; i>=0; i--)
    {
        printf("%c", str[i]);
    }
    return 0;
}