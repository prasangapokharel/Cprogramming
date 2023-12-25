#include<stdio.h>
#include<conio.h>
void main (){
char name[20];
int i,n;
int roll ;
float marks;
float percentage;
FILE *fp;
fp=fopen("student.dat","a");
printf("How many Records You wanna enter bitch");
scanf("%d",&n);
for(i=0;i<n;i++)
{
	printf("\t\n enter Name Of The Students");
	scanf("%s",&name);
	printf("\n");
	printf("enter The Roll Number Of The Students");
	scanf("%d",&roll);
	printf("\n");
	printf("\n Enter Marks Of The Students");
	scanf("%f",&marks);
	printf("\n enter Percentage Of The Students");
	scanf("%f",&percentage);
	
}
	fprintf(fp,"\n%s\n\n%d\n\n%f\n\n%f",name,roll,marks,percentage);
	
fclose(fp); 
getch();
}
