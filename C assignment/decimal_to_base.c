/* Write a C program that uses functions to convert a decimal number to any base 
between 2 and 16. 
Description: The program should prompt the user to enter a decimal number and a 
target base. A separate function must be written that performs the repeated division 
method, stores each remainder, and builds the result in the correct order. For bases 
above 9, remainders 10–15 should be represented as letters A–F. The converted value 
should be displayed from the main function. 
Pre-requisites: Functions, Loops, Arrays, Character Handling.*/

#include <stdio.h>

void convert(int num, int base)
{
    char result[50];
    int i =0, rem;

    while(num > 0)
    {
        rem = num % base;
        if(rem < 10)
            result[i++] = rem + '0';
        else
            result[i++] = rem - 10 + 'A';
        
        num /= base;
    }

    printf("Converted number: ");

    while(i > 0)
        printf("%c", result[--i]);

    printf("\n");

}

int main()
{
    int num, base;
    printf("Enter decimal number: ");
    scanf("%d", &num);

    printf("Enter base (2-16): ");
    scanf("%d", &base);

    convert(num, base);

    return 0;
}