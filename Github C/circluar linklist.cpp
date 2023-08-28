#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student {
    int roll;
    char name[50];
    int age;
};

struct node {
    struct student std;
    struct node* next;
};

struct node* header = NULL; // empty list denotion

struct node* getnode(struct student s) {
    struct node* ptrnew = (struct node*)malloc(sizeof(struct node)); // getnode provides new node
    if (ptrnew == NULL) {
        printf("\nMemory Allocation failed.");
        exit(0);
    }

    ptrnew->std = s;
    ptrnew->next = NULL;
    return ptrnew;
}

void addStudentAtFront() {
    struct student s;
    struct node* ptrnew;
    printf("\nEnter Name Of student: ");
    scanf("%s", s.name);
    printf("Enter Roll Number: ");
    scanf("%d", &s.roll);
    printf("Enter Age of Student: ");
    scanf("%d", &s.age);
    ptrnew = getnode(s);

    if (header == NULL) {
        header = ptrnew;
        header->next = header; // circle
    }
    else {
        ptrnew->next = header->next;
        header->next = ptrnew;
    }
    printf("\nInserted at Front.");
}

void display() {
    struct node* ptrthis;
    if (header == NULL) {
        printf("\nList Is Empty.");
    }
    else {
        printf("\nList Contains:\nRoll\tName\tAge\n");
        ptrthis = header->next; // begin from the first node
        do {
            printf("%d\t%s\t%d\n", ptrthis->std.roll, ptrthis->std.name, ptrthis->std.age);
            ptrthis = ptrthis->next;
        } while (ptrthis != header->next); // until we reach the first node again
    }
}

void removeFromFront() {
    struct node* ptrthis;
    if (header == NULL) {
        printf("\nList Empty.");
        return;
    }
    else if (header == header->next) { // only one node
        ptrthis = header;
        header = NULL;
    }
    else {
        ptrthis = header->next; // node to be removed
        header->next = ptrthis->next; // bypass ptrthis
    }
    free(ptrthis);
    printf("\nRemoved From Front.");
}

void removeFromLast() {
    struct node* ptrthis;
    struct node* prev;
    if (header == NULL) {
        printf("\nEmpty.");
        return;
    }
    if (header == header->next) {
        ptrthis = header;
        header = NULL;
    }
    else {
        prev = header;
        ptrthis = header->next;
        while (ptrthis->next != header) {
            prev = ptrthis;
            ptrthis = ptrthis->next;
        }
        prev->next = ptrthis->next;
        header = prev;
    }
    free(ptrthis);
    printf("\nRemoved From Last.");
}

void insertAfter() {
    if (header == NULL) {
        printf("\nList is Empty");
        return;
    }

    int roll;
    printf("\nEnter Roll Number to insert after: ");
    scanf("%d", &roll);

    struct student s;
    struct node* ptrnew;
    printf("\nEnter Name Of student: ");
    scanf("%s", s.name);
    printf("Enter Roll Number: ");
    scanf("%d", &s.roll);
    printf("Enter Age of Student: ");
    scanf("%d", &s.age);
    ptrnew = getnode(s);

    struct node* ptrthis = header->next;
    while (ptrthis != header) {
        if (ptrthis->std.roll == roll) {
            ptrnew->next = ptrthis->next;
            ptrthis->next = ptrnew;
            printf("\nInserted After Roll Number %d.", roll);
            return;
        }
        ptrthis = ptrthis->next;
    }
    printf("\nRoll Number %d not found. Cannot perform insertion", roll);
}

void insertBefore() {
    if (header == NULL) {
        printf("\nList is Empty");
        return;
    }

    int roll;
    printf("\nEnter Roll Number to insert before: ");
    scanf("%d", &roll);

    struct student s;
    struct node* ptrnew;
    printf("\nEnter Name Of student: ");
    scanf("%s", s.name);
    printf("Enter Roll Number: ");
    scanf("%d", &s.roll);
    printf("Enter Age of Student: ");
    scanf("%d", &s.age);
    ptrnew = getnode(s);

    struct node* ptrthis = header->next;
    struct node* prev = header;
    while (ptrthis != header) {
        if (ptrthis->std.roll == roll) {
            ptrnew->next = ptrthis;
            prev->next = ptrnew;
            if (ptrthis == header->next)
                header->next = ptrnew;
            printf("\nInserted Before Roll Number %d.", roll);
            return;
        }
        prev = ptrthis;
        ptrthis = ptrthis->next;
    }
    printf("\nRoll Number %d not found. Cannot perform insertion", roll);
}

void removeAny() {
    if (header == NULL) {
        printf("\nList is Empty. Cannot perform ");
        return;
    }

    int roll;
    printf("\nEnter Roll Number to remove: ");
    scanf("%d", &roll);

    struct node* ptrthis = header->next;
    struct node* prev = header;
    while (ptrthis != header) {
        if (ptrthis->std.roll == roll) {
            prev->next = ptrthis->next;
            if (ptrthis == header->next)
                header->next = ptrthis->next;
            free(ptrthis);
            printf("\nRemoved RollNum %d", roll);
            return;
        }
        prev = ptrthis;
        ptrthis = ptrthis->next;
    }
    printf("\nRoll Number %d not found. Cannot perform.", roll);
}

void insertAtLast() {
    struct student s;
    struct node* ptrnew;
    printf("\nEnter Name Of student: ");
    scanf("%s", s.name);
    printf("\nEnter Roll Number:");
    scanf("%d", &s.roll);
    printf("Enter Age of the Student:\n");
    scanf("%d", &s.age);
    ptrnew = getnode(s);

    if (header == NULL) {
        header = ptrnew;
        header->next = header; // circle
    }
    else {
        ptrnew->next = header->next;
        header->next = ptrnew;
        header = header->next;
    }
    printf("\nInserted at the end of list.\n");
}

int main() {
    char ch;
    while (1) {
        printf("Select Your Option:\n1. Insert At Front\n2. Insert At Last\n3. Insert After\n4. Insert Before\n");
        printf("5. Remove From Front\n6. Remove From Last\n7. Remove Any\n8. Display All\n9. Exit\n");
        fflush(stdin);
        ch = getchar();
        switch (ch) {
        case '1':
            addStudentAtFront();
            break;
        case '2':
            insertAtLast();
            break;
        case '3':
            insertAfter();
            break;
        case '4':
            insertBefore();
            break;
        case '5':
            removeFromFront();
            break;
        case '6':
            removeFromLast();
            break;
        case '7':
            removeAny();
            break;
        case '8':
            display();
            break;
        case '9':
            return 0;
        }
    }
}

