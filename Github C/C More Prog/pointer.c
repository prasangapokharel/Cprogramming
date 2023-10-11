#include<stdio.h>
void main()
{
    int x,y,*ptr;
    x= 10;
    ptr=&x;
    y=*ptr;
     
  
     *ptr=25;
     printf("\n now x= %d\n",x);
     
}
