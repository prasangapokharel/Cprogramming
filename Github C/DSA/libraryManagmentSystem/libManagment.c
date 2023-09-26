#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

int maxBook = 5; // maximum 5 book can be issued....
struct userInfo
{
    char user[20];
    char pass[20];
};
struct nodeStd
{
    struct student
    {
        int sid;
        char name[50];
        char fac[5];
        int sem;
        int roll;
        int bkIss;
    } std;
    struct nodeStd *next;
    struct nodeStd *pre;
};
struct nodeStd *tailStd = NULL;
struct nodeStd *headStd = NULL;
struct nodeStd forSizeStd;
struct nodeBook
{
    struct book
    {
        int bid;
        char title[50];
        char autho[50];
        int price;
    } bk;
    struct nodeBook *next;
    struct nodeBook *pre;
};
struct nodeBook *tailBook = NULL;
struct nodeBook *headBook = NULL;
struct nodeBook forSizeBook;

struct nodeTran
{
    struct transaction
    {
        char date[30];
        int stdid;
        int bookid;
    } tran;
    struct nodeTran *next;
    struct nodeTran *pre;
};
struct nodeTran *tailTran = NULL;
struct nodeTran *headTran = NULL;
struct nodeTran forSizeTran;
struct issued
{
    int issuedNo;
};
// struct returnBk{
//     int issuedNo;

// };
//================================Selecting file================================
FILE *fileReturn(char mode[4])
{
    FILE *fp;
    char fac[5];
top:
    printf("\n\t\tEnter faculty name: ");
    scanf("%s", fac);

    if (strcmp(fac, "bca") == 0 || strcmp(fac, "BCA") == 0)
    {
        fp = fopen("bca.txt", mode);
    }
    else if (strcmp(fac, "BSW") == 0 || strcmp(fac, "bsw") == 0)
    {
        fp = fopen("bsw.txt", mode);
    }
    else if (strcmp(fac, "BHM") == 0 || strcmp(fac, "bhm") == 0)
    {
        fp = fopen("bhm.txt", mode);
    }
    else if (strcmp(fac, "bbs") == 0 || strcmp(fac, "BBS") == 0)
    {
        fp = fopen("bbs.txt", mode);
    }
    else
    {
        printf("\t\tInvalid faculty name!!!\n\t\tPress enter to continue..");
        getch();
        goto top;
    }
    return fp;
}

//================================New node for student.================================
struct nodeStd *getNodeStd()
{
    char fac[5];
    struct nodeStd *ptrnew;
    ptrnew = (struct nodeStd *)malloc(sizeof(struct nodeStd));
    if (ptrnew == NULL)
    {
        printf("Memory allocation failed.");
        getch();
        exit(0);
    }
    printf("\n\t\tEnter id: ");
    scanf("%d", &ptrnew->std.sid);
    fflush(stdin);
    printf("\t\tEnter name: ");
    gets(ptrnew->std.name);
    printf("\t\tEnter roll no: ");
    scanf("%d", &ptrnew->std.roll);
    fflush(stdin);
    printf("\n\t\tEnter faculty: ");
    gets(ptrnew->std.fac);
    printf("\t\tEnter semester: ");
    scanf("%d", &ptrnew->std.sem);
    fflush(stdin);
    ptrnew->std.bkIss = 0;
    return ptrnew;
}
//================================New node for book.================================
struct nodeBook *getNodeBook()
{
    struct nodeBook *ptrnew;
    ptrnew = (struct nodeBook *)malloc(sizeof(struct nodeBook));
    if (ptrnew == NULL)
    {
        printf("Memory allocation failed.");
        getch();
        exit(0);
    }
    printf("\n\t\tEnter id: ");
    scanf("%d", &ptrnew->bk.bid);
    fflush(stdin);
    printf("\t\tEnter title: ");
    gets(ptrnew->bk.title);
    printf("\t\tEnter Author: ");
    gets(ptrnew->bk.autho);
    printf("\t\tEnter price: ");
    scanf("%d", &ptrnew->bk.price);
    return ptrnew;
}

//================================New node for transaction.================================
struct nodeTran *getNodeTran(int bid, int sid, char date[])
{
    struct nodeTran *ptrnew;
    ptrnew = (struct nodeTran *)malloc(sizeof(struct nodeTran));
    if (ptrnew == NULL)
    {
        printf("Memory allocation failed.");
        getch();
        exit(0);
    }
    ptrnew->tran.bookid = bid;
    ptrnew->tran.stdid = sid;
    strcpy(ptrnew->tran.date, date);

    return ptrnew;
}

