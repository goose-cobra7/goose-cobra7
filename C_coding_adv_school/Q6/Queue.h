#pragma once
#ifndef __MY_QUEUE_HEADER_
#define __MY_QUEUE_HEADER_

#include "List.h"

typedef struct Queue
{
	List list;
}Queue;


/**
@brief Creates and returns an empty queue.
@return An empty queue.
*/
Queue makeEmptyQueue();

/**
@brief Destroys the queue, freeing any allocated memory.
@param[in] q The queue to destroy. / 
*/
void destroyQueue(Queue* q);

/**
@brief Adds an element to the end of the queue.
@param[in] q The queue to add an element to.
@param[in] data The value to add as an element to the queue. 
*/
void enqueue(Queue* q, int data);

/**
@brief Removes the front element from the queue and returns its value.
@param[in] q The queue to remove an element from.
@return The value of the front element in the queue. 
*/
int dequeue(Queue* q);

/**
@brief Returns the value of the front element in the queue without removing it.
@param[in] q The queue to peek at.
@return The value of the front element in the queue.
*/
int peekQueue(const Queue* q);

/**
@brief Checks if the queue is empty.
@param[in] q The queue to check.
@return 1 (true) if the queue is empty, 0 (false) otherwise. 
*/ 
int isEmptyQueue(const Queue* q);

/**
@brief Returns the number of elements in the queue.
@param[in] q The queue to get the size of.
@return The number of elements in the queue. 
*/
int getQueueSize(const Queue* q);

#endif // !__MY_QUEUE_HEADER_
