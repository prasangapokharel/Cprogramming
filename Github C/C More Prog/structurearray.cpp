//WAP to define a user define data type to store name age and salary of 10 employees, also calculate total amount of salary of the employeers ....
#include<stdio.h>
#include<conio.h>
struct employee// structure defination
{
	char name[100];
	int age;
	float salary;
	
};
int main(){

struct employee a[100]; // structure declaratioon
int i;
for(i=0;i<3;i++)
{
	
printf("\nenter name of the employee %d:",i+1);
scanf("%s",&a[i].name);	
printf("\nenter age of the employee:");
scanf("%f",&a[i].age);	
printf("\nenter salary of the employee:");
scanf("%f",&a[i].salary);	
	
	
}
for(i=0;i<3;i++)
{
	

printf("\n%s\t",a[i].name);	

printf("\n%f\t",a[i].age);	

printf("\n%f\t",a[i].salary);	
	
	
}


}
