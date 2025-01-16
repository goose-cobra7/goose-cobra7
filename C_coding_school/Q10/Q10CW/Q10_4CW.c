#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char** split_string_into_word(char const *string,int *word_count);
int main()
{
    //printf("enter the string: ");
    char string[100] = "hello my name is world";
    //gets(string);

    int word_count=0;
    char** index = split_string_into_word(string,&word_count);
    // Print the words
    for (int i = 0; i < word_count; i++) {
        printf("Word %d: %s\n", i + 1, index[i]);
        free(index[i]);  // Free each word
    }
    free(index);  // Free the array of pointers
    return 0;
}

char** split_string_into_word(char const *string, int *word_count)
{
    char** words = NULL;
    *word_count = 0;
    size_t j = 0, i = 0;
    while (string[j] != '\0')
    {
        if (string[j] == ' ' || string[j + 1] == '\0')
        {
            size_t word_length = (string[j] == ' ') ? j - i : j - i + 1;
            words = realloc(words, (*word_count + 1) * sizeof(char*));
            //every word we find by entering the "if" we rellocate the array to higher length
            words[*word_count] = malloc((word_length + 1) * sizeof(char));
            //we put the "0" pointer of the word inside the word[place] and locate space for it

            strncpy(words[*word_count], &string[i], word_length);
            words[*word_count][word_length] = '\0';
            (*word_count)++;
            i = j + 1;
        }
        j++;
    }
    return words;
}

//the way it look at the end
/*the string: "the word is world"
words/word0|   1|    2|    3|    4|    5|                               
1   |   't'| 'h'| 'e' | '\0'|     |     |
____|____________________________________
2   |   'w'| 'o'| 'r' | 'd' | '\0'|     |
____|____________________________________
3   |   'i'| 's'| '\0'|     |     |     |
____|____________________________________
4   |   'w'| 'o'| 'r' | 'l' | 'd' | '\0'|
-----------------------------------------
*/


