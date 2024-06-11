#include<stdio.h>
void insertsort(int n, int a[n]);
int main()
{
	int n,i;
	printf("enter the size of the array::");
	scanf("%d",&n);
	int a[n];
	printf("enter the array elements:");
	for(i=0;i<n;i++){
	scanf("%d",&a[i]);
}
insertsort(n,a);
printf("Sorted array list:");
for(i=0;i<n;i++)
{
	printf("\n%d\n",a[i]);
}
}
void insertsort(int n,int a[n])
{
	int i,j,temp;
	for(i=1;i<n;i++)
	{
	temp=a[i];
	j=i-1;
	while(j>=0 && temp<=a[j])
	{
		a[j+1]=a[j];
		j--;
	}
	a[j+1]=temp;
}
}
