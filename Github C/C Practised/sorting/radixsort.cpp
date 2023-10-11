#include<stdio.h>
#include<conio.h>
#define MAX 20
int getDigitCount(int n)
{
	
		int count=0;	
		while(n>0)
	{
		n=n/10;
		count++;
	}
	return count;
}
int getMaxDigitCount(int arr[], int n)
{
	int max=arr[0],i;
	for(int i=1;i<n;i++)
	
		if(max<arr[i])
		max=arr[i];
	
	//max holds highrest number......

	return getDigitCount(max);
}
void countsort(int arr[], int n, int pos)
{
	int temp[MAX];
	int count[10]={0};
	int i;
	for(i=0;i<n;i++)
	{
		count[(arr[i]/pos)%10]++;
	}
	for(i=1;i<10;i++)
	{
		count[i]+=count[i-1];
	}
	for(i=n-1;i>=0;i--)
	{
		temp[--count[(arr[i]/pos)%10]]=arr[i];
	}
	for(i=0;i<n;i++)
	arr[i]=temp[i];
}
void radixsort(int arr[], int n)
{
	int digitCount=getMaxDigitCount(arr,n);
	int i,pos;
	for(i=1,pos=1;i<=digitCount;i++,pos=pos*10)
	{
		countsort(arr,n,pos);
	}
}
int main()
{
	
	int arr[MAX]={43,23,123,245,420,111,12,23,5,78,19,33};
	int i;
	printf("\nBefore Sorting\n");
	for(i=0;i<12;i++)
	{
		printf("%d ",arr[i]);
	}
	radixsort(arr,12);
		printf("\nAfter Sorting\n");
	for(i=0;i<12;i++)
	{
		printf("%d ",arr[i]);
	}
	getch();
}

