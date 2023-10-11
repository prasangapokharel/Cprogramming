#include<stdio.h>
int exchange(int*,int*);
int main()
{
	int x,y;
	printf("Enter first number:");
	scanf("%d",&x);
	printf("Ebter Second number:");
	scanf("%d",&y);
	exchange(&x,&y);
	printf("Value after exchange: %d %d",x,y);
	
}
int exchange(int*a,int* b)
{
int temp;
temp=*a;
*a=*b;
*b=temp;
return 0;
}
