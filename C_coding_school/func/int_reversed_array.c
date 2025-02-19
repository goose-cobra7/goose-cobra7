#include <stdio.h>
#define ARRAYSIZE 4

void reverseArrayInPlace(int array[], int size) {
    int temp;
    int start = 0;
    int end = size - 1;
    
    while (start < end) {
        // Swap the elements
        temp = array[start];
        array[start] = array[end];
        array[end] = temp;
        
        // Move the pointers
        start++;
        end--;
    }
}

int main() {
    int array[ARRAYSIZE] = {1, 2, 3, 4}; // Initialize the array
    
    // Call the reverseArrayInPlace function
    reverseArrayInPlace(array, ARRAYSIZE);
    
    // Print the reversed array to verify
    for (int a = 0; a < ARRAYSIZE; a++) {
        printf("%d ", array[a]);
    }
    
    return 0;
}
