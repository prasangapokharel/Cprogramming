#include<stdio.h>
#include<conio.h>
int calculate(int a , int b, int *p)
{
	
	*p=a*b;
	return a+b;
}
int main()
{
	
	int m=5,n=6,sum,product;
	sum=calculate(m,n,&product);
	printf("Sum is %d",sum);
	printf("\nProduct is : %d",product);

}
