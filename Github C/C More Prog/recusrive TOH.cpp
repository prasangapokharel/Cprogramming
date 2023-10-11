#include<stdio.h>
#include<conio.h>
void TOH(int, char, char, char); //Function prototype
int main(){
int n;
printf("Enter Number\n");
scanf("%d",&n);
TOH(n,'S','I','D');
getch();
}
void TOH(int n, char S, char I, char D){
if(n>0){
TOH(n-1, S, D,I );
printf("Move disk %d from %c to%c\n", n, S, D);
TOH(n-1, I,S,D); 
}
}

