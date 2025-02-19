#include <stdio.h>
#include <stdlib.h>

#define TOP 10
#define BOT 2

typedef struct Bin_Rep
{
    int *arr;
    int size;
}Bin_Rep;


void initializeBinNum(int *arr,int size);
void initializeNumbers(Bin_Rep *arr, int size);
int bin_to_dec(int *bin,int size);
void print_bin_arr(Bin_Rep *bin_arr,int bin_size);

int main(int argc, char const *argv[])
{
    int Bin_size;
    do
    {
        scanf("%d",&Bin_size);
    } while (Bin_size < 2||Bin_size>50);
    Bin_Rep *bin_arr = (Bin_Rep*)malloc(Bin_size*sizeof(Bin_Rep));
    initializeNumbers(bin_arr,Bin_size);
    print_bin_arr(bin_arr,Bin_size);
}

void initializeBinNum(int *arr,int size)
{
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = rand() % 2;
    }
    
}

void initializeNumbers(Bin_Rep *Bin_arr, int size)
{
    for (size_t i = 0; i < size; i++)
    {
        int bin_size = rand() % (TOP - BOT + 1)+BOT;
        Bin_arr[i].arr = (int*)malloc(bin_size*sizeof(int));
        if (Bin_arr[i].arr == NULL)
        {
            exit(1);
        }
        
        Bin_arr[i].size = bin_size;
        initializeBinNum(Bin_arr[i].arr,bin_size);
    }
}

int bin_to_dec(int *bin,int size)
{
    if(size == 0){return 0;}
    return bin[size-1]+2*bin_to_dec(bin,size-1);
}

void print_bin_arr(Bin_Rep *bin_arr,int bin_size)
{
    for (size_t i = 0; i < bin_size; i++)
    {
        printf("arr[%2d] = %d\n",i,bin_to_dec(bin_arr[i].arr,bin_arr[i].size));
    }
    
}