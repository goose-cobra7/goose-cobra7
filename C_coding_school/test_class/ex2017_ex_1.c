#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Student
{
    char name[12];
    float grade;
    char last;
}Student;


int main(int argc, char const *argv[])
{
    
    return 0;
}

void printStudentList(Student* std)
{
    int i = 0;
    do
    {
        printf("name: %s\n grade: %f\n",std[i].name,std[i].grade);
        if(std[i].last == '#') {break;}
        i++;
    } while (1);
}

Student *add_student(Student *std_list)
{
    Student new_student; //newstudent
    printf("enter name: "); 
    scanf("%s",&new_student.name);
    printf("enter grade: ");
    scanf("%f",&new_student.grade); //finish define new student
    int i = 0; //counter
    while (std_list[i].last != '#')//find std_list leangh
    {
        i++;
    }
    Student *new_std_list = (Student*)realloc(std_list,(i+2)*sizeof(Student));//expend memory by 1
    if (new_std_list == NULL)
    {
        printf("no more free memory");
        exit(0);
    }
    
    std_list[i].last = '0';//last student not last anymore
    std_list[i+1] = new_student; //put new student
    std_list[i+1].last = '#';//is now new last student
    free(std_list);
    return new_std_list;
}