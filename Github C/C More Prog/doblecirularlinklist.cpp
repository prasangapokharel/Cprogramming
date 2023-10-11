#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node* next;
    struct node* prev;
};

struct node* header = NULL;

struct node* getnode(int n) {
    struct node* ptrnew = (struct node*)malloc(sizeof(struct node));

    if (ptrnew == NULL) {
        printf("\nMemory Allocation Failed");
        exit(0);
    }

    ptrnew->info = n;
    ptrnew->next = ptrnew->prev = NULL;
    return ptrnew;
}

void insertAtFront() {
    int n;
    struct node* ptrnew;
    printf("\nEnter New Number: ");
    scanf("%d", &n);
    ptrnew = getnode(n);
    if (header == NULL) {
        header = ptrnew;
        header->next = header->prev = header;
    } else {
        ptrnew->next = header;
        ptrnew->prev = header->prev;
        header->prev->next = ptrnew;
        header->prev = ptrnew;
        header = ptrnew;
    }
    printf("\nNode Inserted at front.");
}

void insertAtBack() {
    int n;
    struct node* ptrnew;
    printf("\nEnter New Number: ");
    scanf("%d", &n);
    ptrnew = getnode(n);
    if (header == NULL) {
        header = ptrnew;
        header->next = header->prev = header;
    } else {
        ptrnew->next = header;
        ptrnew->prev = header->prev;
        header->prev->next = ptrnew;
        header->prev = ptrnew;
    }
    printf("\nNode Inserted at Last/back.");
}

void forwardDisplay() {
    struct node* ptrthis;
    if (header == NULL)
        printf("\nList Empty.");
    else {
        printf("\nList Contains:\n");
        for (ptrthis = header; ptrthis != header->prev; ptrthis = ptrthis->next) {
            printf("%d\t", ptrthis->info);
        }
        printf("%d\t", ptrthis->info); // Print the last node
    }
}

void insertAfter() {
    struct node* ptrthis, * ptrnew;
    int n, key;
    if (header == NULL) {
        printf("\nList Empty.");
        return;
    }
    printf("\nEnter a Number after which you want to insert: ");
    scanf("%d", &key);

    ptrthis = header;

    for (; ptrthis != header; ptrthis = ptrthis->next) {
        if (ptrthis->info == key) {
            printf("\nEnter New Node To Be Inserted: ");
            scanf("%d", &n);

            ptrnew = getnode(n);
            ptrnew->prev = ptrthis;
            ptrnew->next = ptrthis->next;
            ptrthis->next->prev = ptrnew;
            ptrthis->next = ptrnew;

            printf("\nNode Inserted After %d", key);
            return;
        }
    }

    printf("\n%d not Found in the list", key);
}

void insertBefore() {
    struct node* ptrthis, * ptrnew;
    int n, key;
    if (header == NULL) {
        printf("\nList Empty.");
        return;
    }
    printf("\nEnter a Number before which you want to insert: ");
    scanf("%d", &key);

    ptrthis = header;

    for (; ptrthis != header; ptrthis = ptrthis->next) {
        if (ptrthis->info == key) {
            printf("\nEnter New Node To Be Inserted: ");
            scanf("%d", &n);

            ptrnew = getnode(n);
            ptrnew->prev = ptrthis->prev;
            ptrnew->next = ptrthis;
            ptrthis->prev->next = ptrnew;
            ptrthis->prev = ptrnew;

            if (ptrthis == header)
                header = ptrnew;

            printf("\nNode Inserted before %d", key);
            return;
        }
    }

    printf("\n%d not Found in the list", key);
}

void removeFromFront() {
    struct node* ptrthis;
    if (header == NULL) {
        printf("\nList Empty.");
        return;
    }

    ptrthis = header;

    if (header == header->next) {
        header = NULL;
    } else {
        header = header->next;
        header->prev = ptrthis->prev;
        (ptrthis->prev)->next = header;
    }

    free(ptrthis);
    printf("\nNode Removed from the front.");
}

void removeFromLast() {
    struct node* ptrthis;
    if (header == NULL) {
        printf("\nList Empty.");
        return;
    }

    ptrthis = header->prev;

    if (header == header->prev) {
        header = NULL;
    } else {
        header->prev = ptrthis->prev;
        (ptrthis->prev)->next = header;
    }

    free(ptrthis);
    printf("\nNode Removed from the last.");
}

void backwardDisplay() {
    struct node* ptrthis;
    if (header == NULL)
        printf("\nList Empty.");
    else {
        printf("\nList Contains:\n");
        for (ptrthis = header->prev; ptrthis != header; ptrthis = ptrthis->prev) {
            printf("%d\t", ptrthis->info);
        }
        printf("%d\t", ptrthis->info); // Print the first node
    }
}

int main() {
    char ch;
    while (1) {
        system("cls");
        printf("\nSELECT OPTION\n1. InsertAtFront\n2. InsertAtEnd\n3. InsertAfter\n4. InsertBefore\n5. RemoveFromFront\n6. RemoveFromLast\n");
        printf("7. DisplayForward\n8. DisplayBackward\nX. Exit\n");
        fflush(stdin);
        ch = getchar();
        switch (ch) {
            case '1':
                insertAtFront();
                break;
            case '2':
                insertAtBack();
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
                forwardDisplay();
                break;
            case '8':
                backwardDisplay();
                break;
            case 'X':
            case 'x':
                return 0;
            default:
                printf("\nInvalid Option");
                break;
        }
        getchar();
    }
    return 0;
}

