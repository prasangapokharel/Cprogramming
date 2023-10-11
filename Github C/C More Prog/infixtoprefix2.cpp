#include <stdio.h>
#include <string.h>
#include <process.h>
#include <ctype.h>

#define MAX 100

struct stack {
    char items[MAX];
    int tos;
};

void push(struct stack *sp, char ch) {
    sp->items[sp->tos++] = ch;
    return;
}

char pop(struct stack *sp) {
    return sp->items[--sp->tos];
}

char peek(struct stack *sp) {
    return sp->items[sp->tos - 1];
}

int getPrecedence(char ch) {
    switch (ch) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '$': return 3;
        default: return 0;
    }
}

void infixToPrefix() {
    char infix[MAX], ch;
    struct stack opstack, prestack;
    opstack.tos = 0;
    prestack.tos = 0;
    system("cls");
    printf("\nEnter Your Infix Expression:\n");
    gets(infix);
    for (int i = strlen(infix) - 1; i >= 0; i--) {
        if (infix[i] == ')') 
		{
            push(&opstack, infix[i]);
        }
		 else if (isalnum(infix[i]))
		  {
            push(&prestack, infix[i]);
        } else if (infix[i] == '(') 
		{
            do 
			{
                ch = pop(&opstack);
                if (ch != ')')
                    push(&prestack, ch);
            } 
			while (ch != ')');
        } 
		else 
		{
            if (opstack.tos == 0)
			 {
                push(&opstack, infix[i]);
            } 
			else 
			{
                while (getPrecedence(infix[i]) < getPrecedence(peek(&opstack))) 
				{
                    ch = pop(&opstack);
                    push(&prestack, ch);
                    if (opstack.tos == 0)
                        break;
                }
                push(&opstack, infix[i]);
            }
        }
    }
    while (opstack.tos != 0)
	 {
        push(&prestack, pop(&opstack));
    }
    for (int i = prestack.tos - 1; i >= 0; i--) 
	{
        printf("%c", prestack.items[i]);
    }
    getchar();
    return;
}

int main() {
    infixToPrefix();
    return 0;
}

