/*  Write a C program that takes an integer from the user and converts it into a 
string of characters. 
Description:The program should prompt the user to enter a whole number. It must 
then process this integer and store each of its digits as characters within a character 
array (string). The resulting string should represent the number exactly as it was 
entered, including a negative sign if the number is less than zero. Finally, the program 
should display the resulting string on the screen. 
Pre-requisites: Strings, Loops, Operators. */

#include <stdio.h>

int main()
{
    int num, i=0, j;
    char str[20];

    printf("enter integer: ");
    scanf("%d", &num);

    int temp = num;

    while (temp > 0)
    {
        str[i++] = (temp % 10) + '0';
        temp /= 10;
    }

    str[i] = '\0';

    for(j=0; j<i/2; j++)
    {
        char t = str[j];
        str[j] = str[i-j-1];
        str[i-j-1] = t;

    }
    printf("string = %s\n", str);
}