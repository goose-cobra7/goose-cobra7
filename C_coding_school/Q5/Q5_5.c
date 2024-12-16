#include <stdio.h>

int fibonacci(int n) { 
    int prev = 0, current = 1, next, i;
    if (n == 0) return prev; 
    for (i = 2; i <= n; i++) {
        next = prev + current; 
        prev = current; 
        current = next; 
    } 
    return current; 
}

int main() {
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", fibonacci(i));
    }
}