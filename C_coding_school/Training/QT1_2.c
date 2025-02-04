#include <stdio.h>
#include <string.h>
int check_sub_string(char* str1, char* str2);
int main(int argc, char const *argv[])
{
    char str1[] = "ab";
    char str2[] = "abc bbca abab";
    printf("%d\n", check_sub_string(str1, str2));
    return 0;
}

int check_sub_string(char* str1, char* str2)
{
    int str1len = strlen(str1);
    int str2len = strlen(str2);
    int result = 0;
    for (size_t i = 0; i < str2len; i++)
    {
        if (strncmp(str1, str2 + i, strlen(str1))==0)
        {
            result++;
        }
    }
    return result;
}
