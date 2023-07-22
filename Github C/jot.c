#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct stack
{
    char data[100];
    int tos;
};

int main()
{
    struct stack opstack, poststack;
    printf("%d",&opstack.data[0]);
    printf("\n%d",&poststack.data[0]);
    return 0;
}