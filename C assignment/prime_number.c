#include <stdio.h>

int main()
{
    int num, i, flag = 1;

    printf("Enter the Number: ");
    scanf("%d", &num);

    if(num <= 1)
        flag = 0;

    for(i=2;i <= num/2; i++){
        if(num % i == 0)
        {
            flag = 0;
            break;
        }
    }

    if(flag)
    {
        printf("Prime Number\n");
    }else
    {
        printf("Not a Prime Number\n");
    }

    return 0;
}
