#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, i;

    printf("please enter N\n");
    scanf("%d", &N);

    int *ptr2arry = (int *)calloc(4 * (N+1), sizeof (int)); //element i will include no. of times i was read

    if (ptr2arry == NULL) { printf("Error"); exit(0); }

    printf("enter a series of numbers ending with 99\n");

    do {
        scanf("%d", &i);
        if (i != 99) ptr2arry[i]++; 
    } while (i != 99);

    for (i = 0; i <= N; i++)
        if (ptr2arry[i] > 1) printf("%d %d\n", i, ptr2arry[i]);

    free ((int*) ptr2arry);
    return 0;
}
