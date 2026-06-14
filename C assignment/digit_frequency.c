/* Write a C program that uses a function to count the frequency of each digit (0–9) 
in a given integer. 
Description: The program should prompt the user to enter an integer. A separate 
function must be written that takes the number, extracts each digit using a loop, and 
updates a frequency array accordingly. The function should not return a single value 
but instead update the array directly. The main function should then print how many 
times each digit appears in the number. 
Pre-requisites: Functions, Arrays, Loops, Pass by Reference (Pointers). */

#include <stdio.h>

void frequency(int num, int freq[])
{
    int digit;
    while(num != 0)
    {
        digit = num % 10;
        freq[digit]++;
        num /= 10;
    }
}

int main()
{
    int num, i;
    int freq[10] = {0};

    printf("Enter a number: ");
    scanf("%d", &num);

    frequency(num, freq);

    for(i=0; i<10; i++)
    {
        printf("%d occurs %d times\n", i, freq[i]);
    }

return 0;
}