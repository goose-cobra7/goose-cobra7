int Upper_case_counter(char string[])
{
    int counter = 0;
    int i = 0;
    while (string[i] != '\n')
    {
        if (string[i] >= 'A' && string[i] <= 'Z')
        {
            counter++;
        }
        i++;
    }
    
    return counter;
}