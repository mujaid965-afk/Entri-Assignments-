#include <stdio.h>

int main()
{
    char str[200], result[200];
    int i = 0, j = 0;

    printf("enter string: ");
    fgets(str, sizeof(str), stdin);

    while(str[i] != '\0') 
    {
        if(!(str[i] == ' ' && str[i + 1] == ' ')) 
        {
            result[j++] = str[i];
        }
        i++;
    }

    result[j] = '\0';
    printf("Result: %s", result);
    return 0;
}