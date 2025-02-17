#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

typedef struct JCoord
{
    float x;
    float y;
}JCoord;


typedef struct Road
{
    int istoll;
    int Njunc;
    JCoord* JCoord_list;
    float *dur;
    char** direcs;
}Road;


int main(int argc, char const *argv[])
{
    
    return 0;
}

Road* shortestRoad(Road* pNav[])
{
    float max_len = 0;
    Road* max;
    for (int i = 0; i < strlen(pNav); i++)
    {
        if (pNav[i]->dur>0 && pNav[i]->istoll == 0)
        {
            
        }
    }
}
