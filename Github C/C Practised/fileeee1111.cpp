#include <stdio.h>   // headerfile-1
#include <conio.h>   // headerfile-2
#include <string.h>  //headerfile-3
#define MAX 200     //headerfile-4

struct student {
    int id;
    char name[25];
    char address[50];
    char section[20];
    int grade;
};

struct student list[MAX];
int counter = 0;

void Registerstudent() {
    printf("\t\t!! Register Port Unlocked !!\t\t\n\n");
    printf("\t\t!! Start From Here Now... !!\t\t\n");
    
    printf("\n\n1. Enter Name of the student:\n- ");
    scanf("%s", &list[counter].name);
    printf("\n2. Enter Id of the student:\n- ");
    scanf("%d", &list[counter].id);
    printf("\n3. Enter Address of the student:\n- ");
    scanf("%s", &list[counter].address);
    printf("\n4. Enter Section of the student:\n- ");
    scanf("%s", &list[counter].section);
    printf("\n5. Enter of Which Grade/Class You Wanna Register:\n- ");
    scanf("%d", &list[counter].grade);
	counter ++;
    printf("\n");
    printf("\t\t!!Data Entered Successfully\t\t\n");
    printf("\n\n\n");

    printf("!!Registration saved as well!!");
}

void Displaystudent() {
    printf("\t->The List Of Student Who Applied For Registration<-/t");
    printf("\n\n\t!!!! RESULT !!!!\n");
    int i;
    for (i = 0; i < counter; i++) {
        printf("\nThe Name of Student = %s", list[i].name);
        printf("\nThe id of Student = %d", list[i].id);
        printf("\nThe Address of Student = %s", list[i].address);
        printf("\nThe Section of Student = %s", list[i].section);
        printf("\nThe Grade of Student = %d", list[i].grade);
        printf("\n");
        printf("\n");
    }
}

void editstudent() {
    int id;
    printf(" : Enter the ID of the student to update: ");
    scanf("%d", &id);

    int index = -1;
    for (int i = 0; i < counter; i++) {
        if (list[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Student with ID %d not found.\n", id);
        return;
    }

    struct student editstudent;
    printf("\n:Enter the New ID of the student:");
    scanf("%d", &editstudent.id);
    printf("\n1.Enter Name of the student: ");
    scanf("%s", editstudent.name);
    printf("\n2. Enter Address of the student: ");
    scanf("%s", editstudent.address);
    printf("\n3. Enter Section of the student: ");
    scanf("%s", editstudent.section);
    printf("\n4. Enter Grade/Class of the student: ");
    scanf("%d", &editstudent.grade);
	counter++;

    list[index] = editstudent;
    printf("\nData Updated Successfully!\n");
}

void savestudent() {
    FILE* fp;
    fp = fopen("baa", "wb");

    if (fp != NULL) {
        fwrite(list, sizeof(struct student), counter, fp);
    }

    fclose(fp);
}

void readstudent() {
    FILE* fp;
    fp = fopen("baa", "rb");

    if (fp != NULL) {
        while (feof(fp) == 0) {
            if (fread(&list[counter], sizeof(struct student), 1, fp) == 1)
                counter++;
        }
    }

    fclose(fp);
}

void deleteallstudent() {
    if (remove("baa") == 0)
        printf("\n\n:Data Delete Successfully!\n\n");
    else
        printf("\n:Unable to delete the file");
}

int main() {
    char choice;
    readstudent();

    while (1) {
        printf("-> Student Portal From <-\t\t\n");
        printf("1. Register New Students\n2. List Of All Students \n");
        printf("3. Update Student From List\n4. Delete All Student From List\n5. Delete Data\n6. !!!Exit!!!\n\n\n");
        choice = getche();
        switch (choice) {
        case '1':
            Registerstudent();
            break;
        case '2':
            Displaystudent();
            break;
        case '3':
            editstudent();
            break;
        case '4':
            deleteallstudent();
            break;
        case '5':
            // delete1(); // You need to provide the implementation for delete1() function
            break;
        case '6':
            printf(". Do You Wanna Exit y/n ?:\n");
            choice = getche();
            if (choice == 'Y' || choice == 'y')
                savestudent();
            return 0;
            break;
        }
    }
}

