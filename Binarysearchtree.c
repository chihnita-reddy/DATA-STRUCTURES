#include<stdio.h>
#include<stdlib.h>
struct BST
{
  int data;
  struct BST *left;
  struct BST *right;
}*root=NULL;
void insert(struct BST *temp,struct BST *newnode);
void create()
{
  struct BST *newnode;
  newnode=(struct BST*)malloc(sizeof(struct BST));
  newnode->left=NULL;
  newnode->right=NULL;
  printf("enter the data element:");
  scanf("%d",&newnode->data);
  if(root==NULL)
  root=newnode;
  else
  insert(root,newnode);
}
void insert(struct BST *temp,struct BST *newnode)
{
  if(newnode->data<temp->data)
  {
    if(temp->left==NULL)
     temp->left=newnode;
    else
    insert(temp->left,newnode);
  }
  if(newnode->data>temp->data)
  {
    if(temp->right==NULL)
    temp->right=newnode;
    else
    insert(temp->right,newnode);
  }
}
void inorder(struct BST *temp)
{
  if(temp!=NULL)
  {
    inorder(temp->left);
        printf("%d ",temp->data);
        inorder(temp->right);
  }
}
void preorder(struct BST *temp)
{
  if(temp!=NULL)
  {
    printf("%d ",temp->data);
    preorder(temp->left);
    preorder(temp->right);
  }
}
int findmin(struct BST *temp)
{
  while(temp->left!=NULL)
  {
    temp=temp->left;
  }
  return(temp->data);
}
struct BST *findminsucc(struct BST *temp)
{
  while(temp->left!=NULL)
  {
    temp=temp->left;
  }
  return(temp);
}
int findmax(struct BST *temp)
{
  while(temp->right!=NULL)
  {
    temp=temp->right;
  }
  return(temp->data);
}
struct BST *findmaxpre(struct BST *temp)
{
  while(temp->right!=NULL)
  {
    temp=temp->right;
  }
  return(temp);
}
int search(struct BST *temp,int x)
{
  if(temp==NULL)
  return 0;
  else if(temp->data==x)
  return 1;
  else if(x<temp->data)
  search(temp->left,x);
  else
  search(temp->right,x);
}
void delete(struct BST *root,int key)
{
  struct BST *parent,*current;
  parent=NULL;
  current=root;
  //search for key in BST
  while(current!=NULL && current->data!=key)
  {
    parent=current;
    if(key<current->data)
    {
      current=current->left;
    }
    else
    {
      current=current->right;
    }
    // If the key not found in the tree 
    if(current==NULL)
    return ;
  }
    //  case 1: Node having zero children
      if(current->left==NULL && current->right==NULL)
      {
        if(current!=root)
        {
          if(parent->left==current)
          parent->left=NULL;
          else
          parent->right=NULL;
    }
    else
    {
      root=NULL;
    }
  }
  //case 2: Node having 2 children
  else if(current->left!=NULL && current->right!=NULL)
  {
    struct BST *succ;
    succ=findminsucc(current->right);
    int value=succ->data;
    delete(root,value);
    current->data=value;
   } 
   // case 3: Node having single child
   else
   {
     struct node *child;
     child=(current->left!=NULL)?current->left:current->right;
     if(current!=root)
     {
     if(parent->left==current)
     parent->left=child;
     else
     parent->right=child;
      }
      else
      {
        root=child;
    }
    //  case 1: Node having zero children
      if(current->left==NULL && current->right==NULL)
      {
        if(current!=root)
        {
          if(parent->right==current)
          parent->right=NULL;
          else
          parent->left=NULL;
    }
    else
    {
      root=NULL;
    }
  }
  //case 2: Node having 2 children
  else if(current->left!=NULL && current->right!=NULL)
  {
    struct BST *pre;
    pre=findmaxpre(current->right);
    int value=pre->data;
    delete(root,value);
    current->data=value;
   } 
   // case 3: Node having single child
   else
   {
     struct node *child;
     child=(current->right!=NULL)?current->right:current->left;
     if(current!=root)
     {
     if(parent->right==current)
     parent->right=child;
     else
     parent->left=child;
      }
      else
      {
        root=child;
    }
   }  
}
void main()
{
  int nodes,i,x,key;
  printf("Enter the number of nodes:");
  scanf("%d",&nodes);
  for(i=0;i<nodes;i++)
  create();
  printf("\nThe inorder sequence is");
  inorder(root);
  printf("\nThe preorder sequence is");
  preorder(root);
  printf("\nThe min element is");
  printf("%d",findmin(root));
  printf("\nThe max element is");
  printf("%d",findmax(root));
  printf("\nEnter the key element");
  scanf("%d",&x);
  if(search(root,x))
  printf("Element found\n");
  else
  printf("Element not found\n");
  printf("\nEnter the element to delete ");
  scanf("%d",&key);
  delete(root,key);
  printf("\nEnter the element to delete ");
  scanf("%d",&key);
  delete(root,key);
  inorder(root);
  }
}
