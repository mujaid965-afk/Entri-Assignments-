#include <stdio.h>

int main()
{
 int a, b, pos, n;

 printf("Enter first number: ");
 scanf("%d", &a);

 printf("Enter second number: ");
 scanf("%d", &b);

 printf("Enter position and n: ");
 scanf("%d%d", &pos, &n);

 int mask = ((1 << n) - 1) << pos;

 a = a & (~mask);
 a = a | ((b << pos ) & mask);

 printf("Result = %d\n", a);
 return 0;
}