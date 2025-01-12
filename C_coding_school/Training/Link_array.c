#include <stdio.h>
#include <string.h>

#define array_size 100
int array[array_size] = {0};
int library[array_size] = {0};
char* create_string(char *string) ;
int insert_element();
void print_array(int array[array_size]);

int main()
{
    char buffer[100]; // Allocate memory for the string 
    char *string1 = create_string(buffer); // Call the function with the pre-allocated buffer 
    printf("You entered: %s\n", string1); // Print the string
    
    insert_element();

}


void print_array(int array[array_size])
{
    for (int i = 0; i < array_size; i++)
    {
        if (array[i] == 0)
        {
            printf(" ");
        }else{
            printf("%.2p",array[i]);
        }
    }
}


int insert_element()
{
    int id, ele_ptr, link_ptr;
    int i = 0;
    while (array[i] != 0)
    {
        i++;
    }
    if (i == array_size) {return -1;}
    if (i != 0) {i++;}
    printf("enter id of element: ");
    scanf("%d", &id);
    printf("enter value of element: ");
    scanf("%d", &ele_ptr);
    printf("enter link of element: ");
    scanf("%d", &link_ptr);
    array[i] = id;
    array[i+1] = ele_ptr;
    array[i+2] = link_ptr;
}

char* create_string(char *string) 
{ 
    printf("Create string for element: "); 
    fgets(string, 100, stdin); 
    return string; 
}

void add_note()
{
    char buffer[100]; // Allocate memory for the string 
    char *string1 = create_string(buffer); // Call the function with the pre-allocated buffer 
    printf("You entered: %s\n", string1);
    int i = 0;  // Initialize the counter to 0
    while (library[i] != 0)
    {
        i++;
    }
    int *str_ptr[i] = &string1;
}