#include <stdio.h>

int main() {
    int num, pos, n;

    printf("Enter the integer: ");
    scanf("%d", &num);

    printf("Enter the starting bit position (0-indexed): ");
    scanf("%d", &pos);

    printf("Enter the number of bits to toggle: ");
    scanf("%d", &n);

    int mask = ((1 << n) - 1) << pos;
    int result = num ^ mask;

    printf("Original number: %d\n", num);
    printf("Result after toggling: %d\n", result);

    return 0;
}