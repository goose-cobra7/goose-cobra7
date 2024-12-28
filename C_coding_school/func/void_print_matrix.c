int print_metrix(int mat[][size], int n, int m)
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