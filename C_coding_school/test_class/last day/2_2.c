#include <stdio.h>

int find_max(int *arr,int N);

int main(int argc, char const *argv[])
{
    int arr[] = {1,2,3,4,2,3,2};
    printf("%d",find_max(arr,7));
    return 0;
}

int find_max(int *arr,int N)
{
    if(N==0){return 0;}
    int max_next = find_max(arr+1,N-1);
    int max = arr[0];
    return (max > max_next)? max: max_next;
}