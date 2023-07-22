#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 10
struct stack
{
    int data[MAX];
    int top;
};

int pushData(struct stack * st ){
    int item;
    if (st->top==MAX-1)
    {
        printf("\n=====The stack is full=====\n=====Data delete gara babu=====\n");
        return 0;
    }
    printf("\nEnter data: ");
    scanf("%d",&item);
    st->top++;
    st->data[st->top] = item; 
}

int displayData(struct stack st){
    if (st.top==-1)
    {
        printf("\n=====The stack is empty=====\n=====Suruma data hala nani=====\n");
        return 0;
    }
    printf("\n=====The data are===== ");
    for (int i = st.top; i >=0; i--)
    {
        printf("\n%d ",st.data[i]);
    }
    printf("=========================\n");
}

int popData(struct stack* st){
    if (st->top==-1)
    {
        printf("\n=====The stack is empty=====\n=====ma data halara aaija=====\n");
        return 0;
    }

    return st->data[st->top--];

    // or 
    // int data = st->data[st->top];
    // st->top--;
    // return data;
    
    
}

int main()
{
    int item;
    char ch;
    struct stack st;
    st.top=-1;
    do
    {
        printf("\n=========================\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit");
        printf("\n=========================\n");
        printf("Enter option: ");
        ch = getche();
        switch (ch)
        {
        case '1':
            pushData(&st);
            break;
        case '2':
            item = popData(&st);
            break;
        case '3':
            displayData(st);
            break;
        case '4':
        printf("\n=====jau vai jau=====");
        for (int i = 0; i < 1000000000; i++);
        
            return 0;
            break;
        
        default:
            break;
        }
        
    } while (1);
    return 0;
}