/* Write a C program that takes an integer from the user and determines whether 
the number is even or odd. 
Description: The program should prompt the user to enter a whole number. It must 
then check if the number is perfectly divisible by 2. If it is, the program should 
display that the number is even; otherwise, it should display that the number is odd. 
The program should handle both positive and negative integers. 
Pre-requisites: Conditional Statements, Operators. */

#include <stdio.h>

int main()
{
    int num;
    printf("Enter the number:");
    scanf("%d", &num);

    if (num % 2 == 0)
    {
        printf("%d is Even \n", num);
    
    }else
    {
        printf("%d is Odd \n", num);
    }

    return 0;
}