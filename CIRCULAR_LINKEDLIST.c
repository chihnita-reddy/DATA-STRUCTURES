#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node *prev;
	int data;
	struct node *next;
};
struct node *first_node,*current_node;
void insert(int x)
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter the data to be inserted:");
	scanf("%d",&x);
	newnode->data=x;
	newnode->next=NULL;
	if(first_node==NULL)
	{
		first_node=newnode;
		current_node=newnode;
		current_node->next=first_node;
	}
	else
	{
		current_node->next=newnode;
		current_node=newnode;
		current_node->next=first_node;
	}
}
void display()
{
	struct node *temp;
	temp=first_node;
	if(temp==NULL)
	{
		printf("No elements exist");
	}
	do
	{
		printf("\n%d\n",temp->data);
		temp=temp->next;
	}while(temp!=first_node);
}
void insertbegin()
{
  int x;
  struct node*newnode;
  newnode=(struct node*)malloc(sizeof(struct node));
  printf("enter the data to insert at the beginning\n");
  scanf("%d",&x);
  newnode->data=x;
  newnode->next=first_node;
  first_node=newnode;
  current_node->next=newnode;
}
void insertend()
{
	int x;
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter the element to be inserted at the end:");
	scanf("%d",&x);
	current_node->next=newnode;
	current_node=newnode;
	newnode->next=first_node;
	newnode->data=x;
}
void insertbykey(int key)
{
  int status=0;
  struct node*temp;
  temp=first_node;
  while(temp!=NULL)
  {
    if(temp->data==key)
    {
      status=1;
      break;
    }
    temp=temp->next;
  }
  int x;
  struct node*newnode;
  newnode=(struct node*)malloc(sizeof(struct node));
  printf("enter the element to insert ");
  scanf("%d",&x);
  newnode->data=x;
  newnode->prev=temp;
  newnode->next=temp->next;
  temp->next=newnode;
  temp=newnode;
}
void insertbyposition()
{
  int status=0,position,count=0,a;
  printf("enter the position before placing\n");
  scanf("%d",&position);
  struct node*temp;
  temp=first_node;
  while(temp!=NULL)
  {
    if(count!=position-1)
    {
      count++;
      
    }
    else
    {
      break;
    }
    temp=temp->next;
  }
  int x;
  struct node*newnode;
  newnode=(struct node*)malloc(sizeof(struct node));
  printf("enter the element to insert ");
  scanf("%d",&x);
  newnode->data=x;
  newnode->prev=temp;
  newnode->next=temp->next;
  temp->next=newnode;
  temp=newnode;
}
void deletebegin()
{
	struct node *temp;
	temp=first_node;
    first_node=first_node->next;
    current_node->next=first_node;
    free(temp);
}
void deleteend()
{
	struct node *temp;
	temp=first_node;
	while(temp->next!=first_node)
	{
		current_node=temp;
		temp=temp->next;
	}
    current_node->next=first_node;
    free(temp);
}
void main()
{
	insert(1);
	insert(2);
	insert(3);
	display();
	insertbegin();
	display();
	int key;
    printf("enter the key to search");
    scanf("%d",&key);
	insertbykey(key);
	display();
	insertend();
	display();
	printf("\ndelete begin\n");
	deletebegin();
	display();
	printf("\ndelete end\n");
	deleteend();
	display();
	insertbyposition();
	display();
}
