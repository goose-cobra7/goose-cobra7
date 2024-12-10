#include <stdio.h>
int main()
{
    int n;
    printf("enter n for n!\n");
    scanf("%d", &n);//enter the value of n
    int result = 1; //initializing result to 1
    for (int i = 1; i <= n; i++)//running loop from 1 to n
    {
        result *= i; //result = 1*2*3*4*...*n
    }
    printf("%d! = %d\n", n, result);//printing the result
}