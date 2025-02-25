#include <stdio.h>
#include <string.h>

int grater_then_sum(int arr[],int N);

int main()
{
    int arr[] = {6,1,3,1,2,5,2}; //test array
    int temp = grater_then_sum(arr,7);
    printf("%d",temp);
    return 0;
}

int grater_then_sum(int *arr,int N)
{
    int i = 0,k = N,sumi = 0,sumk = 0;
    while (!(k<i))
    {
        if (sumi <= sumk)
        {
            sumi += arr[i];
            i++;
        }else
        {
            sumk += arr[k];
            k--;
        }
    }
    return i;
}