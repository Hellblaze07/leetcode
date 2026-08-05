class Solution {
public:
     void dfs(int k,vector<vector<int>>& adj,vector <int> &vis)
     {
        vis[k]=2;
        for(auto it:adj[k])
        {   if(vis[it] == 0)
            dfs(it,adj,vis);
        }
     }
     bool dfs2(int i,vector<vector<int>>& adj,vector <int> &vis)
     {
       vis[i]=1;
       for(auto it:adj[i])
       {
        if(vis[it] == 2)
        return true;
        else if(vis[it] == 0)
      {if(dfs2(it,adj,vis) == true)
       return true; }
       }
       return false;
     }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector <vector <int>> adj(n);
        for(auto it:invocations)
        {
            adj[it[0]].push_back(it[1]);
        }
        vector <int> vis(n,0);
       dfs(k,adj,vis);
       bool flag=false;
       for(int i=0;i<n;i++)
       {
        if(vis[i] == 0)
       { if(dfs2(i,adj,vis) == true)
        flag=true;
       }
       }
       vector <int> ans;
       if(!flag)
       {
        for(int i=0;i<n;i++)
        {
            if(vis[i] != 2)
            ans.push_back(i);
        }
       }
       else 
       {
        for(int i=0;i<n;i++)
        {
            ans.push_back(i);
        }
       }
       return ans;
    }
};