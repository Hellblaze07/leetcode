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
    int makeConnected(int n, vector<vector<int>>& connections) {
        Disjoint ds(n);
        int count=0;
        for(auto it:connections)
        {
            if(ds.findUpar(it[0]) != ds.findUpar(it[1]))
            ds.UnionBySize(it[0],it[1]);
            else count++;
        }
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(ds.parent[i] == i)
            cnt++;
        }
        if(count<(cnt-1))
        return -1;
        else return cnt-1;
    }
};