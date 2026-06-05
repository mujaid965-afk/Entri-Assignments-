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