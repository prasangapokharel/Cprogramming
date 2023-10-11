#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* header = NULL; // Pointer to the first node (head)

struct node* getnode(int n)
{
    struct node* ptrnew = (struct node*)malloc(sizeof(struct node));
    if (ptrnew == NULL)
    {
        printf("\nMemory allocation failed.");
        exit(1);
    }
    ptrnew->data = n;
    ptrnew->next = NULL;
    return ptrnew;
}

void insertAtFront()
{
    struct node* ptrnew;
    int n;
    printf("\nEnter Number: ");
    if (scanf("%d", &n) != 1)
    {
        printf("Invalid input. Please enter a valid integer.\n");
        return;
    }
    ptrnew = getnode(n);
    if (header == NULL)
    {
        header = ptrnew;
    }
    else
    {
        ptrnew->next = header;
        header = ptrnew;
    }
    printf("\nNumber inserted at the front.");
}

void insertAtBack()
{
    struct node* ptrnew, * ptrthis;
    int n;
    printf("\nEnter Number: ");
    if (scanf("%d", &n) != 1)
    {
        printf("Invalid input. Please enter a valid integer.\n");
        return;
    }
    ptrnew = getnode(n);
    if (header == NULL)
    {
        header = ptrnew;
    }
    else
    {
        ptrthis = header;
        while (ptrthis->next != NULL)
        {
            ptrthis = ptrthis->next;
        }
        ptrthis->next = ptrnew;
    }
    printf("\nNumber inserted at the end.");
}

void insertAfter()
{
    int n, target;
    struct node* ptrnew, * ptrthis;
    printf("\nEnter Number After Which you want to insert: ");
    if (scanf("%d", &target) != 1)
    {
        printf("Invalid input. Please enter a valid integer.\n");
        return;
    }
    printf("Enter Data to Insert: ");
    if (scanf("%d", &n) != 1)
    {
        printf("Invalid input. Please enter a valid integer.\n");
        return;
    }
    ptrnew = getnode(n);
    if (header == NULL)
    {
        printf("\nList is empty. Cannot insert after the specified number.");
        return;
    }
    ptrthis = header;
    while (ptrthis != NULL)
    {
        if (ptrthis->data == target)
        {
            ptrnew->next = ptrthis->next;
            ptrthis->next = ptrnew;
            printf("\nNumber inserted after the specified number.");
            return;
        }
        ptrthis = ptrthis->next;
    }
    printf("\nTarget number not found.");
}

void display()
{
    struct node* ptrthis = header;
    if (ptrthis == NULL)
    {
        printf("\nList is empty.\n");
        return;
    }

    printf("\nList Contents: ");
    while (ptrthis != NULL)
    {
        printf("%d ", ptrthis->data);
        ptrthis = ptrthis->next;
    }
    printf("\n");
}

void removeFromFront()
{
    struct node* ptrthis;
    if (header == NULL)
    {
        printf("\nList is empty. Cannot remove from the front.");
        return;
    }
    ptrthis = header;
    header = header->next;
    free(ptrthis);
    printf("\nNode removed from the front.");
}

void removeFromLast()
{
    struct node* ptrprev, * ptrthis;
    if (header == NULL)
    {
        printf("\nList is empty. Cannot remove from the last.");
        return;
    }
    if (header->next == NULL)
    {
        free(header);
        header = NULL;
        printf("\nNode removed from the last.");
        return;
    }
    ptrprev = NULL;
    ptrthis = header;
    while (ptrthis->next != NULL)
    {
        ptrprev = ptrthis;
        ptrthis = ptrthis->next;
    }
    free(ptrthis);
    ptrprev->next = NULL;
    printf("\nNode removed from the last.");
}

void removeAny()
{
    struct node* ptrprev, * ptrthis;
    int target;
    if (header == NULL)
    {
        printf("\nList is empty. Cannot remove any node.");
        return;
    }
    printf("\nEnter the number to be removed: ");
    if (scanf("%d", &target) != 1)
    {
        printf("Invalid input. Please enter a valid integer.\n");
        return;
    }
    ptrprev = NULL;
    ptrthis = header;
    while (ptrthis != NULL)
    {
        if (ptrthis->data == target)
        {
            if (ptrprev == NULL)
            {
                header = ptrthis->next;
            }
            else
            {
                ptrprev->next = ptrthis->next;
            }
            free(ptrthis);
            printf("\nNode removed.");
            return;
        }
        ptrprev = ptrthis;
        ptrthis = ptrthis->next;
    }
    printf("\nTarget number not found.");
}

void freeList()
{
    struct node* ptrthis = header;
    while (ptrthis != NULL)
    {
        struct node* temp = ptrthis;
        ptrthis = ptrthis->next;
        free(temp);
    }
}

int main()
{
    int choice;
    while (1)
    {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Insert at the front\n");
        printf("2. Insert at the back\n");
        printf("3. Insert after a number\n");
        printf("4. Display the list\n");
        printf("5. Remove from the front\n");
        printf("6. Remove from the last\n");
        printf("7. Remove a specific number\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input. Please enter a valid integer.\n");
            break;
        }

        switch (choice)
        {
            case 1:
                insertAtFront();
                break;
            case 2:
                insertAtBack();
                break;
            case 3:
                insertAfter();
                break;
            case 4:
                display();
                break;
            case 5:
                removeFromFront();
                break;
            case 6:
                removeFromLast();
                break;
            case 7:
                removeAny();
                break;
            case 8:
                freeList();
                printf("\nExiting the program.\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    }
    return 0;
}

