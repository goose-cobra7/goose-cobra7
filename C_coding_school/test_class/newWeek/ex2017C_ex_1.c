#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student
{
    char name[12];
    int grade;
    char last;
}student;


int main(int argc, char const *argv[])
{
    
    return 0;
}

void print_student(student *S)
{
    int i = 0;
    do
    {
        printf("name: %s/n",S[i].name);
        printf("grade: %d/n/n",S[i].grade);
        i++;
    }while(S->last != '#');   
}

student* add_student(student *S)
{
    int end = 0;
    while(S[end].last != '#') {end++;}//fine size of array
    student *new_S = (student*)realloc(S,(end+2)*sizeof(student));//new memory palce
    if (new_S == NULL){printf("memory allo' failed");}
    printf("enter student name: ");
    gets(new_S[end+1].name);
    printf("\nenter grade: ");
    scanf("%d",&new_S[end+1].grade);
    new_S[end].last = NULL; //move "last" to the last
    new_S[end+1].last = '#';
    return new_S;
}
