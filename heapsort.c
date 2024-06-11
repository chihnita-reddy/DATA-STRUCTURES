#include<stdio.h>
#include<stdlib.h>
void main()
{
  int a[100],n,i;
  printf("Enter the number of elements:");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    scanf("%d",&a[i]);
  }
  heapsort(a,n);
  printf("The elements after sorting :");
  for(i=0;i<n;i++)
  {
    printf(" %d ",a[i]);
  }
}
void heapsort(int a[],int n)
{
  //Construct max heap//
  int i;
  for(i=n/2-1;i>=0;i--)
  {
    heapify(a,n,i);  
  }
  for(i=n-1;i>=0;i--)
  {
    swap(&a[0],&a[i]);
    heapify(a,i,0);
  }
}
  void heapify(int a[],int n,int i)
  {
    int large=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n && a[left]>a[large])
    {
      large=left;
    }
    if(right<n && a[right]>a[large])
    {
      large=right;
    }
    //If large is not a root continue heapify//
    if(large!=i)
    {
      swap(&a[i],&a[large]);
      heapify(a,n,large);
    }
}
void swap(int *a,int *b)
{
  int temp;
  temp=*a;
  *a=*b;
  *b=temp;
}
