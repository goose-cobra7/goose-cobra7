#include <stdio.h>

// Define a struct to store student information
typedef struct Student {
    char studentID[10];
    char name[50];
}Student;
//function
void printStudent(Student s1);
void main() 
{ 
    Student s1= {0,0}; 
    scanf("%s",&s1.studentID);
    scanf("%s",&s1.name);
    printStudent(s1);
}

void printStudent(Student s1)
{
    printf("Student ID: %s\n", s1.studentID);
    printf("Name: %s\n", s1.name);
}