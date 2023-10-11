#include<stdio.h>
#include<stdlib.h>

// Structure of a node 
struct Node
{
	int data;
	struct Node *next;
	struct Node *prev;
}*first=NULL;

// Function to create a doubly circular linked list 
void create(int A[],int n)
{
	int i;
	struct Node *t,*last;
	first=(struct Node *)malloc(sizeof(struct Node));
	first->data=A[0];
	first->next=NULL;
	first->prev=NULL;
	last=first;
	
	for(i=1;i<n;i++)
	{
		t=(struct Node*)malloc(sizeof(struct Node));
		t->data=A[i];
		t->next=last->next;
		t->prev=last;
		last->next=t;
		last=t;
	}
	last->next=first;
	first->prev=last;
}

// Function to display the elements in the list 
void Display(struct Node *p)
{
	do
	{
		printf("%d ",p->data);
		p=p->next;
	}while(p!=first);
	printf("\n");
}

// Function to insert a node at the beginning of the list 
void insertAtBeginning(int x)
{
	struct Node *t;
	t=(struct Node *)malloc(sizeof(struct Node));
	t->data=x;
	
	if(first==NULL)
	{
		first=t;
		first->next=first;
		first->prev=first;
	}
	else
	{
		t->next=first;
		first->prev=t;
		first=t;
		first->prev=last;
		last->next=first;
	}
}

// Function to insert a node at the end of the list 
void insertAtEnd(int x)
{
	struct Node *t;
	t=(struct Node *)malloc(sizeof(struct Node));
	t->data=x;
	
	if(first==NULL)
	{
		first=t;
		first->next=first;
		first->prev=first;
	}
	else
	{
		last->next=t;
		t->next=first;
		t->prev=last;
		first->prev=t;
		last=t;
	}
}

// Function to insert a node after a given node 
void insertAtAfter(struct Node *p,int x)
{
	struct Node *t;
	t=(struct Node*)malloc(sizeof(struct Node));
	t->data=x;
	
	if(p->next==first)
	{
		t->next=first;
		p->next=t;
		t->prev=p;
		first->prev=t;
		last=t;
	}
	else
	{
		t->next=p->next;
		t->prev=p;
		p->next->prev=t;
		p->next=t;
	}
}

// Function to delete a node 
void Delete(struct Node *p)
{
	if(p->next==NULL)
	{
		first=NULL;
	}
	else if(p==first)
	{
		first=p->next;
		first->prev=last;
		last->next=first;
		free(p);
	}
	else if(p==last)
	{
		last=p->prev;
		last->next=first;
		first->prev=last;
		free(p);
	}
	else
	{
		p->prev->next=p->next;
		p->next->prev=p->prev;
		free(p);
	}
}

// Function to search an element in the list 
int Search(struct Node *p,int key)
{
	int pos=0;
	do
	{
		if(p->data==key)
		{
			return pos;
		}
		p=p->next;
		pos++;
	}while(p!=first);
	return -1;
}

// Function to save list to a file 
void SaveList(struct Node *p,char *filename)
{
	FiLE *fp;
	fp=fopen(filename,"w");
	if(fp==NULL)
	{
		printf("Error in Opening File\n");
		return;
	}
	
	do
	{
		fprintf(fp,"%d ",p->data);
		p=p->next;
	}while(p!=first);
	fclose(fp);
}

// Function to load list from a file 
void LoadList(struct Node *p,char *filename)
{
	FiLE *fp;
	fp=fopen(filename,"r");
	if(fp==NULL)
	{
		printf("Error in Opening File\n");
		return;
	}
	
	int x;
	while(fscanf(fp,"%d",&x)!=EOF)
	{
		insertAtEnd(x);
	}
	fclose(fp);
close}

int main()
{
	int A[]={10,20,30,40,50};
	create(A,5);
	
	insertAtBeginning(5);
	insertAtEnd(60);
	insertAtAfter(first->next,25);
	
	Delete(first->next);
	
	printf("%d\n",Search(first,30));
	
	SaveList(first,"List.txt");
	
	LoadList(first,"List.txt");
	
	Display(first);
	
	return 0;

}