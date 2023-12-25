#include<stdio.h> 
#include<conio.h>
void main (){
	int n,r,c,sum=0,temp; // lets example 153 . now n=153; 1^3+5^3+3^3=153 . so armstrong is like cube of them . so to find answer we shoudld find its reminder . r=n%10 means 10)153( .so reminder will be 3 So first value of three is take from r ; after that c=r*r*r; means 27 . sum=sum+r means 0+27 is 27 . so this process continous until n!>0 ) 
	printf("enter value of n");
	scanf("%d",&n);
	temp=n;
	while (n>0)
{

r=n%10;
	c=r*r*r;
	sum=sum+c;

n=n/10;	
	
	
	
}
n=temp;
	if (n==sum)
	
	{
	printf("armstrong number");
	}
	
	else 
	{
	printf("Not");
	}
	
		
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}
