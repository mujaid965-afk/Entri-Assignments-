#include <stdio.h>
#include <ctype.h>

int main()
{
    char str[500];
    int alpha[26] = {0};
    int i;

    printf("Enter sentence: ");
    fgets(str, sizeof(str), stdin);

    for(i=0; str[i] != '\0';i++)
    {
        if(isalpha(str[i]))
        {
            alpha[tolower(str[i]) - 'a'] = 1;
        }
    }
    for(i=0; i< 26; i++)
    {
        if(alpha[i] == 0)
        {
            printf("Not pangram\n");
            return 0;
        }
    }
    printf("pangram\n");
    return 0;
}