#include<stdio.h>

void main() {
    // לולאת for שפועלת 3 פעמים
    for (int i = 3; i--; i <= 0) {
        int s1, s2, s3; // הגדרת משתנים לקליטת צדדי המשולש
        printf("enter 3 int side of triangle:"); // בקשת קלט מהמשתמש
        scanf("%d %d %d", &s1, &s2, &s3); // קריאת צדדי המשולש מהמשתמש

        // בדיקה אם המשולש הוא לא משולש תקין
        // (אם אחד מהצדדים שווה לסכום שני הצדדים האחרים)
        if ((s1 == s2 + s3) || (s2 == s1 + s3) || (s3 == s1 + s2)) {
            printf("that not triangle\n"); // הודעה שהמשולש לא תקין
        } else {
            // בדיקה אם המשולש הוא משולש שווה צלעות
            if ((s1 == s2 && s2 == s3 && s3 == s1)) {
                printf("that equilateral triangle\n"); // הודעה שהמשולש שווה צלעות
            } else {
                // בדיקה אם המשולש הוא משולש שווה שוקיים
                if ((s1 == s2 || s2 == s3 || s3 == s1)) {
                    printf("that isosceles triangle\n"); // הודעה שהמשולש שווה שוקיים
                } else {
                    printf("that triangle\n"); // הודעה שהמשולש תקין
                }
            }
        }   
    }
}
