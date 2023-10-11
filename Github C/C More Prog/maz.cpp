#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 10

struct Student {
    char name[100];
    int id;
    char address[100];
};

struct Student studentList[MAX_STUDENTS];
int studentCount = 0;

void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        printf("Maximum number of students reached.\n");
        return;
    }

    struct Student newStudent;
    printf("Enter the name of the student: ");
    fgets(newStudent.name, sizeof(newStudent.name), stdin);
    printf("Enter the ID of the student: ");
    scanf("%d", &newStudent.id);
    getchar(); // Clear the newline character from the buffer
    printf("Enter the address of the student: ");
    fgets(newStudent.address, sizeof(newStudent.address), stdin);

    studentList[studentCount] = newStudent;
    studentCount++;

    printf("Student added successfully.\n");
}

void updateStudent() {
    int id;
    printf("Enter the ID of the student to update: ");
    scanf("%d", &id);
    getchar(); // Clear the newline character from the buffer

    int index = -1;
    for (int i = 0; i < studentCount; i++) {
        if (studentList[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Student with ID %d not found.\n", id);
        return;
    }

    struct Student updatedStudent;
    printf("Enter the new name of the student: ");
    fgets(updatedStudent.name, sizeof(updatedStudent.name), stdin);
    printf("Enter the new address of the student: ");
    fgets(updatedStudent.address, sizeof(updatedStudent.address), stdin);

    studentList[index] = updatedStudent;
    printf("Student updated successfully.\n");
}

void printStudentList() {
    if (studentCount == 0) {
        printf("Student list is empty.\n");
        return;
    }

    printf("Student List:\n");
    for (int i = 0; i < studentCount; i++) {
        printf("Name: %s", studentList[i].name);
        printf("ID: %d\n", studentList[i].id);
        printf("Address: %s\n", studentList[i].address);
        printf("--------------------------\n");
    }
}

int main() {
    int choice;

    do {
        printf("Menu:\n");
        printf("1. Add Student\n");
        printf("2. Update Student\n");
        printf("3. Print Student List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear the newline character from the buffer

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                updateStudent();
                break;
            case 3:
                printStudentList();
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

        printf("\n");
    } while (choice != 4);

    return 0;
}

