#include <stdio.h>
#include <string.h>

void print35(int *a,int N);

int main(int argc, char const *argv[])
{
    int N = 16;
    int arr[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,16};
    print35(arr,N);
    return 0;
}

void print35(int *a,int N)
{
    const int i = N;
    if(N == 0)
    {
        printf("* ");
        return;
        
    }
    if(a[0]%5== 0){printf("%d ",a[0]);}
    print35(a+1,N-1);
    if(a[0]%3 == 0){printf("%d ",a[0]);}
}