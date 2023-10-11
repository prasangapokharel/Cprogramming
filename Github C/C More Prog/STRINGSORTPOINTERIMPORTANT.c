// WAP to display names of 10 student sorting pointer char + shows pass string pointer using function ++ arraysss 
#include<stdio.h>
#include<string.h>
#include<conio.h>
#define SIZE 5
void display(char**ptr,int n) //string pointer is coming so double star........
{
	int i;
	for(i=0;i<n;i++)
	printf("%s\t",ptr[i]);
}
void sort(char**ptr,int n)
{
	int i,j;
	char *temp;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if(strcmpi(ptr[j],ptr[j+1])>0)
			{
				temp=ptr[j];
				ptr[j]=ptr[j+1];
				ptr[j+1]=temp;
			}
		}
	}
}
int main()
{
	
	char *ptr[SIZE]={"ANUP","MANUP","CHANUP","LANUP","DHANUP"};
	printf("\nBEfore SOrting\n");
	display(ptr,5);
	sort(ptr,5);
	printf("\nAfter SOrting::\n");
	display(ptr,5);
}
