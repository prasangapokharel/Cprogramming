#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
#define TRUE 1
#define FALSE 0

typedef struct
{
	char item[MAX];
	int tos;	
} stack;

int IsEmpty(stack *sp)
{
	if(sp->tos == -1)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

int IsFull(stack *sp)
{
	if(sp->tos == MAX-1)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

void pop(stack *sp)
{
	if(IsEmpty(sp))
	{
		printf("\nStack Underflow\n");
		exit(0);
	}
	sp->tos--;
}

void push(stack *sp, char ch)
{
	if(IsFull(sp))
	{
		printf("\nStack Is Full\n");
		return;
	}
	sp->item[++sp->tos] = ch;
}

char peek(stack *sp)
{
	if(IsEmpty(sp))
		return '\0';
	else
		return sp->item[sp->tos];
}

int main()
{
	stack s;
	int i, valid = TRUE;
	char exp[MAX];
	s.tos = -1;
	
	printf("\nEnter Your Expression:\n");
	gets(exp);
	
	for(i = 0; i < strlen(exp); i++)
	{
		if(exp[i] == '[' || exp[i] == '{' || exp[i] == '(')
		{
			push(&s, exp[i]);	
		}
		else if(exp[i] == ']' || exp[i] == '}' || exp[i] == ')')
		{
			if(IsEmpty(&s))
			{
				valid = FALSE;
				break;
			}
			else
			{
				char ch = peek(&s);
				pop(&s);
				
				if((ch == '[' && exp[i] != ']') || (ch == '{' && exp[i] != '}') || (ch == '(' && exp[i] != ')'))
				{
					valid = FALSE;
					break;
				}
			}
		}
	}
	
	if(!IsEmpty(&s))
		valid = FALSE;
	
	if(valid == TRUE)
		printf("\nExpression is valid\n");
	else
		printf("\nExpression is invalid\n");
	
	return 0;
}

