#include<stdio.h>
void selectionsort(int n,int a[n]);
int main()
{
	int n,i;
	printf("enter the size of the array:");
	scanf("%d",&n);
	int a[n];
	printf("enter the attay elements:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	selectionsort(n,a);
	printf("sorted list:");
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}
}
void selectionsort(int n,int a[n])
{
	int i,j,min,temp;
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[min])
			{
				min=j;
			}
		}
		if(min!=i)
		{
			temp=a[min];
			a[min]=a[i];
			a[i]=temp;
		}
	}
}
