#include <stdio.h>

#define arr1_size 5
#define arr2_size 5

float arr1[arr1_size];
float arr2[arr2_size];
float result[(arr1_size+arr2_size)/2];
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
int main()
{
    printf("Enter elements for arr1: ");
    for (int i = 0; i < arr1_size; i++)
    {
        scanf("%f", &arr1[i]);
    }
    
    printf("Enter elements for arr2: ");
    for (int i = 0; i < arr2_size; i++)
    {
        scanf("%f", &arr2[i]);
    }
    
    conjoined_elements(arr1, arr2, result, arr1_size, arr2_size);
    
    printf("Conjoined elements: ");
    for (int i = 0; i < (arr1_size+arr2_size)/2; i++)
    {
        printf("%.2f ", result[i]);
    }
    return 0;
}
