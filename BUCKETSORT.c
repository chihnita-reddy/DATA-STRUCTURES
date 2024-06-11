#include <stdio.h>  
int getMax(int a[], int n)  
{  
  int max = a[0],i;  
  for ( i = 1; i < n; i++)  
    if (a[i] > max)  
      max = a[i];  
  return max;  
}  
void bucket(int a[], int n)   
{  
  int max = getMax(a, n);  
  int bucket[max], i,j;  
  for ( i = 0; i <= max; i++)  
  {  
    bucket[i] = 0;  
  }  
  for ( i = 0; i < n; i++)  
  {  
    bucket[a[i]]++;  
  }  
  for ( i = 0, j = 0; i <= max; i++)  
  {  
    while (bucket[i] > 0)  
    {  
      a[j++] = i;  
      bucket[i]--;  
    }  
  }  
}  
void printArr(int a[], int n)   
{  
int i;
  for ( i = 0; i < n; ++i)  
    printf("%d  ", a[i]);  
}  
int main()  
{  
  int n,i;
  printf("Enter size of an array: ");
  scanf("%d",&n);
  int a[n];  
  printf("Enter elements in an array: ");
  for(i=0;i<n;i++)
  scanf("%d",&a[i]);
  printf("Before sorting array elements are - \n");  
  printArr(a, n);  
  bucket(a, n);  
  printf("\nAfter sorting array elements are - \n");  
  printArr(a, n);  
} 
