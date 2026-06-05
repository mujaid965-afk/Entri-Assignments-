#include <stdio.h>

void convert(int num, int base)
{
    char result[50];
    int i =0, rem;

    while(num > 0)
    {
        rem = num % base;
        if(rem < 10)
            result[i++] = rem + '0';
        else
            result[i++] = rem - 10 + 'A';
        
        num /= base;
    }

    printf("Converted number: ");

    while(i > 0)
        printf("%c", result[--i]);

    printf("\n");

}

int main()
{
    int num, base;
    printf("Enter decimal number: ");
    scanf("%d", &num);

    printf("Enter base (2-16): ");
    scanf("%d", &base);

    convert(num, base);

    return 0;
}