#include <stdio.h>

int *check_even(int *arr,int size);
int print_even(int arr[],int size);

int main(int argc, char const *argv[])
{
    int arr[] = {1,4,5,6,12,2};
    int arr1[] = {1,1,33,5};
    print_even(arr,6);
    print_even(arr1,4);
    return 0;
}

int *check_even(int *arr,int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i]%2 == 0)
        {
            return arr+i;
        }
    }
    return NULL;
}

int print_even(int *arr,int size)
{
    for (int i = 0; i < size; i++)
    {
        if (check_even(arr+i,size-i))
        {
            printf("%d, ",arr[i]);
        }
        
    }
    
    
    
    
}