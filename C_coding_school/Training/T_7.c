#include <stdio.h>
int primeCheck(int const number);
int main()
{
    printf("enter number:");
    int number;
    scanf("%d",&number);
    if (primeCheck(number) == 0)
    {
        printf("not prime");
    }else 
    {
        printf("prime");
    }
    return 0;
}

//Prime Number Check: Write a program to check if a number is prime.
int primeCheck(int const number)
{
    if (number == 0) return 0;
    for (int i = 2; i < number/2; i++)
    {
        if (number % i == 0) return 0;
            
    }
    return 1;
}