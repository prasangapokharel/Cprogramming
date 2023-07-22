
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100

struct stack
{
    char item[MAX];
    int tos;
};

void push(struct stack *s, char c){
    if (s->tos==MAX-1)
    {
        printf("The stack is full.");
    }
}
int main()
{
    int j;
    int valid=1;
    char exp[MAX], symb;
    struct stack s;
    printf("Enter your expression: ");
    gets(exp);
    for (int i = 0; i < strlen(exp); i++)
    {
        symb = exp[i];
        if (symb == '(' || symb == '{' ||symb == '[' )
        {
            push(&s, symb);
        }
        if (symb == ')' || symb == '}' ||symb == ']' )
        {
            if (IsEmpty(s))
            {
                valid = 0;
            }
            else{
                j = pop(&s);
                if ((symb == ')' && symb == '(') || (symb == '}' && symb == '{') ||(symb == ']' && symb == ']'))
                {
                    
                }
                
            }
            
        }
        
    }
    
    return 0;
}