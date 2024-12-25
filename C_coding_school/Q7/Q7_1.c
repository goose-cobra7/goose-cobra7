#include <stdio.h>

#define SIZE 3

void inti_array(float arr[],int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Enter number %d: ", i + 1);
        scanf("%f", &arr[i]);
    }
}

void print_array(float arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("[%.3f] ", arr[i]); //print format [0.0000] [0.0000] ...
    }
    printf("\n");
}


int main()
{
    float arr[SIZE];
    printf("*inside inti_array*\n");
    inti_array(arr,SIZE);
    printf("*inside print_array*\n");
    print_array(arr, SIZE);
    return 0;
}
