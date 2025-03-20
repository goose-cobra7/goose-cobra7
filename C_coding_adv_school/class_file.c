#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *pfile = fopen("amogos.bmp", "rb");
    if (!pfile)
    {
        printf("i can't do it :( \n");
        exit(EXIT_FAILURE);
    }
    fseek(pfile, 18, SEEK_SET);
    int size[2];
    fread(size, sizeof(size[0]), 2, pfile);
    
    int width, height;
    width = size[0];
    height = size[1];
    printf("%dX%d\n", width, height);
    int **arr_w = malloc(width * sizeof(int*));
    if (!arr_w) // Check if malloc succeeds
    {
        printf("Memory allocation failed for arr_w :( \n");
        fclose(pfile);
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < width; i++)
    {
        arr_w[i] = malloc(height * sizeof(int)); // Fixed memory allocation for each row
        if (!arr_w[i]) // Check if malloc succeeds for each row
        {
            printf("Memory allocation failed for row %d :( \n", i);
            // Free previously allocated memory before exiting
            for (int j = 0; j < i; j++)
            {
                free(arr_w[j]);
            }
            free(arr_w);
            fclose(pfile);
            exit(EXIT_FAILURE);
        }
    }

    // Free the allocated memory (prevent memory leaks)
    for (int i = 0; i < width; i++)
    {
        free(arr_w[i]);
    }
    free(arr_w);
    fclose(pfile);

    return 0;
}
