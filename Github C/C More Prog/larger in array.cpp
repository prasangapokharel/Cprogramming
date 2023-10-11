#include<stdio.h>
#include<conio.h>
int main()
{
	
int i,n,a[90],large;
printf("enter the number till:\n=");
scanf("%d",&n);
for(i=0;i<n;i++)
{	
		printf("enter The Marks of Subject%d:",i+1);
		scanf("%d",&a[i]);		
}	
	large=a[0];
for(i=1;i<n;i++)
{

if(large<a[i])
{
large=a[i];	
}	
	
}	
printf("the larger on is :%d",large);
	
	
}
