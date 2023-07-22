#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct tree
{
    int info;
    struct tree *left;
    struct tree *right;
};
struct tree* root=NULL;
struct tree * getnode(int data){
    struct tree * ptrnew;
    ptrnew = (struct tree*)malloc(sizeof(struct tree));
    if (ptrnew==NULL)
    {
        printf("Memory allocation failed");
        exit(0);
    }
    ptrnew->info = data;
    ptrnew->left= ptrnew->right=NULL;
    return ptrnew;    
}
int insert(struct tree* ptrthis,int data){
    if (ptrthis == NULL)
    {
        root = getnode(data);
    }
    else if (data<ptrthis->info)
    {
        if (ptrthis->left==NULL)//if current node have no left son 
        {
            ptrthis->left=getnode(data);//then make new node as left son..
        }
        else
            insert(ptrthis->left,data);        
    }
    else{
        // if (ptrthis->info==data)
        // {   
        //     printf("\nDuplicate entry..");
        // }
        if (ptrthis->right==NULL)//if current node have no right son
        {
            ptrthis->right=getnode(data);
        }
        else{
            insert(ptrthis->right,data);
        }
        
    }   

}

int inorder(struct tree*ptrthis){
    if (ptrthis!=NULL)
    {
        inorder(ptrthis->left);
        printf("%d\t",ptrthis->info);
        inorder(ptrthis->right);
    }
    
}
int main()
{
    int i,n;
    for (int i = 0; i < 5; i++)
    {
        printf("\nEnter a number: ");
        scanf("%d",&n);
        insert(root,n);
    }
    printf("\nTree constructed\nThe binary search tree is: \n");
    inorder(root);    
    return 0;
}