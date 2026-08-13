class Solution {
public:
    void dfs(int i,vector<vector<int>>& adj,vector <int> &vis,int &count)
    {
        vis[i]=1;
        count++;
        for(auto it:adj[i])
        {
            if(!vis[it])
            dfs(it,adj,vis,count);
        }
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size();
        vector <vector <int>> adj(n);
        for(int i=0;i<n;i++)
        {   
            for(int j=0;j<n;j++)
            {   long long x=abs(bombs[i][0]-bombs[j][0]);
                long long y=abs(bombs[i][1]-bombs[j][1]);
                long long rad=bombs[i][2];
                if((x*x+y*y) <= (rad*rad) && (i != j))
                {
                  adj[i].push_back(j);
                }
            }
        }
            int maxi=1;
            for(int i=0;i<n;i++)
            {
                vector <int> vis(n,0);
                int count=0;
                dfs(i,adj,vis,count);
                maxi=max(maxi,count);
            }
        return maxi;
    }
};