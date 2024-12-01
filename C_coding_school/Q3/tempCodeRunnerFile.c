#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    float sum = 0;
    float num = 0;
    char more_multi = 'Y';
    printf("enter the base num:");
    scanf("%f",num);
    if (more_multi == 'y' || more_multi == 'Y')
    {
        float multi = 0;
        printf("enter multiplayer:");
        scanf("%f",&multi);
        sum = sum +(num * multi);
        printf("%f\n",sum);
        printf("do you want to multiplay more: Y/N");
        scanf("%c",more_multi);
    }
        
    return 0;
}


