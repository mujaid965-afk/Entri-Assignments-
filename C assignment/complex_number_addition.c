/*  Define a structure Complex with real and imaginary parts. Write a C program to add 
two complex numbers and display the result. 
Description: The program should define a structure to represent a complex number 
with two members: real part and imaginary part. It must then create functions to 
perform addition of two complex numbers and to display a complex number in a 
readable format (e.g., a + bi). The program should take input for two complex 
numbers, compute their sum using the defined function, and print the result. 
Pre-requisites: Structures, Functions, Basic Arithmetic Operations, Input/Output */

#include <stdio.h>

/* Structure Definition */
struct Complex
{
    float real;
    float imag;
};

/* Function to Add Two Complex Numbers */
struct Complex addComplex(struct Complex c1, struct Complex c2)
{
    struct Complex sum;

    sum.real = c1.real + c2.real;
    sum.imag = c1.imag + c2.imag;

    return sum;
}

/* Function to Display a Complex Number */
void displayComplex(struct Complex c)
{
    printf("%.2f + %.2fi\n", c.real, c.imag);
}

int main()
{
    struct Complex num1, num2, result;

    printf("enter real and imaginary part of first complex number: ");
    scanf("%f %f", &num1.real, &num1.imag);

    printf("enter real and imaginary part of second complex number: ");
    scanf("%f %f", &num2.real, &num2.imag);

    result = addComplex(num1, num2);

    printf("\nFirst Complex number  : ");
    displayComplex(num1);

    printf("Second Complex number : ");
    displayComplex(num2);

    printf("Sum of Complex numbers: ");
    displayComplex(result);

    return 0;
}