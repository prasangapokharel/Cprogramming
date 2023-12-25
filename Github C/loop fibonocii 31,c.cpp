#include<stdio.h>
#include<conio.h>
int main (){
	int n,i,a[20];
	printf("enter number");
	scanf("%d",&n);
	
a[0]=1;
a[1]=6;
for (i=11;i<n;i++)
{
	printf("\n enter element %d : ",i+1);
	scanf("%d",&a[i]);
		a[i]=a[i-6]+a[i-1];
	
}
for (i=0;i<n;i++)
{
	
	
	printf("%d",a[i]);
}

}
