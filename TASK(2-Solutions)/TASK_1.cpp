#include <bits/stdc++.h> 
using namespace std; 
typedef pair<int,int> p;
queue<p> q;
#define MAX 250
int G[MAX][MAX],b,a;
bool temp[MAX][MAX];
int arr[][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
int f=0;
void func(int x,int y)
{
    temp[x][y]=true;
    f+=1;
   for(int i=0;i<8;i++)
    {
        int u=x-+arr[i][0];
        int v=y-arr[i][1];
        if(u>-1 && u<b && v>-1 && v<a && G[u][v] && !temp[u][v])
            q.push(make_pair(u,v));
    }
    while(!q.empty())
    {
        p k=q.front();
        q.pop();
        if(!temp[k.first][k.second])
            func(k.first,k.second);
    }

}
int main()
{
    int t,k;
    cin>>t;
    for(k=0;k<t;k++)
    {
        cin>>b;
        cin>>a;
        int min1=INT_MIN;
        for(int i=0;i<b;i++)
        {
            for(int j=0;j<a;j++)
            {
                cin>>G[i][j];
            }
        }
        memset(temp,false,b*a);
        for(int i=0;i<b;i++)
        {
            for(int j=0;j<a;j++)
            {
                if(G[i][j] && !temp[i][j])
                {
                    func(i,j);
                    min1=max(min1,f);
                    f=0;
                }
            }
        }
        cout<<min1<<endl;
    }
}