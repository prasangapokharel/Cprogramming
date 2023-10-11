#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node
{
	int data;
	struct node* next;
};

struct node* header = NULL;

struct node* getnode(int n)
{
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	if (newnode == NULL)
	{
		printf("\nMemory Allocation Failed.");
		exit(1);
	}
	newnode->data = n;
	newnode->next = NULL;
	return newnode;
}

void insertAtLast()
{
	int n;
	struct node* ptrnew, * ptrthis;
	printf("\nEnter A Number: ");
	scanf("%d", &n);
	ptrnew = getnode(n);
	if (header == NULL)
	{
		header = ptrnew;
	}
	else
	{
		for (ptrthis = header; ptrthis->next != NULL; ptrthis = ptrthis->next) {}
		ptrthis->next = ptrnew;
	}
	printf("\nNode Inserted At End");
}

void insertAfter()
{
	int n, target;
	struct node* ptrnew, * ptrthis;

	printf("\nEnter Number After Which you want to insert: ");
	scanf("%d", &target);

	for (ptrthis = header; ptrthis != NULL; ptrthis = ptrthis->next)
	{
		if (ptrthis->data == target)
		{
			printf("\nEnter Data to Insert in the Middle: ");
			scanf("%d", &n);
			ptrnew = getnode(n);
			ptrnew->next = ptrthis->next;
			ptrthis->next = ptrnew;
			printf("\nNode Inserted After %d", target);
			return;
		}
	}

	printf("\nTarget Node Not Found");
}

void insertBefore()
{
	int n, target;
	struct node* ptrnew, * ptrthis, * ptrback;

	printf("\nEnter Number Before Which you want to insert: ");
	scanf("%d", &target);

	for (ptrthis = ptrback = header; ptrthis != NULL; ptrthis = ptrthis->next)
	{
		if (ptrthis->data == target)
		{
			printf("\nEnter Data to Insert in the Middle: ");
			scanf("%d", &n);
			ptrnew = getnode(n);

			if (ptrthis == header)
			{
				ptrnew->next = header;
				header = ptrnew;
			}
			else
			{
				ptrnew->next = ptrthis;
				ptrback->next = ptrnew;
			}

			printf("\nNode Inserted before %d", target);
			return;
		}
		ptrback = ptrthis;
	}

	printf("\nTarget Node Not Found");
}

void insertAtFront()
{
	int n;
	struct node* ptrnew;
	printf("\nEnter A Number: ");
	scanf("%d", &n);
	ptrnew = getnode(n);
	ptrnew->next = header;
	header = ptrnew;

	printf("\nNode Inserted At Front");
}

void removeFromFront()
{
	struct node* ptrthis;
	if (header == NULL)
	{
		printf("\nEmpty List");
	}
	else
	{
		ptrthis = header;
		header = header->next;
		free(ptrthis);
		printf("\nNode Removed From Front");
	}
}

void removeFromLast()
{
	struct node* ptrthis, * ptrback;

	if (header == NULL)
	{
		printf("\nList Empty");
	}
	else
	{
		for (ptrthis = ptrback = header; ptrthis->next != NULL; ptrthis = ptrthis->next)
		
			ptrback = ptrthis;
		

		if (ptrthis == header)
		{
			header = NULL;
		}
		else
		{
			ptrback->next = NULL;
			free(ptrthis);
			printf("\nRemoved From Last");
		}
	}
}

void removeAny()
{
	int target;
	struct node* ptrthis, * ptrback;

	printf("\nEnter the element you want to remove: ");
	scanf("%d", &target);

	if (header == NULL)
	{
		printf("\nList Is Empty");
		return;
	}

	ptrback = NULL;
	ptrthis = header;
	while (ptrthis != NULL)
	{
		if (ptrthis->data == target)
		{
			if (ptrback == NULL)
			{
				header = ptrthis->next;
			}
			else
			{
				ptrback->next = ptrthis->next;
			}
			free(ptrthis);
			printf("\nNode with value %d removed", target);
			return;
		}
		ptrback = ptrthis;
		ptrthis = ptrthis->next;
	}

	printf("\nTarget Node Not Found");
}

void display()
{
	struct node* ptrthis;
	if (header == NULL)
	{
		printf("\nEMPTY");
	}
	else
	{
		for (ptrthis = header; ptrthis != NULL; ptrthis = ptrthis->next)
		{
			printf("%d\t", ptrthis->data);
		}
	}
}

int main()
{
	char ch;
	while (1)
	{
		system("cls");
		printf("\nSELECT OPTION\n1.Insert\n2.RemoveFromFront\n3.List\n4.insertAtFront\n5.InsertAfter");
		printf("\n6.insertBefore\n7.RemoveFromlast\n8.RemoveAny\n9.Exit\n\n");
		ch = getche();
		switch (ch)
		{
		case '1':
			insertAtLast();
			break;
		case '2':
			removeFromFront();
			break;
		case '3':
			printf("\n");
			display();
			break;
		case '4':
			insertAtFront();
			break;
		case '5':
			insertAfter();
			break;
		case '6':
			insertBefore();
			break;
		case '7':
			removeFromLast();
			break;
		case '8':
			removeAny();
			break;
		case '9':
			return 0;
		default:
			printf("\nInvalid Option");
			break;
		}
		getch();
	}
}

