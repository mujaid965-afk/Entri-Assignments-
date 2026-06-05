#include <stdio.h>

int main()
{
    int num, i=0, j;
    char str[20];

    printf("enter integer: ");
    scanf("%d", &num);

    int temp = num;

    while (temp > 0)
    {
        str[i++] = (temp % 10) + '0';
        temp /= 10;
    }

    str[i] = '\0';

    for(j=0; j<i/2; j++)
    {
        char t = str[j];
        str[j] = str[i-j-1];
        str[i-j-1] = t;

    }
    printf("string = %s\n", str);
}