class Solution {
public:
    bool helper(int i,int j,int balance,vector<vector<char>> &grid,vector<vector<vector<int>>> &dp)
    {
        int n = grid.size();
        int m = grid[0].size();

        //base
        if(i == n-1 && j == m-1)
        {
            if(grid[i][j] == ')') balance--;
            else balance++;
            return  balance == 0;
        }

        if(dp[i][j][balance] != -1) return dp[i][j][balance];

        int prev_balance = balance;

        if(grid[i][j] == '(') balance++;
        else balance--;

        if(balance < 0) return dp[i][j][prev_balance] = false;
        if(balance > 101)
        return dp[i][j][prev_balance] = false;

        //down
        bool down = false;
        if(i+1 < n) down = helper(i+1,j,balance,grid,dp);

        //right
        bool right = false;
        if(j+1 < m) right = helper(i,j+1,balance,grid,dp);


        return dp[i][j][prev_balance] = down || right;

    }
    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(m+1,vector<int>(107,-1)));


        
        return helper(0,0,0,grid,dp);
    }
};