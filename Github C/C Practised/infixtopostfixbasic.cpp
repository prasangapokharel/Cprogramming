#include <stdio.h>
#include<ctype.h>
#include <stdlib.h>
#include <string.h>
#include<process.h>
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
    struct stack sp,opstack, poststack;
    opstack.tos = -1;
    poststack.tos = -1;

    printf("\nEnter Valid Data:\n");
    gets(infix);

    for (int i = 0; i < strlen(infix); i++) {
        if (infix[i] == '(') 
		{
			
            push(&opstack, infix[i]);
            
        } 
		
		else if (isalpha(infix[i])) 
		{
			
            push(&poststack, infix[i]);
            
        } 
		
		else if (infix[i] == ')') 
		{
			
            do 
			
			{
                ch = pop(&opstack);
                if (ch != '(')
                    push(&poststack, ch);
            } 
			while (ch != '(');
			
        } 
		
		else if (opstack.tos == -1) 
		{
			
            push(&opstack, infix[i]);
            
        } 
		
		else 
		{
            while (getPrecedence(infix[i]) <= getPrecedence(opstack.item[opstack.tos])) 
			
			{
                ch = pop(&opstack);
                push(&poststack, ch);
                if (opstack.tos == -1)
                    break;
            }
            push(&opstack, infix[i]);
        }
    }

    while (opstack.tos != -1) 
	{
     
	    push(&poststack, pop(&opstack));
    }

    for (int i = 0; i <= poststack.tos; i++) 
	{
    
	    printf("%c", poststack.item[i]);
    }
    
    return 0;
}

