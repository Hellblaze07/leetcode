class Solution {
public:
    int dp[107][10007];
    int func(int i,int n,vector <int> &ans)
    {
        if(i == 0)
        return n/ans[i];
        if(dp[i][n] != -1)
        return dp[i][n];
        int nottake=func(i-1,n,ans);
        int take=1e8;
        if(ans[i] <= n)
        take=1+func(i,n-ans[i],ans);
        return dp[i][n]=min(nottake,take);
    }
    int numSquares(int n) {
        int i=1;
        vector <int> ans;
        while(i*i<=n)
        {ans.push_back(i*i);
        i++;}
        memset(dp,-1,sizeof dp);
        return func(ans.size()-1,n,ans);
    }
};