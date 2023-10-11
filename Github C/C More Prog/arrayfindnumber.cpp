#include<stdio.h>
int main()
{
	int a[5],flag=0,i,key;
	
	for(i=0;i<=4;i++)
	{
		printf("\nEnter Number Inside Matrix %d:",i+1);
		scanf("%d",&a[i]);
		
	}
	printf("enter the key element:");
	scanf("%d",&key);
	for(i=0;i<=5;i++)
	{
	
	if(key==a[i])
	{
		flag=1;
		break;
	}
	else
	
		flag=0;
	
}
	if(flag==1)
	{
		printf("\n%d was found at position %d",key,i+1);
	}
	else{
		printf("ntg found");
	}
	

}
