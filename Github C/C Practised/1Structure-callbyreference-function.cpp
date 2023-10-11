#include <stdio.h>

struct student {
    int id;
    char name[20];
};

void keyvalue(int* id, char* name) { //the function received the addresss passed from the main program function
	printf("enter value:");
    scanf("%d\t%s", id, name); 
}

int main() {
    struct student sc;
    keyvalue(&sc.id, sc.name); //we passed the address of id and name [suppose 1001 & 1002]
    printf("%d\t%s", sc.id, sc.name);
   }

