 #include<stdio.h>
#include<conio.h>
#include<process.h>
#include<stdlib.h>
#define MAX 100

int stack[100],x,i,choice=0,n,top=-1;
void push();
void pop();
void Display();

int main(){
	
	printf("\n!!!!PUASH POP DISPLAY!!!\n");
	printf("\nEnter Number Of Element in stack:\n");
	scanf("%d",&n);
	printf("\n--------------------------------------\n");
	while(choice!=4)
	{
			printf("\nChoice one from below Option\n");
			printf("\n1.Push\n2.Pop\n3.Show\n4.Exit");
			printf("\nEnter Choice:\n");
			scanf("%d",&choice);
			
			switch(choice)
			{
				case 1: push();break;
				
				case 2: pop();break;
				
				case3 :Display();break;
				
				case 4: printf("\nexiting Program\n");	break;
				
				default:
					printf("\nPlease Enter Valid Choice:\n");
			}
	};
}

void push()
{
	int val;
	if(top==n)
	printf("\nOverflow");
	else
	printf("\nEnter Value:\n");
	scanf("%d",&val);
	top=top+1;
	stack[top]=val;
}

void pop()
{
	if(top==-1)
	printf("\nUnderflow\n");
	else
	x=stack[top];
	top=top-1;	
	printf("\n%d Item is poped Out\n",x);
}

void Display()
{
	for(i=top;i>=0;i--)
	{
		printf("%d\n",stack[i]);
	}
	if(top==-1)
	{
		printf("\nStack Is Empty\n");
	}
}
