class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<int>prev(amount+1,1e9);
        vector<int>curr(amount+1,1e9);
        for(int i=0;i<=amount;i++)
        {
            if(coins[0]*i<=amount)
            prev[coins[0]*i]=i;
            else break;
        }
        for(int i=1;i<n;i++)
        {
            for(int t=0;t<=amount;t++)
            {
                int nottake=prev[t];
                int take=1e9;
                if(coins[i] <= t)
                take=1+curr[t-coins[i]];
                curr[t]=min(take,nottake);
            }
            prev=curr;
        }
        int ans=prev[amount];
        if(ans >= 1e9)
        return -1;
        return ans;
    }
};