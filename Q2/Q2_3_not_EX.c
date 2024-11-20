#include <stdio.h>
#include <math.h>

int main()
{
    int num[4];
    num[0] = -2;
    num[1] = 1;
    num[2] = 1;
    num[3] = 17;
    printf("enter 4 integers: %d %d %d %d\n\n",num[0],num[1],num[2],num[3]);
    int i = 0;
    while (i < 4)
    {
        num[i] = abs(num[i]);
        i++;
    }
    int num_even = 0;
    i = 0;
    while (i < 4) {
        num_even = num_even + ((num[i] + 1)%2);
        i++;
    }
    printf("the number of even integers is %d",num_even);
    return 0;
}
