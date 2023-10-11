#include<stdio.h>
#include<conio.h>
	void quickSort(int arr[], int left, int right) //0 left to 9 right
{
		int pivot=left; //0 index ko lai pivote at first 7
		int down=left,up=right;
		int temp;
		if(left<right)
	{
			
		repeat:	
		while(arr[down]<=arr[pivot] && down<=right)
		{
			down++; 
		}
		while(arr[up]>arr[pivot])
		{
			up--;
		}
		if(down<=up) //exchange down with up & repeat again
		{
			temp=arr[down];
			arr[down]=arr[up];
			arr[up]=temp;
			goto repeat;
		}
		else //exchange pivot with up and partition the list
		{
			temp=arr[pivot];
			arr[pivot]=arr[up];
			arr[up]=temp;
			quickSort(arr,left,up-1); //aply qucik sort to left sub list
			quickSort(arr,up+1,right); //apply quick sort to the right sub list
		}
	}
}
int main(){
	int arr[]={7,4,8,3,9,11,2,8,5,6};
	printf("Before sorting:.........\n");
	for(int i=0;i<10;i++)
	{
		printf("%d ",arr[i]);
	}
	quickSort(arr,0,9); //0 to 9
	printf("\n");
	printf("Before sorting:.........\n");
		for( int i=0;i<10;i++)
	{
		printf("%d ",arr[i]);
	}
} 

