#include<stdio.h>
#include<conio.h>
int main()
{
	
int i,n,a[90],small;
printf("enter the number till:\n=");
scanf("%d",&n);
for(i=0;i<n;i++)
{	
		printf("enter The Marks of Subject%d:",i+1);
		scanf("%d",&a[i]);		
}	
	small=a[0];
for(i=1;i<n;i++)
{

if(small>a[i])
{
small=a[i];	
}	
	
}	
printf("the smaller on is :%d",small);
	
	
}
