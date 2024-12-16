//settings
#define MAX 999 
#define MIN 100
#define ARRAYSIZE 50
#define SMALLER_THEN 500
//include
#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
//global variables
int array_order[10]; //global array order
//global functions
int smaller_then(int arr[],int number,int arr_size)//number is the number that you want to check if smaller then
{
    int count = 0; //number of elements smaller than "number"
    for (int i = 0; i < arr_size; i++)
    {
        if (arr[i] < number)
        {
            count++;
        }
    }
    return count;
}

int odd_count(int arr[],int arr_size) //find how many elements are odd in the array
{
    int count = 0;
    for (int i = 0; i < arr_size; i++)
    {
        if (arr[i] % 2!= 0)
        {
            count++;
        }
    }
    return count;
}

int reset_array(int arr[],int arr_size) //reset the array to {0,0,0,0,0...}
{
    for (int i = 0; i < arr_size; i++)
    {
        arr[i] = 0;
    }
}
int element_digit_count(int arr[],int arr_size)// check what digit is the last digit and store it in the array
{
    for (int i = 0; i < arr_size; i++)
    {
        array_order[arr[i]%10]++;
    }
    
}
int main() //MAIN
{
    int array[ARRAYSIZE]; //create the array
    srand(time(NULL)); //create random seed for rand()
    for (int i = 0; i < ARRAYSIZE; i++) //create random array
    {
        array[i] = rand() % 1000; //no more then 999
        if (array[i] < 100) //number is zero (invalid) number under 100
        {
            i--; //try again
            continue; 
        } 
    }
    printf("Original Array: \n"); //print original array
    for (int i = 0; i < ARRAYSIZE; i++) 
    {
        printf(" %d", array[i]);
        if ((i + 1) % 10 == 0) printf("\n"); //print 10 numbers per line
    }
    int reversed_array[ARRAYSIZE];
    int j = ARRAYSIZE - 1;
    for (int a = 0; a < ARRAYSIZE; a++) //reverse the array
    {
        reversed_array[j] = array[a];
        j--;
    }
    printf("\nReversed Array: \n"); //print reversed array
    for (int i = 0; i < ARRAYSIZE; i++)
    {
        printf(" %d", reversed_array[i]);
        if ((i + 1) % 10 == 0) printf("\n"); //print 10 numbers per line
    }
    printf("the count of elements bigger then %d is: %d\n\n", SMALLER_THEN, smaller_then(array,SMALLER_THEN,ARRAYSIZE));
    printf("the count of odd elements is: %d\n\n",odd_count(array,ARRAYSIZE));
    reset_array(array_order,10); //reset array of the digit count
    element_digit_count(array,ARRAYSIZE); 
    for (int i = 0; i < 10; i++)
    {
        printf("end with %d: %d\n",i,array_order[i]);
    }
    return 0;
}
