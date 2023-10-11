#include<stdio.h>
int main()
{
	int i,j,space;
	for(i=5;i>=1;i--)
	{
		for(j=1;j<=i;j++)
		{
		if(space<=5)
		{
			
		
			if(j%2==0)
			{
				printf("0");
			}
			
			else
			{
				printf("1");
			}
		}
		else
		{
			printf("");
		}
		printf("\n");
	}
	printf("\n");
}
}
