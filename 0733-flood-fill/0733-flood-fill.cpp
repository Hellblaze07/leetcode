class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        vector <vector<int>> flood=image;
        vector <int> dx={-1,0,1,0};
        vector <int> dy={0,1,0,-1};
        int ini=image[sr][sc];
       dfs(sr,sc,flood,image,dx,dy,color,ini);
       return flood;
    }

 void dfs(int row,int col,vector<vector<int>> &flood,vector<vector<int>> &image,vector<int> &dx,vector<int> &dy,int colour,int ini)
 {  int n=image.size();
    int m=image[0].size();
    flood[row][col]=colour;
    for(int i=0;i<4;i++)
    {
        int nrow=row+dx[i];
        int ncol=col+dy[i];
        if((nrow>=0 && nrow<n && ncol>=0 && ncol<m) && (flood[nrow][ncol] != colour) && (image[nrow][ncol] == ini))
        {
            dfs(nrow,ncol,flood,image,dx,dy,colour,ini);
        }
    }
 }
};