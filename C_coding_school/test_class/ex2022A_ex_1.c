#include <stdlib.h>
#include <stdio.h>

#define defultHour 23
#define defultMin 58

typedef struct Time
{
    char min;
    char hour;
}Time;



typedef struct log
{
    char action;
    Time logTime;
}log;
int getMaxCallers(log *stream,int size, int x);
log* createStream(int size);
void initTime(log *loglist,Time log_Time);

void main() 
{
    int size = 10; 
    log* stream = createStream(size); 
    int res = 0; 
    if (stream) 
    { 
        res = getMaxCallers(stream, size, 0); 
        printf("max=%d", res); 
    }
 free(stream); 
}

int getMaxCallers(log *stream,int size, int x)
{
    if (size == 0)
    {
        return x;
    }
    int newX = x + stream->action;
    int maxinRest = getMaxCallers(stream+1,size-1,newX);
    if (maxinRest > newX)
    {
        return maxinRest;
    }else{
        return newX;
    }

}

void initTime(log *loglist,Time log_Time)
{
    loglist->logTime = log_Time;
}

log* createStream(int size)
{
    int Hour = defultHour;
    int Min = defultMin;
    Time t;
    t.hour = Hour;
    t.min = Min; 
    int total = 0;
    log *log_list = malloc(size * sizeof(log));
    for (size_t i = 0; i < size; i++)
    {
        initTime(log_list,t);
        t.min++;
        if (t.min = 60)
        {
            t.min = 0;
            t.hour++;
        }
        if (t.hour = 24)
        {
            t.hour = 0;
        }
        if (total > 0)
        {
            log_list[i].action = ((rand()%2) == 0)? -1:1;
        }else
        {
            log_list[i].action = 1;
        }
        total =+ log_list[i].action;
    }
    return log_list;
}


