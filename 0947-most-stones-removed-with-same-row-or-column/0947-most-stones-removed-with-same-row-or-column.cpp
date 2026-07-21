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
    int removeStones(vector<vector<int>>& stones) {
        int maxrow=0;
        int maxcol=0;
        for(auto it:stones)
        {
            maxrow=max(maxrow,it[0]);
            maxcol=max(maxcol,it[1]);
        }
        Disjoint ds(maxrow+maxcol+1);
        unordered_map<int,int> mp;
        for(auto it:stones)
        {
          ds.UnionBySize(it[0],maxrow+it[1]+1);
          mp[it[0]]=1;
          mp[it[1]+maxrow+1]=1;
        }
        int cnt=0;
        for(auto it:mp)
        {
            if(ds.findUpar(it.first) == it.first)
            cnt++;
        }
        return stones.size()-cnt;
    }
};