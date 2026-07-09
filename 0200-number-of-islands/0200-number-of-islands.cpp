class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        vector <vector <int>> vis(n,vector<int> (m,0));
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == '1' && !vis[i][j])
                {
                  ans++;
                  queue<pair<int,int>> qe;
                  qe.push({i,j});
                  vis[i][j]=1;
                  while(!qe.empty())
                  {
                    int row=qe.front().first;
                    int col=qe.front().second;
                    qe.pop();
                    for(int k=0;k<4;k++)
                    {
                        int nrow=row+dx[k];
                        int ncol=col+dy[k];
                        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && 
                        grid[nrow][ncol] == '1' && !vis[nrow][ncol])
                        {
                           vis[nrow][ncol]=1;
                           qe.push({nrow,ncol});
                        }
                    }
                  }
                }
            }
        }
        return ans;
    }
};