#define size = 6

int print_metrix(int mat[][6], int n, int m) //change 6 to size
{
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < m; i++)
        {
            printf("%d ", mat[j][i]);
        }
        printf("\n");
    }
    
}