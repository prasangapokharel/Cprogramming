#include<stdio.h>
#include<conio.h>
void main ()
{
	int a,b,c,ch;
	printf("enter two number ");
	scanf("%d%d", &a,&b);
	printf("1sum");
	printf("2sub");
	printf("3mul");
	printf("4div");
	printf("enter your choise from 1-4");
	scanf("%d",&ch);
	switch(ch)
	{
	case 1 :
	c = a+b ;
	printf("sum of a&b is %d",c);
			
	break ;
		case 2 :
		c=a-b;
		printf("sub of a&b is %d",c);
		
		break ;
			case 3 :
			c=a/b ;
			printf("div of a&b is %d",c);
			
			break ;
			
			case 4 :
			c=a*b ;
			printf("the mul of a&b is %d",c);
			
			break ;
			
			printf("wrong input enter number from 1-4 ");
		}
			
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}

