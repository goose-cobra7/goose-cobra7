#include <stdio.h>
#include <string.h>

int main()
{
    char str1[] = "abc bbca abab";
    char str2[] = "ab";
    int counter = 0;
    int i = 0, j = 0;
    for (i = 0; i < strlen(str1)-strlen(str2)+1; i++)
    {
        for (j = 0; j < strlen(str2); j++)
        {
            if (*(str1+i+j) != *(str2+j))
            {
                break;
            }
            if (j == strlen(str2)-1)
            {
                counter++;
            }
            
        }
        
    }
    
    
    
    printf("%d",counter);
    return 0;
}