//================================Adding record to file================================
// for student
int outputStdRecord()
{
    FILE *fp;
    fp = fopen("student.txt", "wb");
    struct nodeStd *ptrthis;
    if (fp == NULL)
    {
        printf("\t\tUnable to open a file..");
        return 0;
    }
    ptrthis = headStd;
    do
    {
        fwrite(ptrthis, sizeof(forSizeStd), 1, fp);
        ptrthis = ptrthis->next;
    } while (ptrthis != headStd);
    fclose(fp);
    return 0;
}
// for book
int outputBookRecord()
{
    FILE *fp;
    fp = fopen("book.txt", "wb");
    struct nodeBook *ptrthis;
    if (fp == NULL)
    {
        printf("\t\tUnable to open a file..");
        return 0;
    }
    ptrthis = headBook;
    do
    {
        fwrite(ptrthis, sizeof(forSizeBook), 1, fp);
        ptrthis = ptrthis->next;
    } while (ptrthis != headBook);
    fclose(fp);
    return 0;
}
// for transaction
int outputTransactionRecord()
{
    FILE *fp;
    fp = fopen("transcation.txt", "wb");
    struct nodeTran *ptrthis;
    if (fp == NULL)
    {
        printf("\t\tUnable to open a file..");
        return 0;
    }
    ptrthis = headTran;
    do
    {
        fwrite(ptrthis, sizeof(forSizeTran), 1, fp);
        ptrthis = ptrthis->next;
    } while (ptrthis != headTran);
    fclose(fp);
    return 0;
}

//================================getting record from file================================
// for student
int inputStdRecord()
{
    FILE *fp;
    struct nodeStd *ptrthis;
    fp = fopen("student.txt", "rb");
    if (fp == NULL)
    {
        printf("\t\tUnable to open a file..");
        return 0;
    }
    // ptrthis = headStd;
    while (feof(fp) == 0)
    {
        ptrthis = (struct nodeStd *)malloc(sizeof(struct nodeStd));
        if (ptrthis == NULL)
        {
            printf("Memory allocation failed.");
            getch();
            exit(0);
        }
        if (fread(ptrthis, sizeof(struct nodeStd), 1, fp) == 0)
            continue;
        if (tailStd == NULL)
        {
            headStd = ptrthis;
            tailStd = ptrthis;
            ptrthis->next = ptrthis;
            ptrthis->pre = ptrthis;
        }
        else
        {
            headStd->pre = ptrthis;
            ptrthis->next = headStd;
            tailStd->next = ptrthis;
            ptrthis->pre = tailStd;
            tailStd = ptrthis;
        }
    }
}
// for Book
int inputBookRecord()
{
    FILE *fp;
    struct nodeBook *ptrthis;
    fp = fopen("book.txt", "rb");
    if (fp == NULL)
    {
        printf("\t\tUnable to open a file..");
        return 0;
    }
    // ptrthis = headStd;
    while (feof(fp) == 0)
    {
        ptrthis = (struct nodeBook *)malloc(sizeof(struct nodeBook));
        if (ptrthis == NULL)
        {
            printf("Memory allocation failed.");
            getch();
            exit(0);
        }
        if (fread(ptrthis, sizeof(struct nodeBook), 1, fp) == 0)
            continue;
        if (tailBook == NULL)
        {
            headBook = ptrthis;
            tailBook = ptrthis;
            ptrthis->next = ptrthis;
            ptrthis->pre = ptrthis;
        }
        else
        {
            headBook->pre = ptrthis;
            ptrthis->next = headBook;
            tailBook->next = ptrthis;
            ptrthis->pre = tailBook;
            tailBook = ptrthis;
        }
    }
}
// for Transcation
int inputTransactionRecord()
{
    FILE *fp;
    struct nodeTran *ptrthis;
    fp = fopen("transcation.txt", "rb");
    if (fp == NULL)
    {
        printf("\t\tUnable to open a file..");
        return 0;
    }
    // ptrthis = headStd;
    while (feof(fp) == 0)
    {
        ptrthis = (struct nodeTran *)malloc(sizeof(struct nodeTran));
        if (ptrthis == NULL)
        {
            printf("Memory allocation failed.");
            getch();
            exit(0);
        }
        if (fread(ptrthis, sizeof(struct nodeTran), 1, fp) == 0)
            continue;
        if (tailTran == NULL)
        {
            headTran = ptrthis;
            tailTran = ptrthis;
            ptrthis->next = ptrthis;
            ptrthis->pre = ptrthis;
        }
        else
        {
            headTran->pre = ptrthis;
            ptrthis->next = headTran;
            tailTran->next = ptrthis;
            ptrthis->pre = tailTran;
            tailTran = ptrthis;
        }
    }
}

