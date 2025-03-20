#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_BUFF 254
#define INI_FILE "startup.ini"
#define data_key "Welcome_Phrase=\""

char *get_user_input();
FILE *create_start_file();
char *find_data(char *data_string,FILE *pfile);
char ask_user_Y_N();
void print_File_data(FILE *pfile, char *data_type);
int change_data_phrase(char *data_string,FILE *pfile,char *new_phrase);

int main()
{
    FILE *pfile = fopen(INI_FILE,"r+");
    if (!(pfile))
    {
        printf("enter welcome phrase");
        pfile = create_start_file();
    }else{
    print_File_data(pfile,data_key);
    }
    char user_input = -1;
    do
    {   
        printf("do yo want to change wP(Y/N):\n");
        scanf(" %c",&user_input); //answer
        if (user_input == 'Y' || user_input == 'y')
        {
            printf("enter phrase:\n");
            while ((getchar()) != '\n');
            char new_phrase[STR_BUFF] = {0}; //buffer for input
            fgets(new_phrase,STR_BUFF-1,stdin); //get user input
            change_data_phrase(data_key,pfile,new_phrase);
        }
        
    } while (user_input != 'N'&&user_input != 'n');
    
}

char *get_user_input()
{
    char buffer[STR_BUFF] = {0};
    fgets(buffer,STR_BUFF-1,stdin);
    buffer[strcspn(buffer,"\n")] = '\0';
    char *string = (char*)malloc((strlen(buffer)+1)*sizeof(char));
    strcpy(string,buffer);
    return string;
}

FILE *create_start_file()
{
    FILE *pfile;
    pfile = fopen("startup.ini", "w+");
    char *new_welcome_phrase = get_user_input(); //daynamic
    fprintf(pfile,"Welcome_Phrase=\"%s\"\n",new_welcome_phrase);
    free(new_welcome_phrase);
    fflush(pfile); //save file
    return pfile;
}

char *find_data(char *data_string,FILE *pfile)
{
    char buffer[STR_BUFF] = {0};
    while ((fgets(buffer,STR_BUFF,pfile))!=NULL)
    {
        char *start = strstr(buffer,"Welcome_Phrase=\"");
        if (start)
        {
            char *welcome_phrase_str = (char*)malloc((strlen(start)+1)*sizeof(char));
            int i = 0;
            while (start[i+strlen("welcome_Phrase=\"")] != '"')
            {
                
                welcome_phrase_str[i] = start[i+strlen("welcome_Phrase=\"")]; //copy welcomestring
                i++;
                //without the the "
            }
            welcome_phrase_str[i] = '\0';
            return welcome_phrase_str;
        }
        
    }
    return NULL;
}


void print_File_data(FILE *pfile, char *data_type)
{
    char *string = find_data(data_type,pfile);
    if(string)
    {
        puts(string);
        free(string);
        printf("\n");
    }else
    {
        printf("data not found:\n");
    }
}

int change_data_phrase(char *data_string,FILE *pfile,char *new_phrase)
{
    fseek(pfile,0,SEEK_SET);
    char buffer[STR_BUFF] = {0};
    while ((fgets(buffer,STR_BUFF,pfile))!=NULL)
    {
        char *start = strstr(buffer,data_string);
        if (start)
        {
            int i = 0;
            fseek(pfile,strlen(data_string)-strlen(start),SEEK_CUR);
            while (new_phrase[i] != '\0')
            {
                fprintf(pfile,"%c",new_phrase[i]);
                i++;
            }
            fseek(pfile,-2,SEEK_CUR);
            fputc('"',pfile);
            int j = 0;
            while (j++ < 512)
            {
                if (fgetc(pfile) == EOF)
                {
                    break;
                }
                fseek(pfile,-1,SEEK_CUR);
                if (fgetc(pfile) == '\n')
                {
                    break;
                }
                fseek(pfile,-1,SEEK_CUR);
                fputc(' ',pfile);
            }
            

            fputc('\n',pfile);
            printf("it worked");
            return 1;
        }
        
    }
    return -1;
}

