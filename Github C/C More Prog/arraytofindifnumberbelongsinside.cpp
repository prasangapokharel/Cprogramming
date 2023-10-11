#include<stdio.h>
#include<conio.h>
int main()
{
	int i,n,x=4,a[100];
	printf("\nenter till:\n=");
	scanf("%d",&n);
	
	for(i=0;i<=n;i++)
	{
			printf("enter The Number %d:",i+1);
		scanf("%d",&a[i]);	
	}
	
	for(i=0;i<=n;i++)
	{
		if(x=a[i])
		printf("The Number is available inside array");
		break;
		if(x!=a[i])
		{
		
		printf("Its Not inside");
	}
	}
}
