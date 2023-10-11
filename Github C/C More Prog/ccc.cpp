#include<stdio.h>
#define TRUE 1
#define FALSE 0
int num(int);
int main()
{
	int i;
	for(i=0;i<2000;i++)
	{
		if(num(i)==TRUE)
		printf("%d",i);
	}
}
int num(int n)
{
	int a;
	for(a=2;a<n,a++)
	{
		if(n%a==0)
		return FALSE;
	}
	return TRUE;
}
