#include <stdio.h>
#include <string.h>
#include <math.h>

void HexToDecimal(char string[], char result[]);
int main()
{
    char string[1024];
    char result[1024];
    printf("Enter a string: 0x");
    fgets(string, 1024, stdin); //"1024" number of characters in string, "stdin" standard input (keyboard input)
    HexToDecimal(string, result);
    printf("The decimal equivalent is: %s\n", result); //print the reversed string with upper case letters
    return 0;
}

void HexToDecimal(char string[], char result[])
{
    int i = 0;
    while (string[i]!= '\0')
    {
        if (string[i] >= '0' && string[i] <= '9') //first we find the char value
            string[i] = string[i] - '0'; //move the value to the dec place in the ascii
        else if (string[i] >= 'A' && string[i] <= 'F') //for upper case
            string[i] = string[i] - 'A' + 10;
        else if (string[i] >= 'a' && string[i] <= 'f') //for lower case
            string[i] = string[i] - 'a' + 10;
        i++; //run on string
    }
    //this way the value of the char turn to meaninless string but on the dec it have meaning
    int j = 0,k = 0; //create "k" = counter, "j" = result
    for (i = i-2; i >= 0; i--) //run from the end of the string to the start
    {
        j += string[k] * pow(16,i);// (A*16^2)+(B*16^1)+C
        k++;
    }
    result[1+k] = '\0'; //create end of string
    while (j != 0) //insert the result to string format
    {
        result[k--] = (j % 10) + '0'; //turn it from "int" to "char" using ASCII
        j /= 10;
    }
}