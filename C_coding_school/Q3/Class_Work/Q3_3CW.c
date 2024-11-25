#include <stdio.h>

void main()
{
    int num_ent = 0;
    do
    {
        printf("please enter 3 digit num: ");
        scanf("%d",&num_ent);
    }while(num_ent < 100||num_ent > 999); //check if num is valid
    if (num_ent%2) // hceck if the num is even or uneven
    {
        printf("%d is uneven number\n",num_ent);
    }else{
        printf("%d is a even number\n",num_ent);
    }
    int num_1_dig; // new int for the first int of the num
    num_1_dig = num_ent % 10; // take the first int out of num
    printf("the number of the first int is: %d\n",num_1_dig);
    if (num_ent<250) //check size of it 
    {
        num_ent *= 1.25; //multiplie it
        printf("the number is less then 250 then we multiplie it with 1.25\nthe result is %d",num_ent);
    }
    else if (num_ent>500)
    {
        num_ent *= 1.75;
        printf("the number is more then 500 then we multiplie it with 1.75\nthe result is %d",num_ent);

    }
    else
    {
        num_ent *= 1.5;
        printf("the number is less then between 250 to 500 then we multiplie it with 1.5\nthe result is %d",num_ent);

    }
    
}
/*"num_ent" is a even number
the number of the first int is: "num_1_int"
the number is less then between 250 to 500 then we multiplie it with 1.5
the result is "num_ent/AFTER CHANGE"*/ 