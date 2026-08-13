class Solution {
public:
    int dp[5007][2];
    int func(int i,int buy,vector<int>& prices)
    {   int n=prices.size();
        if(i >= n)
        return 0;
        if(dp[i][buy] != -1)
        return dp[i][buy];
        int profit=0;
        if(buy)
        profit=max(-prices[i]+func(i+1,0,prices),func(i+1,1,prices));
        else 
        profit=max(prices[i]+func(i+2,1,prices),func(i+1,0,prices));
        return dp[i][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof dp);
        return func(0,1,prices);
    }
};