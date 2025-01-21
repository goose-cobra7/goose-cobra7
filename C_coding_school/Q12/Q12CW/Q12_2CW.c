#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BFFER 50

// Define a struct to store student information
typedef struct Student {
    char studentID[10];
    char name[50];
}Student;

typedef struct Class{
    int class_size;
    Student *students;
}Class;
//functions
void add_student(Class *this_class);
Class create_test_class();
Class printfStudent(Class this_class);
void printStudent(Student s1); 
void main() 
{ 
    Class myclass = create_test_class();
    printf("do you want to add a students to the class: Y / N");
    char choise = 0;
    scanf("%c", &choise);
    if (choise == 'Y'||choise == 'y')
    {
        printf("how many students do you want to add: ");
        int choise = 0;
        scanf("%d", &choise);
        for (int i = 0; i < choise; i++)
        {
            add_student(&myclass);
        }
    }
    printfStudent(myclass);
}

void printStudent(Student s1)
{
    printf("Student ID: %s \n", s1.studentID);
    printf("Name: %s \n", s1.name);
}

Class printfStudent(Class this_class)
{
    for (int i = 0; i < this_class.class_size; i++)
    {
        printStudent(this_class.students[i]);
        printf("\n");
    }
    
}

Class create_test_class()
{
    Class my_class;
    my_class.class_size = 2;
    my_class.students = (Student *)malloc(sizeof(Student) * my_class.class_size);
    strcpy(my_class.students[0].studentID, "12345\n");
    strcpy(my_class.students[0].name, "John Doe\n");
    strcpy(my_class.students[1].studentID, "67890\n");
    strcpy(my_class.students[1].name, "Jane Smith\n");
    return my_class;
}

void add_student(Class *this_class)
{
    this_class->class_size++;
    Student* temp_ptr = realloc(this_class->students, this_class->class_size);
    if (temp_ptr == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    this_class->students = temp_ptr;
    char* tempname = malloc(MAX_BFFER);
    printf("please enter the student name: ");
    fseek(stdin, 0, SEEK_END);
    fgets(tempname,MAX_BFFER,stdin);
    strcpy(this_class->students[this_class->class_size - 1].name, tempname);
    printf("please enter the student ID: ");  
    fseek(stdin, 0, SEEK_END);  
    char* tempid = malloc(MAX_BFFER);
    fgets(tempid,MAX_BFFER,stdin);
    strcpy(this_class->students[this_class->class_size - 1].studentID, tempid);
    free(tempname);
    free(tempid);
    
}
