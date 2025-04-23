#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node Node;

struct Node
{
	int key;
	Node *next;
};

void freeList(Node *head);
void printList(Node *head);
Node *addSorted(Node *head, int new_key);
int findMode(Node *head);
Node *makeListFromFile(char *filename);
void makeTextFileWithRandomKeys(char *filename, int num_keys);
void remove_last_next(Node *head);

int main()
{
	srand((unsigned)time(NULL));
	Node *head = NULL;
	makeTextFileWithRandomKeys("input.txt", 20);
	head = makeListFromFile("input.txt");
	printList(head);
	printf("The mode of the linked list is %d\n", findMode(head));
	freeList(head);

	return 0;
}

void freeList(Node *head)
{
	while (head != NULL)
	{
		Node *temp = head;
		head = head->next;
		free(temp);
	}
}

void printList(Node *head)
{
	while (head != NULL)
	{
		printf("%d -> ", head->key);
		head = head->next;
	}
	printf("NULL\n");
}

Node *addSorted(Node *head, int new_key)
{
	Node *newNode = calloc(1, sizeof(Node));
	if (newNode == NULL)
	{
		printf("Failed to allocate memory\n");
		return head; // return the original list in case of error
	}

	newNode->key = new_key;

	// 1. Handle edge case - EMPTY LIST
	if (head == NULL)
		return newNode;

	// 2. Handle edge case - key should be new head
	if (new_key < head->key)
	{
		newNode->next = head;
		return newNode;
	}

	// 3. general case
	Node *temp = head;
	while (temp->next != NULL && temp->next->key < new_key)
		temp = temp->next;

	newNode->next = temp->next;
	temp->next = newNode;
	return head;
}

int findMode(Node *head)
{
	int arr[10] = {0};
	Node *head_temp = head;
	while (head_temp->next)
	{
		arr[head_temp->key]++;
		head_temp = head_temp->next;
	}
	//find the most
	int highest = 0;
	int highest_place = 0;
	for (size_t i = 0; i < 10; i++)
	{
		if (highest < arr[i] )
		{
			highest_place = i;
			highest = arr[i];
		}
		
	}
	return highest_place;
}

Node* makeListFromFile(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return NULL;
    }

    Node* head = NULL;
    int num;
    while (fscanf(file, "%d", &num) == 1) {
        head = addSorted(head, num);
    }

    fclose(file);
    return head;
}



void makeTextFileWithRandomKeys(char *filename, int num_keys)
{
	FILE *fp = fopen(filename, "wt");
	if (fp == NULL)
	{
		printf("Failed to open file %s\n", filename);
		return;
	}

	for (int i = 0; i < num_keys; i++)
	{
		fprintf(fp, "%d\n", rand() % 10);
	}
	fclose(fp);
}