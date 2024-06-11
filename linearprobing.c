#include<stdio.h>
#define size 5
int hashtable[size];
static int count=0;
void initialize()
{
 int i;
 for (i=0;i<size;i++)
 {
  hashtable[i]=-1;
 }
}
void insert(int key)
{
 int j;
 if(count<size)
 {
  j=key%size;
  while(hashtable[j]!=-1)
  {
   j++;
   if(j==size)
   j=0;
  }
  hashtable[j]=key;
  count++;
  
 }
else
printf("Hash table is full");
}
void print()
{
 int i;
 for(i=0;i<size;i++) 
 { 
  printf("the key %d is at index %d\n",hashtable[i],i);
 }
}
int search(int key)
{
 int i,j;
 j=key%size;
 for(i=0;i<size;i++)
 { 
 if(hashtable[j]==key)
  {
  // printf("Element found");
   return j;
  }
  else
  {
   j++;
  if(j==size)
  j=0;
  }
 }
 //printf("Element not found");
 return -1;
}
void delete(int key)
{
 int loc = search(key);
 if(loc!=-1)
 hashtable[loc]=-1;
 else
 printf("/nelement not found for deletion/n");
 }
int main()
{
 int ele;
 int flag;
 initialize();
 insert(10);
 insert(20);
 insert(30);
 insert(35);
 insert(36);
 insert(37);
 insert(38);
 insert(39);
 insert(40);
 insert(50);
 print();
 printf("Enter the element to be searched");
 scanf("%d",&ele);
 flag = search(ele);
 if(flag != -1)
 printf("element found at %d",flag);
 else
 printf("element not found");
 printf("\nEnter the element to be deleted\n");
 scanf("%d",&ele);
 delete(ele);
 print();
 }
 https://www.wattpad.com/1162122275-only-mine-6-personal-slut
