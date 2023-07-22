//WPA to find HCF of two input numbers using recurstion.
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int hcf(int num1, int num2){
    if (num1%num2==0)
    {
        return num2;
    }
    else
        return hcf(num2,num1%num2);
    
}
int main()
{
    int n1,n2;
    printf("Enter 2 number: ");
    scanf("%d %d",&n1,&n2);
    printf("HCF = %d",hcf(n1,n2));
    return 0;
}