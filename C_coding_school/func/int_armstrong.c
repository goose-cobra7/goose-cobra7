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

int armstrong(int num)
{
    int sum = 0;
    int digitcount = countDigits(num);
    for (int i = 0; i < digitcount; i++)
    {
        int digit = findDigit(num, i + 1);
        sum += pow(digit,digitcount);
    }
    return sum==num;
}

/*מספר נרקיסיסטי (narcissistic number), או מספר ארמסטרונג, הוא מספר שסכום חזקות הספרות שלו במספר הספרות הוא המספר עצמו, קצת מבלבל אבל הנה דוגמא:
1634 = 4^4 + 4^3 + 4^6 + 4^1
כאשר מספר הספרות במספר 1634 הוא 4.
יש 88 מספרים כאלה בבסיס עשרוני והגדול מבניהם הוא המספר הבא בן 39 ספרות:
115,132,219,018,763,992,565,095,597,973,971,522,401*/
