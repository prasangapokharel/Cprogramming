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

void infixToPrefix(char infix[MAX]) {
    struct stack opstack, prestack;
    opstack.tos = -1;
    prestack.tos = -1;

    for (int i = strlen(infix) - 1; i >= 0; i--) {
        char ch;
        if (infix[i] == ')') {
            push(&opstack, infix[i]);
        } else if (isalnum(infix[i])) {
            push(&prestack, infix[i]);
        } else if (infix[i] == '$' || infix[i] == '/' || infix[i] == '*' || infix[i] == '+' || infix[i] == '-') {
            while (opstack.tos != -1 && getPrecedence(infix[i]) < getPrecedence(peek(&opstack))) {
                ch = pop(&opstack);
                push(&prestack, ch);
            }
            push(&opstack, infix[i]);
        } else if (infix[i] == '(') {
            while (opstack.tos != -1 && peek(&opstack) != ')') {
                ch = pop(&opstack);
                push(&prestack, ch);
            }
            if (opstack.tos != -1 && peek(&opstack) == ')') {
                pop(&opstack); // Pop the ')' from the operator stack
            }
        }
    }

    while (opstack.tos != -1) {
        char ch = pop(&opstack);
        push(&prestack, ch);
    }

    printf("Prefix expression: ");
    for (int i = prestack.tos; i >= 0; i--) {
        printf("%c", prestack.item[i]);
    }
    printf("\n");
}

int main() {
    char infix[MAX];
    printf("Enter the infix expression: ");
    gets(infix);

    infixToPrefix(infix);

    return 0;
}

