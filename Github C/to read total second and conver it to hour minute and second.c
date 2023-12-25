#include<stdio.h>
#include<conio.h>
void main(){
	int h,m,s;
	printf("enter total second");
	scanf("%d",&s);
	h=s/3600;
	s=s%3600;
	m=s/60;
	s=s%60;
	
	printf(" hour=%d minute=%d second=%d  ",h,m,s);	
	
	
	
	
	
	
	
	
	
}
