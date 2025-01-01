#include <stdio.h>
#include <string.h>
int Upper_case_counter(char string[]);
int main()
{
    char string[100];
    printf("enter a string");
    fgets(string,100,stdin);
    printf("the number of upper case letters is: %d",Upper_case_counter(string));
}

int Upper_case_counter(char string[])
{
    int counter = 0;
    int i = 0;
    while (string[i] != '\n')
    {
        if (string[i] >= 'A' && string[i] <= 'Z')
        {
            counter++;
        }
        i++;
    }
    
    return counter;
}
