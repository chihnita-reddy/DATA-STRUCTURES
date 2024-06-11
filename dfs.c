#include<stdio.h>
int n,visited[20],g[20][20];
void dfs(int s)
{
	int i;
	printf("%d",s+1);
	visited[s]=1;
	for(i=0;i<n;i++)
	{
	if(visited[i]==0 && g[i][s]==1)
	dfs(i);
}
}
int main()
{
	int i,j,s;
	printf("enter the number of vertex");
	scanf("%d",&n);
	for(i=0,i<n;i++;)
	{
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
	dfs(0);
}
