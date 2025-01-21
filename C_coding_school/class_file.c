#include <stdio.h>
#include <stdlib.h>

#define BUFFER 100 // buffer size for temp holding

char* my_int_t_string(int num);

int main(int argc, char const *argv[])
{
    printf("please enter number: ");
    int num;
    scanf("%d", &num);
    char* str = my_int_t_string(num); //turn my int to string
    printf("%s", str);
    free(str); // free memory after usage
    return 0;
}

char* my_int_t_string(int num)
{
    
    int holder = 0; //holder to hold the sign of the number
    if (num < 0) //check if the number is negative
    {
        num = -num;
        holder++;
    }
    char temp_arr[BUFFER]; //temp array with buffer will delete at the end of function
    int i = 0; //index of the array to hold the number
    while (num > 0)//find each digit of the number
    {
        temp_arr[i++] = num % 10 + '0';
        num /= 10;
    }
    char* str = (char*)malloc((i+1) * sizeof(char)); //create memory
    if (str == NULL)
    {
        printf("memory allocation failed");
        return NULL;
    }
    if (holder == 0) //had the sign
    {
        str[0] = '+';
    }else
    {
        str[0] = '-';
    }
    for (int j = 0; j < i; j++)//run from the end to add all numbers to string
    {
        str[i-j] = temp_arr[j];
    }
    str[i+1] = '\0'; //finish the string with '\0' 

    return str; //retrun the adress of the first adress of the string
}