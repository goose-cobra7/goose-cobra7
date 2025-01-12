#include <stdio.h>

#define LIBRARY_SIZE 100

void add_elem(int elem,int place,int *library);
void print_array(int *library);
void remove_elem_by_value(int value, int *library);
void remove_elem_by_place(int place,int *library);
void search_elem(int value,int *library);
void make_pop(int *library);
int main()
{
    int library[LIBRARY_SIZE] = {0,2,3,4,6,1,2,3,4,6,7,2,124,123,12,312,3,124,0,3445,34,6};
    int desi = 0;
    while (desi != -1)
    {
        printf("Choose the action:\n"); 
        printf("1. Add/change element to library\n"); 
        printf("2. Remove element from library\n"); 
        printf("3. Search for an element in library\n"); 
        printf("4. Display all elements in library\n"); 
        printf("5. Sort the library in ascending order\n"); 
        printf("0. Reset library\n"); 
        printf("-1. Exit\n"); 
        printf("Enter your choice: ");
        scanf("%d", &desi);
        
        switch (desi)
        {
            case 1:
                printf("please enter the element you want to add\n");
                int elem;
                scanf("%d", &elem);
                printf("please enter the place where you want to add this element\n");
                int place;
                scanf("%d", &place);
                add_elem(elem, place, library);
                break;
            case 2:
                printf("please chose the method of removing the element:\n");
                printf("1. Remove by value\n");
                printf("2. Remove by place\n");
                int method;
                scanf("%d", &method);
                if (method == 1)
                {
                    printf("please enter the value of the element you want to remove\n");
                    int value;
                    scanf("%d", &value);
                    remove_elem_by_value(value,library);
                }else
                {
                    printf("please enter the place of the element you want to remove\n");
                    int place;
                    scanf("%d", &place);
                    remove_elem_by_place(place,library);
                }
                break;
            case 3:
                printf("please enter the value of the element you want to search for\n");
                int value;
                scanf("%d", &value);
                search_elem(value,library);
                break;
            case 4:
                print_array(library);
                break;
            case 5:
                make_pop(library);
                break;
            case 0:
                // Reset library
                break;
            case -1:
                // Exit
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
}

void add_elem(int elem,int place,int *library)
{
    library[place-1] = elem;
}
void print_array(int *library)
{
    for (int i = 0; i < LIBRARY_SIZE; i++)
    {
        printf("%d ", library[i]);
    }
    printf("\n");
}

void remove_elem_by_place(int place,int *library)
{
    library[place-1] = 0;
}

void remove_elem_by_value(int value,int *library)
{
    for (int i = 0; i < LIBRARY_SIZE; i++)
    {
        if (library[i] == value)
        {
            library[i] = 0;
        }
    }
}

void make_pop(int *library) //funny code
{
    for (int i = 0; i < LIBRARY_SIZE; i++)
    {
        for (int j = 0; j < i; j++)
        {
            printf(" ");
        }
        printf("%d\n ", library[i]);
    }
    
}

void search_elem(int value,int *library)
{
    for (int i = 0; i < LIBRARY_SIZE; i++)
    {
        if (library[i] == value)
        {
            printf("Element found at place %d\n", i);
        }
    }
    
}

void sort_elem()
{
    int temp[LIBRARY_SIZE];
    for (int i = 0; i < LIBRARY_SIZE; i++)
    {
        for (int j = 0; i < LIBRARY_SIZE; i++)
        {
            
        }
        
    }
}