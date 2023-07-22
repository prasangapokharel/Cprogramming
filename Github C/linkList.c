#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node* next;    
};

struct node* header;
struct node* GetNode(int num)
{
    struct node* ptrnew;
    ptrnew=(struct node*)malloc(sizeof(struct node));
    if (ptrnew==NULL)
    {
        printf("Memory allocation failed.");
        getch();
        exit(0);
    }
    ptrnew->next=NULL;
    ptrnew->info=num;
    return ptrnew; 
}
int InsertAtFront(){
    int num;
    struct node*ptrnew;
    printf("\nEnter a number to be added: ");
    scanf("%d",&num);
    ptrnew = GetNode(num);//now we have required node to be inserted.
    if (header==NULL)
    {
        header= ptrnew;
    }
    else
    {
        ptrnew->next=header; //new node's next field is set to current front node 
        header = ptrnew; //noe new node becomes front node.
    }
    printf("Item inserted at the front.\n");
    
}

int InsertAtRear(){
    int num;
    struct node*ptrnew,*ptrthis;
    printf("\nEnter the number to be added: ");
    scanf("%d",&num);
    ptrnew = GetNode(num);//now we have required node to be inserted.
    if (header==NULL)
    {
        header= ptrnew;
    }
    else{
        ptrthis=header; //start from front node
        while (ptrthis->next!=NULL)
        {
            ptrthis=ptrthis->next; //
        }
        ptrthis->next=ptrnew;
    }
}

int InsertAtAfter(){
    int num, index;
    struct node *ptrnew,*ptrthis;
    printf("\nEnter the number to be added: ");
    scanf("%d",&num);
    printf("\nAfter which node: ");
    scanf("%d",&index);
    ptrnew = GetNode(num);
    if (header==NULL)
    {
        header = ptrnew;
    }
    else{  
        ptrthis=header;
        while ((index-1)!=0)
        {
            ptrthis=ptrthis->next;
            index--;
        }
        ptrnew->next = ptrthis->next;
        ptrthis->next = ptrnew;

    }    
}

//Deleting from front
struct node * deletFromFront(){
    struct node *ptrnew = header;
    header = header->next;
    printf("\nItem deleted sucessfully..");
    free(ptrnew);
}

//Deleteing from last
struct node * deletFromLast(){
    struct node * ptrnew = header;
    struct node * ptr = header;
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

    printf("\nLast item deleted..\n");
    free(ptrnew);
}
//Deleting form given nodes
struct node * deleteFromGiven(){
    struct node * ptrnew = header;
    struct node * ptr = header;
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


int Display(){
    struct node*ptrthis;
    if (header==NULL)
    {
        printf("\nList is empty");
    }
    else{
        printf("\nList contains:\n");
        for (ptrthis=header;ptrthis!=NULL;ptrthis=ptrthis->next)
        {
            printf("%d\t",ptrthis->info);
        }
        
    }
}

int main()
{
    char choice;
    header= NULL; //initialy list is empty
    while (1)
    {
        // system("cls");
        printf("\nSelect your choice:\n");
        printf("1. Insert at front.\n2. Insert at rear.\n3. Insert at after.\n4. Remove from front.\n5. Remove form rear.\n6. Remove any.\n7. Display.\n8. Exit.\nEnter option: ");
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
                printf("\nMajala janu hai bye bye.....");
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