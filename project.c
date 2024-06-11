#include<stdio.h>
struct avl
{
	int data;
	struct avl *left,*right;
	int ht;
};

struct avl *insert(struct avl *,int);
struct avl *Delete(struct avl *,int);
void preorder(struct avl *);
void inorder(struct avl *);
void postorder(struct avl *);
int height( struct avl *);
struct avl *rotateright(struct avl *);
struct avl *rotateleft(struct avl *);
struct avl *RightRight(struct avl *);
struct avl *LeftLeft(struct avl *);
struct avl *LeftRight(struct avl *);
struct avl *RightLeft(struct avl *);
int BF(struct avl *);

int main()
{
	struct avl *root=NULL;
	int x,n,i,op;
	do
	{
		printf("\n1.Create:");
		printf("\n2.Insert:");
		printf("\n3.Delete:");
		printf("\n4.Print:");
		printf("\n5.Quit:");
		printf("\n\nEnter Your Choice");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
				printf("\nEnter no.of elements:");
				scanf("%d",&n);
				printf("\nEnter tree data:");
				root=NULL;
				for(i=0;i<n;i++)
				{
					scanf("%d",&x);
					root=insert(root,x);
				}
				break;
				case 2:
					printf("\nEnter a data:");
					scanf("%d",&x);
					root=insert(root,x);
					break;
					case 3:
						printf("\nEnter a data:");
						scanf("%d",&x);
						break;
						case 4:
							printf("\nPreorder sequence:\n");
							preorder(root);
							printf("\n\nInorder sequence:\n");
							inorder(root);
							printf("\n\nPostorder sequence:\n");
							postorder(root);
							printf("\n");
							break;
		}
	}
	while(op!=5);
	return 0;
}
struct avl * insert(struct avl *temp,int x)
{
	if(temp==NULL)
	{
		temp=(struct avl*)malloc(sizeof(struct avl));
		temp->data=x;
		temp->left=NULL;
		temp->right=NULL;
	}
	else
	if(x > temp->data)
	{
		temp->right=insert(temp->right,x);
		if(BF(temp)==-2)
		if(x>temp->right->data)
		temp=RightRight(temp);
		else
		temp=RightLeft(temp);
    }
	else
	if(x<temp->data)
	{
		temp->left=insert(temp->left,x);
		if(BF(temp)==2)
		if(x < temp->left->data)
		temp=LeftLeft(temp);
		else
		temp=LeftRight(temp);
	}
	temp->ht=height(temp);
	return(temp);
}

struct avl * Delete(struct avl *temp,int data)
{
	struct avl *p;
	if(temp==NULL)
	{
		return NULL;
	}
	else
	if(data > temp->data)
	{
			temp->right=Delete(temp->right,data);
	        if(BF(temp)==2)
        	if(BF(temp->left)>=0)
        	temp=LeftLeft(temp);
	        else
	        temp=LeftRight(temp);	
	}
	else
	if(data<temp->data)
	{
			temp->left=Delete(temp->left,data);
	        if(BF(temp)==-2)
	        if(BF(temp->right)<=0)
	        temp=RightRight(temp);
	        else
	        temp=RightLeft(temp);
	}
	else
	{
		//data to be deleted is found
		if(temp->right!=NULL)
		{
			//delete its inorder succesor
			p=temp->right;
			while(p->left!=NULL)
			p=p->left;
			temp->data=p->data;
			temp->right=Delete(temp->right,temp->data);
			if(BF(temp)==2)
			if(BF(temp->left)>=0)
			temp=LeftLeft(temp);
			else
			temp=LeftRight(temp);
		}
		else
		return(temp->left);
	}
	temp->ht=height(temp);
	return(temp);
}

int height(struct avl *temp)
{
	int lh,rh;
	if(temp==NULL)
	return(0);
	if(temp->left==NULL)
	lh=0;
	else
	lh=1+temp->left->ht;
	if(temp->right==NULL)
	rh=0;
	else
	rh=1+temp->right->ht;
	if(lh>rh)
	return(lh);
	return(rh);
}

struct avl * rotateright(struct avl *x)
{
	struct avl *y;
	y=x->left;
	x->left=y->right;
	y->right=x;
	x->ht=height(x);
	y->ht=height(y);
	return(y);
}

struct avl * rotateleft(struct avl *x)
{
    struct avl *y;
	y=x->right;
	x->right=y->left;
	y->right=x;
	x->ht=height(x);
	y->ht=height(y);
	return(y);
}

struct avl * RightRight(struct avl *temp)
{
	temp=rotateleft(temp);
    return(temp);
}

struct avl * LeftLeft(struct avl *temp)
{
	temp=rotateright(temp);
    return(temp); 
}

struct avl * LeftRight(struct avl *temp)
{
	temp->left=rotateleft(temp->left);
    temp=rotateright(temp);
    return(temp);
}

struct avl * RightLeft(struct avl *temp)
{
	temp->right=rotateright(temp->right);
    temp=rotateleft(temp);
    return(temp);
}

int BF(struct avl *temp)
{
	int lh,rh;
	if(temp==NULL)
	return(0);
	
	if(temp->left==NULL)
	lh=0;
	else
	lh=1+temp->left->ht;
	
	if(temp->right==NULL)
	rh=0;
	else
	lh=1+temp->right->ht;
	
	return(lh-rh);
}

void preorder(struct avl *temp)
{
	if(temp!=NULL)
	{
		printf("%d(Bf=%d)",temp->data,BF(temp));
        preorder(temp->left);
        preorder(temp->right);
	}
}

void inorder(struct avl *temp)
{
	if(temp!=NULL)
	{
		preorder(temp->left);
		printf("%d(Bf=%d)",temp->data,BF(temp));
        preorder(temp->right);
	}
}

void postorder(struct avl *temp)
{
	if(temp!=NULL)
	{
		preorder(temp->left);
        preorder(temp->right);
		printf("%d(Bf=%d)",temp->data,BF(temp));
	}
}

