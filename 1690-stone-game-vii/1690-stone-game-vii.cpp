class Solution {
public:
    vector<int> ar;
    vector<int> pre;
    int sum;
    int dp[1005][1005];
    int get(int l,int r){
        if(l>r)return 0;
        if(dp[l][r]!=-1)return dp[l][r];
        int mx=INT_MIN;
        // cout<<pre[r+1]-pre[l]<<' ';
        mx=max(mx,pre[r+1]-pre[l+1]-get(l+1,r));
        mx=max(mx,pre[r]-pre[l]-get(l,r-1));
        return dp[l][r]=mx;
    }
    int stoneGameVII(vector<int>& stones) {
        ar=stones;
        int n=stones.size();
        pre.resize(n+1);
        memset(dp,-1,sizeof dp);
        for(int i=0;i<n;i++)pre[i+1]=pre[i]+stones[i];
        // for(auto &i:pre)cout<<i<<' ';
        sum=accumulate(stones.begin(),stones.end(),0);
        return get(0,n-1);
    }
};