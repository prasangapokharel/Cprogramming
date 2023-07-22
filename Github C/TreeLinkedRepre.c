#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct tnode
{
    int data;
    struct tnode *left;
    struct tnode *right;
    // struct tnode *father;
};

struct tnode * root = NULL;
struct tnode * getNode(int data){
    struct tnode * newNode;
    newNode = (struct newNode*)malloc(sizeof(struct newNode));
    if (newNode == NULL)
    {
        printf("Memory allocation failed");
        return 0;
    }
    newNode->data = data;
    // newNode->father=NULL;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

int insert()

int main()
{
    int ;
    return 0;
}