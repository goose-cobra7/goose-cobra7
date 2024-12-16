#include <stdio.h>
#define SIZE 10
int array[SIZE];
int temp[SIZE];
int print_array(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}

int main()
{
    
    for (int i = 0; i < SIZE; i++)
    {
        array[i] = i;
        temp[i] = 0;
    }
    int temp_count = SIZE - 1;
    for (int i = 0; i < SIZE; i++)
    {
        temp[temp_count] = array[i];
        temp_count--;
    }
    printf("Original Array: ");
    print_array(array, SIZE);
    printf("\nReversed Array: ");
    print_array(temp, SIZE);
    return 0;
}

