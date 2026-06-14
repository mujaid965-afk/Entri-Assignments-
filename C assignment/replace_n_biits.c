/*Write a C program that takes a number and replaces n of its bits, starting from a 
given position, with another set of n bits from a second number. 
Description: The program should prompt the user to enter two integers, a starting bit 
position, and the number of bits n to be modified. It must then clear $n$ bits in the 
first number at the specified position and replace them with the corresponding $n$ 
bits from the second number. The final resulting value should be displayed on the 
screen while all other bits in the first number remain unchanged. 
Pre-requisites: Bitwise Operators */

#include <stdio.h>

int replaceBits(int num1, int num2, int pos, int n)
{
    int mask, extractedBits;

    mask = ((1 << n) - 1);
    extractedBits = num2 & mask;

    num1 = num1 & ~(mask << pos);
    num1 = num1 | (extractedBits << pos);

    return num1;
}

int main()
{
    int num1, num2, pos, n, result;

    printf("enter first number: ");
    scanf("%d", &num1);

    printf("enter second number: ");
    scanf("%d", &num2);

    printf("Enter starting position: ");
    scanf("%d", &pos);

    printf("Enter number of bits to replace (n): ");
    scanf("%d", &n);

    result = replaceBits(num1, num2, pos, n);

    printf("Result after replacing bits = %d\n", result);

    return 0;
}