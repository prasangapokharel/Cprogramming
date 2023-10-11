#include<stdio.h>
int main()
{
	int i,n,a[10];
	printf("enter total subject mark to store:");
	scanf("%d",&n);
	
	for(i=0;i<=n;i++)
	{
		printf("enter number%d:",i+1);
		scanf("%d",&a[i]);
	}
	
	for(i=0;i<=n;i++)
	{
		printf("  \n:%d\n",a[i]);
		
	}


}
