#include<stdio.h>
	int prasanga(int n);
	int main(){
	int n; 
	
	printf("enter number:");
	scanf("%d",&n);  
	
	 
	int a;  
	a= prasanga(n); 
	
	
	printf("%d",a);
}



int prasanga(int n) //120
{
	if(n==0) 
	return 1;
	else
	return n*fctorial(n-1); 
}

