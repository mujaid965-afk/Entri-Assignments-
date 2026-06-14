/*  Write a C program that uses an array to find the second largest and second 
smallest element in a list of numbers. 
Description: The program should prompt the user to enter the size of the array and its 
elements. It must then scan through the array and determine both the second largest 
and second smallest values without sorting the array. The program should handle 
duplicate values correctly — if all elements are the same, it should display an 
appropriate message. Both results should be displayed on the screen. 
Pre-requisites: Arrays, Loops, Conditional Statements.*/

#include <stdio.h>
#include <limits.h>

int main()
{
    int arr[100], n, i;
    int largest = INT_MIN;
    int secondLargest = INT_MIN;
    int smallest = INT_MAX;
    int secondSmallest = INT_MAX;

    printf("Enter size: ");
    scanf("%d", &n);

    printf("enter elements:\n");

    for(i= 0; i<n; i++)
    {
        scanf("%d", &arr[i]);

        if(arr[i] > largest)
        {
            secondLargest = largest;
            largest = arr[i];
        }
        else if(arr[i] > secondLargest && arr[i] != largest)
        {
            secondLargest=arr[i];
        }

        if(arr[i] < smallest)
        {
            secondSmallest = smallest;
            smallest = arr[i];
        }
        else if(arr[i] < secondSmallest && arr[i] != smallest)
        {
            secondSmallest = arr[i];
        }
    }

    if(secondLargest == INT_MIN || secondSmallest == INT_MAX)
    {
        printf("no second largest/smallest exists\n");
    }
    else
    {
        printf("Second Largest = %d\n", secondLargest);
        printf("Second Smallest = %d\n", secondSmallest);
    }

    return 0;
}