//================================Adding new student================================
int registerStd()
{
    char ch = 'y';
    struct nodeStd *ptrnew;
    while (ch == 'y' || ch == 'Y')
    {
        ptrnew = getNodeStd();
        if (tailStd == NULL)
        {
            headStd = ptrnew;
            tailStd = ptrnew;
            ptrnew->next = ptrnew;
            ptrnew->pre = ptrnew;
        }
        else
        {
            headStd->pre = ptrnew;
            ptrnew->next = headStd;
            tailStd->next = ptrnew;
            ptrnew->pre = tailStd;
            tailStd = ptrnew;
        }
        printf("\n\t\tDo you want to add more items?(y/n): ");
        ch = getche();
    }
}

//================================Display student record================================
int listStd()
{
    int i = 0;
    struct nodeStd *ptrthis;
    ptrthis = headStd;
    if (ptrthis == NULL)
    {
        printf("\n\t\tRecord is empty..");
        return 0;
    }

    printf("\n\n\t\t**************Student Record***************\n");
    do
    {
        printf("\n\t\t%d =>\tId: %d\n\t\t\tName: %s\n\t\t\tRoll no: %d\n\t\t\tFaculty: %s\n\t\tSemester: %d\n\t\t_____________________________________________\n", ++i, ptrthis->std.sid, ptrthis->std.name, ptrthis->std.roll, ptrthis->std.fac, ptrthis->std.sem);
        ptrthis = ptrthis->next;
    } while (ptrthis != headStd);

    printf("\n\t\tPress enter to continue.");
    getch();
    return 0;
}

//================================Update record================================
int modifyStd()
{
    struct nodeStd *ptrthis;
    int flag = 0, id, i = 0;
    char name[50], cho;
    ptrthis = headStd;
    if (ptrthis == NULL)
    {
        printf("\n\t\tRecord is empty..");
        return 0;
    }
    printf("\n\n\t\t=======================Select=======================");
    printf("\n\t\tEnter your choice:\n\t\t1. Search Student by name.\n\t\t2. Search Student by id.\n\t\t3. Exit\n\t\t====================================================\n\t\tEnter here: ");
    cho = getche();
    switch (cho)
    {
    case '1':
        fflush(stdin);
        printf("\n\t\tEnter name to search: ");
        gets(name);
        do
        {
            if (strcmp(name, ptrthis->std.name) == 0)
            {
                printf("\t\t=======Old detail=======");
                printf("\n\t\t%d =>\tId: %d\n\t\t\tName: %s\n\t\t\tRoll no: %d\n\t\t\tFaculty: %s\n\t\tSemester: %d\n\t\t_____________________________________________\n", ++i, ptrthis->std.sid, ptrthis->std.name, ptrthis->std.roll, ptrthis->std.fac, ptrthis->std.sem);
                flag = 1;
                fflush(stdin);
                printf("\n\t\t=======Enter new detail=======\n");
                printf("\t\tEnter id: ");
                scanf("%d", &ptrthis->std.sid);
                fflush(stdin);
                printf("\t\tEnter name: ");
                gets(ptrthis->std.name);
                printf("\t\tEnter roll no: ");
                scanf("%d", &ptrthis->std.roll);
                printf("\t\tEnter faculty: ");
                gets(ptrthis->std.fac);
                printf("\t\tEnter semester: ");
                scanf("%d", &ptrthis->std.sem);
                break;
            }
            ptrthis = ptrthis->next;
        } while (ptrthis != headStd);
        if (flag == 0)
        {
            printf("\n\t\tThe name you have entred is not found..");
        }
        break;
    case '2':
        printf("\n\t\tEnter id to search: ");
        scanf("%d", &id);
        do
        {
            if (ptrthis->std.sid == id)
            {
                printf("\t\t=======Old detail=======");
                printf("\n\t\t%d =>\tId: %d\n\t\t\tName: %s\n\t\t\tRoll no: %d\n\t\t\tFaculty: %s\n\t\tSemester: %d\n\t\t_____________________________________________\n", ++i, ptrthis->std.sid, ptrthis->std.name, ptrthis->std.roll, ptrthis->std.fac, ptrthis->std.sem);
                flag = 1;
                fflush(stdin);
                printf("\n\t\t=======Enter new detail=======\n");
                printf("\t\tEnter id: ");
                scanf("%d", &ptrthis->std.sid);
                fflush(stdin);
                printf("\t\tEnter name: ");
                gets(ptrthis->std.name);
                printf("\t\tEnter roll no: ");
                scanf("%d", &ptrthis->std.roll);
                printf("\t\tEnter faculty: ");
                gets(ptrthis->std.fac);
                printf("\t\tEnter semester: ");
                scanf("%d", &ptrthis->std.sem);
                break;
            }
            ptrthis = ptrthis->next;
        } while (ptrthis != headStd);
        if (flag == 0)
        {
            printf("\n\t\tThe id you have entred is not found..");
        }
        break;
    case '3':
        return 0;
        break;

    default:
        printf("\n\t\tPlease enter valid choice...");
        break;
    }
    printf("\n\t\tPress enter to continue.");
    getch();
    return 0;
}

