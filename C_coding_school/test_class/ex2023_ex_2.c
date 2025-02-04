#include <stdio.h>
//מוצא את הגדול בסידרה בצורה ריקורסיבית
int find_max(int arr[], int n);

int main()
{
    int array[] = {1, 5, 3, 9, 2};
    int size = sizeof(array) / sizeof(array[0]);

    int max_value = find_max(array, size);
    printf("The maximum value in the array is: %d\n", max_value);

    return 0;
}

int find_max(int arr[], int n)
{
    if (n == 1)
        return arr[0]; //return the first dig of array 

    int max_in_rest = find_max(arr + 1, n - 1);//
    return (arr[0] > max_in_rest) ? arr[0] : max_in_rest;
}


