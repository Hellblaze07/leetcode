class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector <vector<int>> vis(n,vector <int> (m,-1));
        queue<pair<pair<int,int>,int>> qe;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
               if(mat[i][j] == 0)
               {
                vis[i][j]=0;
                qe.push({{i,j},0});
               }
            }
        }
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};
        while(!qe.empty())
        {
           int i=qe.front().first.first;
           int j=qe.front().first.second;
           int dis=qe.front().second;
           qe.pop();
           for(int k=0;k<4;k++)
           {
            int nrow=i+dx[k];
            int ncol=j+dy[k];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && mat[nrow][ncol] == 1 && 
            vis[nrow][ncol] == -1)
            {
                vis[nrow][ncol]=dis+1;
                qe.push({{nrow,ncol},dis+1});
            }
           }   
        }
        return vis;
    }
};