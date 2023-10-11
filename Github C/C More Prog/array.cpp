#include<stdio.h>
int main()
{
	int temp,i,s1,s2;
	int n, a[5];
	printf("enter number:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	s1=a[0];
	s2=a[0];
	for(i=1;i<n;i++)
	{
		if(s1>a[i])
		{
			s1=a[i];
			
		}
		if(s1>s2)
		{
			temp=s1;
			s1=s2;
			s2=temp;
		}
	}
	for(i=0;i<n;i++)
	{
	
	printf("%d",s2);
}
}
