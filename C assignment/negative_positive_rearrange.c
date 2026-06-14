/*Write a C program that rearranges an array such that all negative numbers 
appear before all positive numbers while preserving the relative order of both 
groups. 
Description: The program should prompt the user to enter the size of the array and its 
elements (a mix of positive and negative integers). It must then rearrange the elements 
so that all negative numbers come first, followed by all positive numbers, without 
changing the order in which the negatives appear among themselves or the positives 
among themselves. Zero can be treated as positive. The rearranged array should be 
displayed on the screen. 
Pre-requisites: Arrays, Loops, Temporary Storage, Order Preservation Logic.*/

#include <stdio.h>

int main()
{
    int n;

    printf("enter the size of array: ");
    scanf("%d", &n);

    int arr[n], result[n];
    int i, k=0;

    printf("enter the elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    /* Store negative numbers first */
    for(i = 0; i < n; i++)
    {
        if(arr[i] < 0)
        {
            result[k++] = arr[i];
        }
    }

    /* Store positive numbers and zero */
    for(i=0; i<n; i++)
    {
        if(arr[i] >= 0)
        {
            result[k++] = arr[i];
        }
    }

    printf("\nRearranged Array:\n");
    for(i=0; i<n; i++)
    {
        printf("%d ", result[i]);
    }

    return 0;
}
