class Solution {
public:
      bool dfs(int i,int j,int k,vector<vector<char>>& board,vector<vector<int>>& vis,string &word)
{   vis[i][j]=1;
    if(k == word.length()-1)
    {
        if(board[i][j] == word[k])
        return true;
        else{ vis[i][j]=0;
            return false;
        }
    }
    if(board[i][j] != word[k])
   {  vis[i][j]=0;
      return false;
   }
    int m=board.size();
    int n=board[0].size();
    int dx[]={-1,0,1,0};
    int dy[]={0,1,0,-1};
    for(int z=0;z<4;z++)
    {
        int nrow=i+dx[z];
        int ncol=j+dy[z];
        if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && board[nrow][ncol] == word[k+1] && !vis[nrow][ncol])
        {
           if(dfs(nrow,ncol,k+1,board,vis,word) == true)
           return true;
        }
    }
    vis[i][j]=0;
    return false;  
}
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>> vis(m,vector <int> (n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j] == word[0])
                {  
                  if(dfs(i,j,0,board,vis,word) == true)
                  return true;
                }
            }
        }
        return false;
    }
};