//================================Remove record================================
int removeStd()
{
    struct nodeStd *ptrthis;
    int id, flag = 0, i = 0;
    char cho, sure;
    ptrthis = headStd;
    printf("\n\t\tEnter student id to delete: ");
    scanf("%d", &id);
    do
    {
        if (ptrthis->std.sid == id)
        {
            printf("\t\t=======Student detail=======");
            printf("\n\t\t%d =>\tId: %d\n\t\t\tName: %s\n\t\t\tRoll no: %d\n\t\t\tFaculty: %s\n\t\tSemester: %d\n\t\t_____________________________________________\n", ++i, ptrthis->std.sid, ptrthis->std.name, ptrthis->std.roll, ptrthis->std.fac, ptrthis->std.sem);
            flag = 1;
            printf("\n\t\tAre you sure want to delete above record?(y/n): ");
            sure = getche();
            if (sure == 'y' || sure == 'Y')
            {
                if (ptrthis->next == ptrthis)
                {
                    free(ptrthis);
                    headStd = NULL;
                    tailStd = NULL;
                    break;
                }
                (ptrthis->pre)->next = ptrthis->next;
                (ptrthis->next)->pre = ptrthis->pre;
                free(ptrthis);
            }
            break;
        }
        ptrthis = ptrthis->next;
    } while (ptrthis != headStd);

    if (flag == 1)
        printf("\n\t\tRecord deleted successfully..!!");
    else
        printf("\n\t\tNo record found with this id..!!");

    printf("\n\t\tPress enter to continue....");
    getch();
}

//================================View Issued Book================================
int viewIssuedBk()
{
    int i = 0, j = 0;
    struct nodeStd *ptrthis;
    struct nodeTran *ptrthisTran;
    struct nodeBook *ptrthisBook;
    // struct issued *ptrthisDate;
    ptrthis = headStd;
    if (ptrthis == NULL)
    {
        printf("\n\t\tRecord is empty..");
        return 0;
    }

    printf("\n\n\t\t**************Student Record***************\n");
    do
    {
        printf("\n\t\t%d =>\tId: %d\n\t\t\tName: %s\n\t\t\tRoll no: %d\n\t\t\tFaculty: %s\n\t\t\tSemester: %d\n\t\t\tNo of book Issued: %d", ++i, ptrthis->std.sid, ptrthis->std.name, ptrthis->std.roll, ptrthis->std.fac, ptrthis->std.sem, ptrthis->std.bkIss);
        if (ptrthis->std.bkIss > 0)
        {
            printf("\n\n\t\t\t***********Book Issued Detail************");
            ptrthisTran = headTran;
            do
            {
                if (ptrthis->std.sid == ptrthisTran->tran.stdid)
                {
                    ptrthisBook = headBook;
                    do
                    {
                        if (ptrthisTran->tran.bookid == ptrthisBook->bk.bid)
                        {
                            printf("\n\t\t\t%d =>\tId: %d\n\t\t\t\tTitle: %s\n\t\t\t\tAuthor: %s\n\t\t\t\tPrice: %d\n\t\t\t_____________________________________________\n", ++j, ptrthisBook->bk.bid, ptrthisBook->bk.title, ptrthisBook->bk.autho, ptrthisBook->bk.price);
                        }

                        ptrthisBook = ptrthisBook->next;
                    } while (ptrthisBook != headBook);
                }

                ptrthisTran = ptrthisTran->next;

            } while (ptrthisTran != headTran);
        }
        printf("\n\t\t_____________________________________________\n");
        ptrthis = ptrthis->next;

    } while (ptrthis != headStd);

    printf("\n\t\tPress enter to continue.");
    getch();
    return 0;
}

