//srevnumber
#include<stdio.h>
#include<conio.h>
#include<math.h>

int digitcount(int n)
{
	int count=0;
	while(n>0)
	{
	
	n=n/10;
	count++;
	
	}
	return count;
}

int sumOfRev(int n)
{
	if(n<10)
	{
		return n;
	}
	else 
	{
		return n%10*pow(10,digitcount(n/10))+sumOfRev(n/10); // digitcount denotes to move fordward
	}
}

int main()
{
	int n;
	printf("\nEnter Number:\n");
	scanf("%d",&n);
	printf("\nThe sum is %d",sumOfRev(n));
	
}

