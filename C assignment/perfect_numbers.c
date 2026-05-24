#include <stdio.h>

int Perfect(int num)
{
    int i, sum=0;
    for(i=1; i<num; i++)
    {
        if(num % i == 0)
            sum += i;
    }

    return sum == num;

}

int main()
{
    int num;

    printf("Enter a  number: ");
    scanf("%d", &num);

    if(Perfect(num))
        printf("Perfect Number\n");
    else
        printf("Not Perfect Number\n");
    
    return 0;
}