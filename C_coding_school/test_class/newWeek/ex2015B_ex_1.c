#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int N;
    printf("enter N: ");
    scanf("%d",&N);
    int *arr = calloc((N+1)*sizeof(int),0);
    if(arr == NULL){printf("memory out!!!");exit(1);}//check memory allo'
    printf("enter numbers:\n");
    int tmp = -1;
    do//let user enter numbers
    {
        scanf("%d",&tmp);
        arr[tmp]++;//in the place add 1
    } while (tmp != -1);//is it over
    for (size_t i = 0; i < N; i++)//print all
    {
        if (arr[i] > 0 )//all num that acur more them 1
        {
            printf("%d,%d\n",i,arr[i]);
        }
        
    }
    
    return 0;
}

