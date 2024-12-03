#include <stdio.h>

void create_triangle(int REL_NUM)
{
    for (int num = 0; num <= REL_NUM; num++)
    {
        for (int i = 1; i <= num; i++)
        {
            printf("%d ", i);
        }
        printf("\n");
    }
    
}

void main()
{
    int REL_NUM = 0;
    scanf("%d",&REL_NUM);
    create_triangle(REL_NUM);
}