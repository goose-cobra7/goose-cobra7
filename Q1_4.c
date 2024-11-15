#include <stdio.h>
#include <ctype.h>

void main()
{
	char input = 'd';
	printf("the uppercase of \"%c\" is ", input);
	char output;
	output = toupper(input);
	printf("\"%c\"", output);
}