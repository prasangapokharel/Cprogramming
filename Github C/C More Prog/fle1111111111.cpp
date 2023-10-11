#include<stdio.h>   // headerfile-1
#include<conio.h>   // headerfile-2
#include<string.h>  //headerfile-3
#define MAX 200     //headderfile-4
struct student {	// this will help defining structure for different datatype for record
int id;
char name[25];
char address[50];
char section[20];
int grade; 	
		
}; //closing syntax of structure

struct student list[MAX];  //declare variable of type struct student as list followed by the size.
int counter=0;// initiallly counter is zero...for identifying either there is record of student before or not
void Registerstudent() //function for registering/taking input of students
{

	{
			printf("\t\t!! Register Port Unlocked !!\t\t\n\n");
			printf("\t\t!! Start From Here Now... !!\t\t\n");
			printf("\n\n1. Enter Name of the student:\n- ");
			scanf("%s",&list[counter].name);
			printf("\n2.Enter Id of the student:\n- ");
			scanf("%d",&list[counter].id);
			printf("\n3.Enter Address of the student:\n- ");
			scanf("%s",&list[counter].address);
			printf("\n4.Enter Section of the student:\n- ");
			scanf("%s",&list[counter].section);
			printf("\n5.Enter of Which Grade/Class You Wanna Register:\n- ");
			scanf("%d",&list[counter].grade);
			printf("\n");
			printf("\t\t!!Data Entered Sucessfull\t\t\n");
			printf("\n\n\n");
			counter++; //after recording 1 data, counter is increased by 1 
			printf("!!Registration saved as well!!");
	}
}

void Displaystudent() //output showing function
{ 
	
	printf("\t->The List Of Student Who Applied For Registration<-/t");
	printf("\n\n\t!!!! RESULT !!!!\n");
	int i;
		for(i=0;i<counter;i++) // counter must be 1 or more to display .. if no data , no counter value ....
		{
		printf("\nThe Name of Student = %s",list[i].name);
		printf("\nThe id of Student = %d",list[i].id);
		printf("\nThe Address of Student = %s",list[i].address);
		printf("\nThe Section of Student = %s",list[i].section);
		printf("\nThe Grade of Student = %d",list[i].grade);
		printf("\n");
		printf("\n");
		}
	
}

 void editstudent() //to update data 
 {
 	
    int id;
    printf(" : Enter the ID of the student to update: ");
    scanf("%d", &id); // asking user to input the id so to change value

    int index = -1; // initializing index variable as -1
    for (int i = 0; i < counter; i++) { // check if counter is more than 1
        if (list[i].id == id) { // if the data in list[i].id is equal to user given id then 
            index = i; // set index as the id 
            break; 
        }
    }

    if (index == -1) {
        printf("Student with ID %d not found.\n", id);
        return;
    }

    struct student editstudent;
	
	printf("\n:Enter the New ID of the student:");
    scanf("%d", &editstudent.id);
    printf("\n1.Enter Name of the student: ");
    scanf("%s", editstudent.name);
    printf("\n2. Enter Address of the student: ");
    scanf("%s", editstudent.address);
    printf("\n3. Enter Section of the student: ");
    scanf("%s", editstudent.section);
    printf("\n4. Enter Grade/Class of the student: ");
    scanf("%d", &editstudent.grade);
	counter++;
    // Update the student record in the list
    list[index] = editstudent; // so here suppose id 1 = list[id] . now after updating the list[1] = editstudent functionedited

    printf("\nData Updated Successfully!\n");
}
	
 	
 
 
 void savestudent() 
 {
 	
 	FILE *fp; // set a pointer as fp
 	fp=fopen("baa","wb"); //open file baa in write mode
 
 	if(fp!=NULL) // if the file is null previously the only
 	{
	 
 		fwrite(list,sizeof(struct student),counter,fp); // write the data from struct student list if counter is more than 0 .
	}	 
 	fclose(fp); //close the file
 	
 }
 
 void readstudent()  //read the data from file
 {
 	
  	FILE *fp; //fp=file pointer
 	fp=fopen("baa","rb"); //open file at read mode
 	if(fp!=NULL) // if no data in file no output ,else
 	{
	 	while(feof(fp)==0) // till the /0 doesnt appear
	 	{
		
 			if(fread(&list[counter],sizeof(struct student),1,fp)==1) //read the data from file pointed by fp 
 			counter++;
 		}
 		
 			
 	}
 
 		fclose(fp); //close
 	
 }
 
 
 void deleteallstudent()
 {
  if (remove("baa") == 0)
  
          printf("\n\n:Data Delete Successfully!\n\n");
      
   else
      {
	  
	  printf("\n:Unable to delete the file");

 		}
 
 void delete1()
 {
 	
 	int id,i,j;
 	printf(" : Enter id:");
 	scanf("%d",&id);
 	for(i=0;i<counter;i++)
 	{
 		if(list[i].id==id) //student found with given id
 		{
 			//delete the record by sifting record remaining by 1 position
 			for(j=i+1;j<counter;j++)
 			{
 				list[j-1]=list[j];///cop[y jth record to its left
			 }
 			counter --;
 			printf("\nRemoved::");
 			return;
		}
		else
		{
			printf("\n Student Record Doesnt Exits With Given Id:");
		}
	 }
 	
 	
 	
 }
 

int main()
{
	
		char choice; //character choice
		readstudent(); // read everything form file just before showing anything
			while(1)
				{
					printf("-> Student Portal From <-\t\t\n");
					printf("1. Register New Students\n2. List Of All Students \n");
					printf("3. Update Student From List\n4. Delete All Student From List\n5. Delete Data\n6. !!!Exit!!!\n\n\n"); 
					choice=getche();
					switch(choice)
					{
						
							case'1': Registerstudent();
							break;
							case '2': Displaystudent();
							break;
							case '3': editstudent();
        					break;
        					case'4': deleteallstudent();
        					break;
							case '5': delete1();
							break;
							case'6':
							printf(". Do You Wanna Exit y/n ?:\n");
							choice=getche();
							if(choice=='Y' ||choice=='y')
						
									{
										savestudent(); //save everything to disk below closing
						    			return 0 ;
									}

									break;
				}
	
}


}


