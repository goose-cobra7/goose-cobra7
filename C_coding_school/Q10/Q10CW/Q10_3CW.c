#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//64 - 90
char* return_upper(char const *string);
int main(int argc, char const *argv[])
{
    printf("enter your string:");
    char string[100]; 
    fgets(string, sizeof(string), stdin);
    char *upper = return_upper(string);
    puts(upper);
    return 0;
}

char* return_upper(char const *string)
{
    int length = strlen(string); 
    char *upper = (char*) malloc(length); // allocate memory for the upper string
    size_t j = 0;//counter for the upper string
    for (int i = 0; i < length; i++)
    {
        if (string[i] > 64 && string[i] < 90)
        {
            upper[j] = string[i]; //move it to the upper the string
            j++;
        }
        
    }
    upper[j] = '\0'; //end the line
    return upper;
}
