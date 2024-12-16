#include <stdio.h>
#include <math.h>
#define ORDER 3 // 3 = X^3 + X^2 + X + a

int main()// main function starts execution here
{
    int puli[ORDER + 1]; // array to store coefficients of polynomial
    for (int i = 0; i < ORDER + 1; i++) // array to store coefficients of polyn
    {
        printf("enter coefficient a%d : ", i);
        scanf("%d", &puli[i]);
    } 
    printf("\nenter value of x : ");
    int x;
    scanf("%d", &x);
    int sum = 0;
    for (int i = 1; i < ORDER + 1; i++)
    {
        sum += pow(x, i)*puli[i]; // calculate the coefficient for each polynomial and sum it
    }
    sum += puli[0]; // add the number in the coefficient a0 (no X)
    printf("p(%d) = %d: ",x, sum);
    return 0;
}
