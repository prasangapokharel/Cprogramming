#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_STUDENTS 100

// Structures
typedef struct {
    int book_id;
    char title[100];
    int available;
} Book;

typedef struct {
    int student_id;
    char name[100];
} Student;

// Function prototypes
void addBook(Book books[], int *bookCount);
void displayBooks(Book books[], int bookCount);
void addStudent(Student students[], int *studentCount);
void displayStudents(Student students[], int studentCount);
void issueBook(Book books[], int bookCount, Student students[], int studentCount);
void returnBook(Book books[], int bookCount, Student students[], int studentCount);

int main() {
    Book books[MAX_BOOKS];
    Student students[MAX_STUDENTS];
    int bookCount = 0;
    int studentCount = 0;
    int choice;

    do {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Add Student\n");
        printf("4. Display Students\n");
        printf("5. Issue Book\n");
        printf("6. Return Book\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook(books, &bookCount);
                break;
            case 2:
                displayBooks(books, bookCount);
                break;
            case 3:
                addStudent(students, &studentCount);
                break;
            case 4:
                displayStudents(students, studentCount);
                break;
            case 5:
                issueBook(books, bookCount, students, studentCount);
                break;
            case 6:
                returnBook(books, bookCount, students, studentCount);
                break;
            case 0:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 0);

    return 0;
}

void addBook(Book books[], int *bookCount) {
    // Implement the function to add a book
}

void displayBooks(Book books[], int bookCount) {
    // Implement the function to display books
}

void addStudent(Student students[], int *studentCount) {
    // Implement the function to add a student
}

void displayStudents(Student students[], int studentCount) {
    // Implement the function to display students
}

void issueBook(Book books[], int bookCount, Student students[], int studentCount) {
    // Implement the function to issue a book to a student
}

void returnBook(Book books[], int bookCount, Student students[], int studentCount) {
    // Implement the function to return a book from a student
}

