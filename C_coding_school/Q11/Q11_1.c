#include <stdio.h>
#include <stdlib.h>

#define MAX_number 1000

char* myltoa(int num);
int main()
{
    printf("please enter number: ");
    int num;
    char *string;
    scanf("%d", &num);
    string = myltoa(num);
    printf("string: %s\n", string);
    free(string); // Free the allocated memory
    return 0;
}

char* myltoa(int num)
{
    int count = 0;
    int holder = 0;
    char temp_array[MAX_number];
    
    if (num == 0) 
    {
        char *string = malloc(2 * sizeof(char));
        string[0] = '0';
        string[1] = '\0';
        return string;
    }

    if (num < 0)
    {
        holder = 1;
        num = -num;
    }
    
    while (num > 0)
    {
        temp_array[count++] = num % 10 + '0';
        num /= 10;
    }

    char *string = malloc((count + holder + 1)*sizeof(char)); 
    int i;
    for (i = 0; i < count; i++)
    {
        string[i + holder] = temp_array[count - i - 1];
    }
    if (holder == 1)
    {
        string[0] = '-';
    }

    string[count + holder] = '\0'; 

    return string;
}
