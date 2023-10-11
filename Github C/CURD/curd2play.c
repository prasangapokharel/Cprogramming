#include <stdio.h> 
#include <conio.h>
#include <stdlib.h> 
#include <string.h> 

struct student 
{ 
	int id; 
	char name[20]; 
	float percentage; 
}; 

void write_student(); //function to write record in file 
void display_all(); //function to display all records 
void search_by_id(); //function to search record using id 
void search_by_name(); //function to search record using name 
void update_record(); //function to update record of file 
void delete_record(); //function to delete record of file 

int main() 
{ 
	int choice; 
	while(1){ 
        printf("\n++==============================================++");
		printf("\n*********Student Record Management System*********\n"); 
		printf("\nChoose one option below :\n"); 
		printf("\n1. Write Student Record in File \n2. Display All Records from File \n3. Search Records by ID \n4. Search Records by Name \n5. Update Records \n6. Delete Records \n7. Exit\n"); 
		printf("\nEnter your choice: "); 
		scanf("%d",&choice); 
		
		switch(choice) 
		{ 
			case 1: 
				write_student(); 
				break; 
			case 2: 
				display_all(); 
				break; 
			case 3: 
				search_by_id(); 
				break; 
			case 4: 
				search_by_name(); 
				break; 
			case 5: 
				update_record(); 
				break; 
			case 6: 
				delete_record(); 
				break; 
			case 7: 
				exit(0); 
				break; 
			default: 
				printf("Please enter valid choice.."); 
		} 
	} 
	return 0; 
} 

// function to write a record in file 
void write_student() 
{ 
	struct student s; 
	FILE *fp; 
	fp = fopen("student.txt","a"); 
	
	printf("\nEnter student id: "); 
	scanf("%d",&s.id); 
    fflush(stdin);
	printf("\nEnter student name: "); 
	// scanf("%s",s.name); 
    gets(s.name);
    fflush(stdin);
	printf("\nEnter student percentage: "); 
	scanf("%f",&s.percentage); 
	
	fwrite(&s,sizeof(s),1,fp); 
	
	fclose(fp); 
	
	printf("\nStudent record saved successfully..!!"); 
    printf("\nPress enter to continue....");
    getch();
	
} 

// display all records from file 
void display_all() 
{ 
	struct student s; 
	FILE *fp; 
    int i=0;
	
	fp = fopen("student.txt","r"); 
	
	if(fp == NULL) 
	{ 
		printf("\n ERROR: Could not open file"); 
		return; 
	} 
	
	printf("\n**************Student Record***************\n"); 
	while(fread(&s, sizeof(s), 1, fp)) 
		printf("\n%d. =>\tID: %d \n\tName: %s \n\tPercentage: %f\n_____________________________________________\n",++i, s.id, s.name, s.percentage); 
	
	fclose(fp); 
    printf("\nPress enter to continue....");
    getch();
} 

// search record using id 
void search_by_id() 
{ 
	struct student s; 
	FILE *fp; 
	int id, flag = 0; 
	
	fp = fopen("student.txt","r"); 
	
	if(fp == NULL) 
	{ 
		printf("\n ERROR: Could not open file"); 
		return; 
	} 
	
	printf("\nEnter student id to search: "); 
	scanf("%d",&id); 
	
	while(fread(&s, sizeof(s), 1, fp)) 
	{ 
		if(id == s.id) 
		{ 
			printf("\nID: %d \nName: %s \nPercentage: %f\n", s.id, s.name, s.percentage); 
			flag = 1; 
			break; 
		} 
	} 
	
	if(flag == 0) 
		printf("\nNo record found with this id..!!"); 
	
	fclose(fp); 
    printf("\nPress enter to continue....");
    getch();
} 

// search record using name 
void search_by_name() 
{ 
	struct student s; 
	FILE *fp; 
	char name[20]; 
	int flag = 0; 
	
	fp = fopen("student.txt","r"); 
	
	if(fp == NULL) 
	{ 
		printf("\n ERROR: Could not open file"); 
		return; 
	} 
	
	printf("\nEnter student name to search: "); 
	scanf("%s",name); 
	
	while(fread(&s, sizeof(s), 1, fp)) 
	{ 
		if(strcmp(name, s.name) == 0) 
		{ 
			printf("\nID: %d \nName: %s \nPercentage: %f\n", s.id, s.name, s.percentage); 
			flag = 1; 
			break; 
		} 
	} 
	
	if(flag == 0) 
		printf("\nNo record found with this name..!!"); 
	
	fclose(fp); 
    printf("\nPress enter to continue....");
    getch();
} 

// update record of file 
void update_record() 
{ 
	struct student s; 
	FILE *fp; 
	int id, flag = 0; 
	
	fp = fopen("student.txt","r+"); 
	
	if(fp == NULL) 
	{ 
		printf("\n ERROR: Could not open file"); 
		return; 
	} 
	
	printf("\nEnter student id to update: "); 
	scanf("%d",&id); 
	
	while(fread(&s, sizeof(s), 1, fp)) 
	{ 
		if(id == s.id) 
		{ 
			printf("\nEnter new name: "); 
			scanf("%s",s.name); 
			printf("\nEnter new percentage: "); 
			scanf("%f",&s.percentage); 
			
			fseek(fp, -sizeof(s), SEEK_CUR); 
			fwrite(&s, sizeof(s), 1, fp); 
			printf("\nRecord updated successfully..!!"); 
			flag = 1; 
			break; 
		} 
	} 
	
	if(flag == 0) 
		printf("\nNo record found with this id..!!"); 
	
	fclose(fp); 
    printf("\nPress enter to continue....");
    getch();
} 

// delete record of file 
void delete_record() 
{ 
	struct student s; 
	FILE *fp, *ft; 
	int id, flag = 0; 
	
	fp = fopen("student.txt","r"); 
	if(fp == NULL) 
	{ 
		printf("\n ERROR: Could not open file"); 
		return; 
	} 
	
	ft = fopen("temp.txt", "w"); 
	
	if(ft == NULL) 
	{ 
		printf("\n ERROR: Could not open file"); 
		fclose(fp); 
		return; 
	} 
	
	printf("\nEnter student id to delete: "); 
	scanf("%d",&id); 
	
	while(fread(&s, sizeof(s), 1, fp)) 
	{ 
		if(id != s.id) 
			fwrite(&s, sizeof(s), 1, ft); 
		else
			flag = 1; 
	} 
	
	fclose(fp); 
	fclose(ft); 
	
	remove("student.txt"); 
	rename("temp.txt","student.txt"); 
	
	if(flag == 1) 
		printf("\nRecord deleted successfully..!!"); 
	else
		printf("\nNo record found with this id..!!"); 

    printf("\nPress enter to continue....");
    getch();
}


