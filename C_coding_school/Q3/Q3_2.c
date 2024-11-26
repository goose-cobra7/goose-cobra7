#define _CRT_SECURE_NO_WARNING
#include <stdio.h>

void main()
{
    // find the m for the y = mx+b
    float x1,x2,y1,y2;
    printf("enter first point (x y): "); 
    scanf("%f %f",&x1,&y1);
    printf("enter secend point (x y): ");
    scanf("%f %f",&x2,&y2);
    //we now have 2 points (x1 y1)(x2 y2)
    float m; //we create new ver' named m for later use
    float y_f,x_f; //ease of debug
    y_f = y1-y2;
    x_f = x1-x2;
    if (x_f == 0 || y_f == 0)//check if point slop is valid
    {
        if (x_f == 0)
        {
            printf("m = inf\n"); //x1 - x2 = 0
            printf("slop doesnot exist");
        }else if (y_f == 0)
        {
            printf("points has no slop\n"); //y1 - y2 = 0
            printf("y = %f",y1);
        }
    }else// its not 0 or inf (slop is valid)
    {
        m = y_f / x_f; //find slop
        double b; // new var for the y crossing 
        b = y1 + (-1*x1*m); //cal' all
        printf("y = %fX + %lf",m,b); //lets rep it up
    }
    
}