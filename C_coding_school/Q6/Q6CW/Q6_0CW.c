#include <stdio.h>

int countDigits(int num)
{
    int count = 0;
    while (num != 0)
    {
        num /= 10;
        count++;
    }
    
    return count;
}
int findDigit(int num, int index)
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
int main()
{
    int num; 
    printf("enter a number: ");
    scanf("%d", &num);
    int count = countDigits(num);//find the number of digits
    int arr_of_num[count]; //create an array to store the digits
    while (num != 0)
    {
        num%10;
    }
    
    int arr_of_the_most_digit[10]; //create an array to store the most digit
    for (int i = 0; i < count; i++) //find the most digit
    {
        
    }
    
    return 0;
}