//================================For student record================================
int student()
{
    char cho;
    do
    {
        printf("\n\n\t\t=======================Select=======================");
        printf("\n\t\tEnter your choice:\n\t\t1. Register Student\t\t4. View Issued Books\n\t\t2. Remove Student\t\t5. List Student\n\t\t3. Modify Student\t\t6. Goto main menu \n \t\t ====================================================\n\t\tEnter here: ");
        cho = getche();
        switch (cho)
        {
        case '1':
            registerStd();
            break;
        case '2':
            removeStd();
            break;
        case '3':
            modifyStd();
            break;
        case '4':
            viewIssuedBk();
            break;
        case '5':
            listStd();
            break;
        case '6':
            return 0;
            break;

        default:
            printf("\n\t\tPlease enter valid choice...");
            break;
        }
    } while (1);
    return 0;
}
//================================For adding Book================================
int addBook()
{
    char ch = 'y';
    struct nodeBook *ptrnew;
    while (ch == 'y' || ch == 'Y')
    {
        ptrnew = getNodeBook(); // now we have required node to be inserted.
        if (tailBook == NULL)
        {
            headBook = ptrnew;
            tailBook = ptrnew;
            ptrnew->next = ptrnew;
            ptrnew->pre = ptrnew;
        }
        else
        {
            headBook->pre = ptrnew;
            ptrnew->next = headBook;
            tailBook->next = ptrnew;
            ptrnew->pre = tailBook;
            tailBook = ptrnew;
        }
        printf("\n\t\tDo you want to add more items?(y/n): ");
        ch = getche();
    }
    return 0;
}

//================================For Modify Book================================
int modifyBook()
{
    struct nodeBook *ptrthis;
    int flag = 0, id, i = 0;
    char name[50], cho;
    ptrthis = headBook;
    if (ptrthis == NULL)
    {
        printf("\n\t\tRecord is empty..");
        return 0;
    }
    printf("\n\n\t\t=======================Select=======================");
    printf("\n\t\tEnter your choice:\n\t\t1. Search Book by title.\n\t\t2. Search Book by id.\n\t\t3. Back\n\t\t====================================================\n\t\tEnter here: ");
    cho = getche();
    switch (cho)
    {
    case '1':
        fflush(stdin);
        printf("\n\t\tEnter title to search: ");
        gets(name);
        do
        {
            if (strcmp(name, ptrthis->bk.title) == 0)
            {
                printf("\t\t=======Old detail=======");
                printf("\n\t\t%d =>\tId: %d\n\t\t\tTitle: %s\n\t\t\tAuthor: %s\n\t\t\tPrice: %d\n\t\t_____________________________________________\n", ++i, ptrthis->bk.bid, ptrthis->bk.title, ptrthis->bk.autho, ptrthis->bk.price);
                flag = 1;
                fflush(stdin);
                printf("\n\t\t=======Enter new detail=======\n");
                printf("\n\t\tEnter id: ");
                scanf("%d", &ptrthis->bk.bid);
                fflush(stdin);
                printf("\t\tEnter title: ");
                gets(ptrthis->bk.title);
                printf("\t\tEnter Author: ");
                gets(ptrthis->bk.autho);
                printf("\t\tEnter price: ");
                scanf("%d", &ptrthis->bk.price);
                break;
            }
            ptrthis = ptrthis->next;
        } while (ptrthis != headBook);
        if (flag == 0)
        {
            printf("\n\t\tThe name you have entred is not found..");
        }
        break;
    case '2':
        printf("\n\t\tEnter id to search: ");
        scanf("%d", &id);
        do
        {
            if (ptrthis->bk.bid == id)
            {
                printf("\t\t=======Old detail=======");
                printf("\n\t\t%d =>\tId: %d\n\t\t\tTitle: %s\n\t\t\tAuthor: %s\n\t\t\tPrice: %d\n\t\t_____________________________________________\n", ++i, ptrthis->bk.bid, ptrthis->bk.title, ptrthis->bk.autho, ptrthis->bk.price);
                flag = 1;
                fflush(stdin);
                printf("\n\t\t=======Enter new detail=======\n");
                printf("\n\t\tEnter id: ");
                scanf("%d", &ptrthis->bk.bid);
                fflush(stdin);
                printf("\t\tEnter title: ");
                gets(ptrthis->bk.title);
                printf("\t\tEnter Author: ");
                gets(ptrthis->bk.autho);
                printf("\t\tEnter price: ");
                scanf("%d", &ptrthis->bk.price);
                break;
            }
            ptrthis = ptrthis->next;
        } while (ptrthis != headBook);
        if (flag == 0)
        {
            printf("\n\t\tThe id you have entred is not found..");
        }
        break;
    case '3':
        return 0;
        break;

    default:
        printf("\n\t\tPlease enter valid choice...");
        break;
    }
    printf("\n\t\tPress enter to continue.");
    getch();
    return 0;
}

