#include<stdio.h>

int multiply(int a, int b)
{
	
	if(b>=1)
	{
		return a+multiply(a,b-1);
	}
	else
	return 0;
	
}

int main()
{
	int a,b;
	printf("\nEnter Value of A:\n");
	scanf("%d",&a);
	printf("\nEnter Value of B:\n");
	scanf("%d",&b);
	printf("the multiple of %d*%d=\t%d",a,b,multiply(a,b));
}
