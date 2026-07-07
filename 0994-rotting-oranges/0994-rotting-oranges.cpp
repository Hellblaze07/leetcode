class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector <int> (m,0));
        queue<pair<pair<int,int>,int>> qe;
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 2)
                {
                    vis[i][j]=2;
                    qe.push({{i,j},0});
                }
                if(grid[i][j] == 1)
                count++;
            }
        }
        int ans=0;
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};
        while(!qe.empty())
        {
            int row=qe.front().first.first;
            int col=qe.front().first.second;
            int t=qe.front().second;
            qe.pop();
            for(int k=0;k<4;k++)
            {
                int nrow=row+dx[k];
                int ncol=col+dy[k];
                if(nrow>=0 && nrow<n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && vis[nrow][ncol] == 0)
                {
                    count--;
                    vis[nrow][ncol]=2;
                    qe.push({{nrow,ncol},t+1});
                    ans=t+1;
                }
            }
        }
        if(count != 0)
        return -1;
        return ans;
    }
};