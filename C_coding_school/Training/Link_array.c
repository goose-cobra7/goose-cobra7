#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define bufsize 1024
char* input_user();
int main()
{
    input_user();
    return 0;
}
//just normal string from user into pointer. 
char* input_user()
{
    char buffer[bufsize];
    printf("Enter a string: ");
    if (fgets(buffer, bufsize, stdin) == NULL) //get user input
    {
        fprintf(stdout, "error reading input\n"); //some problem accar with reading
        return NULL;
    }
    size_t len = strlen(buffer); //length of string without \0
    if (len > 0 && buffer[len - 1] == '\n') //change the enter to end line
    {
        buffer[len - 1] = '\0'; // remove newline character
        len--;
    }
     //"bufsize" number of characters in buffer, "stdin" standard input (keyboard input)
    char *string = malloc(len + 1); // allocate memory for string
    if (string == NULL) //no space found
    {
        fprintf(stderr, "Memory allocation error\n");
        return NULL;
    }
    strcpy(string, buffer); //copy string
    if (string != NULL)
    {
        fputs(string, stdout); //print the string
        free(string);  // Don't forget to free the allocated memory
    }
    return string;
}
//find the file the user want. if fail returns 0
int input_file()
{
    
}
//open the file for editing. if fail return 0
int open_file()
{

}
//close the file for editing.
int close_file()
{

}
//read all text from file. if fail returns 0
int read_from_file()
{

}

