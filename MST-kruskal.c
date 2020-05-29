#include<stdio.h>
#include<stdlib.h>
#define MAX 999
int cost[9][9],parent[9];
int find(int x)
{
    while(parent[x])
	    x=parent[x];
    return x;
}
int uni(int x,int y)
{
    if(x!=y)
    {
        parent[y]=x;
        return 1;
    }
    return 0;
}
int main()
{
 	int m,min=0,i,j,k,x,y,a,b,n,t=1;
	printf("\nENTER NUMBER OF VERTICES:");
    scanf("%d",&n);
    int cost[n][n];
    printf("\nENTER THE ADJACENCY MATRIX:\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0)
                cost[i][j]=MAX;
        }
    }
    printf("--EDGES OF MIN COST MST ARE--\n");
    while(t<n)
    {
        for(i=1,m=MAX;i<=n;i++)
        {
            for(j=1;j <= n;j++)
            {
                if(cost[i][j] <m)
                {
                    m=cost[i][j];
                    x=a=i;
                    y=b=j;
                }
            }
        }
        a=find(a);
        b=find(b);
        if(uni(a,b))
        {
            printf("--EDGE'S:(%d,%d):=%d\n",x,y,m);
            min+=m;
            t=t+1;
        }
        cost[x][y]=cost[y][x]=999;
    }
    printf("\nMINIMUM COST:%d\n",min);
    return 0;
}
