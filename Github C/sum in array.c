#include<stdio.h>
#include<conio.h>
void main (){
	
	int n,i,a[20];
	printf("enter number");
	scanf("%d",&n);
	printf("\n enter the array element ");
	
	for (i=0;i<=n;i++)
	{
	printf("\nenter number here %d :",i+1);
	scanf("%d",&a[i]);
	}
	
for(i=n-1;i>=0;i--)

{
	printf("%d",a[i]);
}	
	
	
	
	
	
	
	
	
	
	
	
}