//================================remove Book record================================
int removeBook()
{
    struct nodeBook *ptrthis;
    int id, flag = 0, i = 0;
    char cho, sure;
    ptrthis = headBook;
    printf("\n\t\tEnter Book id to delete: ");
    scanf("%d", &id);
    do
    {
        if (ptrthis->bk.bid == id)
        {
            printf("\t\t=======Book detail=======");
            printf("\n\t\t%d =>\tId: %d\n\t\t\tTitle: %s\n\t\t\tAuthor: %s\n\t\t\tPrice: %d\n\t\t_____________________________________________\n", ++i, ptrthis->bk.bid, ptrthis->bk.title, ptrthis->bk.autho, ptrthis->bk.price);
            flag = 1;
            printf("\n\t\tAre you sure want to delete above record?(y/n): ");
            sure = getche();
            if (sure == 'y' || sure == 'Y')
            {
                if (ptrthis->next == ptrthis)
                {
                    free(ptrthis);
                    headBook = NULL;
                    tailBook = NULL;
                    break;
                }
                (ptrthis->pre)->next = ptrthis->next;
                (ptrthis->next)->pre = ptrthis->pre;
                free(ptrthis);
            }
            break;
        }
        ptrthis = ptrthis->next;
    } while (ptrthis != headBook);

    if (flag == 1)
        printf("\n\t\tRecord deleted successfully..!!");
    else
        printf("\n\t\tNo record found with this id..!!");

    printf("\n\t\tPress enter to continue....");
    getch();
}

//================================For listing Book================================
int listBook()
{
    int i = 0;
    struct nodeBook *ptrthis;
    ptrthis = headBook;
    if (ptrthis == NULL)
    {
        printf("\n\t\tRecord is empty..");
        printf("\n\t\tPress enter to continue.");
        getch();
        return 0;
    }

    printf("\n\n\t\t**************Book Records***************\n");
    do
    {
        printf("\n\t\t%d =>\tId: %d\n\t\t\tTitle: %s\n\t\t\tAuthor: %s\n\t\t\tPrice: %d\n\t\t_____________________________________________\n", ++i, ptrthis->bk.bid, ptrthis->bk.title, ptrthis->bk.autho, ptrthis->bk.price);
        ptrthis = ptrthis->next;
    } while (ptrthis != headBook);

    printf("\n\t\tPress enter to continue.");
    getch();
    return 0;
}

//================================Search Book record================================
int searchBook()
{
    struct nodeBook *ptrthis;
    int flag = 0, id, i = 0;
    char name[50], cho;
    ptrthis = headBook;
    if (ptrthis == NULL)
    {
        printf("\n\t\tRecord is empty..");
        printf("\n\t\tPress enter to continue.");
        getch();
        return 0;
    }
    printf("\n\n\t\t=======================Select=======================");
    printf("\n\t\tEnter your choice:\n\t\t1. Search Book by title.\n\t\t2. Search Book by id.\n\t\t3. Back\n\t\t====================================================\n\t\tEnter here: ");
    cho = getche();
    switch (cho)
    {
    case '1':
        fflush(stdin);
        printf("\n\t\tEnter title to search: ");
        gets(name);
        do
        {
            if (strcmp(name, ptrthis->bk.title) == 0)
            {
                printf("\t\t==============Book detail==============");
                printf("\n\t\t%d =>\tId: %d\n\t\t\tTitle: %s\n\t\t\tAuthor: %s\n\t\t\tPrice: %d\n\t\t_____________________________________________\n", ++i, ptrthis->bk.bid, ptrthis->bk.title, ptrthis->bk.autho, ptrthis->bk.price);
                flag = 1;
                break;
            }
            ptrthis = ptrthis->next;
        } while (ptrthis != headBook);
        if (flag == 0)
        {
            printf("\n\t\tThe name you have entred is not found..");
        }
        break;
    case '2':
        printf("\n\t\tEnter id to search: ");
        scanf("%d", &id);
        do
        {
            if (ptrthis->bk.bid == id)
            {
                printf("\t\t=======Book detail=======");
                printf("\n\t\t%d =>\tId: %d\n\t\t\tTitle: %s\n\t\t\tAuthor: %s\n\t\t\tPrice: %d\n\t\t_____________________________________________\n", ++i, ptrthis->bk.bid, ptrthis->bk.title, ptrthis->bk.autho, ptrthis->bk.price);
                flag = 1;
                break;
            }
            ptrthis = ptrthis->next;
        } while (ptrthis != headBook);
        if (flag == 0)
        {
            printf("\n\t\tThe id you have entred is not found..");
        }
        break;
    case '3':
        return 0;
        break;

    default:
        printf("\n\t\tPlease enter valid choice...");
        break;
    }
    printf("\n\t\tPress enter to continue.");
    getch();
    return 0;
}

