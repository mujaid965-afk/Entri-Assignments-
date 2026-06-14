/*  Write a C program that takes a string from the user and checks whether it is a 
palindrome. 
Description: The program should prompt the user to enter a string. It must determine 
if the string reads the same forward and backward. The program should then display a 
message to the user stating whether the input is a palindrome or not. 
Pre-requisites: Loops, Control Statements, Strings and Operators. */

#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    int i, len, flag=1;

    printf("Enter a string: ");
    scanf("%s", str);

    len = strlen(str);

    for(i=0; i<len/2; i++)
    {
        if(str[i] != str[len-i-1])
        {
            flag = 0;
            break;
        }
    }
    if(flag)
        printf("Palindrome\n");
    else
        printf("not palindrome");
    
    return 0;
}
