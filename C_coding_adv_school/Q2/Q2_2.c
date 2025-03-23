#include <stdio.h>

int main()
{
    FILE *pfile = fopen("Q2_1.exe","r+");
    fseek(pfile,8704,0);
    char string[13] = {"it is Virus!"};
    fputs(string,pfile);
    puts(string);
    return 0;
}
