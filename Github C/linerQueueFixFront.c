#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 5
struct queue
{
    int item[MAX];
    int front;
    int rear;
};

int enqueue(struct queue *q) //insert item into the queue.0
{
    int n;
    if (q->rear== MAX-1)
    {
        printf("\nQueue is full");
        return 0;
    }
    printf("\nEnter item: ");
    scanf("%d",&n);
    q->rear++;
    q->item[q->rear]=n;
    printf("Item added");
    
}

int dequeue(struct queue*q) //removing item.
{
    if (q->rear==-1)
    {
        printf("\nQueue is empty");
        return 0;
    }
    for (int i = 0; i < q->rear; i++)
    {
        q->item[i] = q->item[i+1];
    }
    
    q->rear--;
    
}

int display(struct queue q){
    if (q.rear== -1)
    {
        printf("\nQueue is empty");

    }
    else{
        printf("\nQueue contains: \n");
        for (int i = q.front; i <= q.rear; i++)
        {
            printf("%d\t",q.item[i]);
        }
        
    }
    
}

int main()
{
    struct queue q;
    char ch;
    int ret;
    q.rear=-1;
    q.front=0;
    do
    {
    printf("\n1. Add item\n2. Remove item.\n3. Display item\n4. Exit");
    printf("\nEnter option here: ");
    ch = getche();
    switch (ch)
    {
    case '1':
        
        enqueue(&q);
        break;
    case '2':
        ret = q.item[q.front];
        dequeue(&q);
        printf("\n%d is removed...",ret);
        break;
    case '3':
        display(q);
        break;
    case '4':
        return 0;
        break;
    
    default:
        break;
    }
        
    } while (1);
    


    return 0;
}