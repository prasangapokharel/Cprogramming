#include<stdio.h>
#include<conio.h>
int main()
{
	
int i,n;
int a[19];
printf("enter the number till u wanna show:\n->");
scanf("%d",&n);
		for(i=0;i<=n;i++)
			{
			printf("\nNumber:%d=",i+1);
			scanf("%d",&a[i]);
			
			}	
	for(i=n;i>=0;i--)
	{
		
		printf("Number:%d\t\n",a[i]);
	}
	
	
}
