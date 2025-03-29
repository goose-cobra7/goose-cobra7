#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* CLASS EX */

//1.ממשו את הפונקציה שבודקת אם קיימת לולאה ברשימה המקושרת
//2. ממשו פונקציה שמתקנת את הלולאה



#define TRUE 1
#define FALSE 0

// Define the structure of a node in the linked list
typedef struct Node {
    int data;
    struct Node* next;
}Node;

void freeList(Node* head);

//בפונקציה הזאת יש באג. במיקום מסויים ברשימה יש לולאה
Node* makeListWithLoop(int len);

Node* makeList(int len);

//הפונקציה תחזיר אמת אם ברשימה המקושרת שראשה הד יש לולאה ותחזיר שקר אחרת
int isLooped(Node* head,int* isResultValid);//את זה צריך לממש

int main() {
    srand(time(NULL));
    Node* headWithLoop = NULL; // Initialize head to NULL
    Node* headNoLoop = NULL; // Initialize head to NULL
   
    headWithLoop = makeListWithLoop(10);
    headNoLoop = makeList(10);

    int validRes = FALSE;//a variable for returning if the result of isLooped
    //is a valid boolean result or an error value.
    int loop = isLooped(headWithLoop, &validRes);
    if (!validRes)
    {
        printf("isLooped Failed to answer due to internal error...\n");
        exit(EXIT_FAILURE);
    }

    switch (loop)
    {
    case TRUE:
        printf("The list contains a loop!\n");
        break;
    case FALSE:
        printf("The list does not contain a loop!\n");
        break;
    default:
        break;
    }


    loop = isLooped(headNoLoop, &validRes);
    if (!validRes)
    {
        printf("isLooped Failed to answer due to internal error...\n");
        exit(EXIT_FAILURE);
    }
    switch (loop)
    {
    case TRUE:
        printf("The list contains a loop!\n");
        break;
    case FALSE:
        printf("The list does not contain a loop!\n");
        break;
    default:
        break;
    }
    // Free the allocated memory for each node
    freeList(headNoLoop);
    //freeList(headWithLoop); can only be done if we fixed the loop in the list,
    //or at least know the length of the list without the loop. as is, this program leaks memory

    return 0;
}

void freeList(Node* head)
{
    Node* temp;
    while (head != NULL)
    {
        temp = head;//this is the node we want to free
        head = head->next;
        free(temp);
    }
}

Node* makeListWithLoop(int len)
{
    Node* head = NULL;
    Node* temp = NULL; // Temporary pointer for traversal
    Node* newNode = NULL; // Temporary pointer to create new nodes
    int value;

    for (int i = 1; i <= len; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node)); // Allocate memory for new node
        if (newNode == NULL)
        {
            freeList(head);
            return NULL;
        }
        value = rand() % 10;

        newNode->data = value; // Set the data for the new node
        newNode->next = NULL; // Set the next pointer to NULL

        // If the list is empty, make the new node the head
        if (head == NULL) {
            head = newNode;
        }
        else {
            // Otherwise, find the last node and link it to the new node
            // note - this is very inefficient
            temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    temp = head;
    for (int i = 0; i < len / 2; i++)
        temp = temp->next;

    Node* tail = temp;
    while (tail->next != NULL)
        tail = tail->next;

    tail->next = temp;
    return head;
}

Node* makeList(int len)
{
    Node* head = NULL;
    Node* tail = NULL;
    if (len <= 0) return head;

    head = calloc(1, sizeof(Node));
    if (head == NULL) return head;

    //special case for first element
    head->data = rand();
    tail = head;

    for (int i = 1; i < len; i++)
    {
        Node* temp = calloc(1, sizeof(Node));
        if (temp == NULL)
        {
            freeList(head);
            return NULL;
        }
        temp->data = rand();
        tail->next = temp;
        tail = temp;
    }

    return head;
}

//assume that if the function encounters an error, it returns false (but changes isResultValid to false)
int isLooped(Node* head, int* isResultValid)//את זה צריך לממש
{


    Node *Jp = head; //slow ass
    Node *Ip = head; //fast ass
    int dis = 0; 
    int over_all_Jp = 0,over_all_Ip = 0;
    int new_distance = 0, old_distance = 1;
    while (new_distance < old_distance)
    {
        new_distance = old_distance; 
        old_distance = 0; //reset distance checker
        Ip = head->next;
        if(Ip == NULL){return 0;}
        Ip = head->next;
        if(Ip == NULL){return 0;}
        if (Ip == Jp)
        {
            break;
        }
        Jp = head->next; 
        over_all_Jp++;
        over_all_Ip += 2;
        
    }



    return TRUE;
    /*Method 1 - very very inefficient*/

    //1.iterate over the list and for every node do the following
    //2.    save the address of the current node in a dynamic array
    //3.    if, when inserting the address to the array,
    //      it is already found in
    //      the array, the aswer is YES (a loop exists)
    //      //### reallocate the array if it gets full
    //4. if NULL is reached, the answer in NO (a loop doesn't exist)

    /*method 1 - sol */

    /*Method 2 - classic solution*/
    //race between 2 pointers - fast pointer, slow pointer
    
}