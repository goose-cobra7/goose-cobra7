#include <stdio.h>
#define ROW_SIZE 4
#define COL_SIZE 8

// Function to flip and print rows
void print_array(int arr[][COL_SIZE])
{
    for (int i = 0; i < ROW_SIZE; i++)
    {
        for (int j = 0; j < COL_SIZE; j++)
        {
            printf(" %3d", arr[i][j]);
        }
        printf("\n");
    }
    
}
void flip_rows(int arr[][COL_SIZE],int row, int end)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = end -1; j >= 0; j--)
        {
            printf(" %3d", arr[i][j]);  
        }
        for (int j = end ; j < COL_SIZE; j++)
        {
           
            printf(" %3d", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int mat[ROW_SIZE][COL_SIZE] = {
        {1, 2, 3, -1, -1, -1, 0, 0},
        {0, 3, 0, -1, 0, 0, 0, 0},
        {2, 2, 5, -1, 0, 0, 0, 0},
        {8, 7, 6, -1, 0, 0, 0, 0}
    };
    flip_rows(mat,ROW_SIZE, 4);
    return 0;
}
