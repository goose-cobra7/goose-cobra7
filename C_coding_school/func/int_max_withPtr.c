#include <stdio.h>

int *max(int *a, int *b); 
void main()
{
    int i = 10,j = 20;
    int *max_ptr = max(&i,&j); //we send the address of i and j to a and b in the function
    printf("The larger number is: %d\n", *max_ptr);
}

int *max(int *a, int *b) //get address of i and j in the function
{
    return (*a > *b) ? a : b; //check what inside the address and compare. 
    //send back the address of largest number
}