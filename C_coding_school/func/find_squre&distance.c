#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct point
{
    float x;
    float y;    
}point;

typedef struct sqaure
{
    point point1,point2;
}sqaure;
float find_dis(sqaure sqaure);
float find_sqaure(sqaure sqaure);
int main()
{
    sqaure my_sq = {{1.12,2.435},{3.5,5.6587}};
    printf("%f",find_sqaure(my_sq));
    printf("distance is %f",find_dis(my_sq));
}

float find_sqaure(sqaure sqaure)
{
    float xd = sqaure.point1.x - sqaure.point2.x;
    float yd = sqaure.point1.y - sqaure.point2.y;
    return (xd*yd);
}

float find_dis(sqaure sqaure)
{
    float xd = sqaure.point1.x - sqaure.point2.x;
    float yd = sqaure.point1.y - sqaure.point2.y;
    return (sqrt(xd*xd+yd*yd));
}

