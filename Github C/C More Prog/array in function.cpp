#include<stdio.h>
#include<conio.h>
int getmax(int arr[],int);
int main()

{
	int arr[]={1,2,3,5,9,6,10,6,5,4};


	printf("the largest is %d",getmax(arr,10));
}
int getmax(int arr[],int n)
{
	int max,i;
	max=arr[0];
		for(i=1;i<n;i++)
		{
			printf("%d",arr[i]);

		if (arr[i]>max)
		{
			max=arr[i];
		}
		
	}
	return max;
}
