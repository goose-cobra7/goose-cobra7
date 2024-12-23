#include <stdio.h>

#define ARRAY_SIZE 4
int inti_array(float arr[], int size);

int print_array(float arr[], int size);

int linear_interpolation(float arr_input[], float arr_output[], int size_input);

int main()
{
    float arr[ARRAY_SIZE];
    float arr_output[ARRAY_SIZE*2];
    inti_array(arr,ARRAY_SIZE);
    print_array(arr, ARRAY_SIZE);
    linear_interpolation(arr, arr_output,ARRAY_SIZE);
    print_array(arr_output, ARRAY_SIZE*2);
}
int linear_interpolation(float arr_input[], float arr_output[], int size_input)
{
    int output_counter = 0;
    for (int i = 0; i < size_input-1; i++)
    {
        arr_output[output_counter] = arr_input[i];
        arr_output[output_counter+1] = (arr_input[i] + arr_input[i+1]) / 2;
        arr_output[output_counter+2] = (arr_input[i+1]);
        output_counter += 2;
    }
    
}
int inti_array(float arr[],int size)
{
    printf("*inti_array*\n");
    for (int i = 0; i < size; i++)
    {
        printf("Enter number %d: ", i + 1);
        scanf("%f", &arr[i]);
    }
    return 0;
}

int print_array(float arr[], int size)
{
    for (int i = 0; i < size-1; i++)
    {
        printf("[%.2f] ", arr[i]);
    }
    

    printf("\n");
    return 0;
}

