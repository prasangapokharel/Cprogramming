#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<process.h>
void shellSort(int arr[], int n)
{
	int gap,i,j,temp;
	for(gap=n/2;gap>=0;gap=gap/2) //repeatedly apply insertion sort with vary number of gaps
	{
		for(i=gap;i<n;i++)
		{
			temp=arr[i];
			for(j=i-gap;j>=0 && arr[j]>temp;j=j-gap)
			{
			
				arr[j+gap]=arr[j];
		}
			arr[j+gap]=temp;
		}
	}
}
int main()
{
	int arr[]={7,4,8,10,16,6,11,3,1,2};
	system("cls");
	printf("\nBEfore .........");
	for(int i=0;i<10;i++) //to find num of element in arrat
		printf("%d ",arr[i]);
	shellSort(arr,10);
	printf("\n");
		printf("\nAfter ASorting.........");
	for(int i=0;i<10;i++) //to find num of element in arrat
		printf("%d ",arr[i]);
	getch();	
}
