#include<stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
	char *name;
	char *country;
	float price;
} Game;

int main(int argc, char const *argv[])
{
    
    return 0;
}

float updatePrice(Game games[],int size,char *country)
{
    int i = 0;
    float highest = 0;
    for (i = 0; i < size; i++)
    {
        if (strcmp(games[i].country,country))//
        {
            games[i].price +=games[i].price*0.1;
            if (highest<games[i].price)
            {
                highest = games[i].price;
            }
            
        }
        
    }
    return highest;
}