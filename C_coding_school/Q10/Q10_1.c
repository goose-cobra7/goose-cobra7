#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>


int isOverlapped(const char* string1, const char* string2);

int main()
{


	char str1[] = "dog";
	char str2[] = "fish";
    char* p1 = str1 + 2;
    char* p2 = str2 + 2;

	printf("%s and %s is %s\n", str1, str2, isOverlapped(str1, str2) ? "overlapped" : "not overlapped");
	printf("%s and %s is %s\n", str2, str1, isOverlapped(str2, str1) ? "overlapped" : "not overlapped");
	printf("%s and %s is %s\n", str1, str1, isOverlapped(str1, str1) ? "overlapped" : "not overlapped");
	printf("%s and %s is %s\n", str2, str2, isOverlapped(str2, str2) ? "overlapped" : "not overlapped");
	printf("%s and %s is %s\n", str1, str1 + 2, isOverlapped(str1, p1) ? "overlapped" : "not overlapped");
	printf("%s and %s is %s\n", str2, p2, isOverlapped(str2, p2) ? "overlapped" : "not overlapped");

	return 0;
}


int isOverlapped(const char* string1, const char* string2) {
    if (string1 == NULL || string2 == NULL) {
        return 0;  
    }

    for (int i = 0; string1[i] != '\0'; i++) {
        for (int j = 0; string2[j] != '\0'; j++) {
            if (string1[i] == string2[j]) {
                return 1; 
            }
        }
    }

    return 0;  
}
