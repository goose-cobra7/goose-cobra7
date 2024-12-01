#include <stdio.h>
#define MAX_MULTI 10

int main()
{
    int num;
    printf("Enter a positive integer: ");
    scanf("%d",&num);//we get the input from user
    for (int i = 0; i < MAX_MULTI; i++)//we range the loop from 0 to MAX_MULTI-1
    {
        printf("%d X %d = %d\n", num, i+1, num*(i+1)); //we print the multiplication table
    }
    return 0; //nothing
}
