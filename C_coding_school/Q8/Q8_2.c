#include <stdio.h>
#include <time.h>
#include <stdlib.h>


#define MAT_A_ROW 5
#define MAT_A_COL 9
#define MAT_B_ROW 9
#define MAT_B_COL 4
#define MAT_C_ROW 5
#define MAT_C_COL 4

int matrix_multiply(int mat_a[][MAT_A_ROW],int mat_b[][MAT_B_ROW],int mat_c[][MAT_C_ROW])
{
    int i, j, k;
    for (i = 0; i < MAT_C_ROW; i++)
    {
        for (j = 0; j < MAT_C_COL; j++)
        {
            mat_c[i][j] = 0;
            for (k = 0; k < MAT_A_ROW; k++)
            {
                mat_c[i][j] += mat_a[i][k] * mat_b[k][j];
            }
        }
    }
    return 0;
}





int main()
{
    srand(time(NULL));
    int mat_a[MAT_A_COL][MAT_A_ROW];
    int mat_b[MAT_B_COL][MAT_B_ROW];
    int mat_c[MAT_C_COL][MAT_C_ROW];
    //TODO: initialize all matrices
    //TODO: multiply mat_a and mat_b and store result in mat_c
    //TODO: print mat_c
    return 0;
}