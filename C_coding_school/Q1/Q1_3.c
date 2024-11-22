#include <stdio.h>

void main()
{
	float DOLLAR_GATE = 3.21;
	float ils;
	int USD = 15;
	ils = USD * DOLLAR_GATE;
	printf("the dolar gate is %2.2f\n", DOLLAR_GATE);
	printf("%d usd = %2.5f ils\n", USD, ils);
}