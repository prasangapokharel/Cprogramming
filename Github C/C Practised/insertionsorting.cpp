#include<stdio.h>
#include<conio.h>
void insertionSort(int arr[], int n)
{
	int i,j,key;
		for(i=1;i<n;i++)
		{
			key=arr[i]; //copy ith element to key
			for(j=i-1;j>=0 && arr[j]>key;j--)
			{
				arr[j+1]=arr[j]; //move 1 position right so that there will be room for 
				//insertion....
			}
			arr[j+1]=key; //put the key item in the vacent room...
		}
	
	
}
int main(){
	int arr[]={7,4,8,3,9,11,2,8,5,6};
	printf("Before sorting:.........\n");
	for(int i=0;i<10;i++)
	{
		printf("%d ",arr[i]);
	}
	insertionSort(arr,10);
	printf("\n");
	printf("Before sorting:.........\n");
		for( int i=0;i<10;i++)
	{
		printf("%d ",arr[i]);
	}
} 

