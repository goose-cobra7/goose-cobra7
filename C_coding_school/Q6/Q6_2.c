#include <stdio.h>
#define ARRAY_SIZE 10 //define the size of list of grades

/*find the average of grades in the list*/
int grade_average(int grades[],int array_size)
{
    int sum = 0;
    for (int i = 0; i < array_size; i++)
    {
        sum += grades[i];
    }
    return sum / array_size;
}
/*find the number of grade within +-1 of the average*/
int grade_in_range(int grades[], int array_size,int average)
{
    int count = 0;
    for (int i = 0; i < array_size; i++)
    {
        if (grades[i] >= average - 1 && grades[i] <= average + 1)
        {
            count++;
        }
        
    }
    return count;
}

/*find the number of grades above the averge*/
int grade_count_above_b(int grades[], int array_size, int b)// replace 'b' with the desired value
{
    int count = 0;
    for (int i = 0; i < array_size; i++)
    {
        if (grades[i] > b)
        {
            count++;
        }
        
    }
    return count;
}
int main()
{
    int grades[ARRAY_SIZE];
    printf("Enter %d grades:\n", ARRAY_SIZE);
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        printf("grade %d: ", i + 1);
        scanf("%d", &grades[i]);
    }
    int average = grade_average(grades, ARRAY_SIZE);
    printf("The average grade is: %d\n", average);
    printf("The number of grades within 1 point of the average is: %d\n", grade_in_range(grades, ARRAY_SIZE, average));
    printf("grade above the average: %d\n", grade_count_above_b(grades, ARRAY_SIZE, average)) ;//grade above the average
    return 0;
}
