#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    printf("enter the number: ");
    int n;
    scanf("%d", &n);
    int* array = (int*)malloc(n*sizeof(int));
    if (array == NULL)
    {
        printf("Memory allocation failed!\n");
        return EXIT_FAILURE;
    }
    printf("Enter the elements: ");
    for (size_t i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
    for (size_t i = 0; i < n; i++)
    {
        printf("%d, ", array[i]);
    }
    free(array);
    
    return 0;
}
