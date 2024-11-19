#include <stdio.h>

void main()
{
    char char1,char2; //מגדירים משתנים של אות
    char1 = 'z';//מכניס בזיכרון
    char2 = 'h';//מכניס בזיכרון
    char1 = char1 - 32;
    char2 = char2 - 32;
    int num_char_sum = char1*100 + char2;
    printf("the number is: %d",num_char_sum);
}