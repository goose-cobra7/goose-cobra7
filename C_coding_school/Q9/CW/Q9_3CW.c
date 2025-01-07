#include <string.h>
#include <stdio.h>

#define MAX_STRING_LENGTH 1024

int print_last_word(const char *string);
int main()
{
    char string[MAX_STRING_LENGTH];
    printf("Enter a string: ");
    fgets(string, 1024, stdin); // "1024" number of characters in string, "stdin" standard input (keyboard input)
    print_last_word(string); // prints
    return 0;
}

int print_last_word(const char *string)
{
    int length = strlen(string);
    int i;
    i = length;
    while (string[i] != ' ')
    {
        i--;
    }
    
    for (i; i < length; i++)
    {
        printf("%c", string[i]);
    }
    
}
