//matrix
#define ROW 3
#define LINE 3
#include <stdio.h>
#include <time.h>
#include <stdlib.h> 

int main() {
    srand(time(NULL)); // initialize random seed to current time
    int matrix[ROW][LINE];
    for (int j = 0; j < LINE; j++)
    {
        for (int i = 0; i < ROW; i++)
        {
            matrix[i][j] = rand() % 10; // generate random number between 0 and 9   
        }
        
    }
    for (int j = 0; j < LINE; j++)
    {
        for (int i = 0; i < ROW; i++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("adding matrix A:\n");
    int matrix_A[LINE][ROW];
    for (int j = 0; j < ROW; j++)
    {
        for (int i = 0; i < ROW; i++)
        {
            matrix_A[i][j] = rand() % 10;
        }
        
    }
    for (int j = 0; j < LINE; j++)
    {
        for (int i = 0; i < ROW; i++)
        {
            printf("%d ", matrix_A[i][j]);
        }
        printf("\n");
    }
    for (int j = 0; j < LINE; j++)
    {
        for (int i = 0; i < ROW; i++)
        {
            matrix[j][i] += matrix_A[j][i];
        }
        printf("\n");
    }
    for (int j = 0; j < LINE; j++)
    {
        for (int i = 0; i < ROW; i++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}