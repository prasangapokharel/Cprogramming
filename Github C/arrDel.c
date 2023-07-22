//deleting the array element..
#include<stdio.h>
int main()
{
    int arr[10] = {2,5,9,7,6,3,8,4,1,0};
    int pos, a;
    printf("Enter position to delete element:  ");
    scanf("%d",&pos);
    for ( a = pos-1; a < 10; a++)
    {
        arr[a] = arr[a+1];
    }
    for (int i = 0; i < 9; i++)
    {
        printf("%d ",arr[i]);
    }
    
       
    return 0;
}