#include<stdio.h>
#include<conio.h>
void main (){
	int positive,negetive,n,i,a[20];

	
printf("enter array element");
scanf("%d",&n);
for (i=0;i<n;i++)
{
	printf("\n enter element %d : ",i+1);
	scanf("%d",&a[i]);
	
	
}

for (i=0;i<n;i++)
{
	
	if( a[i]>0)
	

	positive=a[i];
 if (a[i]>0)
 {
 
 printf(" positive is %d:",a[i]);
}
if (a[i]<0)
{

printf("\n Negetive is %d",a[i]);
}
}
}
