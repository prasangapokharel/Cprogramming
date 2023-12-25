#include<stdio.h>
#include<conio.h>
void main (){
int a;
printf("Enter a Value ");
scanf("%d",&a);
	a=(a<1) || (a<10); 
	printf("\n (a<1) || (a<10)  is %d", a);
	a=(a>1) || (a>10); 
	printf("\n (a>1)||(a>10) is %d",a);
	
	
	
}
