#include <stdio.h>
#include <string.h>

int countVowels(char *string);
int main()
{
    char string[1024];
    printf("Enter a string: ");
    fgets(string, 1024, stdin); //"1024" number of characters in string, "stdin" standard input (keyboard input)
    int vowels = countVowels(string); //read the number of vowels in string
    printf("Number of vowels in the string: %d\n", vowels);
    printf("The string you entered is: %s\n", string);
    return 0;
}

int countVowels(char *string) //i send the address of the string[0], way easier to work with
{
    int count = 0;
    while (*string != '\0') //while not reaching the end of the string
    {
        if (*string == 'a' || *string == 'e' || *string == 'i' || *string == 'o' || *string == 'u' ||
            *string == 'A' || *string == 'E' || *string == 'I' || *string == 'O' || *string == 'U') //check for any vowels
        {
            count++; //if there is add to counter
        }
        string++; //move to the next character
    }
    return count;
}
/*while it is true that its easy to just work with "i" inside the func i find
it more appiling and better for training with pointers*/