#include<stdio.h>
#include<conio.h>
void bubblesort(int arr[], int n)
{
	//flag lea agadi ko sort bhai sakeko kura lai bichhai ma xodera hidnea tarika
	int i,j,temp,flag,count=0;
	for(i=0;i<n-1;i++) //controls the number of passes ..how many time to scan
	{
		flag=1;
		//inner loop bhitra ko value 
		for(j=0;j<n-1-i;j++) // controls the number of comparision in each passes ..+ yo ramro form ho 
		// -i le comparision kam garaudai janxa ... so unnecessary compare garnu parena...
		{
			count ++;
			if(arr[j]>arr[j+1]) //ak paxadi ko ximeko .. thik thau ma xa ok else exchange them
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
				flag=0; //surma flag 1 ..if exchange nai kam bhayena sorted bhai sakyo bhanea flag 0 huna paudaina
				
			}
		}
		if(flag==1) //kunai pani exchange bhayena bhanea break hunxa .. means kunai kura sort bhayena 
		{
			break; //i flag is not reset that means list is already sorted 
		}
	
	}
	
		printf("\n Number of comparision %d:",count); // intotal 81 huda aaba tyo flag ko karan 42 wota bhayo ..so usefullll
	
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
// use same count example in each method to find kati bho bhanera
