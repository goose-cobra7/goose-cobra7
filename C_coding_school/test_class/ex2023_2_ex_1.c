#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int check_password(char* pass);

int main(int argc, char const *argv[])
{
    char password[100];
    fgets(password,100,stdin);
    check_password(password);
    return 0;
}

int check_password(char* pass)
{
    int length = strlen(pass);
    if (length < 8 || length > 12) //length check
    {
        printf("password too short: 8 - 12 letters.");
        return 0;
    }
    int uppercheck = 0;
    for (int i = 1; i < length; i++)//upperletter check
    {
        if (isupper(pass[i]))
        {
            uppercheck = 1;
            break;
        }
    }
    if (uppercheck == 0)
        {
            printf("password need to contain upperletter atleast once exept the start");
            return 0;
        }
    //48 - 57 //number check
    if (isdigit(pass[length-2]) != 1)
    {
        printf("need at least one number at the end of the pass");
        return 0;
    }
}