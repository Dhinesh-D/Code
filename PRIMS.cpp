#include <bits/stdc++.h> 
using namespace std; 
typedef pair<int,int> p;
void prims(vector<p> adj[],int s,int n)
{
    priority_queue<p,vector<p>,greater<p>> pq;
    int dis[n],parent[n];
    bool visit[n];
    for(int i=0;i<n;i++)
    {
        dis[i]=INT_MAX;
        parent[i]=-1;
        visit[i]=true;
    }
    pq.push(make_pair(0,s));
    dis[s]=0;
    parent[s]=s;
    while(!pq.empty())
    {
        int u=pq.top().second;
        pq.pop();
        visit[u]=false;
        for(auto x:adj[u])
        {
            int v=x.first;
            int w=x.second;
            if(visit[v] && dis[v]>w)
            {
                dis[v]=w;
                pq.push(make_pair(dis[v],v));
                parent[v]=u;
            }
        }

    }
    for(int i=1;i<n;i++)
    {
        cout<<parent[i]<<" "<<i<<endl;
    }
    cout<<endl;
}
int main()
{
    int n,x,y,n_e,i,wt;
    cout<<"ENTER NO OF VERTICES:"<<endl;
    cin>>n;
    vector<p> a[n];
    cout<<"ENTER NO OF EDGES:"<<endl;
    cin>>n_e;
    for(i=0;i<n_e;i++)
    {
        cout<<"ENTER X"<<i+1<<":"<<endl;
        cin>>x;
        cout<<"ENTER Y"<<i+1<<":"<<endl;
        cin>>y;
        cout<<"ENTER WEIGHT"<<i+1<<":"<<endl;
        cin>>wt;
        a[x].push_back(make_pair(y,wt));
        a[y].push_back(make_pair(x,wt));
    }
    prims(a,0,n);
}
