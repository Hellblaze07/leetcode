class Solution {
public:
     int dp[507][507];
    int func(int l,int r,vector<int>& presum)
    {
        if(l == r)
        return 0;
        if(dp[l][r] != -1)
        return dp[l][r];
        int maxi=0;
        for(int i=l;i<r;i++)
        {
          if(presum[i+1]-presum[l] > presum[r+1]-presum[i+1])
          {
            maxi=max(maxi,presum[r+1]-presum[i+1]+func(i+1,r,presum));
          }
          else if(presum[i+1]-presum[l] < presum[r+1]-presum[i+1])
          {
            maxi=max(maxi,presum[i+1]-presum[l]+func(l,i,presum));
          }
          else {
            maxi=max(maxi,presum[r+1]-presum[i+1]+func(i+1,r,presum));
            maxi=max(maxi,presum[i+1]-presum[l]+func(l,i,presum));
          }
        }
        return dp[l][r]=maxi;
    }
    int stoneGameV(vector<int>& stone) {
        int n=stone.size();
        vector <int> presum(n+1,0);
        memset(dp,-1,sizeof dp);
        for(int i=0;i<n;i++)
        presum[i+1]=presum[i]+stone[i];
        return func(0,n-1,presum);
    }
};