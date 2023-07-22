//Implementing queue using linked list
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
struct node
{
    int data;
    struct node*next; 
};
struct node * header;
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
int main()
{
    int ;
    return 0;
}