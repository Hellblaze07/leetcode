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
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        Disjoint ds(n*n);
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
               if(grid[i][j] == 1)
               {  int node=i*n+j;
                for(int k=0;k<4;k++)
                {
                    int nrow=i+dx[k];
                    int ncol=j+dy[k];
                    if(nrow>=0 && nrow<n && ncol>= 0 && ncol<n && grid[nrow][ncol] == 1)
                    {
                        int newnode=nrow*n+ncol;
                        ds.UnionBySize(node,newnode);
                    }
                }
               }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == 0)
                {
                    int node=i*n+j;
                    set <int> adj;
                for(int k=0;k<4;k++)
                {
                    int nrow=i+dx[k];
                    int ncol=j+dy[k];
                    if(nrow>=0 && nrow<n && ncol>= 0 && ncol<n && grid[nrow][ncol] == 1)
                    {
                        int newnode=nrow*n+ncol;
                        adj.insert(ds.parent[ds.findUpar(newnode)]);
                    }
                }
                 int sum=0;
                 for(auto it:adj)
                 {
                    sum+=ds.size[it];
                 }
                 maxi=max(maxi,sum+1);
                }
            }
        }
        for(int i=0;i<n*n;i++)
        {
            maxi=max(maxi,ds.size[ds.findUpar(i)]);
        }
return maxi;
    }
};