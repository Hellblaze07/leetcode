class Solution {
public:
    int func(int i,int j,vector<vector<int>>& triangle,vector<vector<int>>& dp)
    {  int n=triangle.size();
      if(i == n-1)
      return triangle[i][j];
      if(dp[i][j] != 1e9)
      return dp[i][j];
    int sum1=triangle[i][j]+func(i+1,j,triangle,dp);
    int sum2=triangle[i][j]+func(i+1,j+1,triangle,dp);
    return dp[i][j] = min(sum1,sum2);
    }
    int minimumTotal(vector<vector<int>>& triangle) {

        vector <vector <int>> dp(207,vector <int> (207,1e9));
        return func(0,0,triangle,dp);
    }
};