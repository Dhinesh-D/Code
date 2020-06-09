#include<bits/stdc++.h>
using namespace std;
typedef struct
{
    int capacity;
    int value;
}st;
int knapsack(st arr[],int W,int n)
{
    int k[n+1][W+1];
    for(int i=0;i<=n;i++)
    {
        for(int w=0;w<=W;w++)
        {
            if(i==0 || w==0)
                k[i][w]=0;
            else if(arr[i-1].capacity<=w)
                k[i][w]=max(arr[i-1].value+k[i-1][w-arr[i-1].capacity],k[i-1][w]);
            else
                k[i][w]=k[i-1][w];
        }
    }
    return k[n][W];
}
int main()
{
    int n,c,v,tc,tv=0;
    cout<<"Enter the total capacity"<<endl;
    cin>>tc;
    cout<<"Enter the no. of items "<<endl;
    cin>>n;
    st arr[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter the capacity"<<endl;
        cin>>c;
        cout<<"Enter the value"<<endl;
        cin>>v;
        arr[i].capacity=c;
        arr[i].value=v;
    }
    cout<<knapsack(arr,tc,n);
}