#include<stdio.h>
#include<conio.h>
int sum(int n)
{
	if(n==0)
	{
		return 0;
	}
	else
	{
		return n+sum(n-1);
	}
}
int main()
{
	int n;
	printf("\nEnter Number:\n");
	scanf("%d",&n);
	printf("\nThe Sum is %d",sum(n));
	
}
