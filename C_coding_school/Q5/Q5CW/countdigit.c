#include <stdio.h>

int countDigits(int num);

int main()
{
    int num = 12345;
    int digits = countDigits(num);
    printf("The number %d has %d digits.\n", num, digits);
    return 0;
}
int countDigits(int num)
{
    int count = 0;
    while (num != 0)
    {
        num /= 10;
        count++;
    }
    
    return count;
}