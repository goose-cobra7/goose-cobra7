#include "List.c"
#include "Queue.c"

#define TEST_DAYS 20
#define Incubate 2
#define Death  5

int main()
{

    return 0;
}

int countInfectedCells(int days,int incubate,int death)
{
    Queue world;
    int alive,incubate,dead;
    world = makeEmptyQueue();
    enqueue(&world,incubate+death);
    for (size_t i = 1; i < days; i++)
    {
        /* code */
    }
    return alive;
}