#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 100
#define TRUE 1
#define FALSE 0

struct list
{
    int array[MAX];
    int pos;
};

int addNumber(struct list * lst){
    int newEle;
    if (lst->pos==MAX-1)
    {
        printf("List is full...");
    }
    else{
        lst->pos++;
        printf("\nEnter new element:  ");
        scanf("%d",&newEle);
        lst->array[lst->pos] = newEle;
        printf("\n");
    }
}

// ==============display=============
int displayList(struct list*lst){
    if (lst->pos==-1)
    {
        printf("\nThe list is empty....\n");
    }
    else{
        printf("\nYour list are: \n");
        for (int i = 0; i <= lst->pos; i++)
        {
            printf("%d ",lst->array[i]);
        }
        
    }
    
}

// =========remove element from given position=============
int removeNum(struct list*lst){
    int position;
    if (lst->pos==-1)
    {
        printf("\nThe list is empty..");
    }
    else{
        printf("\nEnter the position of element to delete.");
        scanf("%d",&position);
        for (int i = position-1; i <= lst->pos; i++)
        {
            lst->array[i] = lst->array[i+1];
        }
        lst->pos--;
        

    }
    
}

int main()
{
    struct list ls;
    char choice;
    ls.pos=-1;
    do
    {
        
    printf("\n1. Add number.\n2. Remove number.\n3. Modify Number.\n4. Display list.\n5. Exit.");
    printf("\nEnter your option: ");
    choice = getche();
    switch (choice)
    {
    case '1':
        addNumber(&ls);
        break;
    case '2':
    removeNum(&ls);
        break;
    case '3':
        // modifyNum();
        break;
    case '4':
        displayList(&ls);
        break;
    case '5':
        return 0;
        break;
    
    default:
        break;
    }
    } while (TRUE);
    
    return 0;
}