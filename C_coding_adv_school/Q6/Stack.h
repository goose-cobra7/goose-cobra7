#pragma once
#ifndef _STACK_H_INC_GUARD__
#define _STACK_H_INC_GUARD__

#include "List.h"

typedef struct
{
	List list;//hiding a list behind the admin struct of stack
} Stack;

/**
 * @brief Creates and returns an empty stack.
 *
 * @return An empty stack.
 */
Stack makeEmptyStack();

/**
 * @brief Pushes a value onto the stack.
 *
 * @param[in] stack - The stack to push the value onto.
 * @param[in] value - The value to push onto the stack.
 * @return @c TRUE if the push was successful, @c FALSE otherwise.
 */
BOOL push(Stack* stack, int value);

/**
 * @brief Pops the top value from the stack and returns it.
 *
 * @param[in,out] stack The stack to pop the value from.
 * @return The top value from the stack, or undefined if the stack is empty.
 */
int pop(Stack* stack);

/**
 * @brief Checks if the stack is empty.
 *
 * @param[in] stack The stack to check.
 * @return @c TRUE if the stack is empty, @c FALSE otherwise.
 */
BOOL isStackEmpty(const Stack* stack);

/**
 * @brief Peeks at the top value of the stack.
 *
 * @param[in] stack The stack to peek at.
 * @return The top value of the stack, or undefined if the stack is empty.
 */
int peekStack(const Stack* stack);

/**
 * @brief Returns the size of the stack.
 *
 * @param[in] stack The stack to get the size of.
 * @return The size of the stack.
 */
int getStackSize(const Stack* stack);

/**
 * @brief Destroys the stack, freeing any allocated memory.
 *
 * @param[in] stack The stack to destroy.
 */
void destroyStack(Stack* stack);

#endif // !_STACK_H_INC_GUARD__
