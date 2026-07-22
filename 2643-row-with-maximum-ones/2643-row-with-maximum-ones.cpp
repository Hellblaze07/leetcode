class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int maxcnt=0;
        int ind=0;
        for(int i=0;i<n;i++)
        {
          int cnt=0;
          for(int j=0;j<m;j++)
          {
            cnt=cnt+mat[i][j];
          }
          if(cnt > maxcnt)
          {
            maxcnt=cnt;
            ind=i;
          }
        }
        return {ind,maxcnt};
    }
};