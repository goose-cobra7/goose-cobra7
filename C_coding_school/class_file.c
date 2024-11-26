#define _CTR_SECURE_NO_WARNING
#include <stdio.h>
#include <math.h>
#define SENT 4
int main() {
    int  num1, num2, num3; float shoresh; float x1, x2;
    printf("pls enter num1: num2: num3:");
    scanf_s("%d %d %d", &num1, &num2, &num3);
    num2 = num2 * num2;
    shoresh = num2 - (SENT * num1 * num2);
    shoresh = (float)sqrt((double)shoresh);
    if (shoresh > 0)
    {
        x2 = (-num2 + shoresh) / (num1 * 2);
        x1 = (-num2 - shoresh) / (num1 * 2);
        printf("x1: %2f, x2: %2f\n", x1, x2);
    return 0;
    }
    else
    {
    if (shoresh = 0)
    {
        print("pitaron 1\n");
    }
    else
        print("no pitaron\n");
    }
}