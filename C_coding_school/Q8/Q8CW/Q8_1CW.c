#include <stdio.h>

#define COLS 3
#define ROWS 4

int inti_arr(int arr[][COLS],int row,int col,int result[])
{
    printf("enter elements into a %dX%d metrix:\n", ROWS, COLS);

    for (int row = 0; row < ROWS; row++) //for each row
    {
        for (int col = 0; col < COLS; col++) //for each column
        {
            printf("Enter element at [%d][%d]: ", row, col); 
            scanf("%d", &arr[row][col]);//enter element
            
        }
        result[row] = arr[row][0] + arr[row][1] + arr[row][2]; //the sum of row elements
    }
}

int main()
{
    int result[ROWS];
    int arr[ROWS][COLS];
    inti_arr(arr,ROWS,COLS,result);
    printf("the result of each row of elements is:");
    for (int i = 0; i < ROWS; i++)
    {
        printf("%3d ", result[i]); //print the sum of each row
    }
    
}