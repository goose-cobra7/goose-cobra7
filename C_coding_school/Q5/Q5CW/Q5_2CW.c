#include <stdio.h>

int change_my_number(int number)
{
    number = 8;
    printf("Inside the function: x = %d\n", number); // prints 8
    return number;

}

int main() 
{
    int number = 5;
    printf("the number out side the function: x = %d\n", number); // prints 5
    number = change_my_number(number);
    printf("after the function: x = %d\n", number);
}