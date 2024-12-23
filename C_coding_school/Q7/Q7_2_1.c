#include <stdio.h>

#define SIZE_1 4
#define SIZE_2 4
#define SIZE_RESULT SIZE_1+SIZE_2

float arr_res[SIZE_RESULT];
float arr[SIZE_1];
float arr2[SIZE_2];

int unique_element(float arr[],float arr2[],float arr_res[],int size,int size2)
{
    float temp_arr[SIZE_1];
    int tmp_count = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            if (arr[i] == arr2[j])
            {
                temp_arr[tmp_count++] = arr[i];
            }else{
                
            }
        }
        
    }
    for (int i = 0; i < SIZE_RESULT; i++)
    {
        arr_res[i] = arr[i];
        arr_res[i+1] = arr2[i];
        
    }
    for (int i = 0; i < SIZE_RESULT; i++)
    {
        for (int j = 0; j < tmp_count; j++)
        {
            if (temp_arr[j] == arr_res[i])
            {
                arr_res[i] = 0; //remove duplicate elements
            }
            
        }
        
    }
    
    
    
    return 0;
}
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
    inti_array(arr,SIZE_1);
    print_array(arr, SIZE_1);
    inti_array(arr2,SIZE_2);
    print_array(arr2, SIZE_2);
    float arr_res[SIZE_RESULT];
    unique_element(arr, arr2, arr_res, SIZE_1, SIZE_2);
    printf("the new array with unique elements\n");
    print_array(arr_res, SIZE_RESULT);
    return 0;
}
