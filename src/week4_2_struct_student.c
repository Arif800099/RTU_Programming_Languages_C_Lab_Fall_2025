/*
 * week4_2_struct_student.c
 * Author: [Arif Asadov]
 * Student ID: [ID241ADB072]
 * Description:
 *   Demonstrates defining and using a struct in C.
 *   Students should define a 'Student' struct with fields like name, id, and grade.
 *   Then create a few instances and print them.
 */

#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int id;
    float grade;
};
// TODO: Define struct Student with fields: name (char[]), id (int), grade (float)
// Example:
// struct Student {
//     char name[50];
//     int id;
//     float grade;
// };
int main() {
    struct Student student1, student2;

    strcpy(student1.name, "Alice Johnson");
    student1.id = 1001;
    student1.grade = 9.1;

    strcpy(student2.name, "Bob Smith");
    student2.id = 1002;
    student2.grade = 8.7;

    printf("Student 1: %s, ID: %d, Grade: %.1f\n", student1.name, student1.id, student1.grade);
    printf("Student 2: %s, ID: %d, Grade: %.1f\n", student2.name, student2.id, student2.grade);
    // TODO: Declare one or more Student variables

    // TODO: Assign values (either manually or via scanf)

    // TODO: Print struct contents using printf

    return 0;
}
