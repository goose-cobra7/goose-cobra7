#include <stdio.h>
int array_order[10];

int array[10] = {124,122,123,123,123,123,123,123,123,123};
int reset_array(int arr[],int arr_size)
{
    for (int i = 0; i < arr_size; i++)
    {
        arr[i] = 0;
    }
}
int element_digit_count(int arr[],int arr_size)
{
    for (int i = 0; i < arr_size; i++)
    {
        array_order[arr[i]%10]++;
    }
    
}
int print_array(int arr[], int arr_size)
{
    for (int i = 0; i < arr_size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

int main(int argc, char const *argv[])
{
    print_array(array,10);
    element_digit_count(array,10);
    print_array(array_order,10);
    reset_array(array,10);
    print_array(array,10);
    return 0;
}
