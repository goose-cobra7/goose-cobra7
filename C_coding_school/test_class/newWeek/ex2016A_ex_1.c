#include <stdio.h>
#include <stdlib.h>

int diffrent_nums(int arr[],int len);

int main(int argc, char const *argv[])
{
    int arr[] = {1,2,3,4,6,6,7,7,8,9,1};//11
    diffrent_nums(arr,11);
    return 0;
}

int diffrent_nums(int arr[],int len)
{
    int checker = 0;
    for (size_t i = 0; i < len; i++)
    {
        checker = 0;
        for (size_t j = i+1; j < len; j++)
        {
            if (arr[j] == arr[i])
            {
                checker = 1;
                break;
            }
            
        }
        if (checker == 1)
        {
            printf("%d,",arr[i]);
        }
        
    }
    
}