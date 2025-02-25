#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define BUFFER 13
int checkPass(char pass[]);


int main()
{
    char pass[13];
    printf("enter password: ");
    scanf("%s",&pass);
    printf("%d", checkPass(pass));
    return 0;
}

int checkPass(char pass[])
{
    if (strlen(pass) > 12||strlen(pass)<8)
    {
        return 0;
    }
    int UpCa = 0;
    for (size_t i = 1; i < strlen(pass); i++)
    {
        if (isupper(pass[i]) == 1 )
        {
            UpCa = 1;
            break;
        }
        
    }
    if (UpCa == 0)
    {
        return 0;
    }
    int len = strlen(pass);
    if (isdigit(pass[len - 1]) == 0 )
    {
        return 0;
    }
    return 1;
}