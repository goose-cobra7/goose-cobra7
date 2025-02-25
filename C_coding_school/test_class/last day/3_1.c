#include <stdlib.h>
#include <stdio.h>
void flip_me(int *arr,int N);

int main(int argc, char const *argv[])
{
    int arr[] = {1,2,3,4,5,6,7};
    flip_me(arr,7); 
    return 0;
}

void flip_me(int *arr,int N)
{
    if (N == 1)
    {
        printf("%d,",arr[0]);
        return;
    }
    flip_me(arr+1,N-1);
    printf("%d,",arr[0]);
    return;
}