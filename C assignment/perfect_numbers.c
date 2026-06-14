/*  Write a C program that uses a function to check whether a given number is a 
Perfect Number. 
Description: The program should prompt the user to enter a positive integer. A 
separate function must be written that computes the sum of all proper divisors of the 
number (excluding the number itself) and returns whether the sum equals the original 
number. The main function should display whether the number is perfect or not. 
(Example: 6 = 1+2+3, 28 = 1+2+4+7+14) 
Pre-requisites: Functions, Loops, Return Values.*/

#include <stdio.h>

int Perfect(int num)
{
    int i, sum=0;
    for(i=1; i<num; i++)
    {
        if(num % i == 0)
            sum += i;
    }

    return sum == num;

}

int main()
{
    int num;

    printf("Enter a  number: ");
    scanf("%d", &num);

    if(Perfect(num))
        printf("Perfect Number\n");
    else
        printf("Not Perfect Number\n");
    
    return 0;
}