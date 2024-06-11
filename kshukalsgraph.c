#include<stdio.h>
int parent[20]={0},cost[10][10],n,min,mincost=0,ne=1;
int u,v,a,b,i,j;
int find(int i)
{
	while(parent[i])
	i=parent[i];
	return i;
}
int uni(int i,int j)
{
	if(i!=j)
	{
		parent[j]=i;
		return 1;
	}
	else
	return 0;
}
int main()
{
	printf("Enter the number of vertices");
	scanf("%d",&n);
	printf("enter the cost adjacency matrix");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&cost[i][j]);
			if(cost[i][j]==0)
			cost[i][j]=999;
		}
	}
	while(ne<n)
	{
		for(i=1,min=999;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(cost[i][j]<min)
				{
					min=cost[i][j];
					a=u=i;
					b=v=j;
				}
			}
		}
		u=find(u);
		v=find(v);
		if(uni(u,v))
		
		{
			printf("\n edge %d(%d %d) cost :%d",ne++,a,b,min);
			mincost=mincost+min;	
		}
		cost[a][b]=cost[b][a]=999;
	}
		printf("\nfinal mincost %d",mincost);
}
