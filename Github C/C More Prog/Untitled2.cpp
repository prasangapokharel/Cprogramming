//WAP a program to calculate the sum of two numbers using function
#include<stdio.h>
int add(int);
int main()
{
	add();
	getch();
}
int add()
{
	int x,y;
	printf("Enter a numbers:");
	scanf("%d%d",&x,&y);
	printf("sum=%d",x+y);
return 0;	
}
