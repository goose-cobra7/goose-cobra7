#include <stdio.h>
#include <math.h>
#define ORDER 10 // 3 = X^3 + X^2 + X + a

int Horner_rule();
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
    int sum = puli[ORDER];
    for (int i = ORDER; i > 0; i--)
    {
        sum = sum * x + puli[i-1]; // Horner's rule to evaluate polynomial at x
    }
    
    printf("p(%d) = %d: ",x, sum);
    return 0;
}
