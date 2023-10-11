/*wap to calculate n th terms of fibonacci series
0,1,1,2,3,5,8,13,21,34,55.......*/
#include<stdio.h>
int fib (int n)
{
         if (n==1)
         return 0;
         else if(n==2)
         return 1;
         else
         return fib (n-2)+fib(n-1);
}
int main()
{
     int n;
     print f ("%d",fib(n));
     return 0;
}