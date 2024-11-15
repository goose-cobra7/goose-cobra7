#include <stdio.h>

int main()
{
    int input = 268;
    printf("old num = %d\n\n",input);
    int hundred,tens,singles,new_hundred;
    singles = (input % 10);
    tens = ((input - singles) % 100)/10;
    hundred = input - singles - tens;
    tens++;
    new_hundred = singles;
    singles = hundred / 100;
    printf("new num = %d%d%d",new_hundred,tens,singles);
    return 0;
}