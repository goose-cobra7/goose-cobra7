#include <string.h>
#include <stdio.h>
#include <ctype.h>

int NumOfCapitals(char* string,int place);

int main()
{
    /* Test the function with example cases */
    char str1[] = "Day nice a have ";
    printf("Number of capitals from index 0: %d\n", NumOfCapitals(str1, 0)); // Should return 1
    printf("Number of capitals from index 3: %d\n", NumOfCapitals(str1, 3)); // Should return 0
    return 0;
}

int NumOfCapitals(char* string,int place)
{
    static int length;
    length = strlen(string);
    if (place == length -1)
    {
        return (isupper(string[place]));
    }
    return (isupper(string[place])+NumOfCapitals(string,place+1));
    
}