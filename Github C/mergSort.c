#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 10
int merge(int arr[], int lower,int mid,int upper){
    int temp[SIZE];
    int i = lower,j = mid+1,k = lower;
    while (i<=mid&&j<=upper)//until either list finishes
    {
        if (arr[i]<=arr[j])//if element in the first sublist is smaller
        {
            temp[k++] = arr[i++];//copy element from first sublist
        }else
            temp[k++]=arr[j++];//otherwise copy element from second sublist        
    }
    while (i<=mid)//if there is any element in the first sublist 
    {
        temp[k++]=arr[i++];//copy them into the final list 
    }
    while (j<=upper)//if there is any element in the second sublist
    {
        temp[k++]= arr[j++];//copy them into the final list
    }
    for (int i = lower; i <= upper; i++)//copy back all the list into original array
    {
        arr[i] = temp[i];
    }
    
    
    
    
}

int mergeSort(int arr[],int lower, int upper){
    int mid;
    if (lower<upper)//if the list contains more than one element then half the
    {
        mid = (lower+upper)/2;//calculate the middle point if the list
        mergeSort(arr,lower,mid);//apply mergesort to the first half
        mergeSort(arr,mid+1,upper);//apply mergesort to the second half
        merge(arr,lower,mid,upper);//rejoin the sublist to create sorted single
    }
    
}

int main()
{
    int arr[] = {8,12,4,10,9,7,5,2,5,1};
    printf("Before sorting: \n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ",arr[i]);
    }

    mergeSort(arr,0,9);

    printf("\nAfter sorting: \n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ",arr[i]);
    }

    
    return 0;
}