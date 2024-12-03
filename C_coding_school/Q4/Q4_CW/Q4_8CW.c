#include <stdio.h>

int athert(int number)
{
    int sum =number;
    for (int i = number - 1; i > 0; i--)
    {
        sum = sum * i;
        printf("%d*",i);
    }   
    return sum;
}
void main()
{
    int number;
    scanf("%d",&number);
    printf("=%d",athert(number));
}