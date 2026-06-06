#include <stdio.h>

int main()
{
    int num, pos, n;

    printf("Enter number: ");
    scanf("%d", &num);

    printf("Enter starting position (0-indexed) and number of bits to extract: ");
    scanf("%d %d", &pos, &n);

    int mask = (1 << n) - 1;
    int extracted_bits = (num >> pos) & mask;

    printf("Extracted value: %d\n", extracted_bits);

    return 0;
}