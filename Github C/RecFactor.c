//program to calculate factorial of a number
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
long fact(int n){
    if(n==0){
        return 1;
    }
    else
        return n*fact(n-1);
}
int main()
{
    int n;
    printf("Enter a number for factorial: ");
    scanf("%d",&n);
    printf("\nThe factorial of %d is %ld.",n,fact(n));
    return 0;
}