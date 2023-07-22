#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define UP 72
#define DOWN 80
#define ENTER 13
#define TRUE 1
#define FALSE 0
#define MENULEN 50
#define MENUX 10
#define MENUY 8
struct menu
{
    char caption[MENULEN];
    int row;
    int col;
    int selected;
    void (*fptr)();
    struct menu *next;
    struct menu *prev;
};

struct menu *menubar = NULL;
void displaymenu()
{
    struct menu *ptrthis;
    if (menubar == NULL)
        return;
    ptrthis = menubar; // point to last node
    do
    {
        ptrthis = ptrthis->next; // move to next node
        SetConsoleCursorPosition(ptrthis->row, ptrthis->col);
        if (ptrthis->selected == TRUE)
            printf("[X] %s", ptrthis->caption);
        else
            printf("[ ] %s", ptrthis->caption);
    } while (ptrthis != menubar);
}
void onkeypress(char ch)
{
    struct menu *ptrthis;
    if (menubar == NULL)
        return;
    ptrthis = menubar;
    do
    {
        ptrthis = ptrthis->next;
        if (ptrthis->selected == TRUE)
        {
            if (ch == ENTER)
            {
                (*ptrthis->fptr)();
            }
            else if (ch == UP)
            {
                ptrthis->selected = FALSE;
                (ptrthis->prev)->selected = TRUE;
            }
            else if (ch == DOWN)
            {
                ptrthis->selected = FALSE;
                (ptrthis->next)->selected = TRUE;
            }
            else
            {
            }
            return;
        }
    } while (ptrthis != menubar);
}
struct menu *getmenu()
{
    struct menu *ptrnew = (struct menu *)malloc(sizeof(struct menu));
    if (ptrnew == NULL)
    {
        printf("Memory allocation failed. Program will terminate now.");
        getch();
        exit(0);
    }
    ptrnew->next = NULL;
    ptrnew->prev = NULL;
    return ptrnew;
}
void insert()
{
    gotoxy(MENUX, MENUY);
    printf("Item inserted.\tPress any key to go back.");
    if (!getch())
        getch();
}
void update()
{
    gotoxy(MENUX, MENUY);
    printf("Item updated.\tPress any key to go back.");
    if (!getch())
        getch();
}
void deletes()
{
    gotoxy(MENUX, MENUY);
    printf("Item deleted.\tPress any key to go back.");
    if (!getch())
        getch();
}
void list()
{
    gotoxy(MENUX, MENUY);
    printf("List generated.\tPress any key to go back.");
    if (!getch())
        getch();
}
void quit() { exit(0); }
int main()
{
    char captionlist[][MENULEN] = {"Insert", "Update", "Delete", "List", "Exit"};
    void (*fptrlist[])(void) = {insert, update, deletes, list, quit};
    char ch;
    int i;
    for (i = 0; i < 5; i++)
    {
        struct menu *ptrnew = getmenu();
        strcpy(ptrnew->caption, captionlist[i]);
        ptrnew->row = MENUX;
        ptrnew->col = MENUY + i;
        ptrnew->fptr = *fptrlist[i];
        if (i == 0)
        {
            ptrnew->next = ptrnew->prev = ptrnew;
            ptrnew->selected = TRUE;
        }
        else
        {
            ptrnew->selected = FALSE;
            ptrnew->prev = menubar;
            ptrnew->next = menubar->next;
            (menubar->next)->prev = ptrnew;
            menubar->next = ptrnew;
        }
        menubar = ptrnew;
    }
    while (TRUE)
    {
        displaymenu();
        fflush(stdin);
        ch = getch();
        if (!ch)
            ch = getch();
        onkeypress(ch);
    }
}