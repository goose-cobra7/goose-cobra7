#include <stdio.h>
#include <math.h>

int countDigits(int num)// Function to count digits in a number
{
    int count = 0;
    while (num != 0)
    {
        num /= 10;
        count++;
    }
    
    return count;
}
int findDigit(int num, int index) // Function to find the digit at a given position in a number
{
    int tmp_num = num;
    int temp_multiplier = 1;
    
    // Move to the correct position
    for (int i = 1; i < index; i++)
    {
        temp_multiplier *= 10;
    }
    
    // Extract the digit
    tmp_num /= temp_multiplier;
    int digit = tmp_num % 10;
    
    return digit;
}

int armstrong(int num) // Function to check if a number is Armstrong
{
    int sum = 0;
    int digitcount = countDigits(num);
    for (int i = 0; i < digitcount; i++) 
    {
        int digit = findDigit(num, i + 1); // Find the digit
        sum += pow(digit,digitcount);
    }
    return sum==num;
}
int main() // Driver code
{
    printf("Enter a number: ");
    int num;
    scanf("%d", &num); // Read the number from user
    printf("%d",armstrong(num)); // Prints 1 if the number is Armstrong, 0 otherwise
}
