#include <stdio.h>
#include <conio.h> // Include conio.h for getch()

#define FALSE 0
#define TRUE 1
#define UP 72
#define DOWN 80
#define ENTER 13

void gotoxy(int x, int y);

int main()
{
    char choice;
    int select = 1;

    while (TRUE)
    {
        gotoxy(10, 12);
        printf("Select Your Choice:\n");
        gotoxy(10, 13);

        if (select == 1)
        {
            printf("[X] Register");
        }
        else
        {
            printf("[] Register");
        }

        gotoxy(10, 14);

        if (select == 2)
        {
            printf("[X] Remove");
        }
        else
        {
            printf("[] Remove");
        }

        gotoxy(10, 15);

        if (select == 3)
        {
            printf("[X] List");
        }
        else
        {
            printf("[] List");
        }

        gotoxy(10, 16);

        if (select == 4)
        {
            printf("[X] Exit");
        }
        else
        {
            printf("[] Exit");
        }

        fflush(stdin);
        choice = getch();

        switch (choice)
        {
            case UP:
                if (select > 1)
                {
                    select--;
                }
                break;

            case DOWN:
                if (select < 4)
                {
                    select++;
                }
                break;

            case ENTER:
                switch (select)
                {
                    case 1:
                        printf("\nCalling register\n");
                        break;

                    case 2:
                        printf("\nCalling Remove register\n");
                        break;

                    case 3:
                        printf("\nCalling list register\n");
                        break;

                    case 4:
                        printf("\nExiting...\n");
                        return 0;

                    default:
                        printf("\nInvalid choice\n");
                        break;
                }
                break;

            default:
                printf("\nClick");
                break;
        }
    }

    return 0;
}

void gotoxy(int x, int y)
{
    printf("%c[%d;%df", 0x1B, y, x);
}

