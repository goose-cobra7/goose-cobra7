#include <stdio.h>

int print_the_array(int num1,int num2)
{
    int i;
    for (i = num1; i <= num2; i++)
    {
        if (i == 15)
        {
            break;
        }
        else if ((i % 3 == 0)||(i % 5 == 0))
        {
            continue;
        }else
        {
            printf("%d ", i);
        }
        
    }
    return 0;
}
int main()
{
    int num1,num2;
    scanf("%d %d",&num1,&num2);
    print_the_array(num1,num2);
}