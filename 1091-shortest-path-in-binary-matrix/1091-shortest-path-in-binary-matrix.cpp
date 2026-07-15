class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        vector <vector<int>> dist(n,vector<int> (n,-1));
        queue <pair<int,pair<int,int>>> qe;
        if(grid[0][0] == 1)
        return -1;
        qe.push({1,{0,0}});
        dist[0][0]=1;
        while(!qe.empty())
        {
            int dis=qe.front().first;
            int row=qe.front().second.first;
            int col=qe.front().second.second;
            qe.pop();
            for(int i=-1;i<=1;i++)
            {
                for(int j=-1;j<=1;j++)
                {
                    int nrow=row+i;
                    int ncol=col+j;
                    if(nrow >= 0 && ncol >= 0 && nrow <n && ncol < n && grid[nrow][ncol] == 0)
                    {
                        if(dist[nrow][ncol] == -1)
                        {
                            dist[nrow][ncol]=dis+1;
                            qe.push({dist[nrow][ncol],{nrow,ncol}});
                        }
                    }
                }
            }
        }
        return dist[n-1][n-1];
    }
};