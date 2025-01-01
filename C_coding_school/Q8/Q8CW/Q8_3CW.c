#include <stdio.h>
#include <string.h>

int find_last_char(char string[], char chr)
{
    for (int i = strlen(string)-1; i >=0; i--)
    {
        if (string[i] == chr)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    char string[100];
    printf("enter a string");
    fgets(string,100,stdin);
    printf("enter a character");
    char chr;
    scanf("%c", &chr);
    printf("last character of string is %d\n", find_last_char(string,chr));
    return 0;
}
