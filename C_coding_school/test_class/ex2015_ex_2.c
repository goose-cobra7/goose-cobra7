#include <string.h>
#include <stdio.h>

int check_sub_string(char* str1, char* str2);


int main(int argc, char const *argv[])
{
    char str1[] = "abc bbca abab";
    char str2[] = "ab";
    printf("the times: %d",check_sub_string(str1,str2));
    return 0;
}

int check_sub_string(char* str1, char* str2)
{
    int times = 0;
    int leangh = strlen(str1)-strlen(str2);
    for (size_t i = 0; i < leangh; i++)
    {
        for (size_t j = 0; j < strlen(str2); j++)
        {
            
        }
    }
    
    return times;
}

