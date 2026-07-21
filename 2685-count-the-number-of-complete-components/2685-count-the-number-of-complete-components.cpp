class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector <int> vis(n,0);
        int cnt=0;
        vector<vector<int>> adj(n);
        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<vector <int>> components(n);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {   queue<int> qe;
                int sum=0;
                qe.push(i);
                vis[i]=1;
                while(!qe.empty())
                {
                 int curr=qe.front();
                 qe.pop();
                 components[cnt].push_back(curr);
                 sum=sum+adj[curr].size();
                 for(auto it:adj[curr])
                 {
                    if(!vis[it])
                    {
                        qe.push(it);
                        vis[it]=1;
                    }
                  }
                }
                components[cnt].push_back(sum);
                cnt++;
            }
        }
        int ans=0;
      for(int i=0;i<cnt;i++)
      {
        int m=components[i].size()-1;
        int sum=components[i][m];
        if(m*(m-1)/2 == sum/2) 
        ans++;
      }
      return ans;
    }
};