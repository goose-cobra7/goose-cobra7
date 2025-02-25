#include <stdio.h>
int JumpInMat(int A[10][10],int row,int col);
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

void initialize_matrix(int matrix[ROWS][COLS], int min, int max) {
    srand(time(0)); // אתחול מחולל המספרים הרנדומליים עם הזרע הנוכחי

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            matrix[i][j] = (rand() % (max - min + 1)) + min;
        }
    }
}

void print_matrix(int matrix[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrix[ROWS][COLS];
    initialize_matrix(matrix, 0, 130);

    printf("The initialized matrix is:\n");
    print_matrix(matrix);
    int temp = JumpInMat(matrix,3,2);
    printf("\njumps: %d",temp);
    return 0;
}


int JumpInMat(int A[10][10],int row,int col)
{
    int x = col,y = row,res,jumps = 0;
    res = A[x][y];
    while((res <= 99 && 0<=res)&&jumps<99)
    {
        res = A[res/10][res%10];
        jumps++;
    }
    return jumps;
}