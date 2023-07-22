// circular linked list example.......

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

struct node
{
    int data;
    struct node *next;
};

struct node *tail;

struct node *GetNode(int num)
{
    struct node *ptrnew;
    ptrnew = (struct node *)malloc(sizeof(struct node));
    if (ptrnew == NULL)
    {
        printf("Memory allocation failed.");
        getch();
        exit(0);
    }
    ptrnew->data = num;
    ptrnew->next = NULL;
    return ptrnew;
}

int InsertAtFront()
{
    int num;
    struct node *ptrnew;
    printf("\n\t\tEnter a number to be added: ");
    scanf("%d", &num);
    ptrnew = GetNode(num); // now we have required node to be inserted.
    if (tail == NULL)
    {
        tail = ptrnew;
        ptrnew->next = tail;
    }
    else
    {
        ptrnew->next = tail->next;
        tail->next = ptrnew;
    }
    printf("\t\tData inserted at the front.\n");
}

int InsertAtRear()
{
    int num;
    struct node *ptrnew;
    printf("\n\t\tEnter the number to be added: ");
    scanf("%d", &num);
    ptrnew = GetNode(num); // now we have required node to be inserted.
    if (tail == NULL)
    {
        tail = ptrnew;
        ptrnew->next = tail;
    }
    else
    {
        ptrnew->next = tail->next;
        tail->next = ptrnew;
        tail = tail->next;
    }
    printf("\t\tData inserted at the rear\n");
}

int InsertAtAfter()
{ // Some issue encountered..........solve it
    int key, num;
    struct node *ptrnew, *ptrthis;
    if (tail == NULL)
    {
        printf("\n\t\tList is empty.");
        return 0;
    }

    printf("\n\t\tEnter a number after which you want to insert: ");
    scanf("%d", &key);
    ptrthis = tail;
    do
    {
        if (ptrthis->data == key)
        {
            printf("\n\t\tEnter a number: ");
            scanf("%d", &num);
            ptrnew = GetNode(num);
            ptrnew->next = ptrthis->next;
            ptrthis->next = ptrnew;
            if (ptrthis == tail)
            {
                tail = tail->next;
            }
            printf("\n\t\tData inserted after %d", key);
            return 0;
        }
        ptrthis = ptrthis->next;

    } while (ptrthis != tail);
    printf("\n\t\tNode whith data %d is not found\nPress enter to continue.", key);
    getch();
}

int deletFromFront()
{
    struct node *ptrthis;
    if (tail == NULL)
    {
        printf("\n\t\tList is empty");
        return 0;
    }
    if (tail == tail->next)
    {
        ptrthis = tail;
        tail = NULL;
    }
    else
    {
        ptrthis = tail->next;
        tail->next = ptrthis->next;
    }
    free(ptrthis);
    printf("\n\t\tRemoved from front.");
}

int deletFromLast()
{
    struct node *ptrthis;
    if (tail == NULL)
    {
        printf("\n\t\tList is empty");
        return 0;
    }
    ptrthis = tail->next;
    while (ptrthis->next != tail)
    {
        ptrthis = ptrthis->next;
    }
    if (tail == tail->next)
    {
        ptrthis = tail;
        tail = NULL;
    }
    else
    {
        ptrthis->next = tail->next;
        free(tail);
        tail = ptrthis;
    }
    printf("\n\t\tRemoved from last.");
}

int deleteFromGiven()
{
    int key;
    struct node *ptrthis,*ptrpre;
    if (tail == NULL)
    {
        printf("\n\t\tList is empty");
        return 0;
    }
    printf("\n\t\tEnter a number which you want to delete: ");
    scanf("%d", &key);
    
    ptrthis = tail;
    do
    {
        if (ptrthis->data == key)
        {
            if (tail = tail->next)
            {
                free(tail);
                tail = NULL;
                printf("\n\t\tData deleted sucessfully.");
                return 0;
            }
        
            if (ptrthis == tail)
            {
                while (ptrthis->next!=tail)
                {
                    ptrthis = ptrthis->next;
                }
                ptrthis->next = tail->next;
                free(tail);
                tail = ptrthis;
                printf("\n\t\tData deleted sucessfully.");
                return 0;
            }
            else{
                while (ptrpre->next!=ptrthis)
                {
                   ptrpre = ptrpre->next;
                }
                ptrpre->next = ptrthis->next;
                free(ptrthis);                 
                printf("\n\t\tData deleted sucessfully.");
                return 0;
            }
        }
        ptrthis = ptrthis->next;

    } while (ptrthis != tail);
}

int Display()
{
    struct node *ptr = tail;
    if (tail == NULL)
    {
        printf("\n\t\tThe list is empty..");
        return 0;
    }

    printf("\n\t\t=======================It contain:=======================\n");
    ptr = tail->next;
    printf("\t\t");
    do
    {
        printf("%d\t", ptr->data);
        
        ptr = ptr->next;
    } while (ptr != tail->next);
    printf("\n\t\t=========================================================");
    printf("\n\t\tPress enter to continue..\n\t\t");
    getch();
}

int main()
{
    char choice;
    tail = NULL; // initialy list is empty
    while (1)
    {
        printf("\n\t\t|==================Select your choice:==================|\n\t\t|-------------------------------------------------------|\n");
        printf("\t\t|  1. Insert at front.\t\t5. Remove form rear.\t|\n\t\t|  2. Insert at rear.\t\t6. Remove any.\t\t|\n\t\t|  3. Insert at after.\t\t7. Display.\t\t|\n\t\t|  4. Remove from front.\t8. Exit.\t\t|\n\t\t|=======================================================| \n\t\t==> Enter option: ");
        choice = getche();
        switch (choice)
        {
        case '1':
            InsertAtFront();
            break;
        case '2':
            InsertAtRear();
            break;
        case '3':
            InsertAtAfter();
            break;
        case '4':
            deletFromFront();
            break;
        case '5':
            deletFromLast();
            break;
        case '6':
            deleteFromGiven();
            break;
        case '7':
            Display();
            break;
        case '8':
            printf("\n\t\tMajala janu hai bye bye.....");
            return 0;
            // or exit(0)
            break;

        default:
            printf("Please Enter Valid option.....\nNepali translation:\nOption ramrori hernus.....");
            break;
        }
    }

    return 0;
}