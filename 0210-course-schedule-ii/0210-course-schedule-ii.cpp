class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& edges) {
          vector<vector<int>> adj(n);
        vector <int> indegree(n,0);
        for(auto it:edges)
        {
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
        queue<int> qe;
        for(int i=0;i<n;i++)
        {
            if(indegree[i] == 0)
            qe.push(i);
        }
      vector <int> topo;
        while(!qe.empty())
        {
            int curr=qe.front();
            qe.pop();
            topo.push_back(curr);
            for(auto it:adj[curr])
            {
                indegree[it]--;
                if(indegree[it] == 0)
                qe.push(it);
            }
        }
        if(topo.size()== n)
        return topo;
        else return {};
    }
};