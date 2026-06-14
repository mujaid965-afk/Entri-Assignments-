/* Write a C program that finds all pairs of elements in an array whose sum equals 
a given target value. 
Description: The program should prompt the user to enter the size of the array, its 
elements, and a target sum. It must then examine all possible pairs of elements in the 
array and identify every pair whose sum matches the target. Each valid pair should be 
printed on the screen. If no such pair exists, an appropriate message should be 
displayed. The same element should not be paired with itself. 
Pre-requisites: Arrays, Nested Loops, Conditional Statements. */

#include <stdio.h>

int main()
{
    int arr[100];
    int n, target;
    int i, j;
    int found = 0;

    printf("enter size: ");
    scanf("%d", &n);

    printf("enter elements:\n");

    for(i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("enter target sum: ");
    scanf("%d", &target);

    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(arr[i] + arr[j] == target)
            {
                printf("(%d, %d)\n", arr[i], arr[j]);
                found = 0;
            }
        }
    }

    if(!found)
    {
        printf("No pair found\n");
    }

    return 0;
}
