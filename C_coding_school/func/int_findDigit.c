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