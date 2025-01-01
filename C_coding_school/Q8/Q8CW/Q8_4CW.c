#include <string.h>
#include <stdio.h>

#define STR_1_SIZE 10
#define STR_2_SIZE 10

int string_finder(char string1[],char string2[])
{
    int len1 = strlen(string1);
    int len2 = strlen(string2);
    for (int i = 0; i < len1 - len2; i++)
    {
        int j = 0;
        for (j = 0; j< len2; j++)
        {
            if (string1[i+j] == string2[j])
            {
                if (j == len2-1) return i;
                continue;
            }
            
        }
        
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    char string1[STR_1_SIZE];
    char string2[STR_2_SIZE];
    printf("Enter the first string: ");
    fgets(string1,STR_1_SIZE,stdin);
    if (string1[strlen(string1) - 1] == '\n') (string1[strlen(string1) - 1] = '\0');

    fseek(stdin,0,SEEK_END);
    printf("Enter the second string: ");
    fgets(string2,STR_2_SIZE,stdin);
    if (string2[strlen(string2) - 1] == '\n') (string2[strlen(string2) - 1] = '\0');
    int found = string_finder(string1,string2);
    printf("%s found at index %d\n", (found != 0)? "Found" : "Not Found", found);
    //print this sentence ---------if found is not 0 => print "found" else print "not found" and at 
    return 0;
}
