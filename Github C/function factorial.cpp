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
	if(n==0) 
	return 1;
	else
	return n*(n-1); 
}
