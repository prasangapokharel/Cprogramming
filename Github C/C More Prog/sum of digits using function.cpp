// WAP a program to find sum of digits of a number using function.
#include<stdio.h>
int sum(int);
int main()
{
	int n,s;
	printf("Enter your number");
	scanf("%d",&n);
	s=sum(n);
	printf("Sum of digits %d",s);
}
int sum(int n)
{
	int s=0;
	printf("Value of n is: %d\n",n);
	while(n>0)
	{
		s=s+n%10;
		n=n/10;
	}
		printf("Value of n is: %d\n",n);
	return s;
}
