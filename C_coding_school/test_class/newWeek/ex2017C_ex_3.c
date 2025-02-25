#include <stdio.h>
#include <string.h>

#define SIZE 256 

void Cypher(char text[], const char forbid[][SIZE]);


int main()
{
    const char forbiddenStrings[][SIZE] = {"flower", "blo", "plant",""}; 
    char text[] = "A flower, sometimes known as a bloom or blossom, is the reproductive structure found in flowering plants. PLANTS ARE COOL." ; 
    Cypher(text, forbiddenStrings);
    printf("CENSORED TEXT: %s\n", text);
}

void Cypher(char text[], const char forbid[][SIZE])
{
    int i = 0;
    while (forbid[i][0])
    {
        char *checker;
        do
        {
            checker = NULL;
            checker = strstr(text,forbid[i]);
            if(checker == NULL){break;}
            for (size_t k = 0; k < strlen(forbid[i]); k++)
            {
                checker[k] = '*';
            }
        } while (1);
        
        i++;
    }
    
}