#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define ID_SIZE 10
typedef char id_t[ID_SIZE];//type definition for string of length ID_SIZE

typedef struct grade
{
	const char* course;//pointer to course string (this string is allocated somewhere else and only pointed to from here)
	int score;
}Grade;

typedef struct student
{
	id_t id;//here, id is a string of length 10. type defined above.
	//it's a string because some id's begin with 0
	char* name;//dynamic name string
	Grade* grades;//a dynamic grade array
	int numGrades;//grade array allocation size
}Student;

typedef struct classroom
{
	Student* students;//a dynamic student array
	int classSize;//array allocation size
}Classroom;


void printStudent(const Student* s);
void printClassroom(Classroom c);
const Student* findHighestAverage(Classroom c);
const Student* findStudentById(Classroom c, const id_t id);
void removeStudent(Classroom* c, const Student* s);
void print_js_students(Classroom c); //just for debug

/*auxiliary function used for freeing*/

//frees a single student
void freeStudent(Student* s);

//iterates over all allocated students and frees them
void freeClassroom(Classroom* c, int numberOfAllocatedStudents);

int main()
{
	srand((unsigned)time(NULL));
	//making up some data for the exercise (assume in a real application, this data comes from files/databases/web Api's)
	const char* courses[] = { "C++", "Java", "Python", "C", "C#" , "PHP", "JavaScript", "Ruby", "Go", "Swift", "Rust", "SQL", "HTML", "CSS" };//array of course names
	const char* names[] = { "John", "Jane", "Jack", "Jill", "Joe", "Judy" ,	"Johnathan", "Mark", "Samantha", "Bob", "Ann" , "Tim", "Katie", "Sarah" };//array of student names
	const id_t ids[] = { "012345780", "547224732", "123553216", "877423233", "111222345", "999999999" , "000000000", "111111111", "222222222", "444444444", "555555555", "666666666", "888888888", "232323232" };//array of student ids

	//The following /***/ creates a random sized classroom
	/***/
	Classroom bestClass = { NULL, rand() % _countof(names) + 1 };//randomized class size
	bestClass.students = (Student*)calloc(bestClass.classSize, sizeof(Student));
	if (bestClass.students == NULL)
	{
		printf("Error! - memory allocation failed. exiting...\n");
		exit(1);
	}
	//! end of classroom creation

	//The following /***/ creates each student in the random sized classroom
	/***/
	for (int i = 0; i < bestClass.classSize; i++)
	{
		strcpy(bestClass.students[i].id, ids[i]);
		bestClass.students[i].name = _strdup(names[i]);// str duplicate can fail.
		bestClass.students[i].numGrades = rand() % _countof(courses) + 1;//randomized number of courses, at least one.
		bestClass.students[i].grades = (Grade*)calloc(bestClass.students[i].numGrades, sizeof(Grade));//this allocation can fail

		if (bestClass.students[i].grades == NULL
			|| bestClass.students[i].name == NULL)
		{
			printf("Error! - memory allocation failed. exiting...\n");
			freeClassroom(&bestClass, i + 1);//free all memory resources allocated so far.
			exit(1);
		}

		//randomize student i course grades array
		for (int j = 0; j < bestClass.students[i].numGrades; j++)
		{
			//randomized courses - I'm allowing a student to have repeat courses
			bestClass.students[i].grades[j].course = courses[rand() % _countof(courses)];//only point to existing string, no allocation
			bestClass.students[i].grades[j].score = rand() % 61 + 40;//randomized score
		}
	}
	//! end of students creation


	printClassroom(bestClass);

	const Student* highest = findHighestAverage(bestClass);
	if (highest != NULL)
	{
		printf("The student with Highest average is %s, with id %s\n", highest->name, highest->id);
		printf("\n\nRemoving student %s, with id %s\n", highest->name, highest->id);
		removeStudent(&bestClass, highest);
	}


	printClassroom(bestClass);

	highest = findHighestAverage(bestClass);
	if (highest != NULL)
	{
		printf("After removal of previous student, The student with Highest average is %s, with id %s\n", highest->name, highest->id);
		printf("\n\nRemoving student %s, with id %s\n", highest->name, highest->id);
		removeStudent(&bestClass, highest);
	}


	printClassroom(bestClass);
	//print_js_students(bestClass);
	freeClassroom(&bestClass, bestClass.classSize);// if we reached so far, all students were allocated successfully, so numberOfAllocatedStudents is the classroom size

	return 0;
}

void printStudent(const Student* s)
{
	printf("name: %s\n",s->name);
	printf("ID: %s\n",s->id);
	printf("Grades:\n");
	float grad_sum = 0;
	for (size_t i = 0; i < s->numGrades; i++)
	{
		printf("%s:",s->grades[i].course);
		printf("%d\n",s->grades[i].score);
		grad_sum += s->grades[i].score;
	}
	printf("Avrage: %f\n\n",grad_sum/s->numGrades);
}

const Student* findHighestAverage(Classroom c)
{
	struct student *highestI;
	float high_stG = 0;
	float Stu_Av = 0;
	for (size_t i = 0; i < c.classSize ; i++)
	{
		Stu_Av = 0;
		for (size_t j = 0; j < c.students[i].numGrades ; j++)
		{
			Stu_Av += c.students[i].grades[j].score;
		}
		Stu_Av = Stu_Av/c.students[i].numGrades;
	if (Stu_Av > high_stG)
	{
		high_stG = Stu_Av;
		highestI = c.students+i;
	}
	}
	
	return highestI;
}

void removeStudent(Classroom* c, const Student* s)
{
	int index = -1;
	for (int i = 0; i < c->classSize; i++)
	{
		if (c->students+i == s)
		{
			index = i;
			break;
		}
		
	}
	if (index == -1)
	{
		printf("error student not found"); //error
	}
	free(c->students[index].name);
	free(c->students[index].grades);
	for (int i = index; i < c->classSize-1; i++)
	{
		c->students[i] = c->students[i+1];
	}
	c->classSize--;
	c->students = (Student*)realloc(c->students,c->classSize * sizeof(Student));
	if (c->students == NULL && c->classSize > 0)
	{
		printf("error: memory reallocation failed!! ");
		exit(1);
	}
	
}

void printClassroom(Classroom c)
{
	for (size_t i = 0; i < c.classSize; i++)
	{
		printStudent(c.students+i);
	}
	
}

void freeStudent(Student* s)
{
	free(s->grades);
	free(s->name);
}

void freeClassroom(Classroom* c, int numberOfAllocatedStudents)
{
	for (size_t i = 0; i < numberOfAllocatedStudents; i++)
	{
		freeStudent(c->students+i);
	}
	
}

const Student* findStudentById(Classroom c, const id_t id)
{
	struct student *ptr;
	int i = 0;
	while (!ptr)
	{
		if (c.students[i].id == id)
		{
			ptr = &c.students[i];
			return ptr;
		}
		i++;
	}
	printf("student was not found:");
	return NULL;
}

//print just students as list for debuging
void print_js_students(Classroom c)
{
	for (size_t i = 0; i <  c.classSize; i++)
	{
		printf(" %s/n",c.students[i].name);
	}
}