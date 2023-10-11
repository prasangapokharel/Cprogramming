#include<stdio.h>
#include<conio.h>

int hcf(int a, int b)
{
	if (a%b==0)
		return b;
	else
		return hcf(b,a%b);	
	
}
int main()
{
	int a,b;
	printf("\nEnter Value of A:\n");
	scanf("%d",&a);
	printf("\nEnter Value of B:\n");
	scanf("%d",&b);
	printf("\nNum in hcf of %d,%d is %d",a,b,hcf(a,b));
}
