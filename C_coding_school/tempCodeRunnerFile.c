#include<stdio.h>

void main()
{
    int grade;
    do
    {
        printf("enter");
        scanf("%d",&grade);
    } while (grade <= 0 || grade >= 100);
    printf("you enter valid grade %d",grade);
    for (grade;grade > 0;grade--)
    {
        printf("%d\n",grade);
    }
}