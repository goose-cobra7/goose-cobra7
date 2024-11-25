#include<stdio.h>

void main()
{
    int num1,num2;
    printf("enter 2 num");
    scanf("%d %d",&num1,&num2);//enter 2 num
    (num1 == num2)? printf("numbers are equal"):printf("number are unequal"); //same line (check)? case1:"else"case2
}