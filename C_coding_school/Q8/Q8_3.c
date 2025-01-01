#include <stdio.h>

#define MAT_SIZE 3

int rotate_matrix(int matrix[MAT_SIZE][MAT_SIZE]);

int main()
{
    int matrix[MAT_SIZE][MAT_SIZE];
    for (int i = 0; i < MAT_SIZE; i++)
    {
        for (int j = 0; j < MAT_SIZE; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
        
    }
    for (int i = 0; i < MAT_SIZE; i++)
    {
        for (int j = 0; j < MAT_SIZE; j++)
        {
            printf(" %3d", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for (int i = 0; i < 4; i++)
    {
        rotate_matrix(matrix);    
    }
        
    return 0;
}

int rotate_matrix(int matrix[MAT_SIZE][MAT_SIZE])
{
    int i, j;
    int temp[MAT_SIZE][MAT_SIZE];
    for (i = 0; i < MAT_SIZE; i++)
    {
        for (j = 0; j < MAT_SIZE; j++)
        {
            temp[j][i] = matrix[(MAT_SIZE-1)-j][i];
        }
    }
    for (i = 0; i < MAT_SIZE; i++)
    {
        for (j = 0; j < MAT_SIZE; j++)
        {
            matrix[j][i] = temp[i][j];
        }
    }
    printf("Rotated matrix:\n");
    for (int i = 0; i < MAT_SIZE; i++)
    {
        for (int j = 0; j < MAT_SIZE; j++)
        {
            printf(" %3d", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}