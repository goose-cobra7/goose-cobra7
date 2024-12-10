#include <stdio.h>

int sumPlusMinus(int num)
{
    int sign = +1;
    int sum = 0;
    while (num > 0)
    {
        sum += sign * (num % 10);
        num /= 10;
        sign *= -1;
    }
    return sum;
}

int main()
{
    int num;
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    if (sumPlusMinus(sumPlusMinus(num)) == 0 && num != 0)
    {
        printf("%d devided by 11\n", num);
    }else
    {
        printf("%d does not devide by 11\n", num);
    }

}