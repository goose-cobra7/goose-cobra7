#include <stdio.h>

#define SIZE_STR 6

int print_bigger(int *string, int size);
void main()
{
    printf("enter string of number:");
    int string[SIZE_STR];
    for (int i = 0; i < SIZE_STR; i++)
    {
        scanf("%d", &string[i]);
    }
    for (int i = 0; i < SIZE_STR; i++)
    {
        printf("%d", string[i]);
    }
    printf("\n");
    print_bigger(string, SIZE_STR);
}

int print_bigger(int *string, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (string[i] > string[i + 1])
        {
            printf("%d", string[i - 1]);
        }
        
    }
       
}