#include <stdio.h>
#include <stdlib.h>

#define BUFFER 100
#define start_size 4

int* my_realoc(int *array,int new_size);


int main(int argc, char const *argv[])
{
    int *my_string = malloc(start_size*sizeof(int));
    for (size_t i = 0; i < start_size; i++)
    {
        my_string[i] = i+rand()%100;
        printf("%3d,",my_string[i]);
    }
    printf("\n");
    int *my_new_string = my_realoc(my_string,8*sizeof(int));
    free(my_string);
    for (int i = 0; i < 8; i++)
    {
        printf("%3d,",my_new_string[i]);
    }
    
    return 0;
}

int* my_realoc(int *array,int new_size)
{
    int *my_new_string = malloc(new_size);
    for (size_t i = 0; i < 4; i++)
    {
        my_new_string[i] = array[i];
    }
    return my_new_string;
}