#include<stdio.h>
int main()
{
	
	int i,j,a[2][2],b[2][2];
	for(i=1;i<=2;i++)
	{
		for(j=1;j<=2;j++)
		{
			printf("\enter first array values:");
			scanf("%d",&a[i][j]);
		}
	}
		for(i=1;i<=2;i++)
	{
		for(j=1;j<=2;j++)
		{
				printf("\enter second array values:");
			scanf("%d",&b[i][j]);
		}
	}
			for(i=1;i<=2;i++)
	{
		for(j=1;j<=2;j++)
		{
		
			printf("%d\t",a[i][j]);
			printf("\n");
	 }
		
	}
			for(i=1;i<=2;i++)
	{
		for(j=1;j<=2;j++)
		{
		
			printf("%d\t",b[i][j]);
				printf("\n");
		}
	
	}
		
		
	
}
