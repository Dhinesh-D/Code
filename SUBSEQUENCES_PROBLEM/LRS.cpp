#include<bits/stdc++.h>
using namespace std;
string lrs(string s)
{
    int n=s.length();
    int lcs[n+1][n+1],i,j;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=n;j++)
        {
            if(i==0 || j==0)
                lcs[i][j]=0;
            else if(s[i-1]==s[j-1] && i!=j)
                lcs[i][j]=1+lcs[i-1][j-1];
            else
                lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
        }
    }
    i=n;
    j=n;
    string res="";
    while (i>0 && j>0)
    {
        if(lcs[i][j]==lcs[i-1][j-1]+1)
        {
            res+=s[i-1];
            i--;
            j--;
        }
        else if(lcs[i][j]==lcs[i-1][j])
            i--;
        else
            j--;
    }
    reverse(res.begin(),res.end());
    return res;
}
int main()
{
    string s1;
    cin>>s1;
    cout<<lrs(s1);

}