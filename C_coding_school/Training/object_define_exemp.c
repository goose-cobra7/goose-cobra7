#include <stdio.h>
#include <math.h>
typedef struct my_objs //define struct my_objs and give it a name "obg"
{
    //what inside the object
    double x; 
    double y;
}obg;
//every time we create a new object we create 2 new variables
int main()
{
    //this is one way to create an object
    obg obj1;
    obj1.x = 1.2;
    obj1.y = 2.5;
    //this is another
    obg obj2 = {3.2, 4.9};
    //find distance between two points
    double distance = sqrt(pow(obj2.x - obj1.x, 2) + pow(obj2.y - obj1.y, 2));
    printf("The distance between obj1 and obj2 is: %.2f\n", distance);

    return 0;
}
