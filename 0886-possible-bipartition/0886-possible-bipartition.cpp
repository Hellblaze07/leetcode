class Solution {
public:
    bool dfs(int i,int col, vector<vector<int>> &adj,vector <int>&vis)
    {
        vis[i]=col;
        for(auto it:adj[i])
        {
            if(vis[it] != -1 && vis[it] == col)
            return false;
            else if( vis[it] == -1  && dfs(it,!col,adj,vis) == false)
            return false;
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector <vector <int>> adj(n+1);
        for(auto it:dislikes)
       { adj[it[0]].push_back(it[1]);
       adj[it[1]].push_back(it[0]);
       }

        vector <int> vis(n+1,-1);
        for(int i=1;i<=n;i++)
        {   if(vis[i] == -1)
            if(dfs(i,0,adj,vis) == false)
            return false;
        }
        return true;
    }
};