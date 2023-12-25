#include<stdio.h>
#include<conio.h>
void main (){
int i;
char str[50];
printf("enter Character /string before reverse=");
gets(str); /*its nothing else then scanf*/
i=strrev(str);/* its na thing then reversing the character/string */ 
printf("Reverse is =%s",i);
}
