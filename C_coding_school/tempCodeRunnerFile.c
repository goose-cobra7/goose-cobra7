#define _CTR_SECURE_NO_WARNINGS
#include<stdio.h>

void main() 
{
    int vector_X[3];
    int vector_Y[3];
    printf("Enter vector X values:");
    for (int i = 0; i < 3; i++)
    {
        scanf("%d", &vector_X[i]);
    }
    printf("Enter vector Y values:");
    for (int i = 0; i < 3; i++)
    {
        scanf("%d", &vector_Y[i]);
    }
    for (int i = 0; i < 3; i++)
    {
        printf("Dot product of vector X and Y at index %d is: %d\n", i, vector_X[i] + vector_Y[i]);
    }
    
}