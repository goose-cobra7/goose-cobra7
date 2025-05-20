#include "List.c"
#include "Stack.c"
#include <stdlib.h>

void empty_stack(Stack *stack);
void print_menu(int value);
void clear();

int main()
{
    int choise = 0;
    int value = 0;
    Stack data = makeEmptyStack();
    Stack data_history = makeEmptyStack();
    while (TRUE)
    {
        choise = 0;
        print_menu(value);
        scanf("%d",&choise);
        switch (choise)
        {
        case 1:
            value++;
            push(&data,value);
            if (!isStackEmpty(&data_history))
            {
                empty_stack(&data_history);
            }
            
            break;
        case 2:
            value--;
            push(&data,value);
            if (!isStackEmpty(&data_history))
            {
                empty_stack(&data_history);
            }
            break;
        case 3:
            push(&data_history,pop(&data));
            value = data.list.head->data;
            break;
        case 4:
            if(isStackEmpty(&data_history)){break;}
            push(&data,pop(&data_history));
            value = data.list.head->data;
            break;
        case 5:
        destroyStack(&data);
        destroyStack(&data_history);
        exit(0);
            break;
        default:
            break;
        }
        clear();
    }
    
    return 0;
}

void empty_stack(Stack *stack)
{
    while (!isStackEmpty(stack)) {
		// Pop an element from the stack
		pop(stack);
	}
}

void print_menu(int value)
{
        printf("Current value: %d\n", value);
        printf("Choose an option:\n");
        printf("1. Increment\n");
        printf("2. Decrement\n");
        printf("3. Undo\n");
        printf("4. Redo\n");
        printf("5. Exit\n");
        printf("Enter your hoice: ");
}

void clear()
{
    #ifdef __WIN32__
    system("cls");
    #endif
    #ifdef __linux__ 
    system("clear");
    #endif
    #ifdef __unix__ 
    system("clear");
    #endif
    #ifdef __APPLE__ 
    system("clear");
    #endif
}