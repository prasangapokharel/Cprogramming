#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 100

struct student{
	
	int id;
	char name[20];
	char address[20];
};
struct student s[MAX];
int counter=0;

void registerstudent()
{
	
printf("\n!!!!WELCOME TO PORTAL!!!!\n");
printf("\nEnter Id :\n");
scanf("%d",&s[counter].id);
printf("\nEnter Name :\n");
scanf("%s",&s[counter].name);
printf("\nEnter Address :\n");
scanf("%s",&s[counter].address);
counter ++;
}

void displaystudent()
{

printf("\t->The List Of Student Who Applied For Registration<-/t");
    printf("\n\n\t!!!! RESULT !!!!\n");
    int i;
    for (i = 0; i < counter; i++) {
        printf("\nThe Id of Student = %d", s[i].id);
        printf("\nThe Namme of Student = %s", s[i].name);
        printf("\nThe Address of Student = %s", s[i].address);
        printf("\n");
        printf("\n");

}
}
int main() {
    char choice;
  

    while (1) {
        printf("-> Student Portal From <-\t\t\n");
        printf("1. Register New Students\n2. List Of All Students \n3.Exit\n");
        printf("\n");
        choice = getche();
        switch (choice) {
        case '1':
            registerstudent();
            break;
        case '2':
            displaystudent();
            break;
        case '3':
            printf(". Do You Wanna Exit y/n ?:\n");
            choice = getche();
            if (choice == 'Y' || choice == 'y')
            return 0;
            break;
        }
    }
}

