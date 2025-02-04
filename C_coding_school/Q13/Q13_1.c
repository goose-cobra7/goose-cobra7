#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES

#define PI 3.14159265358979323846

typedef struct point
{
    float x;
    float y;
}point;

typedef struct line
{
    point A;
    point B;
}line;

typedef struct circle
{
    point center;
    float radius;
}circle;

typedef struct rectangle
{
    point A; //bottom left
    point B; //top right
}rectangle;

void rectangle_sett(rectangle _rectangle_,float* size, float* serface);
void circle_sett(circle circle1, float* size, float* serface);
float distance(line Line);

int main()
{
    point PointA;
    point PointB;
    float size;
    float serface;
    while (1)
    {
        printf("welcome, what shape do you want to create: Line(1),Circle(2),Rectangle(3),End program(0)\n");
        int choise;
        do
        {
            scanf("%d",&choise);
        } while (choise < 0 || choise > 3);
        
        switch (choise)
        {
        case 1: //line //point A,point B
            printf("Line\nenter 2 points in formet:\nformet:x\ny\nx\ny\n");
            scanf("%f",&PointA.x);
            scanf("%f",&PointA.y);
            scanf("%f",&PointB.x);
            scanf("%f",&PointB.y);
            line LineA_B = {PointA,PointB};
            size = distance(LineA_B);
            printf("the distance between the points is:%f\n",size);
            break;
        case 2: //circle //point A, radius
            printf("enter point:\nformet:\nx\ny\n");
            point PointC;
            scanf("%f",&PointC.x);
            scanf("%f",&PointC.y);
            printf("enter radius:\n");
            float Radius;
            scanf("%f",&Radius);
            circle _circle_ = {PointC,Radius};
            circle_sett(_circle_,&size,&serface);
            printf("the size of the circle is: %f\nthe serface of the circle is: %f\n",size,serface);
            break;
        case 3: //rectangle //point A, point B
            printf("please enter 2 points, bottom left, top right:\n");
            printf("formet: x,y,x,y\n");
            scanf("%f",&PointA.x);
            scanf("%f",&PointA.y);
            scanf("%f",&PointB.x);
            scanf("%f",&PointB.y);
            rectangle _rectangle_ = {PointA,PointB};
            rectangle_sett(_rectangle_,&size,&serface);
            printf("the size of the rectangle: %f \nthe serface of the rectangle: %f\n",size,serface);
            break; 
        case 0: //end program
            exit(1);
            break;
        default:
            break;
        }
    }
    
    return 0;
}

float distance(line Line)
{
    float result = (Line.A.x *Line.B.x)+(Line.A.y *Line.B.y); 
    return sqrtf(result);
}

void circle_sett(circle circle1, float* size, float* serface)
{
    *size = 2*PI*circle1.radius;
    *serface = PI*(circle1.radius*circle1.radius);
}

void rectangle_sett(rectangle _rectangle_,float* size, float* serface)
{
    *size = (float)(2*(_rectangle_.A.x-_rectangle_.B.x)) + (2*(_rectangle_.A.y-_rectangle_.B.y));
    *size = sqrtf((*size)* (*size));
    *serface = (float)((_rectangle_.A.x-_rectangle_.B.x) * (_rectangle_.A.y-_rectangle_.B.y));
    *serface = sqrtf((*serface)*(*serface));
}