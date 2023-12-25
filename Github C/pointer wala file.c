#include<stdio.h>
#include<conio.h>

void main (){
	
	FILE *f;
	int r;
	char name[20];
	f=fopen("student.txt","w");
	printf("enter name");
	scanf("%s",&name);
	printf("enter roll number");
	scanf("%d",&r);
	fprintf(f,"\n%s\t%d",name,r);
	fclose(f);
	
	
	
	
	
	
	
	
	
	
}
