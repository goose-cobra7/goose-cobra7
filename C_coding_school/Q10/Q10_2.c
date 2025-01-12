#include <stdio.h>

#define SIZE 8

void sortedSquares(int* arr, int* squaredArray, int size);
void printIntegerArray(int* arr, int size);
void terribleBubbleSort(int* arr, int size);
void swapIntegers(int* a, int* b);

int main() {
    int arr[SIZE] = { -9, -5, -2, 0, 0, 3, 5, 27 };
    int squares[SIZE]; //solution array
    
    printf("Original array: ");
    printIntegerArray(arr, SIZE);
    
    sortedSquares(arr, squares, SIZE);
    
    printf("Sorted squares array: ");
    printIntegerArray(squares, SIZE);
    
    return 0;
}

void printIntegerArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

void sortedSquares(int* arr, int* squaredArray, int size) {
    for (int i = 0; i < size; i++)
    {
        *(squaredArray + i) = *(arr + i) * *(arr + i);
    }
    terribleBubbleSort(squaredArray,size);
}

/// <summary>
/// Sorts the array "arr" in increasing order using a bad (long execution time) version of
/// the sorting algorithm "bubble sort"
/// </summary>
/// <param name="arr">The array to sort</param>
/// <param name="size">Number of elements in the array "arr"</param>
void terribleBubbleSort(int* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (*(arr + j) > *(arr + j + 1))
                swapIntegers(arr + j, arr + j + 1);
        }
    }
}

/// <summary>
/// swaps the integer values pointed to by pointers a and b.
/// </summary>
/// <param name="a"></param>
/// <param name="b"></param>
void swapIntegers(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
