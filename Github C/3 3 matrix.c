#include<stdio.h>
void main (){
	int i,j,n,m,a[3][3],b[3][3],c[3][3];
	printf("enter order of marrix: \n");
	scanf("%d%d",&m,&n);
	printf("enter Elements: ");
	
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	for(i=0;i<m;i++)
	{
		
		for(j=0;j<n;j++)
		{
			scanf("%d",&b[i][j]);
		}
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
			printf("%d",c[i][j]);
			
		}
		printf("\n");
	}
	
	
	
	
	
	
	
	
	
	
}
