#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LEN 50
#define DATA_FILE "students.txt"

typedef struct {
    char name[NAME_LEN];
    int id;
    float gpa;
} Student;

int load_students(Student arr[]);
void save_students(Student arr[], int count);
void add_student(Student arr[], int *count);
void list_students(Student arr[], int count);

int main(void) {
    Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    count = load_students(students);

    do {
        printf("\n=== Student Management System ===\n");
        printf("1. List students\n");
        printf("2. Add student\n");
        printf("3. Save and Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                list_students(students, count);
                break;
            case 2:
                add_student(students, &count);
                break;
            case 3:
                save_students(students, count);
                printf("Data saved. Goodbye!\n");
                break;
            default:
                printf("Invalid option. Try again.\n");
        }
    } while (choice != 3);

    return 0;
}

int load_students(Student arr[]) {
    FILE *fp = fopen(DATA_FILE, "r");
    int count = 0;
    if (fp == NULL) return 0;
    while (fscanf(fp, "%49[^,],%d,%f\n", arr[count].name, &arr[count].id, &arr[count].gpa) == 3) {
        count++;
        if (count >= MAX_STUDENTS) break;
    }
    fclose(fp);
    return count;
}

void save_students(Student arr[], int count) {
    FILE *fp = fopen(DATA_FILE, "w");
    if (fp == NULL) return;
    for (int i = 0; i < count; i++) {
        fprintf(fp, "%s,%d,%.2f\n", arr[i].name, arr[i].id, arr[i].gpa);
    }
    fclose(fp);
}

void add_student(Student arr[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("Cannot add more students.\n");
        return;
    }
    printf("Enter name: ");
    fgets(arr[*count].name, NAME_LEN, stdin);
    arr[*count].name[strcspn(arr[*count].name, "\n")] = '\0';
    printf("Enter ID: ");
    scanf("%d", &arr[*count].id);
    printf("Enter GPA: ");
    scanf("%f", &arr[*count].gpa);
    getchar();
    (*count)++;
    printf("Student added successfully!\n");
}

void list_students(Student arr[], int count) {
    if (count == 0) {
        printf("No students found.\n");
        return;
    }
    printf("\n%-20s %-10s %-5s\n", "Name", "ID", "GPA");
    printf("----------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-20s %-10d %.2f\n", arr[i].name, arr[i].id, arr[i].gpa);
    }
}
