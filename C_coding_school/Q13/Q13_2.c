#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct birth_date
{
    int year;
    int month;
    int day;
}birth_date;

typedef struct human
{
    int id;
    char* name;
    char* family;
    birth_date birth_date_h;
}human;

typedef struct student
{
    human _human_;
    float avrage_grade;
    int points;
    int semester;
}student;
student init_5_stu();
int human_age(human _human_,int year);
int student_age(student _student_,int year);
float age_avarge(student* stu_arr,int arr_size);
char* create_string();
student change_student(student *stu_arr,int arr_place);
student print_stu(student stu);
student* init_5_stu_no_input();


int main(int argc, char const *argv[])
{
    student stu_arr = init_5_stu();
    return 0;
}

int human_age(human _human_,int year)
{
    return (year-(_human_.birth_date_h.year));
}

int student_age(student _student_,int year)
{
    return (human_age(_student_._human_,year));
}

float age_avarge(student* stu_arr,int arr_size)
{
    printf("enter the year:");
    int year;
    scanf("%d",&year);
    float avarege;
    for (int i = 0; i < arr_size; i++)
    {
        avarege += student_age(stu_arr[i],year);
    }
    avarege = avarege/arr_size;
    return avarege;
}

char* create_string()
{
    char buffer[100];
    fseek(stdin,0,SEEK_END);
    fgets(buffer,100,stdin);
    char* new_string = malloc(strlen(buffer)*sizeof(char)+1);
    strcpy(new_string,buffer);

    return new_string;
}

student change_student(student *stu_arr,int arr_place)
{
    printf("enter ID,name,family name:");
    int ID;
    scanf("%d",&ID);
    char *name = create_string();
    char *family_name = create_string();
    stu_arr[arr_place]._human_.id = ID;
    stu_arr[arr_place]._human_.name = name;
    stu_arr[arr_place]._human_.family = family_name;
    printf("enter birth date:day,month,year");
    int day,month,year;
    scanf("%d %d %d",&day,&month,&year);
    stu_arr[arr_place]._human_.birth_date_h.day = day;
    stu_arr[arr_place]._human_.birth_date_h.month = month;
    stu_arr[arr_place]._human_.birth_date_h.year = year;
    printf("enter avarage grade:");
    float avarage_grade;
    scanf("%f",&avarage_grade);
    printf("enter points:");
    int points;
        scanf("%d",&points);
    printf("enter semester:");
    int semester;
    scanf("%d",&semester);
    stu_arr[arr_place].avrage_grade = avarage_grade;
    stu_arr[arr_place].points = points;
    stu_arr[arr_place].semester = semester;
}

student print_stu(student stu)
{
    printf("student Id:%d\n",stu._human_.id);
    printf("student name: %s\n",stu._human_.name);
    printf("student family name: %s\n",stu._human_.family);
    printf("birth date: %d %d %d\n",stu._human_.birth_date_h.day,stu._human_.birth_date_h.month,stu._human_.birth_date_h.year);
    printf("avrage grade: %f\n",stu.avrage_grade);
    printf("points: %d\n",stu.points);
    printf("semester: %d\n",stu.semester);
}

student init_5_stu() //create 5 students
{
    student stu_arr[5];
    for (int i = 0; i < 5; i++)
    {
        change_student(stu_arr,i);
    }
    for (int i = 0; i < 5; i++)
    {
        print_stu(stu_arr[i]);
    }
    printf("avarge age: %f",age_avarge(stu_arr,5));
}

student* init_5_stu_no_input() // Initialize 5 students without input
{
    student* stu_arr = (student*)malloc(5 * sizeof(student));

    for (int i = 0; i < 5; i++)
    {
        stu_arr[i]._human_.id = i + 1;
        stu_arr[i]._human_.name = "Name";
        stu_arr[i]._human_.family = "Family";
        stu_arr[i]._human_.birth_date_h.day = 1 + i;
        stu_arr[i]._human_.birth_date_h.month = 2 + i;
        stu_arr[i]._human_.birth_date_h.year = 2000 + i;
        stu_arr[i].avrage_grade = 85.0 + i;
        stu_arr[i].points = 10 + i;
        stu_arr[i].semester = 1 + i;
    }
    return stu_arr;
}