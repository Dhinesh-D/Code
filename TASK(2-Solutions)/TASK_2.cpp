#include <bits/stdc++.h> 
using namespace std; 
typedef pair<int,pair<int,int>> p;
bool comp2(p a,p b)
{
    return a.second.second>b.second.second;
}
bool comp1(p a,p b)
{
    return a.second.first<b.second.first;
}
int main()
{
    int t;
    cin>>t;
    for(int k=0;k<t;k++)
    {
        int i,n,val;
        vector<int> x,y;
        vector<p> temp;
        int d=0,c=0;
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>val;
            x.push_back(val);
        }
        for(i=0;i<n;i++)
        {
            cin>>val;
            y.push_back(val);
        }
        for(i=0;i<n;i++) 
        {
            temp.push_back(make_pair(i,make_pair(x[i],y[i])));
        }
        sort(temp.begin(),temp.end(),comp2);
        sort(temp.begin(),temp.end(),comp1);
        int m;
        cin>>m;
        map<int,int> mp;
        vector<bool> v;
        for(i=0;i<n;i++)
        {
            mp[i]=i;
            v.push_back(false);
        }
        for(i=0;i<m;i++)
        {
            int a,b;
            cin>>a;
            cin>>b;
            mp[b-1]=a-1;
        }
        while(temp.size())
        {
            for(i=0;i<n;i++)
            {
                int z=temp[i].first;
                if(mp[z]==z || v[mp[z]])
                {
                    v[z]=true;
                    d+=temp[i].second.first;
                    c+=d*temp[i].second.second;
                    temp.erase(temp.begin()+i);
                    n-=1;
                    break;
                }
            }
        }
        cout<<c<<endl;
    }
}