#include <stdio.h>

void main()
{
    for (int i = 10; i <= 20; i++)
    {
        if (i != 12 && i != 15 && i != 18)
        {
        printf("%d ", i);
        }if (i==18)
        {   
        break;
        }
    }
    
    
    
}