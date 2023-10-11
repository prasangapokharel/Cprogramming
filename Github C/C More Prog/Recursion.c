//recursion : when a function call itself.
//it is called recursive function call
/*wap to clculate the factorial of a number using recursion.*/
#include<stdio.h>
#include<conio.h>
int fact (int)

int main()
{
     int n,f;
     clrscr();
     printf("enter a number:");
     scanf("%d",&n);
     f=fact(n);
     printf("factorial of %d  is %d ",n,f);
     return 0;
}
int fact (int n)
{
    if (n==0)
       return 1;
       else
       return n*fact (n-1);
}