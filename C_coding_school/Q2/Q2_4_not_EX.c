#include <stdio.h>

void main()
{
    char charic[3] = "zh";
    printf("the old string: %s\n",charic);
    int i = 0;
    while (i<2)
    {
        charic[i] = charic[i] - 32;
        i++;
    }
    printf("the new string: %s\n",charic);
    int num_str = 0;
    num_str += charic[0]*100;
    num_str = num_str + charic[1];
    printf("the number of the string: %d\n",num_str);
}
