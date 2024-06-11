#include<stdio.h>
int visited[20]={0},mincost=0,min,cost[10][10];
int a,b,u,v,n,ne=1;
int i,j;
int main()
{
	printf("enter the number of vertices");
	scanf("%d",&n);
	printf("enter the cost adjacency matrix");
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	{
		scanf("%d",&cost[i][j]);
		if(cost[i][j]==0)
		{
			cost[i][j]=999;	
		}
	}
	visited[1]=1;
	while(ne<n)
	{
		for(i=1,min=999;i<=n;i++)
		for(j=1;j<=n;j++)
			if(cost[i][j]<min)
				if(visited[i]!=0)
				{
					min=cost[i][j];
					a=u=i;
					b=v=j;
				}
				if(visited[u]==0 || visited[v]==0)
				{
					printf("\n edge %d(%d %d) cost :%d",ne++,a,b,min);
					mincost=mincost+min;
					visited[b]=1;
				}
				cost[a][b]=cost[b][a]=999;
    } 
	printf("the final mincost of spaning tree %d",mincost);
}
