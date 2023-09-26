#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>

struct node
{
    struct information{
        char name[50];
        int roll;
        // char faculty[30];
        int sem;
        char phon[15];
    }info;
    struct node * next;
    struct node * pre;
};
// struct information{
//     char name[50];
//     int roll;
//     char faculty[30];
//     int sem;
//     char phon[15];
// };

int addRecord();
int updateRecord();
int deleteRecord();
int displayRecord();
int searchRecord();

struct node * tail = NULL;
struct node * head = NULL;
struct node forSize;


FILE * fileReturn(char mode[4]){
    FILE *fp;
    char fac[5];
    top:
    printf("\n\t\tEnter faculty name: ");
    scanf("%s",fac);
    
    if (strcmp(fac,"bca")==0 || strcmp(fac,"BCA") == 0)
    {
        fp = fopen("bca.txt",mode);
    }
    else if (strcmp(fac,"BSW")==0 || strcmp(fac,"bsw") == 0)
    {
        fp = fopen("bsw.txt",mode);
    }
    else if (strcmp(fac,"BHM")==0 || strcmp(fac,"bhm") == 0)
    {
        fp = fopen("bhm.txt",mode);
    }
    else if(strcmp(fac,"bbs")==0 || strcmp(fac,"BBS") == 0){
        fp = fopen("bbs.txt",mode);
    }
    else{
        printf("\t\tInvalid faculty name!!!\n\t\tPress enter to continue..");
        getch();
        goto top;
    }
    return fp;
}

struct node * getNode(){
    FILE *fp;
    char fac[5];
    struct node *ptrnew;
    ptrnew = (struct node *)malloc(sizeof(struct node));
    if (ptrnew == NULL)
    {
        printf("Memory allocation failed.");
        getch();
        exit(0);
    }
    fp = fileReturn("ab");
        
    fflush(stdin);
    printf("\t\tEnter name: ");
    gets(ptrnew->info.name);
    printf("\t\tEnter roll no: ");
    scanf("%d",&ptrnew->info.roll);
    printf("\t\tEnter semester: ");
    scanf("%d",&ptrnew->info.sem);
    fflush(stdin);
    printf("\t\tEnter phon no: ");
    gets(ptrnew->info.phon);
    fwrite(ptrnew,sizeof(forSize),1,fp); 
	fclose(fp); 
    
    return ptrnew;
}

int main()
{
    char cho;
    tail = NULL;
    while (1)
    {
        printf("\n\n\t\t==================Select==================");
        printf("\n\t\t1. Add record.\t\t4. Delete record\n\t\t2. Modify record.\t5. Display record.\n\t\t3. Search record.\t6. Exit.\n\t\t==========================================\n\t\tEnter option:  ");
        cho = getche();

        switch (cho)
        {
        case '1':
            addRecord();
            break;
        case '2':
            updateRecord();
            break;
        case '3':
            searchRecord();
            break;
        case '5':
            displayRecord();
            break;
        case '6':
            return 0;
            break;
        default:
            printf("\n\t\tPlease enter valid option...");
            break;
        }
    }
    return 0;
}

int addRecord(){
    char ch='y';
    struct node *ptrnew;
    while (ch == 'y' || ch == 'Y')
    {
        ptrnew = getNode(); // now we have required node to be inserted.
        if (tail == NULL)
        {
            head = ptrnew;
            tail = ptrnew;
            ptrnew->next = ptrnew;
            ptrnew->pre = ptrnew;
        }
        else
        {
            head->pre = ptrnew;
            ptrnew->next = head;
            tail->next = ptrnew;
            ptrnew->pre = tail;
            tail = ptrnew;
        }
        printf("\n\t\tDo you want to add more items?(y/n): ");
        ch = getche();

    }
}
int displayRecord(){
    FILE * fp;
    int size;
    int i=0;
    char fac[5];
    struct node ptrthis;
    fp = fileReturn("rb");
    if (fp == NULL)
    {
        printf("\t\tUnable to open a file..");
        return 0;
    }

    printf("\n\n\t\t**************Student Record***************\n"); 
    while(fread(&ptrthis, sizeof(ptrthis), 1, fp)){
        printf("\n\t\t%d =>\tName: %s\n\t\t\tRoll no: %d\n\t\t\tSemester: %d\n\t\t\tNumber: %s\n\t\t_____________________________________________\n",++i,ptrthis.info.name,ptrthis.info.roll,ptrthis.info.sem,ptrthis.info.phon);
    }
    printf("\n\t\tPress enter to continue.");
    getch();
    fclose(fp);
    return 0;
}
int searchRecord(){
    FILE *fp;
    struct node ptrthis;
    int i = 0,flag=0;
    char name[50];
    fp = fileReturn("rb");
    fflush(stdin);
    printf("\n\t\tEnter name to search: ");
    gets(name);
    while (fread(&ptrthis,sizeof(forSize),1,fp))
    {
        if (strcmp(name,ptrthis.info.name)==0)
        {
            flag=1;
            printf("\n\t\t%d =>\tName: %s\n\t\t\tRoll no: %d\n\t\t\tSemester: %d\n\t\t\tNumber: %s\n\t\t_____________________________________________\n",++i,ptrthis.info.name,ptrthis.info.roll,ptrthis.info.sem,ptrthis.info.phon);
        }
        
    }
    if (flag==0)
    {
        printf("\n\t\tThe name you have entred is not found..");
    }
    
    printf("\n\t\tPress enter to continue.");
    getch();
    
}

int updateRecord(){
    FILE*fp;
    struct node ptrthis;
    fp = fileReturn("r+");
    int flag=0;
    char name[50];
    if(fp == NULL) 
	{ 
		printf("\n\t\t ERROR: Could not open file"); 
		return 0; 
	} 

    fflush(stdin);
    printf("\n\t\tEnter name to search: ");
    gets(name);
    // printf("\nWhat is up");
    while (fread(&ptrthis,sizeof(forSize),1,fp))
    {
        if (strcmp(name,ptrthis.info.name)==0)
        {
            flag=1;
            fflush(stdin);
            printf("\t\t=======Enter new detail=======\n");
            fflush(stdin);
            printf("\t\tEnter name: ");
            gets(ptrthis.info.name);
            printf("\t\tEnter roll no: ");
            scanf("%d",&ptrthis.info.roll);
            printf("\t\tEnter semester: ");
            scanf("%d",&ptrthis.info.sem);
            fflush(stdin);
            printf("\t\tEnter phon no: ");
            gets(ptrthis.info.phon);

            fseek(fp,-sizeof(forSize), SEEK_CUR); 
            fwrite(&ptrthis,sizeof(forSize),1,fp);
            break; 
        }
    }
    if (flag==0)
    {
        printf("\n\t\tThe name you have entred is not found..");
    }
	fclose(fp); 
    printf("\n\t\tPress enter to continue.");
    getch();
    return 0;
}