#include <stdio.h>

void main()
{
    for (int i = 1; i < 100; i++)
    {
        if (i % 7 == 0)
        {
            printf("%d ", i);
        }else if(((i % 10))== 7)
        {
            printf("%d ", i);
        }else if(i>= 70 && i<= 79)
        {
            printf("%d ", i);
        }
    }
    
}