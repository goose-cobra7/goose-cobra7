#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h> // For sleep function

#define SCREEN_WIDTH 40
#define FRAMES 400
#define SLEEP_TIME 10000 // 100000 microseconds = 0.01 seconds

void bouncingPoint() {
    int position = 0;
    int direction = 1; // 1 for right, -1 for left

    for (int frame = 0; frame < FRAMES; frame++) {
        // Clear the screen (for Unix-like systems)
        //printf("\033[2J\033[H");

        // Print the current frame
        for (int i = 0; i < SCREEN_WIDTH; i++) {
            if (i == position) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");

        // Update position
        position += direction;

        // Bounce if we hit the edges
        if (position == 0 || position == SCREEN_WIDTH - 1) {
            direction *= -1;
        }

        // Sleep to control frame rate
        usleep(SLEEP_TIME);
    }
}

int main()
{
    int pingpong_fact = 1;
    if (pingpong_fact == 1)
    {
        bouncingPoint();
    }
    
    return 0;
}