#include <stdio.h>
void reverse(char *string);
int string_count(const char *string);

int main()
{
    printf("enter your string: ");
    char string[100];
    fgets(string, sizeof(string), stdin);
    reverse(string);
    printf("reversed string is: %s", string);
    return 0;
}

int string_count(const char *string)
{
    int i = 0;
    while (*string != '\n')
    {
        i++;
        string++;
    }
    return i;
}

//Reverse a String: Create a program that reverses a given string.
void reverse(char *string)
{
    int Leangh = string_count(string);
    char temp[Leangh];
    int i, j = Leangh - 1;
    for (int i = 0; i < Leangh; i++)
    {
        temp[i] = string[j];
        j--;
    }
    for (int i = 0; i < Leangh; i++)
    {
        string[i] = temp[i];
    }
}
