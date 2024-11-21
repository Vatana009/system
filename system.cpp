#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

// Define a structure for a student
typedef struct {
    int id;
    char name[50];
    char course[50];
    int age;
} Student;

// Global array to store students
Student students[MAX_STUDENTS];
int studentCount = 0;

// Function prototypes
void addStudent();
void viewStudents();
void searchStudent();
void updateStudent();
void deleteStudent();
void displayMenu();

int main() {
    int choice;
    while (1) {
        displayMenu();
        printf("\n\tEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addStudent(); break;
            case 2: viewStudents(); break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            case 6: printf("Exiting program.\n"); exit(0);
            default: printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

void displayMenu() {
    printf("\n=== Student Management System ===");
    printf("\n\t1. Add Student");
    printf("\n\t2. View Students");
    printf("\n\t3. Search Student");
    printf("\n\t4. Update Student");
    printf("\n\t5. Delete Student");
    printf("\n\t6. Exit");
}

void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        printf("Maximum student limit reached.\n");
        return;
    }
    Student s;
    printf("\tEnter Name: ");
    scanf(" %[^\n]s", s.name); // Use %[^\n] to read string with spaces
    printf("\tEnter ID: ");
    scanf("%d", &s.id);
    printf("\tEnter Course: ");
    scanf(" %[^\n]s", s.course);
    printf("\tEnter Age: ");
    scanf("%d", &s.age);
    students[studentCount++] = s;
    printf("\tStudent added successfully.\n");
}

void viewStudents() {
    if (studentCount == 0) {
        printf("\tNo students to display.\n");
        return;
    }
    printf("\n========= List Students =========\n");
    for (int i = 0; i < studentCount; i++) {
        printf("\tName\t: %s\n\tID\t: %d\n\tCourse\t: %s\n\tAge\t: %d\n\n", 
               students[i].name, students[i].id, students[i].course, students[i].age);
    }
}

void searchStudent() {
    char course[50];
    int found = 0;

    printf("\tEnter course to search: ");
    scanf(" %[^\n]s", course); // Read the course input with spaces

    printf("\n====== Review Students ======\n", course);
    for (int i = 0; i < studentCount; i++) {
        if (strcmp(students[i].course, course) == 0) { // Compare courses
            printf("\tName\t: %s\n", students[i].name);
            printf("\tID\t: %d\n", students[i].id);
            printf("\tCourse\t: %s\n", students[i].course);
            printf("\tAge\t: %d\n\n", students[i].age);
            found = 1;
        }
    }

    if (!found) {
        printf("\tNo students found for the course: %s\n", course);
    }
}



void updateStudent() {
    int id;
    printf("\tEnter student ID to update: ");
    scanf("%d", &id);
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            printf("\tEnter new Name: ");
            scanf(" %[^\n]s", students[i].name);
            printf("\tEnter new Course: ");
            scanf(" %[^\n]s", students[i].course);
            printf("\tEnter new Age: ");
            scanf("%d", &students[i].age);
            printf("\tStudent updated successfully.\n");
            return;
        }
    }
    printf("\tStudent not found.\n");
}

void deleteStudent() {
    int id, found = 0;
    printf("\tEnter student ID to delete: ");
    scanf("%d", &id);
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            for (int j = i; j < studentCount - 1; j++) {
                students[j] = students[j + 1];
            }
            studentCount--;
            found = 1;
            printf("\tStudent deleted successfully.\n");
            break;
        }
    }
    if (!found) {
        printf("\tStudent not found.\n");
    }
}
