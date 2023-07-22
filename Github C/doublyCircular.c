#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node{
    int data;
    struct node * next;
    struct node * prev;
};
struct node * tail = NULL;

struct node * getNode(int num){
    struct node * ptrnew = (struct node*)malloc(sizeof(struct node));
    if (ptrnew = NULL)
    {
        printf("Memory allocation failed.");
        getch();
        return 0;
    }
    ptrnew->data = num;
    ptrnew->next = ptrnew->prev = NULL;
    return ptrnew;
}
int insertAtFront(){
    int num;
    struct node * ptrnew, *ptrthis;
    ptrnew = getNode(num);
    if (tail == NULL)
    {
        tail = ptrnew;
        tail->next = tail;
        tail->prev = tail;
    }
    else{
        
    }
    
}
int main()
{
    int ;
    return 0;
}