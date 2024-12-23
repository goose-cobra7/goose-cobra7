#include <stdio.h>

#define SIZE_1 4
#define SIZE_2 4
#define SIZE_RESULT SIZE_1+SIZE_2

float arr_res[SIZE_RESULT];
float arr[SIZE_1];
float arr2[SIZE_2];
float result[(SIZE_RESULT)/2];
int conjoined_elements(float arr1[], float arr2[],float result[], int arr_size1, int arr_size2)
{
    int count = 0;
    for (int i = 0; i < arr_size1; i++)
    {
        for (int j = 0; j < arr_size2; j++)
        {
            if (arr1[i] == arr2[j])
            {
                result[count] = arr2[j];
                count++;
            }
            
        }
        
    }
    
}

int unique_element(float arr[],float arr2[],float arr_res[],int size,int size2)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        int is_duplicate = 0; //default is false
        for (int j = 0; j < size2; j++)
        {
            if (arr[i] == arr2[j])
            {
                is_duplicate = 1; //change to true 
                break;
            }
        }
        if (is_duplicate == 0) //only if is_duplicate is true (1)
        {
            arr_res[count] = arr[i];
            count++;
        }
    }
    for (int i = 0; i < size2; i++)
    {
        int is_duplicate = 0; //default is false
        for (int j = 0; j < size; j++)
        {
            if (arr2[i] == arr[j])
            {
                is_duplicate = 1; //change to true 
                break;
            }
        }
        if (is_duplicate == 0) //only if is_duplicate is true (1)
        {
            arr_res[count] = arr2[i];
            count++;
        }
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
    int i = 0;
    while (arr[i] != 0)
    {
        printf("[%.2f] ", arr[i]);
        i++;
    }

    printf("\n");
    return 0;
}


int main()
{
    inti_array(arr,SIZE_1);
    print_array(arr, SIZE_1);
    inti_array(arr2,SIZE_2);
    print_array(arr2, SIZE_2);
    float arr_res[SIZE_RESULT];
    unique_element(arr, arr2, arr_res, SIZE_1, SIZE_2);
    conjoined_elements(arr, arr2, result, SIZE_1, SIZE_2);
    printf("*unique array*\n");
    print_array(arr_res, SIZE_RESULT);
    printf("*conjoined array*\n");
    print_array(result, (SIZE_RESULT)/2);
    return 0;
}
