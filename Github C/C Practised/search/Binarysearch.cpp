#include<stdio.h>
#include<conio.h>
/*int linearsearch(int arr[], int n , int key)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(arr[i]==key)
		
			return i; //found at ith index 
	}
			return -1;//not found & return with -1 value...
	
}
*/
int binarysearch(int arr[], int low, int high, int key)
{
	int mid;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(arr[mid]==key)
		{
			return mid;
		}
		else if(arr[mid]>key)
		{
			high=mid-1;
		}
		else
		{
			low=mid+1;
		}
	}
 return -1; //not found ....................................
}

int main()
{
	int arr[]={1,3,4,9,15,16,17,20,22,41};
	int key,found;
	printf("Enter Number to be search: ");
	scanf("%d",&key);
//	found=linearsearch(arr,10,key);
	found=binarysearch(arr,0,9,key);
	if(found==-1)
	{
		printf("%d does not exit....",key);
	}
	else
	printf("%d exist at position %d",key,found+1);
}
