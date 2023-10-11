#include<stdio.h>
#include<conio.h>
#include<string.h>
struct student {	
int id;
char name[25];
char address[50];
char section[20];
int grade; 	
		
};

struct student s[20];
void Registerstudent()
{
	int number,i;
	for(i=1;i<=2;i++)
	{
			printf("\t\t!! Register Port Unlocked !!\t\t\n\n");
			printf("\t\t!! Start From Here Now... !!\t\t\n");
			printf("\n\n1. Enter Name of the student:\n- ");
			scanf("%s",&s[i].name);
			printf("\n2.Enter Id of the student:\n- ");
			scanf("%d",&s[i].id);
			printf("\n3.Enter Address of the student:\n- ");
			scanf("%s",&s[i].address);
			printf("\n4.Enter Section of the student:\n- ");
			scanf("%s",&s[i].section);
			printf("\n5.Enter of Which Grade/Class You Wanna Register:\n- ");
			scanf("%d",&s[i].grade);
			printf("\n");
			printf("\t\t!!Data Entered Sucessfull\t\t\n");
			printf("\n\n\n");
	}
}

void Displaystudent()
{ 
	
	printf("\t->The List Of Student Who Applied For Registration<-/t");
	printf("\n\n\t!!!! RESULT !!!!\n");
	int i;
		for(i=1;i<=2;i++)
	{
		printf("\nThe Name of Student = %s",s[i].name);
		printf("\nThe id of Student = %d",s[i].id);
		printf("\nThe Address of Student = %s",s[i].address);
		printf("\nThe Section of Student = %s",s[i].section);
		printf("\nThe Grade of Student = %d",s[i].grade);
		printf("\n");
		printf("\n");
	}
}

int main()
{
	
		char choice;
			while(1)
				{
					up: printf("-> Student Portal From <-\t\t\n");
					printf("1. Register New Students\n2. List Of All Students \n");
					printf("3. Remove A Student From List\n4. Update Student!!!\n\n"); 
					choice=getche();
					switch(choice)
					{
						
							case'1': Registerstudent();
							break;
							case '2': Displaystudent();
							break;
							case '3':
                			printf("Exiting program. Goodbye!\n");
               				return 0;
               				default:
							printf("Invalid choice. Please try again.\n");
               				break;
					
							printf("Do You Wanna Continue Further y/n ?");
							choice=getche();
							if(choice=='Y' ||choice=='y')
						
									{
						    			goto up;
									}
							else
									{
									printf("Exiting program. Goodbye!\n");
               						return 0;	
									}
				}
	
}

}


