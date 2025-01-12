
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void rotate_array(const int* arr, int* rotated, int length, int n);
void printArray(int* arr, int length);

int main()
{
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int rotated[_countof(arr)] = { 0 };

    printf("Original array:\n");
    printArray(arr, 10);

    rotate_array(arr, rotated, 10, 3);
    printf("Rotated right by 3 places:\n");
    printArray(rotated, 10);

    rotate_array(arr, rotated, 10, -7);
    printf("Rotated left by 7 places:\n");
    printArray(rotated, 10);

    rotate_array(arr, rotated, 10, 1001);
    printf("Rotated right by 1001 places:\n");
    printArray(rotated, 10);

    rotate_array(arr, rotated, 10, -2);
    printf("Rotated left by 2 places:\n");
    printArray(rotated, 10);

    return 0;
}

void rotate_array(const int* arr, int* rotated, int length, int n) {
    n = n%length;
    if (n<0)
    {
        n = length + n;
    }
    for (int i = 0; i < length; i++)
    {
        rotated[i] = arr[(i + n)%length];
    }
    
}

void printArray(int* arr, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
