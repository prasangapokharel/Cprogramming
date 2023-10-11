#include<stdio.h>
int main()
{
	
	int n;
	int mul=1;
	printf("\nEnter num:\n");
	scanf("%d",&n);

	for(int i=1;i<=n;i++)
	{
		mul=mul*i;
	}
	printf("%d",mul);
}
