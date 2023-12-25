#include<stdio.h>
#include<conio.h>
void main (){
	int sum=0,n,i,a[20];
	printf("enter number");
	scanf("%d",&n);
	
printf("enter array element");

for (i=0;i<=n;i++)
{
	printf("\n enter element %d : ",i+1);
	scanf("%d",&a[i]);
	
	
}
for (i=0;i<=n;i++)
{
	
	sum=sum+a[i];

	
	
	

}
	printf("the sum of given array  is %d",sum);
}
