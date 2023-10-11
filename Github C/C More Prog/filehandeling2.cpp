//WAP to find/calulate the sum of numbers stored on data file named "ram.txt"
#include<stdio.h>
int main()
{
	FILE *ptr;//file pointer
	int n,sum=0; 
	ptr=fopen("ram.txt","r"); //open file for reading mode

	if(ptr==NULL) //if problem 
	{
		printf("file couldnt be opened");
	}
	else
	{
		while(feof(ptr)==0) // feof(ptr) value xa then 1 so 1==0 no so left
		{
		
		fscanf(ptr,"%d\n",&n); //read one number at a time..........or if(fcanf(ptr,"%d\n",&n)==1)
		//printf("%d\n",n);
		sum=sum+n;
	}
	printf("%d\n",sum);

}
	fclose(ptr); //close the file......
}
