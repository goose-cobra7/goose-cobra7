#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int rectangleArea(int length, int width);
#define INVALID_INPUT -1
#define RUN_FOREVER 1


int rectangleArea(int length, int width) {
    if (length <= 0 || width <= 0) {
        return -1;
    }
    return length * width;
}

int main()
{
    while (RUN_FOREVER)
    {
        int length = 0;
        int width = 0;
        printf("Enter length and width of rectangle (to stop input, enter any letter/symbol): ");
        int ret = scanf("%d %d", &length, &width);

        // scanf returns the number of parameters successfully input.
        if (ret != 2) break;
        int area = rectangleArea(length, width);
        if (area == INVALID_INPUT)
            printf("Invalid input\n");
        else
            printf("Rectangle with sides %d [units] and %d [units] has Area: %d [units^2]\n", length, width, area);
    }

    printf("Exiting...\n");
    return 0;
}