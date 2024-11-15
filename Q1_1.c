#include <stdio.h>

void main()
{
	int input = 7283;
	int sec, min, hour;
	sec = input % 60;
	min = (input - sec)/ 60;
	min = min % 60;
	hour = input - (sec)-(min * 60);
	hour = hour / 3600;
	printf("your input is %d in sec\n", input);
	printf("%2.2d:%2.2d:%2.2d \n",hour ,min ,sec);
}