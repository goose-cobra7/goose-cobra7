#include "List.c"
#include "Stack.c"
#include "Queue.c"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int countHungry(Stack* sandwiches, Queue* customers);

#define PEOPLE_SANDWITCH_COUNT 7//experiment with this value for the randomized test
#define SANDWITCH_TYPES 3//experiment with this value after solving for 3 sandwich types

int main()
{
	srand((unsigned)time(NULL));
	int hungryCustomers = 0;

	Stack sandwiches = makeEmptyStack();
	Queue customers = makeEmptyQueue();

	/*RANDOMIZED TEST*/
	//uncomment this section for a randomized test (remember to comment out the deterministic test)
	for (int i = 0; i < PEOPLE_SANDWITCH_COUNT; i++)
	{
		enqueue(&customers, rand() % SANDWITCH_TYPES);
		push(&sandwiches, rand() % SANDWITCH_TYPES);
	}

	/*DETERMINISTIC TEST - CORRECT RESULT IS 3*/
	//uncomment this section for a deterministic test. result should be 3 ((remember to comment out the randomized test)
	/*int sandwitchArray[] = { 2, 2, 0, 2, 2, 1, 2, 0, 1 };
	int customersArray[] = { 1, 2, 1, 0, 2, 1, 2, 2, 2 };
	for (int i = 0; i < _countof(sandwitchArray); i++)
	{
		enqueue(&customers, customersArray[i]);
		push(&sandwiches, sandwitchArray[i]);
	}*/

	hungryCustomers = countHungry(&sandwiches, &customers);

	destroyStack(&sandwiches);
	destroyQueue(&customers);

	printf("There were %d customers still hungry by the end of lunch.\n", hungryCustomers);
	return 0;
}

int countHungry(Stack* sandwiches, Queue* customers)
{
	int sandwich_top;
	int customer_top;
	int size = getQueueSize(customers);
	int count = 0;
	while (1)
	{
		sandwich_top = peekStack(sandwiches);
		customer_top = peekQueue(customers);
		if (sandwich_top == customer_top)
		{
			dequeue(customers);
			pop(sandwiches);
			size = getQueueSize(customers);
			if (size == 0)
			{
				return size;
			}
			count = 0;
		}else{
			enqueue(customers,dequeue(customers));
			count++;
			if (count == size)
			{
				return size;
			}
		}
		
	}
	
}