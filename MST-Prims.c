#include<stdio.h>
void main() 
{
	int visited[10]= {0},min_cost=0;
	int a,b,x,y,n,i,j,t=1,m=0;
	printf("\n Enter the number of nodes:");
	scanf("%d",&n);
	int cost[n][n];
	printf("\n Enter the adjacency matrix:\n");
	for (i=1;i<=n;i++)
	{
	  for (j=1;j<=n;j++) 
	  {
		scanf("%d",&cost[i][j]);
		if(cost[i][j]==0)
		    cost[i][j]=999;
		}
	}
	visited[1]=1;
	printf("\n");
	while(t<n) 
	{
		for (i=1,m=999;i<=n;i++)
		   for (j=1;j<=n;j++)
		   if(cost[i][j]<m)
		    {
			  if(visited[i]!=0) 
				{
					m=cost[i][j];
					a=x=i;
					b=y=j;
				}
			}
			if(visited[x]==0 || visited[y]==0) 
			{
			printf("\nEDGE'S:(%d %d) cost:%d",a,b,m);
			min_cost+=m;
			t=t+1;
			visited[b]=1;
			}
			cost[a][b]=cost[b][a]=999;
	}
	printf("\n\nMINIMUM COST:%d",min_cost);
}
