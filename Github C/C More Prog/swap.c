#include <stdio.h>
int reverse(int);
int main()
{
    int n,r;
    printf("enter a number  :");
    scanf("%d",&n);
    r=reverse(n);
    if (r==n)
         printf("It is palindrome");
        
    else 
         printf("It is not palindrome");
         return 0;
} 
int reverse (int n)
{
       int r=0;
       while (n>0)
       {
        r=r*10+n%10;
        n=n/10;

       }
       return r;
       }