#include <stdio.h> 

float foo(float arr[], float v,int i,int length); 

int main() 
{ 
    float v,res,arr[] = {1,0,0,-1}; 
    v = -2.2; 
    res = foo(arr,v,0,sizeof(arr)/sizeof(arr[0])); 
    printf("res = %.4f\n",res); 
    return 0; 
} 

float foo(float arr[], float v,int i,int length) 
{ 
    if(i == length - 1) 
    { 
        return arr[i]; 
    } 
    return arr[i] + v*foo(arr,v,i+1,length); 
}