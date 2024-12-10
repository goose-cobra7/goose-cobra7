#include <stdio.h>
#define ARRAY_SIZE 10

int main()
{
    int arr[ARRAY_SIZE];
    for (int i = 0; i < 10; i++)
    {
        arr[i] = 1+i;
    }
    arr[1] = 9;
    int temp = arr[2];
    int temp2 = arr[6];
    arr[6] = temp;
    arr[2] = temp2;
    float sum=0;
    for (int i = 0; i < 10; i++)
    {
        sum += arr[i];
    }
    sum = sum / ARRAY_SIZE;
    printf("Sum of the array elements: %.2f\n", sum);
    
    return 0;
}
