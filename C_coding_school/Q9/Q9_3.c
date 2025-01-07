#include <stdio.h>
#include <string.h>
#include <math.h>

int HexToDecimal(char string[]);
int main()
{
    char string[1024];
    printf("Enter a string: 0x");
    fgets(string, 1024, stdin); //"1024" number of characters in string, "stdin" standard input (keyboard input)
    int dec = HexToDecimal(string);
    printf("The decimal value of the hexadecimal number is: %d\n", dec);
    return 0;
}

int HexToDecimal(char string[])
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
    int j = 0,k = 0;
    for (i = i-2; i >= 0; i--) 
    {
        j += string[k] * pow(16,i);
        k++;
    }
    return j;
}