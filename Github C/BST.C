#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define TRUE 1
struct node
{
   int info;
   struct node*left;
   struct node*right;
   struct node*father;
};
struct node*root=NULL;//empty binary tree initialized
struct node*getNode(int d)//creat a brand-new single node binary tree
{
   struct node*ptrnew=(struct node*)malloc(sizeof(struct node));
   if(ptrnew==NULL)
   {
      printf("Fatal Error: memory allocation failed.");
      getch();
      exit(0);
   }
   ptrnew->info=d;
   ptrnew->left=ptrnew->right=NULL;
   return ptrnew;
}
void insertNode()
{
   int data;
   struct node*ptrnew,*ptrthis;
   printf("Enter a number to be inserted:");
   scanf("%d",&data);
   ptrnew=getNode(data);
   if(root==NULL)
   {
      root=ptrnew;
      printf("\nNode inserted at the root position.");
   }
   else
   {
      ptrthis=root;
      while(ptrthis!=NULL)
      {
	 if(data<ptrthis->info)
	 {
	   if(ptrthis->left==NULL)
	   {
	      ptrthis->left=ptrnew;
	      break;
	   }
	   else
	      ptrthis=ptrthis->left;
	 }
	 else
	 {
	   if(ptrthis->right==NULL)
	   {
	      ptrthis->right=ptrnew;
	      break;
	   }
	   else
	      ptrthis=ptrthis->right;
	 }
      }
      printf("\nData inserted.");
   }
}
void removeNode()
{
   int data;
   struct node*ptrthis,*ptrparent=NULL;
   printf("Enter a number to be removed:");
   scanf("%d",&data);
   ptrthis=root;
   while(ptrthis!=NULL)
   {
     if(ptrthis->info==data)//this is the condition where we find node to be deleted
     {
       if(ptrthis->left==NULL && ptrthis->right==NULL)//if node is leaf node
       {
	  //this is the node to be removed.
	  if(ptrthis==root)//if root is leaf node then simply set root=NULL;
	    root=NULL;
	  else if(ptrparent->left==ptrthis)
	     ptrparent->left=NULL;
	  else
	    ptrparent->right=NULL;
	  free(ptrthis);
       }
       else if(ptrthis->left==NULL)//if node has right son only
       {
	  if(ptrparent->left==ptrthis)//if deleted node is left son
	     ptrparent->left=ptrthis->right;
	  else
	    ptrparent->right=ptrthis->right;
       }
       else if(ptrthis->right==NULL)//if node has left son only
       {
	  if(ptrparent->left==ptrthis)//if deleted node is left son
	     ptrparent->left=ptrthis->left;
	  else
	     ptrparent->right=ptrthis->left;
       }
       else//if node has both left and right son
       {

       }
     }
     else if(ptrthis->info>data)
     {
	ptrparent=ptrthis;
	ptrthis=ptrthis->left;
     }
     else
     {
       ptrparent=ptrthis;
       ptrthis=ptrthis->right;
     }
   }
   printf("\n%d does not exist in the tree.",data);
}

struct node*getMinNode(struct node*r)
{
	while(r->left!=NULL)
	{
		r=r->left;
		return r;
	}
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
void postorder()
{
   if(r!=NULL)
   {
      preorder(r->left);
      preorder(r->right);
      printf("%d  ",r->info);
   }
}
void search()
{
   int data;
   struct node*ptrthis=root;
   struct node*temp;
   printf("Enter a number to be searched:");
   scanf("%d",&data);
   while(ptrthis!=NULL)
   {
      if(ptrthis->info==data)
      {
	 printf("%d exists in the tree.",data);
	 return;
      }
      else if(ptrthis->info>data)
	ptrthis=ptrthis->left;
      else
	ptrthis=ptrthis->right;
   }
   printf("%d does not exist in the tree.",data);
}

void bstRemove(struct node*r, int d){
if(r==NULL)
{
	printf("%d Doesnt exit in tree.",d);
}
	else if(r->info==d){
		
		if(r->left==NULL && r->right==NULL)
		{
			if(r->father==NULL)
			{
				root=NULL;
			}
		else if(isLeft(r))
		{
			(r->father)->left=NULL;
		}
		else {
			(r->father)->right=NULL;
		}
		free(r);
		}
		
	}
	else if(r->info>d){
		
		
		if(r->left==NULL && r->right==NULL)
		{
			
		}
		else if(r->left==NULL){
			
			
			if(r->father==NULL) //if r is root node
			{
				root=r->right;
				root->father=NULL;
			}
			else if(isLeft(r))
			{
				(r->father)->left=r->right;
				(r->right)->right=r->father;
				
			}
			else{
						(r->father)->right=r->right;
				(r->right)->right=r->father;	
			}
			free(r);
		}
		else if(r->right==NULL)
		{
			
			
				if(r->father==NULL) //if r is root node
			{
				root=r->left;
				root->father=NULL;
			}
			else if(isLeft(r))
			{
				(r->father)->left=r->left;
				(r->left)->father=r->father;
				
			}
			else{
						(r->father)->left=r->right;
				(r->left)->father=r->father;	
			}
			free(r);
			
			
		}
		else //if r has both son
		{
			
			temp=getMinNode(r->right);
			r->info=temp->info;
			temp->info=d;
			bstRemove(temp,d); //recursively
			
			
			
		}
		printf("%d removed from tree",data);
	}
}



void main()
{
   char ch;
   while(TRUE)//repeat forever
   {
     
     printf("Select your choice:\n");
     printf("1. Add \n2. Remove\n3. Inorder \n4. Preorder\n5. Postorder");
     printf("\n6. Search\n7. Exit");
     fflush(stdin);
     ch=getche();
     clrscr();
     switch(ch)
     {
	case '1':insertNode();break;
	case '2':removeNode(root,data);
				printf("ennter dataL:");
				scanf("%d",&data);
			
				break;
	case '3':printf("Tree contains: \n");inorder(root);break;
	case '4':printf("Tree contains: \n");preorder(root);break;
	case '5':printf("Tree contains: \n");postorder(root);break;
	case '6':search();break;
	case '7': return 0;
     }
     getch();
   }
}
