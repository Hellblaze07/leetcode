class Solution {
public:
 int dp[507][507][2];
 int func(int i,int j,vector<int>& piles,int chance)
 {
    if(i > j)
    return 0;
    if(dp[i][j][chance] != -1)
    return dp[i][j][chance];
    if(chance)
    {
        return dp[i][j][chance]=max(piles[i]+func(i+1,j,piles,!chance),piles[j]+func(i,j-1,piles,!chance));
    } 
    else {
        return dp[i][j][chance]=min(piles[i]+func(i+1,j,piles,!chance),piles[j]+func(i,j-1,piles,!chance));
    }

 }
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        memset(dp,-1,sizeof(dp));
        int alice=func(0,n-1,piles,1);
        int sum=0;
        for(auto it:piles)
        sum+=it;
        return alice > sum/2;
    }
};