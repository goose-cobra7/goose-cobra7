#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* make_string();

#define BUFFER 256

typedef struct note
{
    char* header;
    char* the_note;
    char* connection;
}note;

int main()
{
    char* mystring =  make_string();
    puts(mystring);
    return 0;
}

char* make_string()
{
    char buffer[BUFFER] = {0};
    fgets(buffer,BUFFER,stdin);
    char* string = malloc((strlen(buffer)+1)*sizeof(char));
    if (string == NULL)
    {
        printf("error in memory allocation");
        return NULL;
    }
    strcpy(string,buffer);
    return string;
}

void print_note(struct note note_t_print)
{
    puts(note_t_print.header);
    for (size_t i = 0; i < strlen(note_t_print.the_note) ; i++)
    {
        puts(note_t_print.the_note+i);
    }
    for (size_t i = 0; i < strlen(note_t_print.connection); i++)
    {
        puts(note_t_print.connection);
    }
}

note make_new_note()
{
    char* header = make_string();
    note new_note = {0};
    new_note.header = header;
    return new_note;
}

