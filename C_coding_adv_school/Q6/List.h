#pragma once
#ifndef _LIST_ADT_INCLUDE_GUARD__
#define _LIST_ADT_INCLUDE_GUARD__

#include <stdio.h>
#include <stdlib.h>

typedef unsigned int BOOL;

#define TRUE 1
#define FALSE 0

#define LIST_END NULL
#define EMPTY_LIST NULL

#define LIST_POINTER_ERROR "Error - NULL pointer.\n"
#define BAD_ALLOC "Error - allocation error.\n"

/**
 * Node implements a singly linked list (sll) node
 */
typedef struct Node
{
	int data; /**< The value stored in the node */
	struct Node* next; /**< Points to the next list element. can be NULL*/
}Node;

/**
 * Struct List is the managing structure for the ADT List.\n
 */
typedef struct List
{
	Node* head; //!< pointer to an sll Node. this is the list's head
	Node* tail; //!< pointer to an sll Node. this is the list's tail
	int size; //!< the number of elements in the list
} List;

/**
 * \brief Creates and returns an empty list.
 *
 * \return An empty List object, ready for use.
 * \public \memberof List
 */
List makeEmptyList();

/**
 * \brief adds an element to the head of the list.
 *
 * \param list Pointer to the list being initialized.
 * \param data The value to add as element at the head of the list.
 * \return TRUE if the operation was successful, FALSE otherwise.
 * \attention Assumes list has been properly initialized.
 * \public \memberof List
 */
BOOL addToHead(List* list, int data);

/**
 * \brief removes the first element from a list and returns it's data value
 *
 * \param list The list to remove an element from.
 * \returns the first element in the list
 * \attention Assumes list has been properly initialized.
 * \warning Calling this method on an empty list results in undefined behavior.
 * \public \memberof List
 */
int removeFromHead(List* list);

/**
 * \brief adds a new element with value data to the end of a list.
 *
 * \param list The list to append an element to.
 * \param data The value to add as element at the tail of the list.
 * \return TRUE if the operation was successful, FALSE otherwise.
 * \attention Assumes list has been properly initialized.
 * \public \memberof List
 */
BOOL addToTail(List* list, int data);

/**
 * \brief finds the last element of the list, removes it and returns it's value.\n
 *
 * \param list The list to remove an element from.
 * \returns the last element in the list
 * \attention Assumes list has been properly initialized.
 * \warning Calling this method on an empty list results in undefined behavior.
 * \public \memberof List
 */
int removeFromTail(List* list);

/**
 * \brief outputs the list elements, from head through tail into the standard output.\n
 * this method does not change the list.
 * \param list The list to print.
 * \attention Assumes list has been properly initialized.
 * \public \memberof List
 */
void printList(const List* list);

/**
 * \brief checks if a list is empty.\n
 * this method does not change the list.
 * \param list The list to check for emptiness.
 * \returns 1 (true) if the list is empty, 0 (false) otherwise
 * \attention Assumes list has been properly initialized.
 * \attention Calling isEmpty on a destroyed list returns true but should be regarded as undefined behavior.
 * \public \memberof List
 */
BOOL isEmptyList(const List* list);

/**
 * \brief returns the value of the first element in the list.\n
 * this method does not change the list.
 * \param list The list to check for emptiness.
 * \returns the value of the first element in the list
 * \attention Assumes list has been properly initialized.
 * \warning Calling peekHead on an empty list results in undefined behavior.
 * \public \memberof List
 */
int peekHead(const List* list);

/**
 * \brief returns the number of elements in the list.\n
 * this method does not change the list.
 * \param list The list to check for emptiness.
 * \returns the number of elements in the list
 * \attention Assumes list has been properly initialized.
 * \public \memberof List
 */
int getListSize(const List* list);

/**
 * \brief frees/deallocates all resources used by struct list\n
 *	- destroying an already destroyed list has no effect.\n
 *  - destroying a NULL pointer has no effect.
 * \param list - The list to destroy
 * \attention Assumes list has been properly initialized.
 * \warning destroying a list that has never been initialized results in undefined behavior
 * \public \memberof List
 */
void destroyList(List* list);

#endif