//================================For Book record================================
int book()
{
    char cho;
    do
    {
        printf("\n\n\t\t=======================Select=======================");
        printf("\n\t\tEnter your choice:\n\t\t1. Add Book\t\t4. List Books\n\t\t2. Modify Book\t\t5. Search Book\n\t\t3. Delete Book\t\t6. Goto main menu \n \t\t ====================================================\n\t\tEnter here: ");
        cho = getche();
        switch (cho)
        {
        case '1':
            addBook();
            break;
        case '2':
            modifyBook();
            break;
        case '3':
            removeBook();
            break;
        case '4':
            listBook();
            break;
        case '5':
            searchBook();
            break;
        case '6':
            return 0;
            break;

        default:
            printf("\n\t\tPlease enter valid choice...");
            break;
        }
    } while (1);
    return 0;
}

//================================For book issue================================
int forIssue()
{
    // struct nodeTran *ptrthisTran;
    struct nodeTran *ptrnew;
    struct nodeStd *ptrthisStd;
    struct nodeBook *ptrthisBk;
    ptrthisStd = headStd;
    ptrthisBk = headBook;
    // ptrthisTran = headTran;
    int sid, bid, flag = 0, i = 0, j = 0, flag1 = 0;
    char date[30];
    printf("\n\t\tEnter Student id: ");
    scanf("%d", &sid);

    do
    {
        if (ptrthisStd->std.sid == sid)
        {
            if (ptrthisStd->std.bkIss < maxBook)
            {
                printf("\t\t=======Student detail=======");
                printf("\n\t\t%d =>\tId: %d\n\t\t\tName: %s\n\t\t\tRoll no: %d\n\t\t\tSemester: %d\n\t\t_____________________________________________\n", ++i, ptrthisStd->std.sid, ptrthisStd->std.name, ptrthisStd->std.roll, ptrthisStd->std.sem);
                flag = 1;
                printf("\n\t\t=======Book Issued detail=======");
                if (ptrthisStd->std.bkIss == 0)
                {
                    printf("\n\t\tNone of the book is Issued.");
                }
                else
                {
                    printf("\n\t\tNuber of book Issued: %d", ptrthisStd->std.bkIss);
                }
                fflush(stdin);
                printf("\n\t\tEnter today's date(yyyy/mm/dd): ");
                gets(date);
                printf("\n\t\tEnter book id to issue: ");
                scanf("%d", &bid);
                do
                {
                    if (ptrthisBk->bk.bid == bid)
                    {
                        printf("\t\t=======Book detail=======");
                        printf("\n\t\t%d =>\tId: %d\n\t\t\tTitle: %s\n\t\t\tAuthor: %s\n\t\t\tPrice: %d\n\t\t_____________________________________________\n", ++j, ptrthisBk->bk.bid, ptrthisBk->bk.title, ptrthisBk->bk.autho, ptrthisBk->bk.price);
                        flag1 = 1;
                        ++ptrthisStd->std.bkIss;
                        // ==========Transaction==========

                        ptrnew = getNodeTran(bid, sid, date);
                        if (tailTran == NULL)
                        {
                            headTran = ptrnew;
                            tailTran = ptrnew;
                            ptrnew->next = ptrnew;
                            ptrnew->pre = ptrnew;
                        }
                        else
                        {
                            headTran->pre = ptrnew;
                            ptrnew->next = headTran;
                            tailTran->next = ptrnew;
                            ptrnew->pre = tailTran;
                            tailTran = ptrnew;
                        }
                        break;
                    }
                    ptrthisBk = ptrthisBk->next;
                } while (ptrthisBk != headBook);
                if (flag1 == 0)
                {
                    printf("\n\t\tThe book id you have entred is not found..");
                    getch();
                    return 0;
                }
                break;
            }
            else
            {
                printf("\n\t\tId = %d Have already issued 5 book", sid);
                printf("\n\t\tPress enter to continue..");
                getch();
            }
        }
        if (flag == 0)
        {
            printf("\n\t\tThe student id you have entred is not found..");
            getch();
            return 0;
        }
        ptrthisStd = ptrthisStd->next;

    } while (ptrthisStd != headStd);

    printf("\n\t\tBook issued sucessfully...\n\t\tPress entetr to continue.");
    getch();
}

