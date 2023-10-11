//WAP To Store 10 Numbers into data file named "ram.txt"
#include<stdio.h>
int main()
{
	FILE *ptr;//file pointer
	int i; 
	ptr=fopen("ram.txt","w"); //which file we are opening and on which mode we are using.moreover write mode delete prev file else it create blank file
	//sometimes file gets locked ....or pc dont have storage ... we coud use absolute C:/database/ram.txt
	if(ptr==NULL) //if problem 
	{
		printf("file couldnt be opened");
	}
	else
	{
		
		for(i=1;i<=3;i++)
			fprintf(ptr,"%d\n",i); //write number .....
		
		fclose(ptr);//closefile	
		printf("Data saved....");	
	}
	
}
