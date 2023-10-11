#include <stdio.h>
#include <conio.h>

#define MAX_SIZE 100

struct Student {
    char name[50];
    int age;
    float gpa;
};

struct Student studentList[MAX_SIZE];
int count = 0;

void registerStudent() {
    if (count >= MAX_SIZE) {
        printf("List is full. Cannot register more students.\n");
        return;
    }

    struct Student newStudent;

    printf("Enter student name: ");
    scanf("%s", newStudent.name);

    printf("Enter student age: ");
    scanf("%d", &newStudent.age);

    printf("Enter student GPA: ");
    scanf("%f", &newStudent.gpa);

    studentList[count] = newStudent;
    count++;

    printf("Student registered successfully.\n");
}

void updateStudent() {
    if (count == 0) {
        printf("No students in the list. Cannot update.\n");
        return;
    }

    char searchName[50];
    printf("Enter the name of the student to update: ");
    scanf("%s", searchName);

    int found = 0;
    int i;
    for (i = 0; i < count; i++) {
        if (strcmp(studentList[i].name, searchName) == 0) 
		{
            found = 1;
            break;
        }
    }

    if (found) {
        printf("Enter updated student name: ");
        scanf("%s", studentList[i].name);

        printf("Enter updated student age: ");
        scanf("%d", &studentList[i].age);

        printf("Enter updated student GPA: ");
        scanf("%f", &studentList[i].gpa);

        printf("Student data updated successfully.\n");
    } else {
        printf("Student not found in the list.\n");
    }
}

void displayStudents() {
    if (count == 0) {
        printf("No students in the list.\n");
        return;
    }

    printf("\nStudent List:\n");
    printf("--------------------------------------------------------\n");
    printf("Name\t\tAge\t\tGPA\n");
    printf("--------------------------------------------------------\n");

    int i;
    for (i = 0; i < count; i++) {
        printf("%s\t\t%d\t\t%.2f\n", studentList[i].name, studentList[i].age, studentList[i].gpa);
    }

    printf("--------------------------------------------------------\n");
}

int main() {
    char choice;

    while (1) {
        printf("\n************ Student Management System ************\n");
        printf("1. Register Student\n");
        printf("2. Update Student\n");
        printf("3. Display Students\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        choice = getche();
        printf("\n");

        switch (choice) {
            case '1':
                registerStudent();
                break;
            case '2':
                updateStudent();
                break;
            case '3':
                displayStudents();
                break;
            case '4':
                printf("Exiting program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}

