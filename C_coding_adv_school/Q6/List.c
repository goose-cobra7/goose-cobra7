#include "List.h"

List makeEmptyList()
{
	List list = { EMPTY_LIST, EMPTY_LIST, 0 };
	return list;
}

int removeFromHead(List* list)
{

	int toReturn = list->head->data; //save return value
	Node* temp = list->head->next; //save new list head
	free(list->head);
	list->head = temp;//update list
	//check if list has become empty after removal
	if (list->head == EMPTY_LIST)
	{
		list->tail = EMPTY_LIST;//update list
	}

	--list->size;//update list
	return toReturn;
}

void printList(const List* list)
{
	if (list->head == EMPTY_LIST)
	{
		return;
	}

	Node* temp = list->head;
	while (temp != LIST_END)
	{
		printf("%d->", temp->data);
		temp = temp->next;
	}

	printf("NULL\n");
}

BOOL addToTail(List* list, int data)
{
	//create new list node
	Node* newTail = (Node*)calloc(1, sizeof(Node));
	if (newTail == NULL)
	{
		return FALSE;
	}
	newTail->data = data;
	//case this is very first list element added to empty list
	if (list->tail == EMPTY_LIST)
	{
		list->head = list->tail = newTail;//update list
	}
	else //list has at least one element
	{
		list->tail->next = newTail;
		list->tail = newTail;//update list
	}

	++list->size;//update list
	return TRUE;
}

BOOL isEmptyList(const List* list)
{
	//triple check for testing purposes
	return (list->head == EMPTY_LIST && list->tail == EMPTY_LIST && list->size == 0);
}

void destroyList(List* list)
{
	if (list == NULL)
	{
		return;
	}

	Node* toDestroy = list->head;
	Node* next;
	while (toDestroy != LIST_END)
	{
		next = toDestroy->next;
		free(toDestroy);
		toDestroy = next;
	}

	list->head = list->tail = EMPTY_LIST;//update list
	list->size = 0;//update list
}

BOOL addToHead(List* list, int data)
{
	//create new list node
	Node* newHead = (Node*)calloc(1, sizeof(Node));
	if (newHead == NULL)
	{
		return FALSE;
	}
	newHead->data = data;
	//case this is very first list element added to empty list
	if (list->head == EMPTY_LIST)
	{
		list->head = list->tail = newHead;//update list
	}
	else //list has at least one element
	{
		newHead->next = list->head;
		list->head = newHead;//update list
	}
	++list->size;
	return TRUE;
}

int removeFromTail(List* list)
{
	//temp nodes to iterate over list and find the element previous to tail
	Node* current = list->head;
	Node* previous = NULL;
	while (current->next != LIST_END)
	{
		previous = current;
		current = current->next;
	}

	int toReturn = current->data;//save return value
	free(current);
	list->tail = previous;//update list
	//check if list has become empty after removal
	if (list->tail == EMPTY_LIST)
	{
		list->head = EMPTY_LIST;//update list
	}
	else
	{
		list->tail->next = LIST_END;//update tail to point to null (was previously pointing to freed element)
	}

	--list->size;
	return toReturn;
}

int peekHead(const List* list)
{
	return list->head->data;
}

int getListSize(const List* list)
{
	return list->size;
}