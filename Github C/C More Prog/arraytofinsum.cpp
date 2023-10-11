#include<stdio.h>

int main()
{
	
	int i,j,a[3][3],b[3][3],c[3][3];
	for(i=1;i<=3;i++)
	{
		for(j=1;j<=3;j++)
		{
			printf("enter number for the array%d:",i+1);
			scanf("%d",&a[i][j]);
		}
	}
	
		for(i=1;i<=3;i++)
	{
		for(j=1;j<=3;j++)
		{
			printf("enter number for the array%d:",i+1);
			scanf("%d",&b[i][j]);
		}
	}
	
	c[i][j]=a[i][j]+b[i][j];
			for(i=1;i<=3;i++)
	{
		for(j=1;j<=3;j++)
		{
			printf("sum is %d",c[i][j]);
		}
	}
}
