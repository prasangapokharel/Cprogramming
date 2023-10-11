#include<stdio.h>
#include<conio.h>
int main()
{
	
	int i,n,a[100],sum=0,av=0;
	printf("\nenter the number:\n=");
	scanf("%d",&n);
	
	for(i=0;i<=n;i++)
	{
		printf("enter The Marks of Subject%d:",i+1);
		scanf("%d",&a[i]);
	}
	for(i=0;i<=n;i++)
	{
		sum=sum+a[i];
		
	}
	av=sum/n;
	printf("the sum is %d:",sum);
	printf("the average is %d",av);
	
	
	
	
	
	
}
