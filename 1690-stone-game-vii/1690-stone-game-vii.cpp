class Solution {
public:
    vector<int> ar;
    vector<int> pre;
    int dp[1005][1005][2];
    int func(int l,int r,int chance){
        if(r - l == 1)
        {
            if(chance == 0)
            return max(ar[l],ar[r]);
        }
        if(r == l)
        return 0;
        if(dp[l][r][chance]!=-1)return dp[l][r][chance];
        int mx=INT_MIN;
        // cout<<pre[r+1]-pre[l]<<' ';
        if(chance == 0)
      {  mx=max(mx,func(l+1,r,!chance));
        mx=max(mx,func(l,r-1,!chance));
        return dp[l][r][chance]=mx;
      }
      else {
        int mx=INT_MAX;
        mx=min(mx,ar[l]+func(l+1,r,!chance));
        mx=min(mx,ar[r]+func(l,r-1,!chance));
       return dp[l][r][chance]=mx;
      }
      return 0;
    }
    int stoneGameVII(vector<int>& stones) {
        ar=stones;
        int n=stones.size();
        pre.resize(n+1);
        memset(dp,-1,sizeof dp);
        return func(0,n-1,0);
    }
};