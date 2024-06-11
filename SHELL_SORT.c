#include<stdio.h>
void shell_sort(int a[],int n);
int main()
{
	int n,i;
	printf("enter the size of the array:");
	scanf("%d",&n);
	int a[n];
  printf("enter the array elements:");
  for(i=0;i<n;i++)
  {
  scanf("%d",&a[i]);
  }
  shell_sort(a,n);
  printf("elements after sorting:");
  for(i=0;i<n;i++){
  	printf("%d",a[i]);
  }
}
void shell_sort(int a[],int n){
	int gap,j,i,temp,x=1,k;
	for(gap=n/2;gap>=1;gap=gap/2){
		for(j=gap;j<n;j++)
		{
			for(i=j-gap;i>=0;i=i-gap){
				if(a[i]>a[i+gap]){
					temp=a[i];
					a[i]=a[i+gap];
					a[i+gap]=temp;
				
				}
	
		    else
        {
          break;
        }
      }
    }
  }
  printf("sorted list:");
  for(i=0;i<n;i++)
  {
    printf("%d\n",a[i]);
  }
}
		/*printf("After %d pass :",x++);
		for(k=0;k<n;k++){
			printf("%d",a[k]);
			printf("\n");
	}
}*/
