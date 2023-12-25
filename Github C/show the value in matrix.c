#include<stdio.h>
void main (){
	int i,j,n,m,a[2][2],b[2][2];
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
			printf("%d%d",a[i][j],b[i][j]);
			
		}
		printf("\n");
	}
	
	
	
	
	
	
	
	
	
	
}
