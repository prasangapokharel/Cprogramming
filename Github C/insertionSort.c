#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int insertionSort(int arr[],int n){
    int j,key;
    for (int i = 1; i < n; i++)
    {
        key = arr[i];
        j = i-1;
        while (j>=0&&key<arr[j])
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;        
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

    insertionSort(arr,10);

    printf("\nAfter sorting: \n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ",arr[i]);
    }

    
    return 0;
}