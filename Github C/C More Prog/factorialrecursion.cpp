#include<stdio.h>
int main()
{
	int n,i;
	int facto=1;
	printf("\nEnter The Value Of N:\n");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	
	{
		facto=facto*i;
		return facto;
		
	}
	
	printf("\n%d",facto);	
	
	}

