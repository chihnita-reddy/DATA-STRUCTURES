#include<stdio.h>
#include<stdlib.h>
#define size 7 
struct node 
{ 
    int data; 
    struct node *next; 
}; 
struct node *chain[size]; 
void init() 
{ 
    int i; 
    for(i = 0; i < size; i++) 
        chain[i] = NULL; 
}   
void insert(int value) 
{ 
    //create a newnode with value 
    struct node *newNode = malloc(sizeof(struct node)); 
    newNode->data = value; 
    newNode->next = NULL; 
 
    //calculate hash key 
    int key = value % size; 
 
    //check if chain[key] is empty 
    if(chain[key] == NULL) 
        chain[key] = newNode; 
    //collision 
    else 
    { 
        //add the node at the end of chain[key]. 
        struct node *temp = chain[key]; 
        while(temp->next!=NULL) 
        { 
            temp = temp->next; 
        } 
        temp->next = newNode; 
    } 
} 
 void deleting(int value)
 {
    int key = value % size; 
   struct node *temp=chain[key],*temp1;
   while(temp!=NULL)
   {
     if(temp->data==value)
     break;
    temp1=temp;
     temp=temp->next;
   }
     temp1++->next = temp->next;
     free(temp);
     
  }

 int search(int value)
 {
   int key=value%size;
   struct node*temp=chain[key];
   while(temp!=NULL)
   {
     if(temp->data==value)
     break;
     else
     temp=temp->next;
   }
   }
void print() 
{ 
    int i; 

    for(i = 0; i < size; i++) 
    { 
        struct node *temp = chain[i]; 
        printf("chain[%d]-->",i); 
        while(temp) 
        { 
            printf("%d -->",temp->data); 
            temp = temp->next; 
        } 
        printf("NULL\n"); 
    } 
} 
int main() 
{ 
int ele;
int flag;
    //init array of list to NULL 
    init(); 
    insert(70); 
    insert(0); 
    insert(3); 
    insert(10); 
    insert(4); 
    insert(5); 
    insert(6);
    insert(23);
    insert(15);
    insert(12);
    print(); 
printf("Enter the element to be searched");
 scanf("%d",&ele);
 flag = search(ele);
 if(flag==ele)
 printf("element found at %d");
 else
 printf("element not found");
deleting(10);
}
