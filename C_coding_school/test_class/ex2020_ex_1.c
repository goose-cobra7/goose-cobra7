#include <stdio.h>

int bin_to_dec(int *bin,int size);

int main(int argc, char const *argv[])
{
    int binery[] = {1,0,0,1,1,0};
    int sum = bin_to_dec(binery,6);
    printf("%d",sum);
    return 0;
}

int bin_to_dec(int *bin,int size)
{
    if(size == 0){return 0;}
    return bin[size-1]+2*bin_to_dec(bin,size-1);
}