#include<stdio.h>

void main()
{
    char grade;
    printf("enter a grade char:[E F G A F]:");
    scanf("%c",&grade);//enter char
     if (grade>32){//make sure its upper case
        grade -= 32;
    }
    switch (grade)//check if valid and give score
    {
    case ('E'):
        printf("Exelent");
        break;
    case ('F'):
        printf("Fail");
        break;
    case ('G'):
        printf("Good");
        break;
    case ('A'):
        printf("Avrage");
        break;
    case ('V'):
        printf("Very Good");
        break;
    default://if no letter is found in case then fuck you, its not valid
        printf("please enter valid grade");
        break;
    }
}