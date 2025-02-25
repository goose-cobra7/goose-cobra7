#include <stdio.h>
int find_max(int arr[],int size);

int main(int argc, char const *argv[])
{
    int arr[] = {1,2,3,4,5,5,4,1};
    printf("%d",find_max(arr,8));   
    return 0;
}

int find_max(int arr[],int size)
{
    if(size == 1){return arr[0];}
    int max_inRest = find_max(arr+1,size-1);
    return (max_inRest > arr[0])? max_inRest:arr[0];
}