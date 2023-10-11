#include<stdio.h>
#include<conio.h>
#define m 3
#define n 3
int main()
{
	int i,j,a[m][n],b[m][n],c[m][n];
	printf("enter element of first matrix:\n");
	for(i=0;i<m;i++)
	{
			for(j=0;j<n;j++)
			{
					scanf("%d",&a[i][j]);
			}
			
	}
	printf("\n The First MAtrix is:\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
				printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
		printf("enter element of second matrix:\t");
	for(i=0;i<m;i++)
	{
			for(j=0;j<n;j++)
			{
					scanf("%d",&b[i][j]);
			}
			
	}
	printf("\n The Second MAtrix is:\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
				printf("%d\t",b[i][j]);
		}
		printf("\n");
	}
	
		for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			c[i][j]=a[i][j]+b[i][j];
		}
	
	}
	
			for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d\t",c[i][j]);
		}
	printf("\n");
	}
	
}
