class Solution {
public:
    int minPathSum(vector<vector<int>>& matrix) {
       int m=matrix.size();
       int n=matrix[0].size();
       vector <int> prev(n,0);
       for(int i=0;i<m;i++)
       {  vector <int> curr(n,0);
        for(int j=0;j<n;j++)
        {  if(i == 0 && j == 0)
            curr[j]=matrix[i][j];
            else { 
            int up=matrix[i][j];
            int down=matrix[i][j];
            if(i>0)
            up+=prev[j];
            else up+=1e9;
            if(j>0)
            down+=curr[j-1];
            else down+=1e9;
            curr[j]=min(up,down);
        }
        }
        prev=curr;
       } 
       return prev[n-1];
    }
};