#include <stdio.h>
#include <string.h>
#include <ctype.h>

int NumOfCap(char str[],int index);

int main(int argc, char const *argv[])
{
    char str[] = {"RgRgg"};
    printf("%d",NumOfCap(str,1));
    return 0;
}

int NumOfCap(char str[],int index)
{
    if (strlen(str) == index)
    {
        return 0;
    }else
    {
        return (isupper(str[index-1])+NumOfCap(str,index+1));
    }
}

