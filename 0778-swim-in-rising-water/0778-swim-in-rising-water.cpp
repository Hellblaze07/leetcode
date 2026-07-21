class Disjoint
   { public:
    vector<int> parent,size;
    Disjoint(int n)
    {
    parent.resize(n+1);
    size.resize(n+1);
    for(int i=0;i<=n;i++)
    {parent[i]=i;
    size[i]=1;
    }
    }
    int findUpar(int node)
    {
        if(parent[node] == node)
        return node;
        return parent[node]=findUpar(parent[node]);
    }
    void UnionBySize(int u,int v)
    {
        int ultu=findUpar(u);
        int ultv=findUpar(v);
        if(ultu == ultv)
        return;
        if(size[ultu]<size[ultv])
        {
            parent[ultu]=ultv;
            size[ultv]+=size[ultu];
        }
        else {
            parent[ultv]=ultu;
            size[ultu]+=size[ultv];
        }
    }
   };
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        int row[n*n];
        int col[n*n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                row[grid[i][j]]=i;
                col[grid[i][j]]=j;
            }
        }
        Disjoint ds(n*n);
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};
        for(int i=0;i<n*n;i++)
        {   int r=row[i];
            int c=col[i];
            int node=r*n+c;
            for(int k=0;k<4;k++)
            { int nr=r+dx[k];
            int nc=c+dy[k];
            if(nr>=0 && nr<n && nc>=0 && nc<n)
            {  int adj=nr*n+nc;
               if(grid[nr][nc]<i)
                ds.UnionBySize(node,adj);
            }
            }
            if(ds.findUpar(0) == ds.findUpar(n*n-1))
            return i;
        }
        return -1;
    }
};