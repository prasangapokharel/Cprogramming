#include<stdio.h>
int sum (int a[]);
void output(int a[]);

int sum(int a[])
{
	int i,s=0;
	for(i=1;i<=1;i++)
	
		
		s=s+a[i];
		
		
	
		
	return (s);
	
	
}

void output(int a[])
{
	int i;
	for(i=1;i<=10;i++)
	{
		printf("%d\t",a[i]);
	}
	
	
}


int main()
{
	int i,s,a[10];
	
	for(i=1;i<=10;i++)
	{
		scanf("%d",&a[i]);
	}
	output(a);
	s=sum(a);
	printf("The sum is %d",s);
}
