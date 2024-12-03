#include <stdio.h>

void main()
{
    printf("enter integer between 1 and 20:");
    int num;
    int sum = 0;
    scanf("%d",&num);
    for (int i = 0; i <= num; i++)
    {
        sum += i;
    }
    printf("the sum of the first %d natural numbers is: %d\n", num, sum);
    
}