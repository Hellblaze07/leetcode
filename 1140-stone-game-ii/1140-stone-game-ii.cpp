class Solution {
public:
    int dp[101][2][101];
    int func(int i,int chance,int m,vector <int>&presum)
    {  int n=presum.size()-1;
        if(i >= n)
        return 0;
        if(dp[i][chance][m] != -1)
        return dp[i][chance][m];
        if(chance == 0)
        {    int maxi=0;
            for(int j=i;j<i+2*m;j++)
            {
               if(j<n)
               {
                maxi=max(maxi,presum[j+1]-presum[i] + func(j+1,!chance,max(j-i+1,m),presum));
               }
            }
            return dp[i][chance][m]=maxi;
        }
        else {
           int mini=1e9;
            for(int j=i;j<i+2*m;j++)
            {
               if(j<n)
               {
                mini=min(mini,0 + func(j+1,!chance,max(j-i+1,m),presum));
               }
            }
            return dp[i][chance][m]= mini;
        }
    return 0;
    }


    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        vector <int> presum(n+1,0);
        for(int i=0;i<n;i++)
        presum[i+1]=presum[i]+piles[i];
        memset(dp,-1,sizeof dp);
        return func(0,0,1,presum);
    }
};