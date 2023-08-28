#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <cstdlib>
struct node
{
   int info;
   struct node *left;
   struct node*right;
   struct node*father;
};
struct node*root=NULL;//initialize empty binary tree
struct node*getnode(int info)
{
   struct node* ptrnew=(struct node*)malloc(sizeof(struct node));
   if(ptrnew==NULL)
   {
      printf("Memory allocation failed.");
      getch();
      exit(0);
   }
   ptrnew->info=info;
   ptrnew->father=ptrnew->left=ptrnew->right=NULL;
   return ptrnew;
}
void bstInsert()
{
   int n;
   struct node*ptrnew,*parent=NULL,*curr=root;
   printf("Enter a number to be inserted.");
   scanf("%d",&n);
   ptrnew=getnode(n);
   while(1)
   {
      if(curr==NULL)
      {
	 if(root==NULL)
	 {
	   root=ptrnew;
	   printf("%d inserted at the root.",ptrnew->info);
	 }
	 else
	 {
	    if(ptrnew->info<parent->info)
	    {
	      parent->left=ptrnew;
	      printf("%d inserted to the left of %d.",ptrnew->info,parent->info);
	    }
	    else
	    {
	      parent->right=ptrnew;
	      printf("%d inserted to the right of %d.",ptrnew->info,parent->info);
	    }
	    ptrnew->father=parent;
	 }
	 return;
      }
      else if(ptrnew->info<curr->info)
      {
	 parent=curr;
	 curr=curr->left;
      }
      else
      {
	 parent=curr;
	 curr=curr->right;
      }
   }
}
int isLeft(struct node* p)
{
   if((p->father)->left==p)
     return 1;
   else
     return 0;
}
struct node* getMinNode(struct node*r)
{
   while(r->left!=NULL)
     r=r->left;
   return r;
}
//recursive version
void bstRemove(struct node*r,int d)
{
    struct node*temp;
   if(r==NULL)
     printf("%d does not exist in the tree.",d);
   else if(r->info==d)//node found and it needs to be removed.
   {
      if(r->left==NULL && r->right==NULL)//if r is leaf node
      {
	 if(r->father==NULL)//if root node is to be removed
	    root=NULL;
	 else if(isLeft(r))//if deleted node is left son of its father node
	    (r->father)->left=NULL;
	 else //if deleted node is right son of its father node
	   (r->father)->right=NULL;
	 free(r);
      }
      else if(r->left==NULL)//if r has only right son
      {
	 if(r->father==NULL)//if r is root node
	 {
	    root=r->right;
	    root->father=NULL;
	 }
	 else if(isLeft(r))
	 {
	   (r->father)->left=r->right;
	   (r->right)->father=r->father;
	 }
	 else
	 {
	   (r->father)->right=r->right;
	   (r->right)->father=r->father;
	 }
	 free(r);
      }
      else if(r->right==NULL)//if r has only left son
      {
	 if(r->father==NULL)//if r is root node
	 {
	    root=r->left;
	    root->father=NULL;
	 }
	 else if(isLeft(r))
	 {
	   (r->father)->left=r->left;
	   (r->left)->father=r->father;
	 }
	 else
	 {
	   (r->father)->left=r->right;
	   (r->left)->father=r->father;
	 }
	 free(r);
      }
      else//if r has both left and right son
      {
	  temp=getMinNode(r->right);
	  r->info=temp->info;
	  temp->info=d;
	  bstRemove(temp,d);//recursive call
	  return;
      }
      printf("%d removed from the tree.",d);
   }
   else if(r->info>d)//go to left branch
      bstRemove(r->left,d);
   else
      bstRemove(r->right,d);
}
void inorder(struct node*r)
{
   if(r!=NULL)
   {
      inorder(r->left);
      printf("%d  ",r->info);
      inorder(r->right);
   }
}
void preorder(struct node*r)
{
  if(r!=NULL)
  {
     printf("%d  ",r->info);
     preorder(r->left);
     preorder(r->right);
  }
}
void postorder(struct node*r)
{
   if(r!=NULL)
   {
      postorder(r->left);
      postorder(r->right);
      printf("%d   ",r->info);
   }
}
void bstSearch(struct node *r,int target)
{
   if(r==NULL)
      printf("%d does not exist in the tree.",target);
   else if(r->info==target)
      printf("%d found in the tree.",target);
   else if(r->info > target)
      bstSearch(r->left,target);
   else
      bstSearch(r->right,target);
}
void search(struct node*r)
{
   int target;
   printf("Enter a number to be searched:");
   scanf("%d",&target);
   bstSearch(r,target);
}
int main()
{
   char ch;
   int data;
   while(1)
   {
      system("cls");
      printf("Select your option:\n1. Insert\n2. Remove\n3. Inorder Visit");
      printf("\n4 Preorder Visit\n5.Postorder Visit\n6. Search\n7. Exit\n");
      fflush(stdin);
      ch=getche();
      system("cls");
      switch(ch)
      {
	 case '1':bstInsert();break;
	 case '2':
	       printf("Enter a number to be removed");
	       scanf("%d",&data);
	       bstRemove(root,data);break;
	 case '3':inorder(root);break;
	 case '4':preorder(root);break;
	 case '5':postorder(root);break;
	 case '6':search(root);break;
	 case '7':return 0;
      }
      getch();
   }
}
