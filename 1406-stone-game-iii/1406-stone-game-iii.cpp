class Solution {
public:
   int dp[50007][2];
    int func(int i,int chance,vector<int>& stone)
    { int n=stone.size();
      if(i >= n)
      {
        return 0;
      }
      if(dp[i][chance] != -1e9)
      return dp[i][chance];
      if(chance == 0)
      {  int maxi=-1e8;
        maxi=max(maxi,stone[i]+func(i+1,!chance,stone));
        if(i+1<n)
        maxi=max(maxi,stone[i]+stone[i+1]+func(i+2,!chance,stone));
        if(i+2<n)
        maxi=max(maxi,stone[i]+stone[i+1]+stone[i+2]+func(i+3,!chance,stone));
        return  dp[i][chance]=maxi;
        }
        else {
        int maxi=1e9;
        maxi=min(maxi,0+func(i+1,!chance,stone));
        if(i+1<n)
        maxi=min(maxi,0+func(i+2,!chance,stone));
        if(i+2<n)
        maxi=min(maxi,0+func(i+3,!chance,stone));
        return dp[i][chance]= maxi;
        }   
      }
    
    string stoneGameIII(vector<int>& stone) {
        int sum=accumulate(stone.begin(),stone.end(),0);
        for(int i = 0; i <= stone.size(); i++) {
            dp[i][0] = -1e9;
            dp[i][1] = -1e9;
        }
        int ali=func(0,0,stone);
        if(ali*2 > sum)
        return "Alice";
        else if(ali*2<sum)
        return "Bob";
        else return "Tie";
    }
};