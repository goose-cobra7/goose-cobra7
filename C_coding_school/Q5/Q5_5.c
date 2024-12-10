#include <stdio.h>
int a(int b) { 
int c = 0, d = 1, e, f;
if (b == 0) return c; 
for (f = 2; f <= b; f++) {
     e = c + d; 
     c = d; 
     d = e; 
    } 
    return d; 
}

int main() {
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n",a(i));
    }
}