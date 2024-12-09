#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int who_is_bigger(int a, int b)
{
    if (a > b)
    {
        return 1;
    }
    else if (a < b)
    {
        return 2;
    }
    else
    {
        return 0;
    }
    
}

int main()
{
    int a, b;
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);
    switch (who_is_bigger(a, b))
    {
    case 0:
        printf("%d and %d are equal.\n", a, b);
        break;
    case 1:
        printf("%d is greater than %d.\n", a, b);
        break;
    default:
        printf("%d is less than %d.\n", a, b);
        break;
    }
}