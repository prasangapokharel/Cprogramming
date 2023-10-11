#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

struct stack {
    char item[MAX];
    int tos;
};

void push(struct stack *sp, char ch) {
    sp->item[++sp->tos] = ch;
}

char pop(struct stack *sp) {
    return sp->item[sp->tos--];
}

char peek(struct stack *sp) {
    return sp->item[sp->tos];
}

int getPrecedence(char ch) {
    switch (ch) {
        case '(':
            return 0;
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '$':
            return 3;
    }
    return -1; // Add a default return value in case of an invalid character
}

int main() {
    char infix[MAX], ch;
    struct stack opstack, poststack;
    opstack.tos = -1;
    poststack.tos = -1;

    printf("Enter the infix expression: ");
    gets(infix);

    for (int i = 0; i < strlen(infix); i++) 
	{

        if (infix[i] == '(')
		 {
            push(&opstack, infix[i]);
        }
		 else if (isalnum(infix[i])) 
		 {
            push(&poststack, infix[i]);
        } 
		else if (infix[i] == '$' || infix[i] == '/' || infix[i] == '*' || infix[i] == '+' || infix[i] == '-') 
		{
            while (opstack.tos != -1 && getPrecedence(infix[i]) <= getPrecedence(peek(&opstack)))
			 {
                ch = pop(&opstack);
                push(&poststack, ch);
            }
            push(&opstack, infix[i]);
        }
		 else if (infix[i] == ')') {
            while (opstack.tos != -1 && peek(&opstack) != '(') 
			{
                ch = pop(&opstack);
                push(&poststack, ch);
            }
            if (opstack.tos != -1 && peek(&opstack) == '(') 
			{
                pop(&opstack); // Pop the '(' from the operator stack
            }
        }
    }

    while (opstack.tos != -1) 
	{
        ch = pop(&opstack);
        push(&poststack, ch);
    }

    printf("Postfix expression: ");
    for (int i = 0; i <= poststack.tos; i++) 
	{
        printf("%c", poststack.item[i]);
    }
    printf("\n");

    return 0;
}

