#include<stdio.h>
#include<conio.h>
int fib(int n)
{
	
		if(n==1)
			return 0;
		else if (n==2)
			return 1;
		else
			return fib(n-2)+fib(n-1);
	
	
	
	
	
}

int main()
{
	int n;
	printf("enter value of n");
	scanf("%d",&n);
	printf("%d",fib(n));
	
	
	
	
}
