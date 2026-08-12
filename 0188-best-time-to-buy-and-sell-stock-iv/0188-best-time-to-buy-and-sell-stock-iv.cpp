class Solution {
public:
      int dp[1007][2][101];
      int func(int i,int buy,int cap,vector <int> &prices)
    {
        int n=prices.size();
        if(i >= n || cap == 0)
        return 0;
        if(dp[i][buy][cap] != -1)
        return dp[i][buy][cap];
        int profit=0;
        if(buy)
        {
        profit=max(-prices[i]+func(i+1,0,cap,prices),func(i+1,1,cap,prices));
        }
        else profit=max(prices[i]+func(i+1,1,cap-1,prices),func(i+1,0,cap,prices));
        return dp[i][buy][cap]=profit;
    }
    int maxProfit(int k, vector<int>& prices) {
         memset(dp,-1,sizeof dp);
        return func(0,1,k,prices);
    }
};