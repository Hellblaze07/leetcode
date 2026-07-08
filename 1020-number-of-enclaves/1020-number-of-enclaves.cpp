class Solution {
public:
    void bfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>&vis,int dx[],int dy[])
    {
        vis[i][j]=1;
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> qe;
        qe.push({i,j});
        while(!qe.empty())
        {
            int row=qe.front().first;
            int col=qe.front().second;
            qe.pop();
            for(int k=0;k<4;k++)
            {
                int nrow=row+dx[k];
                int ncol=col+dy[k];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol] == 1 && !vis[nrow][ncol] )
                {
                    vis[nrow][ncol]=1;
                    qe.push({nrow,ncol});
                }
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};
        vector<vector<int>> vis(n,vector<int> (m,0));
        for(int i=0;i<n;i++)
        {
           if(grid[i][0] == 1 && !vis[i][0])
          { 
            bfs(i,0,grid,vis,dx,dy);
          }
           if(grid[i][m-1] == 1 && !vis[i][m-1])
           bfs(i,m-1,grid,vis,dx,dy);
        }
        for(int j=0;j<m;j++)
        {
            if(grid[0][j] == 1 && !vis[0][j])
            {
             bfs(0,j,grid,vis,dx,dy);
            }
            if(grid[n-1][j] == 1 && !vis[n-1][j])
            {
             bfs(n-1,j,grid,vis,dx,dy);
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 1 && !vis[i][j])
                cnt++;
            }
        }
        return cnt;
    }
};