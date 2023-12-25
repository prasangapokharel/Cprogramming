#include<stdio.h>
#include<conio.h>
int main (){
	
	int i,j,m,n,a[5][5];
	printf("enter order ofmatrix...\n");
	scanf("%d%d",&m,&n);
	printf("enter matrix element");
	for(i=0;i<m;i++ )
	
		for(j=0;j<n;j++)
		
		scanf("%d",&a[i][j]);
		
		
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d",a[i][j]);
			printf("\n");
		}
	}
	
	
	
	
	
	
	
}
