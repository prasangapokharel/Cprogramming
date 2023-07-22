#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>

struct node{
    int data;
    struct node *next;
};
struct node * head;

void linkListTraversal(){
    struct node*ptrthis;
    if (head==NULL)
    {
        printf("\nList is empty");
    }
    else{
        printf("\nList contains:\n");
        ptrthis = head;
        while (ptrthis!=0)
        {
            printf("%d\t",ptrthis->data);
            ptrthis=ptrthis->next;
            
        }        
    }

}


struct node * linkListInsertionFront(){
    int data;
    printf("\nEnter data:   ");
    scanf("%d",&data);
    struct node * ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = head;
    head = ptr;
    return head;
}

struct node * deletFromFront(){
    struct node *ptr = head;
    head = head->next;
    free(ptr);
}

struct node * deletFromLast(){
    struct node * ptrnew;
    struct node * ptr;
    ptrnew = head;
    ptr = head;
    int k = 0;
    while (ptrnew->next!=NULL)
    {
        ptrnew = ptrnew->next;
        k++;
    }
    while (k-1!=0)
    {
        ptr=ptr->next;
        k--;
    }
    ptr->next = NULL;

    printf("Last item deleted..\n");
    free(ptrnew);
}

struct node * deleteFromGiven(){
    struct node * ptrnew = head;
    struct node * ptr = head;
    int ind1,ind2;
    printf("\nEnter nodes number to be deleted: ");
    scanf("%d",&ind1);
    ind2=ind1;
    while (ind1-1!=0)
    {
        ptrnew=ptrnew->next;
        ind1--;
    }
    while (ind2-2!=0)
    {
        ptr=ptr->next;
        ind2--;
    }
    ptr->next=ptrnew->next;
    printf("Given item deleted.\n");
    free(ptrnew);
}

int main()
{
    char cho;
    int data;
    head = (struct node*)malloc(sizeof(struct node));
    head = NULL;
    while (1)
    {
        printf("\n1. to add at front.\n2. to display.\n3. Delet front.\n4. Delete last\n5. delete from given\n6. Exit.\nEnter option: ");
        cho = getche();
        switch (cho)
        {
            case '1':
                linkListInsertionFront();

                break;
            case '2':
                linkListTraversal();

                break;
            case '3':
                deletFromFront();
                break;
            case '4':
                deletFromLast();
                break;
            case '5':
                deleteFromGiven();
                break;
            case '6':
                return 0;
                break;

            default:
                break;
        }

    }
    
    return 0;
}