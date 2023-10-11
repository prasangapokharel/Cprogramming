//WAP to display all the prime number between 1 to 2000
#include<stdio.h>
int num(int);
int main()
{
	int i;
	for(i=1;i<=2000;i++)
	{
		if(num(i)==1)
		printf("%d",i);
		
	}
	int num(int n);
	{
		int a;
		for(a=2;a<n;a++)
		{
			if (n%a==0)
			return 0;
		}
		return 1;
	}
}

