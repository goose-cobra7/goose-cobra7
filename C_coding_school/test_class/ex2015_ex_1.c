#include <stdio.h>

int greaterSum(int a[], int N);
//מוצא מאיזה נקודה צד שמאל שווה לצד שני 
int sum(int A[], int N);
//summ all the array
int main(int argc, char const *argv[])
{
    int array[] = {62,24,36,85,91,52,20};
    printf("the i is: %d", greaterSum(array,7));
    return 0;
}
int greaterSum(int a[], int N) {
    int totalSum = sum(a, N); //find the summ of the array
    int leftSum = 0;//summ in left side
    for (int i = 0; i < N; i++) {
        leftSum += a[i];//add new int from the left to the sum
        if (leftSum > totalSum - leftSum) {//take the same int from the sum 
                            //check if the new sum is smoller then right side
            return i;
        }
    }
    return N - 1; // Return the last index if no such index is found
}

int sum(int A[], int N) {
    int total = 0;
    for (int i = 0; i < N; i++) {
        total += A[i];
    }
    return total;
}