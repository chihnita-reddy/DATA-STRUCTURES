#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
struct node
{
	struct node*left;
	int data;
	struct node*right;
}*stack[30];
int top=-1;

void push(struct node*temp)
{
	top=top+1;
	stack[top]=temp;
}

struct node*pop()
{
	return stack[top--];
}

void postorder(struct node*temp)
{
  if(temp!=NULL)
  {
  postorder(temp->left);
  postorder(temp->right);
  printf("%d",temp->data);

  }
}
void main()
{
	char exp[30];
	int i;
	printf("enter the infix expression");
	scanf("%s",exp);
	for(i=0;exp[i]!='\0';i++)
	{
		if(isalnum(exp[i]))
		{
		struct node*newnode=(struct node*)malloc(sizeof(struct node));
	    newnode->left=NULL;
	    newnode->right=NULL;
	    newnode->data=exp[i];
	    push(newnode);
		
	    }
	else if(exp[i]=='+' || exp[i]=='-' || exp[i]=='*' || exp[i]=='/' || exp[i]=='^')
	{
		struct node*ptr1,*ptr2;
		ptr1=pop();
		ptr2=pop();
		struct node*newnode=(struct node*)malloc(sizeof(struct node));
	    newnode->left=ptr2;
	    newnode->right=ptr1;
	    newnode->data=exp[i];
	    push(newnode);
	}
   }
   postorder(stack[0]);
}
