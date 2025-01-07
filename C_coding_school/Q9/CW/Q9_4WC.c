#define SIZE 10 
#include <stdio.h> 

int divideToSentences(char* sentence, char** arr, int size);
void main() 
{ 
    char sentence[] = "Remember that function";
    char* arr[SIZE]; 
    int numOfWord = divideToSentences(sentence, arr, SIZE); 
    char**ptr; 
    for (ptr = arr; ptr < arr + numOfWord; ptr++) printf("word: %s \n", *ptr); 
    //system("pause");
}

int divideToSentences(char* sentence, char** arr, int size) 
{
    while (sentence != NULL)
    {
        if (*sentence == ' ')
        {
            *sentence = '\0';
            
        }
        sentence++;
    }
    //TODO: splt the sentece into words using \0
    //TODO: copy the pointer to the start of the word to arr[]
    //TODO: return the number of words
    
}