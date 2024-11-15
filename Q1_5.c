#include <stdio.h>

void main()
{
	int hour, min;
	hour = 22; 
	min = 30;
	long offset = 111111; //the offset of the time in min
	printf("hours:%d \n min:%d \noffset:%d\n", hour, min, offset); //printing input
	min = min + (offset % 60); //find mins
	if (min >= 60) // if more then 60
	{
		min = min % 60; 
		hour++; // give the hours some time (be nice)
	}
	hour = hour + (offset / 60);
	int day = 0;
	if (hour >= 24) //check if more the one day
	{
		day = hour / 24; //give day
		hour = hour % 24;
	}
	
	
	printf(" %2.2d:%2.2d ", hour, min);//priniting time without days
	if (day >= 1)
	{
		if (day == 1)
			printf("and %d day",day); //one day
		else
			printf("and %d days",day); //more then one day
	}
}