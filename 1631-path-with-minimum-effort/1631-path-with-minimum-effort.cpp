class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>> dis(n,vector <int> (m,1e9));
        dis[0][0]=0;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> qe;
        qe.push({0,{0,0}});
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};
        while(!qe.empty())
        {
            int diff=qe.top().first;
            int row=qe.top().second.first;
            int col=qe.top().second.second;
            qe.pop();
            for(int i=0;i<4;i++)
            {
                int nrow=row+dx[i];
                int ncol=col+dy[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m)
                {
                    int ndiff=max(diff,abs(heights[nrow][ncol]-heights[row][col]));
                    if(ndiff < dis[nrow][ncol])
                    {
                        dis[nrow][ncol]=ndiff;
                        qe.push({ndiff,{nrow,ncol}});
                    }
                }
            }
        }
        return dis[n-1][m-1];
    }
};