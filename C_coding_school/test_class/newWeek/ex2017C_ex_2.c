#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("enter N for 0 - N number:");
    int N;
    scanf("%d",&N);
    int *arr = malloc(N*sizeof(int));
    for (size_t i = 0; i < N; i++){arr[i] = 0;}
    int temp;
    printf("enter num ending with 99:");
    do
    {
        scanf("%d",&temp);
        if (temp == 99){break;}
        (arr[temp])++;
    } while (1);
    for (size_t i = 0; i < N; i++)
    {
        if (arr[i] > 1)
        {
            printf("%d,",i);
        }
    }
    return 0;
}

