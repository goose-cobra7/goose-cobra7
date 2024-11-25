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
            printf("that a triangle\n"); // הודעה שהמשולש תקין
        }
    }
}
