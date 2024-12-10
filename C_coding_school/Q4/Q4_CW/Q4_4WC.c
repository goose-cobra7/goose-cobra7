
#include <stdio.h>

void main()
{
    int num;
    int sum = 0;
    while (num > 0)
    {
        
        printf("Enter a positive integer: ");
        scanf("%d", &num);
        if (num <= 0) break;
        sum += num;
    } 
    printf("The sum of all positive integers entered is: %d", sum);
}