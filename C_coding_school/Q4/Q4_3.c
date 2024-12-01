#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

int main()
{
    srand((unsigned)time(NULL));
    int myrand = rand() % 100 + 1; // Generate a random number between 1 and 100
    int guess, guess_time;
    do
    {
        printf("enter your guess: ");
        scanf("%d", &guess);// Get the guess
        guess_time++;// count the number of attempts
        if (guess < myrand)
        {
            printf("your guess is too low\n");
        }else if (guess > myrand)
        {
            printf("your guess is too high\n");
        }
    } while (guess != myrand);
    printf("Congratulations! You guessed the number in %d attempts\n", guess_time);
    return 0;
}
