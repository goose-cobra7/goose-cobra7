#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#define AMPLITUDE 100 //the more the better accuracy but more computing power needed

int main() 
{ 
    float a,b,res;// create the float ver'
    scanf("%f %f",&a,&b); //a=1.26535 b=3.4452
    int int_a,int_b; //create the in ver'
    int_a = a * AMPLITUDE; // int_a=126 || we multiplie and store the value in int  
    int_b = b * AMPLITUDE; // b=3.44
    res = (int_a - (float)int_b) / AMPLITUDE;//we put it back in the float to work with it and 
    //lowering the value back to the same dec'
    printf("%f",res); //-2.180000
}