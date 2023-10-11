#include<stdio.h>
void add(add);
void main()
{
    add();
 
}
 void add()
 {
    int X,Y;

    printf("Enter two numbers :");
    scanf("%d%d",&X,&Y);
    printf("sum=%d",X+Y);
   return;
}
