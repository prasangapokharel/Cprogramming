#include<stdio.h>
	int prasanga(int n);
	int main(){
	int n; 
	
	printf("enter number:");
	scanf("%d",&n);  
	 
	
	printf("%d",prasanga(n));
}



 prasanga(int n) //120
{
	if(n==1) 
	return 1;
	else if
	if(n==0)
	return 0;
	else
	return n+prasanga(n-1); 
}


