#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
int bubbleSort(int arr[],int n){
    int temp,sorted;
    for (int i = 0; i < n-1; i++) //number of pass
    {
        sorted = 1;
        for (int j = 0; j < n-1-i; j++) // number of comparision in each pass.
        {
            if (arr[j]>arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                sorted = 0;
            }
            
        }
        printf("\nAfter %dth pass: \n",i+1);
        for (int j = 0; j < 10; j++)
        {
           printf("%d\t",arr[j]);
        }
        getch();
        if (sorted == 1)
            break;   
    }
}
int main()
{
    int num[] = {8,67,3,55,76,2,7,9,44,90};
    printf("Befor sorting: \n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d\t",num[i]);
    }
    bubbleSort(num,10);    
    return 0;
}