#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// הגדרת מבנה הרופא
typedef struct {
    char phone[11];
    char doc_name[20];
} doc;

// הגדרת מבנה החולה
typedef struct {
    char name[20];
    int id;
    char *disease;
    doc doctor;
} patient;

// פונקציית אתחול החולה
patient* init_patient(const char *pname, int pid, const char *disease, const char *dname, const char *phone) {
    patient *new_patient = (patient*)malloc(sizeof(patient));
    if (!new_patient) {
        return NULL;
    }

    strcpy(new_patient->name, pname);
    new_patient->id = pid;

    new_patient->disease = (char*)malloc(strlen(disease) + 1);
    if (!new_patient->disease) {
        free(new_patient);
        return NULL;
    }
    strcpy(new_patient->disease, disease);

    strcpy(new_patient->doctor.phone, phone);
    strcpy(new_patient->doctor.doc_name, dname);

    return new_patient;
}

// פונקציית חירום לחיפוש חולים
int alert(patient* patients[], int nPatient, const char *disease) {
    int count = 0;
    for (int i = 0; i < nPatient; i++) {
        if (patients[i] && strcmp(patients[i]->disease, disease) == 0) {
            printf("Name: %s, ID: %d, Doctor: %s, Phone: %s\n", patients[i]->name, patients[i]->id, patients[i]->doctor.doc_name, patients[i]->doctor.phone);
            count++;
        }
    }
    return count;
}

// פונקציית מחיקה
int remove_patient(int pid, patient* patients[], int nPatient) {
    for (int i = 0; i < nPatient; i++) {
        if (patients[i] && patients[i]->id == pid) {
            free(patients[i]->disease);
            free(patients[i]);
            for (int j = i; j < nPatient - 1; j++) {
                patients[j] = patients[j + 1];
            }
            patients[nPatient - 1] = NULL;
            return nPatient - 1;
        }
    }
    return nPatient;
}

int main() {
    patient* patients[MAX_SIZE] = {0};
    int nPatient = 0;

    patients[nPatient++] = init_patient("JohnDoe", 123, "Asthma", "Dr. Smith", "1234567890");
    patients[nPatient++] = init_patient("JaneDoe", 456, "Diabetes", "Dr. Brown", "0987654321");

    printf("Before removal:\n");
    alert(patients, nPatient, "Asthma");

    nPatient = remove_patient(123, patients, nPatient);

    printf("\nAfter removal:\n");
    alert(patients, nPatient, "Asthma");

    for (int i = 0; i < nPatient; i++) {
        free(patients[i]->disease);
        free(patients[i]);
    }

    return 0;
}
