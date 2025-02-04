#include <stdio.h>
int greatersum(int A[], int N);
int main(int argc, char const *argv[])
{
    int array[] = {6, 1, 3, 1, 2, 5, 10};
    printf("%d\n", greatersum(array, 7));
    return 0;
}

int sum(int x, int y)
{
    return x + y;
}

int greatersum(int A[], int N)
{
    int i = 0, j = N -1;
    int sumi = A[i], sumj = A[j];
    while (i < j)
    {
        if (sumi <= sumj)
        {
            sumi += A[i++];
        }else
        {
            sumj += A[j--];
        }
    }
    return i+1;
}