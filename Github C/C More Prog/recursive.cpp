#include<stdio.h>
#include<conio.h>
int fact (int);
int main()
{
	
	int n,f;
	printf("enter a number:");
	scanf("%d",&n);
	f=fact(n);
	printf("factorial of %d is %d",n,f);
}
int fact(int n)
{
	
	if(n==0)
	{
		return 1;
	}
	else 
	{
		return n*fact(n-1);
	}
	
}

