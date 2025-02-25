#include <stdio.h>
#include <math.h>

int convertToDecimal(const int *arr,int size);

int main(int argc, char const *argv[])
{
    int arr[] = {1,0,0,1,1,0};
    int temp = convertToDecimal(arr,6);
    printf("%d",temp);
    return 0;
}

int convertToDecimal(const int *arr,int size)
{
    if (size == 0){return 0;}
    return (arr[0] * pow(2,size-1)) + convertToDecimal(arr+1,size-1);
}