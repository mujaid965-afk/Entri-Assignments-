/* Write a C program that uses functions to evaluate a simple arithmetic expression 
given two numbers and an operator. 
Description: The program should prompt the user to enter two floating-point 
numbers and an arithmetic operator (+, -, *, /). A separate function must be written for 
each operation (add, subtract, multiply, divide). A selector function should take the 
operator as a parameter and call the appropriate function, returning the result to main. 
Division by zero must be handled gracefully inside the divide function. 
Pre-requisites: Functions, Switch/Conditionals, Float Arithmetic, Error Handling. */

#include <stdio.h>

float add(float a, float b)
{
    return a + b;
}
float sub(float a, float b)
{
    return a - b;
}
float mul(float a, float b)
{
    return a * b;
}
float div(float a, float b)
{
    if(b == 0)
    {
        printf("Division by zero is not possible\n");
        return 0;
    }
    else{
        return a / b;
    }
}
int main()
{
    float a, b;
    char op;

    printf("Enter expression (a op b): ");
    scanf("%f %c %f",&a, &op, &b);

    switch(op)
    {
        case '+':
            printf("Result = %.2f\n", add(a, b));
            break;
        case '-':
            printf("Result = %.2f\n", sub(a, b));
            break;
        case '*':
            printf("Result = %.2f\n", mul(a, b));
            break;
        case '/':
            printf("Result = %.2f\n", div(a, b));
            break;
        default:
            printf("invalid operator\n");
    }
    return 0;
}


