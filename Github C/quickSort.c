#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void exchange(int *p,int*q)
{
  int temp=*p;
  *p=*q;
  *q=temp;
}
int partition(int arr[],int lower,int upper)
{
   int pivot=lower;
   int down=lower;
   int up=upper;
   while(down<up)
   {
      while(arr[down]<=arr[pivot]&&down<=upper)down++;
      while(arr[up]>arr[pivot])up--;
      if(down<up)
	    exchange(&arr[down],&arr[up]);
   }
   exchange(&arr[pivot],&arr[up]);
   return up;
}
void quicksort(int arr[],int lower,int upper)
{
   int pos;
   if(lower<upper)//if there are at least two elements in the list
   {
      pos=partition(arr,lower,upper);
      quicksort(arr,lower,pos-1);
      quicksort(arr,pos+1,upper);
   }
}

int main()
{
    int arr[] = {8,10,5,12,14,5,7,13};
    printf("\nBefore sorting: \n");
    for (int i = 0; i < 8; i++)
    {
        printf("%d ",arr[i]);
    }
    quicksort(arr,0,7);
    printf("\nAfter sorting: \n");
    for (int i = 0; i < 8; i++)
    {
        printf("%d ",arr[i]);
    }
    
    return 0;
}