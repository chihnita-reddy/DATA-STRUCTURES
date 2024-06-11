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
	newnode->prev=NULL;
	newnode->next=NULL;
	if(first_node==NULL)
	{
		first_node=newnode;
		current_node=newnode;
	}
	else
	{
		current_node->next=newnode;
		newnode->prev=current_node;
		current_node=newnode;
	}
}
void displayforward()
{
	struct node *temp;
	temp=first_node;
	while(temp!=NULL)
	{
		printf("\n%d\n",temp->data);
		temp=temp->next;
	}
}
void displaybackward()
{
	struct node *temp;
	temp=current_node;
	while(temp!=NULL)
	{
		printf("\n%d\n",temp->data);
		temp=temp->prev;
	}
}
void insertbegin()
{
	int x;
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("enter the data to insert at the beginning\n");
    scanf("%d",&x);
    newnode->data=x;
    first_node->prev = newnode;
    newnode->next=first_node;
    newnode->prev = NULL;
    first_node=newnode;
}
void insertend()
{
	int x;
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter the element to be inserted at last:");
	scanf("%d",&x);
	newnode->data=x;
	newnode->prev=current_node;
	newnode->next=NULL;
	current_node->next=newnode;
	current_node=newnode;
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
 void search()
     {
       struct node*temp;
       temp=first_node;
       int key;
       printf("Enter the key element to search:");
       scanf("%d",&key);
       while(temp!=NULL)
         {
           if(temp->data==key)
           {
             printf("Found");
             break;
         }
           temp=temp->next;
       }
       if(temp->data!=key)
       printf("Not found");
   }
   int sum_of_elements() 
{ 
   struct node *temp; 
   temp=first_node; 
   int sum=0; 
   while(temp!=NULL) 
   { 
       sum=sum+temp->data; 
       temp=temp->next; 
   } 
   printf("sum of elements is %d\n",sum); 
} 
int count_of_elements() 
{ 
  struct node*temp; 
  int ct=0; 
  temp=first_node; 
  while(temp!=NULL) 
  { 
    ct++; 
    temp=temp->next; 
  } 
  printf("\n numbers of elements present in the list%d\n",ct); 
}
int no_of_occurence(int n) 
{ 
    int count=0; 
    struct node *temp; 
    temp=first_node; 
    while(temp!=NULL) 
  { 
        if(temp->data==n) 
    { 
            ++count; 
        } 
        temp=temp->next; 
    } 
    printf("number of times elments repeated is %d\n",count); 
} 
int max_element() 
{ 
    struct node *temp; 
    temp=first_node; 
    int max=0; 
    while(temp!=NULL) 
  { 
        if(temp->data>max) 
    { 
            max=temp->data; 
             
        } 
        temp=temp->next; 
    } 
    printf("the maximum element is %d\n",max); 
} 
int min_element() 
{ 
    struct node *temp; 
    temp=first_node; 
    int min=first_node->data; 
    while(temp!=NULL) 
  { 
        if(temp->data<min) 
    { 
            min=temp->data; 
        } 
        temp=temp->next; 
    } 
    printf("the minimum element is %d\n",min); 
}
void deletebegin()
{
  struct node*temp;
  temp=first_node;
  first_node=first_node->next;
  free(temp);
}
void deleteend()
{
  struct node*temp,*temp1;
  temp=first_node;
  while(temp->next!=NULL)
  {
    temp1=temp;
    temp=temp->next;
  }
    current_node=temp1;
    temp1->next=NULL;
  free(temp);
}
void main()
{
  insert(20);
  insert(30);
  insert(40);  
  displayforward();
  displaybackward();
  insertbegin();
  displayforward();
  insertend();
  displayforward();
  int key;
  printf("enter the key to search");
  scanf("%d",&key);
  insertbykey(key);
  displayforward();
  insertbyposition();
  displayforward();
  sum_of_elements();
     count_of_elements(); 
   int n;
     printf("enter the element to check how many times it repeated :\n"); 
     scanf("%d",&n); 
     no_of_occurence(n); 
     displayforward();
     max_element(); 
     displayforward();
     min_element(); 
     displayforward();
  printf("\ndelete begin\n");
  deletebegin();
  displayforward();
  printf("\ndelete end\n");
  deleteend();
  displayforward(); 
 }