//================================For book Return================================
int forReturn()
{
    struct nodeTran *ptrthisTran;
    struct nodeTran *ptrnew;
    struct nodeStd *ptrthisStd;
    struct nodeBook *ptrthisBk;
    ptrthisStd = headStd;
    ptrthisBk = headBook;
    ptrthisTran = headTran;
    int sid, bid, flag = 0, i = 0, j = 0, flag1 = 0;
    char date[30];
    printf("\n\t\tEnter Student id: ");
    scanf("%d", &sid);

    do
    {
        if (ptrthisStd->std.sid == sid)
        {
            if (ptrthisStd->std.bkIss > 0)
            {
                printf("\t\t=======Student detail=======");
                printf("\n\t\t%d =>\tId: %d\n\t\t\tName: %s\n\t\t\tRoll no: %d\n\t\t\tSemester: %d\n\t\t_____________________________________________\n", ++i, ptrthisStd->std.sid, ptrthisStd->std.name, ptrthisStd->std.roll, ptrthisStd->std.sem);
                flag = 1;
                printf("\n\t\t=======Book Issued detail=======");
                ptrthisTran = headTran;
                do
                {
                    if (sid == ptrthisTran->tran.stdid)
                    {
                        printf("\n\t\tNumber of books Issued: %d", ptrthisStd->std.bkIss);
                        // printf("\n\t\tIssued date = %s", ptrthisTran->tran.date);
                        break;
                    }
                    ptrthisTran = ptrthisTran->next;
                } while (ptrthisTran != headTran);

                printf("\n\t\tEnter book id to return: ");
                scanf("%d", &bid);
                do
                {
                    if (ptrthisBk->bk.bid == bid)
                    {
                        printf("\t\t=======Book detail=======");
                        printf("\n\t\t%d =>\tId: %d\n\t\t\tTitle: %s\n\t\t\tAuthor: %s\n\t\t\tPrice: %d\n\t\t_____________________________________________\n", ++j, ptrthisBk->bk.bid, ptrthisBk->bk.title, ptrthisBk->bk.autho, ptrthisBk->bk.price);
                        flag1 = 1;
                        --ptrthisStd->std.bkIss;
                        break;
                    }
                    ptrthisBk = ptrthisBk->next;
                } while (ptrthisBk != headBook);
                ptrthisTran = headTran;
                do
                {
                    if (bid == ptrthisTran->tran.bookid)
                    {
                        if (ptrthisTran->next == ptrthisTran)
                        {
                            free(ptrthisTran);
                            headTran = NULL;
                            tailTran = NULL;
                        }
                        else if (ptrthisTran == headTran)
                        {
                            (ptrthisTran->pre)->next = ptrthisTran->next;
                            (ptrthisTran->next)->pre = ptrthisTran->pre;
                            headTran = ptrthisTran->next;
                            free(ptrthisTran); 
                        }
                        
                        else
                        {
                            (ptrthisTran->pre)->next = ptrthisTran->next;
                            (ptrthisTran->next)->pre = ptrthisTran->pre;
                            free(ptrthisTran);
                        }
                        break;
                    }
                    ptrthisTran = ptrthisTran->next;
                } while (ptrthisTran != headTran);

                if (flag1 == 0)
                {
                    printf("\n\t\tThe book id you have entred is not found..");
                    getch();
                    return 0;
                }
                break;
            }
            else
            {
                printf("\n\t\tId = %d Have not issued any book", sid);
                printf("\n\t\tPress enter to continue..");
                getch();
            }
        }
        ptrthisStd = ptrthisStd->next;

    } while (ptrthisStd != headStd);

    if (flag == 0)
    {
        printf("\n\t\tThe student id you have entred is not found..");
        getch();
        return 0;
    }
    printf("\n\t\tBook returned sucessfully...\n\t\tPress entetr to continue.");
    getch();
}

//================================For Transaction================================
int transaction()
{
    struct nodeTran *ptrthis;
    char cho;
    printf("\n\n\t\t=======================Select=======================");
    printf("\n\t\tEnter your choice:\n\t\t1. Issue Book.\n\t\t2. Returned Book.\n\t\t3. Back\n\t\t====================================================\n\t\tEnter here: ");
    cho = getche();
    switch (cho)
    {
    case '1':
        forIssue();
        break;
    case '2':
        forReturn();
        break;
    case '3':
        return 0;
        break;

    default:
        printf("\n\t\tPlease enter valid choice...");
        getch();
        break;
    }
}

int main()
{
    char cho;
    struct userInfo us;
    inputStdRecord();
    inputBookRecord();
    inputTransactionRecord();
    // FILE *fp;
    // fp = fopen("LoginInfo.txt","wb");
    // printf("Enter user name: ");
    // gets(us.user);
    // printf("Enter user pass: ");
    // gets(us.pass);
    // fwrite(&us,sizeof(us),1,fp);

    do
    {
        printf("\n\n\t\t=======================Select=======================");
        printf("\n\t\tEnter your choice:\n\t\t1. Student Management\t\t3. Transaction Detail\n\t\t2. Book Management\t\t4. Exit\n\t\t====================================================\n\t\tEnter here: ");
        cho = getche();
        switch (cho)
        {
        case '1':
            student();
            break;
        case '2':
            book();
            break;
        case '3':
            transaction();
            break;
        case '4':
            outputStdRecord();
            outputBookRecord();
            outputTransactionRecord();
            return 0;
            break;

        default:
            printf("\n\t\tPlease enter valid choice");
            break;
        }
    } while (1);

    return 0;
}