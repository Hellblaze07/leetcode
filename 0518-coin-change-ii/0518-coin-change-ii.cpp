class Solution {
public:
    int dp[307][5007];
    int func(int i,int amount,vector <int> &nums)
    {
      if(i  == 0)
      {
        if(amount%nums[0] == 0)
        return 1;
        else return 0;
      }
      if(dp[i][amount] != -1)
      return dp[i][amount];
      int notpick=func(i-1,amount,nums);
      int pick=0;
      if(nums[i]<=amount)
      pick=func(i,amount-nums[i],nums);
      return  dp[i][amount]=pick+notpick;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        memset(dp,-1,sizeof dp);
        return func(n-1,amount,coins);
    }
};