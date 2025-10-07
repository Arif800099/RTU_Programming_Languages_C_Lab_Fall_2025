/*
 * week4_3_struct_database.c
 * Author: [Your Name]
 * Student ID: [Your ID]
 * Description:
 *   Simple in-memory "database" using an array of structs.
 *   Students will use malloc to allocate space for multiple Student records,
 *   then input, display, and possibly search the data.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char name[50];
    int id;
    float grade;
};

// TODO: Define struct Student with fields name, id, grade


 int main() {
    int n, i;
    struct Student *students;

    printf("Enter number of students: ");
    scanf("%d", &n);

    students = malloc(n * sizeof(struct Student));

    for (i = 0; i < n; i++) {
        printf("Enter data for student %d: ", i + 1);
        scanf("%s %d %f", students[i].name, &students[i].id, &students[i].grade);
    }

    printf("\nID     Name        Grade\n");
    for (i = 0; i < n; i++) {
        printf("%-6d %-12s %.1f\n", students[i].id, students[i].name, students[i].grade);
    }

    free(students);

    // TODO: Allocate memory for n Student structs using malloc

    // TODO: Read student data in a loop

    // TODO: Display all student records in formatted output

    // Optional: Compute average grade or find top student

    // TODO: Free allocated memory

    return 0;
}
