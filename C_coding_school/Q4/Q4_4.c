#include <stdio.h>

int main()
{
    printf("enter the amount of  terms in the series: ");
    int term_amount;
    scanf("%d", &term_amount);
    double pie = 1;
    int sign = -1;
    for (int i = 3; i < term_amount; i += 2)
    {
        pie += (1.0/i * sign); //make the base value of pie
        sign *= -1; //change the sign of the effect on base value of pie
        //printf ("%lf\n", pie); live update of the value of pie base value
    }
    
    printf("the estimated value of pi with %d terms is: %lf", term_amount, 4 * pie);
    return 0;
}
