#include<stdio.h>
#include<conio.h>
void swap(int *p, int *q) //arubela simple ma huntheyo ya address pass ko karan * aako ho dhanyabad!
{
	int temp=*p;
	*p=*q;
	*q=temp;
}
void heapify(int arr[], int n, int p)
{
	int left=2*p+1,right=2*p+2,max=p;
	if(left<n && arr[left]>arr[max])
	{
		max=left;
	}
	if(right<n && arr[right]>arr[max])
	{
		max=right;
	}
	if(max!=p)
	{
		swap(&arr[p],&arr[max]);
		heapify(arr,n,max);
	}
}

void heapsort(int arr[],int n)
{
	int i;
	for(i= n/2-1;i>=0;i--) //obtain max heap at first...............
	
		heapify(arr,n,i);
	for(i=n-1;i>1;i--)
	{
		swap(&arr[0],&arr[i-1]);// swap root with last item in heap .pass by reference tarikale gareko
		heapify(arr,i-1,0);
	}
	
}
int main()
{
	int arr[]={23,11,32,45,61,6,7,4,11,30};
	int i;
	printf("Before Sorting\n");
	for(i=0;i<10;i++)
	{
		printf("%d ",arr[i]);
		
	}
	heapsort(arr,10);
		printf("\nAfter Sorting\n");
	for(i=0;i<10;i++)
	{
		printf("%d ",arr[i]);
		
	}
}
