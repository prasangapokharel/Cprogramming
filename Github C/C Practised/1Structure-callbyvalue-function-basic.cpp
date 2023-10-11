#include<stdio.h>
struct student{
	int id;
	char name[20];
	char address[20];
	float mark;
	
};

void print(int id, char name[], char address[], float mark)
{
	printf("%d\t%s\t%s\t%f\t\t",id,name,address,mark);
}
int main()
{
	struct student s1={20,"PRIYANSHU","ITAHARI",20.5};
	print(s1.id,s1.name,s1.address,s1.mark);
}
