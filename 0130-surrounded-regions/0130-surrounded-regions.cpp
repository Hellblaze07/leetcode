class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};
        vector<vector<int>> vis(n,vector<int> (m,0));
        for(int j=0;j<m;j++)
        {
            if(board[0][j] == 'O' && vis[0][j] == 0)
            dfs(0,j,vis,board,dx,dy);
            if(board[n-1][j] == 'O' && vis[n-1][j] == 0)
            dfs(n-1,j,vis,board,dx,dy);
        }
        for(int i=0;i<n;i++)
        {
            if(board[i][0] == 'O' && vis[i][0] == 0)
            dfs(i,0,vis,board,dx,dy);
            if(board[i][m-1] == 'O' && vis[i][m-1] == 0)
            dfs(i,m-1,vis,board,dx,dy);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j] == 0)
                board[i][j]='X';
            }
        }
    }
    void dfs(int i,int j,vector<vector<int>>&vis,vector<vector<char>>&board,int dx[],int dy[])
    {
       vis[i][j]=1;
       int n=board.size();
       int m=board[0].size();
       for(int k=0;k<4;k++)
       {
        int nrow=i+dx[k];
        int ncol=j+dy[k];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol] == 0 && 
        board[nrow][ncol] == 'O')
        {
            dfs(nrow,ncol,vis,board,dx,dy);
        }
       }
    }
};