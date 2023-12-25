#include<stdio.h>
#include<conio.h>
void main (){
	int i;
char String1[50];
char String2[50];
printf("Enter Strings Below\t\n");
for(i=1;i<2;i++)
{

printf("\n enter first string");
gets(String1);
printf("\nenter second string");
gets(String2);
strcat(String1,String2);
}
for(i=0;i<2;i++)
{

printf("joinsAttring are %s\n",String1);

}
}
