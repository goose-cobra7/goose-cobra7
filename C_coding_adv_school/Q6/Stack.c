#include "Stack.h"

Stack makeEmptyStack()
{
	Stack s;
	s.list = makeEmptyList();
	return s;
}

BOOL push(Stack* stack, int value)
{
	return addToHead(&stack->list, value);
}

int pop(Stack* stack)
{
	return removeFromHead(&stack->list);
}

BOOL isStackEmpty(const Stack* stack)
{
	return isEmptyList(&stack->list);
}

void destroyStack(Stack* stack)
{
	destroyList(&stack->list);
}

int peekStack(const Stack* stack)
{
	return peekHead(&stack->list);
}

int getStackSize(const Stack* stack)
{
	return getListSize(&stack->list);
}