#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void main()
{
    char chr;
    printf("insert character:");
    scanf("%c", &chr); //input
    printf("the original char: %c    ",chr); //first print
    if (chr >= 'a' && chr <= 'g') //char is between (a-g)
    {
        chr -= 32; // we go down
        chr++;
    }
    else if (chr >= 'H' && chr <= 'Z')// char is between (H-Z)
    {
        chr += 32; // we go up
        chr--;

    }
    else //not of the above
    {
        chr *= 2; //double or go home
        if (chr > 127) chr -= 127;//making sure we are not over 127
    }
    printf("the result char: %c",chr); //secend print
}