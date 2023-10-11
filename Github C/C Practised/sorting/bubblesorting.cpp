#include<stdio.h>
#include<conio.h>
void bubblesort(int arr[], int n)
{
	int i,j,temp;
	for(i=0;i<n-1;i++) //controls the number of passes ..how many time to scan
	{
		//inner loop bhitra ko value 
		for(j=0;j<n-1;j++) // controls the number of comparision in each passes
		{
			if(arr[j]>arr[j+1]) //ak paxadi ko ximeko .. thik thau ma xa ok else exchange them
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
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
	bubblesort(arr,10);
	printf("\n");
	printf("Before sorting:.........\n");
		for( int i=0;i<10;i++)
	{
		printf("%d ",arr[i]);
	}
} 
// here if all in order then it will waste memory uslesslessly ... we know ak choti ma aauta data ta aafno thau ma janxa.. so this method not truely efficient ....so example 12 is 
// greates value so ak choti sort bhayesi we can igonre it compleytely
//bubble sort also stable sort ...tya aagadi ko 8 aagadi aauxa sort ma paxadi ko paxadiiii........// bubble sort is example of stable sorting
