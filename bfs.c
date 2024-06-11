#include<stdio.h>
int visited[20],g[20][20],queue[20],front=0,rear=-1,n;

void bfs(int s)
{
	int i;
	for(i=0;i<n;i++)
	if(g[s][i]==1 && visited [i]==0)
	queue[++rear]=i;
	
	if(front<=rear)
	{
		visited[queue[front]]=1;
		bfs(queue[front++]);
	}
}
int main()
{
	int i,j,s;
	printf("enter the number of vertices n the graph");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		queue[i]=0;
		visited[i]=0;
	}
	printf("enter the adjacency matrix");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&g[i][j]);
		}
	}
	printf("enter the starting vertex");
	scanf("%d",&s);
	bfs(s);
	for(i=0;i<n;i++)
	{
		if(visited[i])
		printf("%d-->",i);
		else
		{
			printf("bfs not possible");
			break;
		}
	}
}
