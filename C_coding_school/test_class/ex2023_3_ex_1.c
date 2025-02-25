#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct jCoord
{
    float x;
    float y;
}jCoord;

typedef struct Road
{
    int istoll;
    int Njunc;
    jCoord *juncs;
    float *dur;
    char **direcs;
}Road;

float sum_dis(Road *R); //sum the distance using jCoord
Road *ShortestRoad(Road *pNav[]); //find shortest Road return pointer

int main()
{
    
    return 0;
}

Road *ShortestRoad(Road *pNav[])
{
    float new_sum = 0;
    float sum = sum_dis(pNav[0]);
    int highestI = 0;
    for (size_t i = 1; i < 10; i++)
    {
        if (pNav[i] == NULL)
        {
            break;
        }else
        {
            new_sum = sum_dis(pNav[i]);
            if (sum > new_sum && pNav[i]->istoll == 0)
            {
                sum = new_sum;
                highestI = i;
            }
        }
    }
    return pNav[highestI];
}

float sum_dis(Road *R)
{
    float sum = 0;
    for (size_t i = 0; i < R->Njunc-1; i++)
    {
        float X = R->juncs[i].x-R->juncs[i+1].x;
        float Y = R->juncs[i].y-R->juncs[i+1].y;
        sum += sqrt(X*X + Y*Y);
    }
    return sum;
}

void printDirc(Road *R)
{
    int i = 0;
    printf("%d. ",i);
    printf("starting at: (x%f , y%f)\n",R->juncs->x,R->juncs->y);
    for (size_t k = 0; k < R->Njunc; k++)
    {
        printf("%d. ",i);
        char temp = R->direcs[k][0];
        if (temp == 's')
        {
            printf("continue stright");
        }
        if (temp == 'l')
        {
            printf("contine left");
        }else
        {
            printf("contine right");
        }
        i++;
    }
    printf("%d. ",i); //print end
    printf("welcome to ruppin");
}

void DeleteRoad(Road *pNav[],Road *R)
{
    int temp = -1; // check if Road in list (-1)==not in list
    for (size_t i = 0; i < 10; i++)//find place or return -1
    {
        if (pNav[i] == R)
        {
            temp = i;
            break;
        }
        
    }
    if (temp == -1) 
    {
        printf("Road you enter is not in list");
        exit(1);
    }
    //free all dynemic memory
    free(pNav[temp]->juncs);
    free(pNav[temp]->direcs);
    free(pNav[temp]->dur);
    free(pNav[temp]);
    pNav[temp] = NULL; //set place to NULL
    for (size_t i = temp; i < 9; i++)//move all to left
    {
        pNav[i] = pNav[i+1];
    }
    pNav[10] = NULL;//set last one to NULL
}