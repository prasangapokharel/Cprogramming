#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int digitSum(int n){
    if(n<10)
        return n;
    else    
        return n%10+digitSum(n/10); 
}
int main()
{
    int n;
    printf("Enter you digit: ");
    scanf("%d",&n);
    printf("\nThe sum of digit %d is %d",n,digitSum(n));
    return 0;
}