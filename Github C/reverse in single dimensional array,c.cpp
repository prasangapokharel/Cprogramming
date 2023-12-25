#include<stdio.h>
#include<conio.h>
int main (){
	int n,i,a[20];
	printf("enter number");
	scanf("%d",&n);
	

printf("enter array Elements");
for (i=0;i<n;i++)
{
	printf("\n enter element %d : ",i+1);
	scanf("%d",&a[i]);
	
	
}
for (i=n-1;i>0;i--)
{
	printf("\n  the element %d",a[i]);
}

}
