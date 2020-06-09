def fun(l,k):
    n=len(l)
    dp=[[0 for i in range(n+1)] for j in range(k+1)]
    for i in range(1,k+1):
        for j in range(1,n+1):
            dp[i][j]=dp[i][j-1]
            if l[j-1]<=i and l[j-1]>0:
                dp[i][j]+=dp[i//l[j-1]][j-1]+1
    return dp[k][n]
l=list(map(int,input().split()))
k=int(input())
print(fun(l,k))