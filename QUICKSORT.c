#include<stdio.h> 
void quicksort(int a[],int l, int h) 
{ 
  int i,j,pivot,temp; 
  if(l<h) 
  { 
    pivot=l,i=1,j=h; 
    while(i<j) 
    { 
      while(a[i]<=a[pivot] && i<j) 
      i++; 
      while(a[j]>a[pivot]) 
      j--; 
      if(i<j) 
      { 
        // interchange a[i] and a[j] 
        temp=a[i]; 
        a[i]=a[j]; 
        a[j]=temp; 
      } 
       
    } 
    // interchange a[j] with a[pivot] element  
    temp=a[j]; 
    a[j]=a[pivot]; 
    a[pivot]=temp; 
    quicksort(a,0,j-1); // left sublist  
    quicksort(a,j+1,h); // right sublist 
   } 
} 
int main() 
{ 
  int i,n; 
  printf("enter the size"); 
  scanf("%d",&n); 
  int a[n]; 
  printf("enter the elements"); 
  for(i=0;i<n;i++) 
  scanf("%d",&a[i]); 
  // function calling 
  quicksort(a,0,n-1); 
  printf("sorted list"); 
  for(i=0;i<n;i++) 
  printf("\t%d",a[i]); 
}
