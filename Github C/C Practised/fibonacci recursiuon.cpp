//fibonacci series
#include<stdio.h>
#include<conio.h>

int fib(int n) //function return nth term 
{
	
	if(n==1)
	{
		return 0;
	}
	if(n==2)
	{
		return 1;
	}
	else
	{
		return fib(n-1)+fib(n-2);
	}
	
}
int main()
{
	
	int n;

	for(int i=1;i<10;i++)
	{
	
	printf("\n%dth term is : %d",i,fib(i));
	}
}
