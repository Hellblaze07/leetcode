class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector <vector <int>> front(m,vector <int> (m,0));
        vector <vector <int>> curr(m,vector <int> (m,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i == j)
                front[i][j]=grid[n-1][j];
                else front[i][j]=grid[n-1][i]+grid[n-1][j];
            }
        }
        for(int i=n-2;i>=0;i--)
        {
            for(int j1=0;j1<m;j1++)
            {
                for(int j2=0;j2<m;j2++)
                {
                    int maxi=INT_MIN;
                    for(int dx=-1;dx<=1;dx++)
                    {
                        for(int dy=-1;dy<=1;dy++)
                        {
                            int value=0;
                            if(j1 == j2)
                            value=grid[i][j1];
                            else value=grid[i][j1]+grid[i][j2];
                            if(j1+dx >= 0 && j1+dx < m && j2+dy < m && j2+dy >= 0)
                            {
                                value+=front[j1+dx][j2+dy];
                            }
                            else value-=1e8;
                            maxi=max(maxi,value);
                        }
                    }
                    curr[j1][j2]=maxi;
                }
            }
            front=curr;
        }
   return front[0][m-1];
    }
};