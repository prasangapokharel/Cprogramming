#include<stdio.h>
#include<conio.h>
void main (){
	int n,i,a[20];
	printf("enter number");
	scanf("%d",&n);
	
a[0]=0;
a[1]=1;
for (i=2;i<n;i++)
{
	printf("\n enter element %d : ",i+1);
	scanf("%d",&a[i]);
		a[i]=a[i-1]+a[i-2];
	
}
for (i=0;i<n;i++)
{
	
	
	printf("%d",a[i]);
}

}
