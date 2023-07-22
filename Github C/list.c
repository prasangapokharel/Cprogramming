#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 10
typedef struct{
    char name[50];
    int roll;
    char grade[30];
}student;
typedef struct 
{
    int rear;
    student std[MAX];
}list;

int addStudent(list*);  //insertAtLast, insertAtFirst, insertBefore, insertAfter
int removeStudent(list*); //removeAtLast, removeAtFirst
int listStudent(list*);    // sortedByName, sortedByRoll
int updateStudent(list*);

int main()
{
    list slist;
    char ch;
    slist.rear = -1;
    do
    {
        printf("\n1. Insert\n2. Remove\n3. Update\n4. List\n5. Exit");
        printf("\nEnter option: ");
        ch = getche();
        switch (ch)
        {
        case '1':
            addStudent(&slist);
            break;
        case '2':
            removeStudent(&slist);
            break;
        case '3':
            updateStudent(&slist);
            break;
        case '4':
            listStudent(&slist);
            break;
        case '5':
            return 0;
            break;
        
        default:
        printf("\nEnter valid option.........");
            break;
        }
    } while (1);
    
    return 0;
}

int addStudent(list *ls){
    student st;
    if (ls->rear == MAX-1)
    {
        printf("\nThe List is full");
    }
    else{
        printf("\nEnter student detail: \n");
        fflush(stdin);
        printf("Name: ");
        gets(st.name);
        printf("Roll no: ");
        scanf("%d",&st.roll);
        fflush(stdin);
        printf("Grade: ");
        gets(st.grade);
        ls->rear++;
        ls->std[ls->rear]=st;
        printf("\nStudent Added...");
    }
    return 0;
};

int removeStudent(list *ls){
    int roll, found = 0;
    printf("\nEnter roll no. of student to be removed: ");
    scanf("%d",&roll);
    for (int i = 0; i <= ls->rear; i++)
    {
        if (found == 1)//if already found then shift all remaining one position
        {
            ls->std[i-1]=ls->std[i];
        }
        else if (ls->std[i].roll == roll)// if found..
        {
            found = 1;
            printf("\nStudent removed. Name: %s\tRoll no: %d\tGrade: %s",ls->std[i].name,ls->std[i].roll,ls->std[i].grade);
        }        
    }
    if (found == 1)
    {
        ls->rear--;
    }
    else
        printf("\nStudent not found"); 
}

int updateStudent(list *ls){
    int roll,found=0;
    printf("\nEnter student roll no: ");
    scanf("%d",&roll);
    for (int i = 0; i <= ls->rear; i++)
    {
        if (ls->std[i].roll==roll)
        {
            fflush(stdin);
            printf("\nYour name is %s. Enter new name: ",ls->std[i].name);
            gets(ls->std[i].name);
            fflush(stdin);
            printf("\nYour grade is %s. Enter new grade: ",ls->std[i].grade);
            gets(ls->std[i].name);
            printf("Your roll no is %d. Enter new roll no: ",ls->std[i].roll);
            scanf("%d",&ls->std[i].roll);
            printf("\nUpdated......");
            found = 1;
            break;

        }
        
    }
    if (found == 0)
    {
        printf("\nStudent not found");
    }
}

int listStudent(list *ls){
    printf("\nRoll no\t\tName of student\t\tGrade Name\n");
    for (int i = 0; i <= ls->rear; i++)
    {
        printf("%d\t\t%s\t\t%s\n",ls->std[i].roll,ls->std[i].name,ls->std[i].grade);
    }
    
}