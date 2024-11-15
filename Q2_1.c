#include <stdio.h>

void main()
{
	int input = 546; //the input num
	int hundred, tens,num; 
	num = (input % 10); //geting the single digit
	input = input - num; //deleting the single digit from the input
	tens = (input % 100)/10; //geting the tens digit
	hundred = (input - tens)/100;//geting the hundred digit
	printf("the hundred digit is: %d\nthe tens digit is: %d",hundred,tens );
}