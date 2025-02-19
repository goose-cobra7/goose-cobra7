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

//סופר כמה ספרות יש במספר