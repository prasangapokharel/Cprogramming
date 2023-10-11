#include<stdio.h>
#include<conio.h>	
struct student // structure defination
{
char name[50];
char street[100];
char city[50];
char state[20];
int pin;
};
int main(){

	struct student s;//structure variable decleration
	printf("%d",sizeof(struct student));
	printf("\nenter your name:");
	scanf("%s",&s.name);//scanf("%f^\nls",s.name) or gets(s.name) .... for full name 
	printf("\nenter street :");
	scanf("%s",&s.street);
	printf("\nEnter city :");
	scanf("%s",&s.city);
	printf("\nEnter State:");
	scanf("%s",s.state);
	printf("\nEnter Pin:");
	scanf("%d",&s.pin);
	printf("\nYour Name is:%s\n Your Stree is :%s\n Your City is :%s\nYour State Is :%s\nYour PIn is :%d\n",s.name,s.street,s.city,s.state,s.pin);
	// here s.name . is operator and field name work as ordinary variable ......variablename.fieldname
	
	
	
	
}

