class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int maxi=0;
        vector <vector <int>> vis(m,vector <int> (n,0));
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!vis[i][j] && grid[i][j] == 1)
                {
                 vis[i][j]=1;
                 int count=0;
                 queue <pair<int,int>> qe;
                 qe.push({i,j});
                 while(!qe.empty())
                 {
                   int r=qe.front().first;
                   int c=qe.front().second;
                   count++;
                   qe.pop();
                   for(int k=0;k<4;k++)
                   {
                     int nrow=r+dx[k];
                     int ncol=c+dy[k];
                     if(nrow >=0 && nrow < m && ncol >= 0 && ncol < n && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1)
                     {
                        qe.push({nrow,ncol});
                        vis[nrow][ncol] =1;
                     }
                   }
                 }
                 maxi=max(maxi,count);
                }
            }
        }
        return maxi;
    }
};