/*  Write a C program that rotates the elements of an array by n positions in a 
specified direction. 
Description: The program should prompt the user to enter the array elements, the 
number of positions (n) to rotate, and the direction (left or right). It must then shift the 
elements accordingly — elements that fall off one end should reappear at the opposite 
end. The rotation must work for any value of n, including values larger than the array 
size. The final rotated array should be displayed on the screen. 
Pre-requisites: Arrays, Loops, Modulus Operator.*/

#include <stdio.h>

int main()
{
    int arr[100], temp[100];
    int n, r, i;
    char dir;
    printf("enter size: ");
    scanf("%d", &n);

    printf("enter elements: ");

    for(i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("enter number of rotations: ");
    scanf("%d", &r);

    printf("enter direction (L/R): ");
    scanf("%c", &dir);

    r = r%n;

    if(dir == 'L' | dir == 'R')
    {
        for(i=0; i<n; i++)
        {
            temp[i] = arr[(i+r)%n];
        }
    }
    else
    {
        for(i=0; i<n; i++)
        {
            temp[(i+r)%n] = arr[i];
        }
    }
    printf("Rotated array:\n");
    for(i=0; i<n; i++)
    {
        printf("%d", temp[i]);
    }

    return 0;
}