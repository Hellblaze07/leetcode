class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector <int> vis(n,0);
        vector <int> pathvis(n,0);
        vector <int> safe;
        vector <int> check(n,0);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
            dfs(i,vis,pathvis,check,graph); 
            }
            if(check[i] == 1)
            safe.push_back(i); 
        }
        return safe;
       
    }
    bool dfs(int node,vector <int> &vis,vector<int> &pathvis,vector<int> &check,
    vector<vector<int>>& graph)
    {
        vis[node]=1;
        pathvis[node]=1;
        for(auto it:graph[node])
        {
            if(!vis[it])
            {
              if(dfs(it,vis,pathvis,check,graph) == true)
              return true;
            }
            else if(pathvis[it])
            {
              return true;
            }
        }
        check[node]=1;
      pathvis[node]=0;
      return false;
    }
};