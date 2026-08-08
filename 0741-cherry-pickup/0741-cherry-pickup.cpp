class Solution {
public:
    int dp[57][57][57];
    int func(int r,int c,int c1,vector<vector<int>>& grid)
    {  int n=grid.size();
      int r1=r+c-c1;
      if(r == n || r1 == n || c == n || c1 == n || grid[r][c] == -1 || 
      grid[r1][c1] == -1)
      return -1e8;
      if( r== n-1 && c == n-1)
      return grid[r][c];
      if(dp[r][c][c1] != -1)
      return dp[r][c][c1];
      int ans=grid[r][c];
      if(c != c1)
      ans+=grid[r1][c1];
      int maxi=INT_MIN;
      maxi=max(maxi,func(r+1,c,c1,grid));
      maxi=max(maxi,func(r+1,c,c1+1,grid));
      maxi=max(maxi,func(r,c+1,c1,grid));
      maxi=max(maxi,func(r,c+1,c1+1,grid));
      return dp[r][c][c1]=maxi+ans;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        int ans= func(0,0,0,grid);
        return max(0,ans);
    }
};