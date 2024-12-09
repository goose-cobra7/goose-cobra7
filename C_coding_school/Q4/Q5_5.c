#include <stdio.h>

int main() {
    int n;
    int k;
    long long result = 1;

    printf("Enter value of n: ");
    scanf("%d", &n);
    printf("Enter value of k: ");
    scanf("%d", &k);

    if (k > n)        // Invalid case
        result = 0;
    else if (k == 0 || k == n)    // Base cases
        result = 1;
    else
        for (int i = 1; i <= k; i++) {
            result *= n - i + 1;
            result /= i;    // this always divides with remainder 0 (requires proof)
        }

    printf("C(%d,%d) = %llu\n", n, k, result);

    return 0;
}
