#include <stdio.h>
#define arr_col 10
#define arr_row 10

int main()
{
    int arr[arr_col][arr_row];
    for (int col = 0; col < arr_col; col++)
    {
        for (int row = 0; row < arr_row; row++)
        {
            arr[col][row] = (col + 1) * (row + 1);
            printf("%3d ", arr[col][row]);
        }
        printf("\n");
    }
    
    return 0;
}
