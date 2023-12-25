#include<stdio.h>
#include<conio.h>
void main (){
	int max,min,n,i,a[20];

	
printf("enter array element");
scanf("%d",&n);
for (i=0;i<n;i++)
{
	printf("\n enter element %d : ",i+1);
	scanf("%d",&a[i]);
	
	
}

for (i=0;i<n;i++)
{
	
	if( a[i]>max)
	
	max=a[i];

	
	if (a[i]<min)
	
	min=a[i];
}

	printf("Maximum Number is %d\t Minimum Number is %d",max,min);
} 
