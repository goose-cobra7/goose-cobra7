#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FALSE 0
#define TRUE 1

typedef struct node
{
	int key;
	struct node* next;
	struct node* prev;
}Node;

typedef struct list
{
	Node* head;
	Node* tail;
}List;

//פונקציית ממשק - מאתחלת מבנה מנהל של רשימה דו-כיוונית
void initList(List* list);

//פונקציית ממשק - מוסיפה לסוף הרשימה המקושרת הדו-כיוונית
int addToTail(List* list, int data);

//פונקציית ממשק - משחררת את משאבי הרשימה הדו-כיוונית
void freeList(List* list);

//פונקציית ממשק - מדפיסה את הרשימה הדו-כיוונית
void printList(const List* list);

//פונקציית ממשק - מחזירה אמת <--> הרשימה ריקה
int isEmpty(const List* list);

//******************* 1 - easy) IMPLEMENT THIS INTERFACE FUNCTION
//הפונקציה יוצרת רשימה חדשה ובה כל האיברים עם המפתחות החיוביים בלבד
//הפונקציה מקצה צמתים חדשות לרשימה החדשה ולא מצביעה לצמתים ברשימה הישנה
List allPositive(const List* list);

//******************* 2 - medium) IMPLEMENT THIS INTERFACE FUNCTION
//הפונקציה מסירה את האיבר עם המפתח הגדול ביותר ברשימה ומחזירה אותו
//הפונקציה מניחה שהרשימה לא ריקה ושמפעיל הפונקציה אחראי לבדוק שאינה ריקה בעזרת
//	isEmpty
int removeLargest(List* list);

//******************* 3 - hard) IMPLEMENT THIS INTERFACE FUNCTION
//הפונקציה ממיינת את הרשימה בסדר עולה של המפתחות
void sortList(List* list);

int main()
{
	srand((unsigned int)time(NULL));

	List list;
	initList(&list);

	for (int i = 0; i < 10; i++)
	{
		addToTail(&list, rand() % 100 - 50);
	}
	printList(&list);

	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", removeLargest(&list));
		printList(&list);
	}
	List list_pos = allPositive(&list);
	printList(&list_pos);
	freeList(&list);
	return 0;
}

void initList(List* list)
{
	list->head = NULL;
	list->tail = NULL;
}

int addToTail(List* list, int data)
{
	Node* newNode = (Node*)calloc(1, sizeof(Node));
	if (newNode == NULL)
		return FALSE;

	newNode->key = data;

	if (list->head == NULL)
	{
		list->head = newNode;
		list->tail = newNode;
	}
	else
	{
		list->tail->next = newNode;
		newNode->prev = list->tail;
		list->tail = newNode;
	}

	return TRUE;
}

void freeList(List* list)
{
	Node* curr = list->head;
	while (curr != NULL)
	{
		Node* temp = curr->next;
		free(curr);
		curr = temp;
	}

	list->head = NULL;
	list->tail = NULL;
}

void printList(const List* list)
{
	Node* curr = list->head;
	printf("NULL <-->");
	while (curr != NULL)
	{
		printf(" %d <-->", curr->key);
		curr = curr->next;
	}
	printf(" NULL\n");
}

int isEmpty(const List* list)
{
	return list->head == NULL;
}

List allPositive(const List* list)
{
	List *new_list = malloc(sizeof(List));
	initList(new_list);
	if(!new_list){exit ;}
	Node *reader = list->head;
	while (reader)
	{
		if(reader->key >= 0)
		{
			addToTail(new_list,reader->key);
		}
		reader = reader->next;
	}
	return *new_list;
}

int removeLargest(List* list)
{
	
}

void sortList(List* list)
{
	
}