class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(m+1,vector<int>(107,0)));
        if (grid[0][0] == ')' || grid[n-1][m-1] == '(') return false;
         dp[n-1][m-1][1]=1;
         for(int i=n-1;i>=0;i--)
         {
            for(int j=m-1;j>=0;j--)
            {  
               for(int bal=0;bal<=106;bal++)
                {
                   if(grid[i][j] == '(')
                   { if(bal<106)
                    {
                        if(i<n-1 && dp[i+1][j][bal+1])
                        dp[i][j][bal]=1;
                        if(j<m-1 && dp[i][j+1][bal+1])
                        dp[i][j][bal]=1;
                    }
                   }
                   else {
                    if(bal>0)
                    {
                        if(i<n-1 && dp[i+1][j][bal-1])
                        dp[i][j][bal]=1;
                        if(j<m-1 && dp[i][j+1][bal-1])
                        dp[i][j][bal]=1;
                    }
                   }
                }
            }
         }
        return dp[0][0][0];
    }
};