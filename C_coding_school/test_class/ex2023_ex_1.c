#include <stdio.h>

#define MAT_SIZE_X 3 //define size x
#define MAT_SIZE_Y 3 //define size y
int mirror(int arr[][3]); //define the fun'

int main()
{
//int metrix   
    int matrix[MAT_SIZE_Y][MAT_SIZE_X] = {
        {1,2,3},
        {1,2,3},
        {1,2,3}
    };
    //print metrix
    printf("the original metrix: \n");
    for (int i = 0; i < MAT_SIZE_Y; i++)
    {
        for (size_t j = 0; j < MAT_SIZE_X; j++)
        {
            printf("|%d|",matrix[i][j]);
        }
        printf("\n");
    }
    mirror(matrix); //mirror
    //print mirror
    printf("\nflipped metrix:\n");
    for (int i = 0; i < MAT_SIZE_Y; i++)
    {
        for (size_t j = 0; j < MAT_SIZE_X; j++)
        {
            printf("|%d|",matrix[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}

int mirror(int arr[][3])
{
    int temp[MAT_SIZE_Y][MAT_SIZE_X];
    int mirror = MAT_SIZE_X;
    for (int i = 0; i < MAT_SIZE_Y; i++)
    {
        for (size_t j = 0; j < MAT_SIZE_X; j++)
        {
            temp[i][j] = arr[i][MAT_SIZE_X-1-j];
            //flip it on the x
        }
    }
    for (size_t i = 0; i < MAT_SIZE_Y; i++)
    {
        for (size_t j = 0; j < MAT_SIZE_X; j++)
        {
            arr[i][j] = temp[i][j];
            //return to the original metrix
        }
        
    }
    
}
