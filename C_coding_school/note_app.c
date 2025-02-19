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


char* make_string();
void print_note(struct note note_t_print);
note make_new_note();
note* add_new_note_to_list(note* note_list);

int main()
{
    note* note_list = {0};
    while (1)
    {
        int choise;
        scanf("%d",choise);
        switch (choise)
        {
        case 1:
            printf("--new note--\nheader: ");
            note_list = add_new_note_to_list(note_list);
            break;
        
        default:
            break;
        }
    }
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

void print_note(const note note_t_print)
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

note* add_new_note_to_list(note* note_list)
{
    note new_note = make_new_note();
    int place = find_place_for_new_note(note_list);//find empty slot
    if (strlen(note_list) <= place)
    {
        realloc(note_list,strlen(note_list)+1);
    }
    note_list[place] = new_note;
    edit_note(note_list,place);
    return note_list;
}

int find_place_for_new_note(note* note_list)
{
    int place = 0;
    while (note_list != '\0')
    {
        place++;
    }
    return place;
}

note* edit_note(note* note_list,int place)
{
    
}