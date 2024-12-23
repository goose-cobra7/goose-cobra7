#include <stdio.h>

#define SIZE 3

int inti_array(float arr[],int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Enter number %f: ", i + 1);
        scanf("%f", &arr[i]);
    }
    return 0;
}

int print_array(float arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("[%.3f] ", arr[i]); //print format [0.0000] [0.0000] ...
    }
    printf("\n");
    return 0;
}


int main()
{
    float arr[SIZE];
    inti_array(arr,SIZE);
    print_array(arr, SIZE);
    return 0;
}
