#include <stdio.h>

void main()
{
    int num = -1,NUM;
    int sum = 0;
    do
    {
        printf("Enter a positive integer: ");
        
        scanf("%d", &num);
    } while (num <= 0);//validate the input is positive
    
    NUM = num;//need to store the original number for later use
    printf("%d", num);
    if (num % 2 != 0) num -= 1;//make sure the number is even
    while (num > 0)
    {
        sum += num;
        num -= 2;
    }
    printf("The sum of the odd numbers from 0 to %d is: %d", NUM, sum);
    
    
}