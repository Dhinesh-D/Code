#include<bits/stdc++.h>
using namespace std;
vector<int> p;
int find(vector <int> p,int u){
    if(p[u]==-1)
        return u;
    return find(p,p[u]);
}
main()
{	
	int v,n_e,x,y;
	cout<<"ENTER NO OF VERTICES:"<<endl;
	cin>>v;
	cout<<"ENTER NO OF EDGES:"<<endl;
	cin>>n_e;
	vector<int> a[v];
	for(int i=0;i<n_e;i++){
		cout<<"ENTER X"<<i+1<<":"<<endl;
		cin>>x;
		cout<<"ENTER Y"<<i+1<<":"<<endl;
		cin>>y;
		a[x].push_back(y);
	}
	for(int i=0;i<v;i++){
		p.push_back(-1);
	}
	int flag=0;
	for(int i=0;i<v;i++)
	{
	    for(int j=0;j<a[i].size();j++)
		{
	        x=find(p,i);
	        y=find(p,a[i][j]);
	        if(x==y)
			{
	            flag=1;
	            break;
	        }
	        p[find(p,x)]=find(p,y);
	    }
	}
	if(flag==1)
	    cout<<"\nGIVEN GRAPH CONTAINS CYCLE";
	else
	    cout<<"\nGIVEN GRAPH DOESN'T CONTAINS ANY CYCLE";
	
}
