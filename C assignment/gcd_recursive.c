/* Write a C program that uses a recursive function to find the GCD of two 
numbers using the Euclidean algorithm. 
Description: The program should prompt the user to enter two positive integers. A 
recursive function must be written that repeatedly applies the Euclidean method  
replacing the larger number with the remainder of dividing the two until the 
remainder is zero. The GCD should be returned to the main function and displayed on 
the screen. 
Pre-requisites: Functions, Recursion, Modulus Operator.*/

#include <stdio.h>

int gcd(int a, int b)
{
    if(b == 0)
        return a;
    return gcd(b, a % b);

}

int main()
{
    int a, b;

    printf("Enter two Numbers: ");
    scanf("%d%d", &a, &b);

    printf("GCD = %d\n", gcd(a, b));

    return 0;
}