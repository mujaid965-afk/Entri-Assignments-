/*  Write a C program that takes two integers and swaps n bits starting from a given 
position in both numbers. 
Description: The program should prompt the user to enter two integers, a starting bit 
position, and the number of bits (n) to be swapped. It must then exchange the n 
consecutive bits at the specified position between the two numbers — the bits from 
the first number go into the second, and vice versa — while all remaining bits in both 
numbers stay exactly as they were. Both final values should be displayed on the 
screen after the swap. 
Pre-requisites: Bitwise Operators, Loops, Assignment Operators.*/

#include <stdio.h>
int main()
{
    int a, b, pos, n;

    printf("Enter  two numbers: ");
    scanf("%d%d",&a, &b);

    printf("Enter position and n: ");
    scanf("%d%d", &pos, &n);

    int mask = ((1 << n) - 1);

    int bits1 = (a >> pos) & mask;
    int bits2 = (b >> pos) & mask;

    int xor = bits1 ^ bits2;

    a ^= (xor << pos);
    b ^= (xor << pos);

    printf("After Swap:\n");
    printf("a = %d\n", a);
    printf("b = %d\n", b);

    return 0;
}
