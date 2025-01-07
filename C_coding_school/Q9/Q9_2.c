#include <stdio.h>
#include <string.h>

int UpperCaseAndRevers(char string[]);
int main()
{
    char string[1024];
    printf("Enter a string: ");
    fgets(string, 1024, stdin); //"1024" number of characters in string, "stdin" standard input (keyboard input)
    printf("The string you entered is: %s\n", string);
    UpperCaseAndRevers(string);
    printf("The reversed and uppercase string is: %s\n", string); //print the reversed string with upper case letters
    return 0;
}

int UpperCaseAndRevers(char string[])
{
    int i = 0;
    while (string[i] != '\0' ) //runing until geting to the end of the string
    {
        if (string[i] >= 'a' && string[i] <= 'z') //check a = 97 until z = 122 and move them to A = 65 --- Z = 90
        {
            string[i] = string[i] - 32; 
        }
        i++; //move forword
    }
    //now we need to reverse for it ill create "temp" type string to play with
    char temp[1024];
    i = 0; //reset i to run from 0 - to the end of the sring
    int j = 0;
    while (string[j] != '\0')
    {
        j++; //move forword
    }
     //make j to run from end to the start
    //this way we just move i from the orginal to the j in the temp and rewrite the original string
    for (j = j-2; j >= 0; j--) // we use  j  to run from the end to the start
    {
        temp[i] = string[j];
        i++; //i---------> <--------- j
    }
    for (i = 0; i < strlen(string); i++)
    {
        string[i] = temp[i]; //we rewrite the original
        //this is because temp is inside the func 
    }
}

/*i move j by 2 back cause j is starting out bound of the string: and once he get to NULL / \0 it finish printing
there for i needed to change the start point of j
TOME: it might be easier to run with pointers*/
