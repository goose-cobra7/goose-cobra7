#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct Password
{
    char *EntryCode;
    int N;
    char InputCode[200];
    int status;  
}Password;

int main(int argc, char const *argv[])
{
    Password test_pass;

    return 0;
}

int check_password(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] < 'a' || str[i] > 'z')
        {
            return 0;
        }
        
    }
    return 1;
}

void init_password(Password *pass)
{
    pass->EntryCode=malloc(pass->N*sizeof(char));//memory allo
    for (size_t i = 0; i < pass->N; i++)//init entry pass
    {
        pass->EntryCode[i] = rand()%25 + 97;//only a-z
    }
    do
    {
        scanf("%s",&pass->InputCode);//get user input pass
    } while (check_password(pass->InputCode) == 0);//which is valid

    int temp = strcmp(pass->EntryCode,pass->InputCode);//comper entry to input
    if (temp) //0<x
    {
        pass->status = 1;
    }else //0
    {
        pass->status = 0;
    }
}

int password_check(Password *pass,int index)
{
    if (index == pass->N)//finished checking the EntryCode
    {
        return 0;
    }
    if (pass->InputCode[index] > pass->EntryCode[index])//input higher then entry
    {
        printf("-");
    }else if (pass->InputCode[index] < pass->EntryCode[index])//input low then entry
    {
        printf("+");
    }else //perfect
    {
        printf("=");
    }
    return password_check(pass,index+1);//next one please
}