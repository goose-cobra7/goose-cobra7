#include <stdio.h>
int seperator_array[40];
int seperator(int num) 
{
    int count = 0;
    while (num!=0)
    {
        seperator_array[count] = num % 10;    
        num /= 10;
        count++;
    }
    return count;
}

int main(int argc, char const *argv[])
{
    int num;
    scanf("%d", &num);
    printf("%d\n", seperator(num));
    for(int i = seperator(num)-1; i >= 0 ; i--)
    {
        printf("%d ", seperator_array[i]);
    }
    return 0;
}
