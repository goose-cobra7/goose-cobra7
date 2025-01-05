#include <stdio.h>

#define MAX_COL_SIZE 50
#define EFFECTIVE_COL_SIZE 2
#define ROW_SIZE 2

//matrix multiplication
void func(int A[][MAX_COL_SIZE], int B[][MAX_COL_SIZE], int C[][MAX_COL_SIZE], int rows, int cols, int i, int j)
{
    if (i == rows) return; //done the metrix multiplication when the row counter == rows

    C[i][j] = A[i][j] + B[i][j]; //i = row counter // j = column counter

    if (j + 1 < cols)
        func(A, B, C, rows, cols, i, j + 1); //move one column
    else
        func(A, B, C, rows, cols, i + 1, 0); //move one row
}

int main()
{
    int A[ROW_SIZE][MAX_COL_SIZE] =
    {
        {1, 2},
        {3, 4}
    };

    int B[ROW_SIZE][MAX_COL_SIZE] =
    {
        {5, 6},
        {7, 8}
    };

    int C[ROW_SIZE][MAX_COL_SIZE] =
    {
        {0, 0},
        {0, 0}
    };

    func(A, B, C, ROW_SIZE, EFFECTIVE_COL_SIZE, 0, 0);

    return 0;
}
