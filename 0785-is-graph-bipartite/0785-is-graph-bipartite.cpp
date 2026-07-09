class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector <int> vis(n,-1);
        for(int i=0;i<n;i++)
        {
            if(vis[i] == -1)
            {
               vis[i]=0;
               queue<int> qe;
               qe.push(i);
               while(!qe.empty())
               {
                int curr=qe.front();
                qe.pop();
                for(auto it:graph[curr])
                {
                    if(vis[it] == -1)
                    {
                        vis[it]=!vis[curr];
                        qe.push(it);
                    }
                    else {
                        if(vis[it] == vis[curr])
                        return false;
                    }
                }
               }
            }
        }
        return true;

    }
};