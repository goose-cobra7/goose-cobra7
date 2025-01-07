#include <stdio.h>

#define SIZE_STR 6

int Max_Number(int *str, int *results);
void main()
{
    printf("enter string of number");
    int results[2];
    int str[SIZE_STR];
    for (int i = 0; i < SIZE_STR; i++)
    {
        scanf("%d", &str[i]);
    }
    Max_Number(str, results);
    printf("max: %d\n", results[0]);
    printf("min: %d", results[1]);
}

int Max_Number(int *str, int *result)
{
    int max = str[0];
    for (int i = 1; i < SIZE_STR; i++)
    {
        if (str[i] > max)
            max = str[i];
    }
    int min = str[0];
    for (int i = 1; i < SIZE_STR; i++)
    {
        if (str[i] < min)
            min = str[i];
    }
    result[0] = max;
    result[1] = min;
}