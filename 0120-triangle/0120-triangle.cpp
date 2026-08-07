class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector <int> prev(n,0);
        for(int i=0;i<n;i++)
        {
            prev[i]=triangle[n-1][i];
        }
        for(int i=n-2;i>=0;i--)
        {    vector <int> curr(n,0);
            for(int j=i;j>=0;j--)
            {
               int sum1=triangle[i][j]+prev[j];
               int sum2=triangle[i][j]+prev[j+1];
               curr[j]=min(sum1,sum2);
            }
            prev=curr;
        }
        return prev[0];
    }
};