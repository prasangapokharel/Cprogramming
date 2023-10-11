//sumofdigit
#include<stdio.h>
#include<conio.h>

int sumOfDigit(int n)
{
	if(n<10)
	{
		return n;
	}
	else 
	{
		return n%10+sumOfDigit(n/10);
	}
}

int main()
{
	int n;
	printf("\nEnter Number:\n");
	scanf("%d",&n);
	printf("\nThe sum is %d",sumOfDigit(n));
	
}

