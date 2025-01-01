#include <stdio.h>
#include <time.h>
#include <stdlib.h>


#define MAT_A_ROW 5
#define MAT_A_COL 9
#define MAT_B_ROW 9
#define MAT_B_COL 5
#define MAT_C_ROW 5
#define MAT_C_COL 5





int main()
{
    srand(time(NULL));
    int mat_c[MAT_C_ROW][MAT_C_COL]; //create output matrix
    //initialize all matrices
    int mat_a[MAT_A_ROW][MAT_A_COL]; //create A matrix
    for (int i = 0; i < MAT_A_ROW; i++) //initialize with random number
    {
        for (int j = 0; j < MAT_A_COL; j++)
        {
            mat_a[i][j] = rand() % 10;
        }
    }


    int mat_b[MAT_B_ROW][MAT_B_COL]; //create B matrix
    for (int i = 0; i < MAT_B_ROW; i++) //initialize with random number
    {
        for (int j = 0; j < MAT_B_COL; j++)
        {
            mat_b[i][j] = rand() % 10;
        }
    }
    
    //print matrix A
    printf("matrix A:\n");
    for (int i = 0; i < MAT_A_ROW; i++)
    {
        for (int j = 0; j < MAT_A_COL; j++)
        {
            printf("%3d",mat_a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("matrix B:\n");
    //print matrix B
    for (int i = 0; i < MAT_B_ROW; i++) 
    {
        for (int j = 0; j < MAT_B_COL; j++)
        {
            printf("%3d",mat_b[i][j]);
        }
        printf("\n");
    }
    
    printf("\n");
    //start multiplie HERE
    for (int i = 0; i < MAT_C_ROW; i++) //run on rows in MAT C
    {
        for (int j = 0; j < MAT_C_COL; j++) //run on col in MAT C
        {
            mat_c[i][j] = 0; //reset the cell before starting to multi
            for (int k = 0; k < MAT_A_COL; k++)  //run on k
            //k = the rows in col A and row in mat B
            {
                mat_c[i][j] += mat_a[i][k] * mat_b[k][j]; // C = a1b1 + a2b2 + a3b3 ...
            }
        }
    }
    //print matrix C
    printf("multiplications result:\n");
    for (int i = 0; i < MAT_C_COL; i++)
    {
        for (int j = 0; j < MAT_C_ROW; j++)
        {
            printf("%5d",mat_c[i][j]);
        }
        printf("\n");
    }
    return 0;
}