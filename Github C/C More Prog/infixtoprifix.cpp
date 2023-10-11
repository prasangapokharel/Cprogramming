#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 100

struct stack {
    char items[MAX];
    int tos;
};

void push(struct stack* sp, char ch)
{
    sp->items[++sp->tos] = ch;
}

char pop(struct stack* sp)
{
    return sp->items[sp->tos--];
}

char peek(struct stack* sp)
{
    return sp->items[sp->tos];
}

int isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
        return 1;
    return 0;
}

int getPrecedence(char ch)
{
    switch (ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return 0;
}

void infixToPrefix(char infix[], char prefix[])
{
    struct stack opstack;
    opstack.tos = -1;
    int i, j = 0;

    for (i = strlen(infix) - 1; i >= 0; i--) {
        if (isalnum(infix[i])) {
            prefix[j++] = infix[i];
        }
        else if (infix[i] == ')') {
            push(&opstack, infix[i]);
        }
        else if (infix[i] == '(') {
            while (opstack.tos != -1 && peek(&opstack) != ')') {
                prefix[j++] = pop(&opstack);
            }
            if (opstack.tos != -1 && peek(&opstack) != ')') {
                printf("Invalid infix expression\n");
                return;
            }
            else {
                pop(&opstack);
            }
        }
        else if (isOperator(infix[i])) {
            while (opstack.tos != -1 && getPrecedence(infix[i]) < getPrecedence(peek(&opstack))) {
                prefix[j++] = pop(&opstack);
            }
            push(&opstack, infix[i]);
        }
    }

    while (opstack.tos != -1) {
        prefix[j++] = pop(&opstack);
    }

    prefix[j] = '\0';

    // Reverse the prefix expression
    strrev(prefix);
}

int main()
{
    char infix[MAX], prefix[MAX];

    printf("Enter your infix expression: ");
    gets(infix);

    infixToPrefix(infix, prefix);

    printf("Prefix expression: %s\n", prefix);

    return 0;
}

