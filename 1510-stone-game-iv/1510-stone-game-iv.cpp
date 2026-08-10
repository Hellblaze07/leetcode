class Solution {
public:
    int func(int n,int chance,vector<vector<int>>&dp)
    {
      if(n<=0)
     {
        if(chance == 0)
        return false;
        else return true;
     }
     if(dp[n][chance] != -1)
     return dp[n][chance];
        for(int i=1;i*i<=n;i++)
      {
        if(chance == 0)
        {
            if(func(n-i*i,!chance,dp) == true)
            return dp[n][chance]= true;
        }
        else {
            if(func(n-i*i,!chance,dp) == false)
            return dp[n][chance]=false;
        }
      }
      if(chance == 0)
      return dp[n][chance]=false;
      else return dp[n][chance]=true;
    }
    bool winnerSquareGame(int n) {
        vector <vector<int>> dp(n+1,vector <int> (2,-1));
        return func(n,0,dp);
    }
};