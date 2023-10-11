#include<stdio.h>
#include<conio.h>
#define MAX 10
#define HIGHEST 13

int getHighest(int arr[], int n)
{
	int max=arr[0],i;
	for(i=1;i<n;i++)
	{
		if(max<arr[i])
		
			max=arr[i];
	}
		return max;
}
void countSort(int arr[] , int n)
{
	int temp[MAX];
	int count[HIGHEST]={0};
	int max=getHighest(arr,n);
	int i;
	for(i=0;i<n;i++)//count each item in the array & update its count in count array
	{
		count[arr[i]]++;
	}
	for(i=1;i<=max;i++)
	{
		count[i]+=count[i-1];
	}
	for(i=n-1;i>=0;i--)
	{
		temp[count[arr[i]]-1]=arr[i];
		count[arr[i]]--;
	}
	for(i=0;i<n;i++) //copy back to array original
	{
		arr[i]=temp[i];
	}
}
int main(){
	int arr[MAX]={12,9,5,2,1,2,5,7,11,4};
	int i;
	printf("\nBefore Sorting");
	for(i=0;i<MAX;i++)
	{
		printf("\n%d ",arr[i]);
	}
	countSort(arr,MAX);
		printf("\nAfter Sorting");
	for(i=0;i<MAX;i++)
	{
		printf("\n%d ",arr[i]);
	}
}
