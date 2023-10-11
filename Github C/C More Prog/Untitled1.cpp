//WAP to input 10 different numbers from keyboard and display them in a alphabetical order.
#include<stdio.h>
#include<string.h>
#define MAX 10
#define SIZE 50
int main()
{
	char name[MAX][SIZE];
	char temp[SIZE];
	
	int i,j;
	for(i=0;i<MAX;i++)
	{
		printf(" Enter name: ",i+1);
		gets(name[i]);
	}
	for (i=0;i<MAX;i++)
	{
		for(j=0;j<MAX-1;j++)
		{
			if(strcmpi(name[j],name[j+1])>0)
			{
				strcpy(temp,name[j]);
				strcpy(name[j],name[j+1]);
				strcpy(name[j+1],temp);
			}
		}
	}
	printf("Names after shorting\n");
	for(i=0;i<MAX;i++)
	printf("%s\n",name[i]);
	return 0;
}

