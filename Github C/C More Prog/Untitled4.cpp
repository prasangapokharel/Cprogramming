#include<stdio.h>
int main()
{
	int printline();
	printline();
	printf("This is a function Program\n");
	printline();
}
int printline()
{
	int i;
	for(i=0;i<40;i++)
	printf("*");
	printf("\n");
	return 0;
}
