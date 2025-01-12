#include <stdio.h>

int main()
{
    int *x[10]; //{0,0,0,0,0,0,0,0,0,0,0,0}
    int var_1 = 10; //variable
    x[0] = &var_1; 
    x[1] = &var_1+1;
    *x[0] = 1;
    printf("%d\n", x[0]);
    printf("%d\n", *x[0]);
    printf("%d\n", x[0][0]);
    **x[1] = 2;
    printf("%d\n", x[1]);
    printf("%d\n", *x[1]);
    printf("%d\n", x[1][0]);
    *x[0]= 0;
    printf("%d\n", x[0]);
    printf("%d\n", *x[0]);
    printf("%d\n", x[0][0]);
    return 0;
}
