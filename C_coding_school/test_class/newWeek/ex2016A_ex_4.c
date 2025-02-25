#include <stdio.h>
#include <string.h>

#define ARR_SIZE 10
int main()
{
    int id[] = {1,3,4,0,6,4,2,9,7};//ARR_SIZE
    int *p_id[10];
    for (size_t i = 0; i < 10; i++)
    {
        for (size_t j = 0; j < ARR_SIZE; j++)
        {
            if (id[j] == i)
            {
                p_id[i] = id+j;
            }
            
        }
        
    }
    for (size_t i = 0; i < 10; i++)
    {
        printf("%d:",i);
        for (size_t j = 0; j < ARR_SIZE; j++)
        {
            printf("%d ",p_id[i][0]);
        }
        printf("\n");
    }
    
    return 0;
}
