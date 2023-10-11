#include<stdio.h>
#include<conio.h>
int main()
{
	
int i,n,a[90],large=0;
printf("enter the number till:\n=");
scanf("%d",&n);
for(i=0;i<=n;i++)
{
	
printf("enter the numbers %d:",i+1);
scanf("%d",a[i]);	
	
	
}	
	
for(i=0;i<=n;i++)
{

if(large<a[i])
{
large=a[i];	
}	
	
}	
printf("the larger on is %d:",large);
	
	
}
