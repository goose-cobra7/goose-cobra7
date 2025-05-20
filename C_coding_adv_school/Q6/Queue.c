#include "Queue.h"

Queue makeEmptyQueue()
{
	Queue q;
	q.list = makeEmptyList();
	return q;
}

void destroyQueue(Queue* q)
{
	destroyList(&(q->list));
}

void enqueue(Queue* q, int data)
{
	addToTail(&(q->list), data);
}

int dequeue(Queue* q)
{
	return removeFromHead(&(q->list));
}

int peekQueue(const Queue* q)
{
	return peekHead(&(q->list));
}

int isEmptyQueue(const Queue* q)
{
	return isEmptyList(&(q->list));
}

int getQueueSize(const Queue* q)
{
	return getListSize(&(q->list));
}