#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    float score;
} Student;

void addStudent(const char* filename, Student* s) {
    FILE* file = fopen(filename, "ab"); // Append mode
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    fwrite(s, sizeof(Student), 1, file);
    fclose(file);
}

void deleteStudent(const char* filename, int id) {
    FILE* file = fopen(filename, "rb");
    FILE* tempFile = fopen("temp.bin", "wb");

    if (!file || !tempFile) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    Student s;
    while (fread(&s, sizeof(Student), 1, file)) {
        if (s.id != id) {
            fwrite(&s, sizeof(Student), 1, tempFile); // Copy everything except the item to be deleted
        }
    }

    fclose(file);
    fclose(tempFile);

    remove(filename);         // Delete original file
    rename("temp.bin", filename); // Rename temp file to original
}

void updateStudent(const char* filename, int id, Student* updatedStudent) {
    FILE* file = fopen(filename, "rb+"); // Open for reading and writing
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    Student s;
    while (fread(&s, sizeof(Student), 1, file)) {
        if (s.id == id) {
            fseek(file, -sizeof(Student), SEEK_CUR); // Move back to overwrite
            fwrite(updatedStudent, sizeof(Student), 1, file);
            break;
        }
    }

    fclose(file);
}

int main() {
    const char* filename = "students.bin";

    // Add students
    Student s1 = {1, "Alice", 85.2};
    Student s2 = {2, "Bob", 90.5};
    addStudent(filename, &s1);
    addStudent(filename, &s2);

    // Update a student
    Student updatedStudent = {2, "Bob", 95.0};
    updateStudent(filename, 2, &updatedStudent);

    // Delete a student
    deleteStudent(filename, 1);

    return 0;
}
