#include<stdio.h>

int fun(int *ptr1, int *ptr2) // the address of x , y will get stored in the pointer *ptr1 and *ptr2 .. 
// if we only use ptr1 and ptr2 , they wont be capable to hold the address .. so *ptr1 & *ptr2 required
{
	
	*ptr1=20; // ptr1 = 1000 and the *ptr1 = the value of address in ptr
	*ptr2=10; 
		
	
}
int main()
{
	int x=10;
	int y=20;
	printf("\nThe  Value Before x:%d & y=%d",x,y);
	fun(&x , &y); // here the address of x and y will get passed to the function .
	printf("\nThe  Value Afterx:%d & y=%d",x,y);
}
