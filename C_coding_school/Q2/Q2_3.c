#include <stdio.h>

void main()
{
    int num1,num2,num3,num4;
    num1 = 1;
    num2 = 1;
    num3 = -3;
    num4 = 5;
    printf("enter 4 integers: %d %d %d %d\n",num1,num2,num3,num4);
    int num_sum = 0;
    num_sum = num_sum + ((num1*num1)%2);
    num_sum = num_sum + ((num2*num2)%2);
    num_sum = num_sum + ((num3*num3)%2);
    num_sum = num_sum + ((num4*num4)%2);
    num_sum = 4 - num_sum;
    printf("the number of even integers is %d",num_sum);
}