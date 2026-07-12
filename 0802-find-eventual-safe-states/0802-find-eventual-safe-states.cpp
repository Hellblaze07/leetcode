class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector <vector<int>> adj(n);
        vector <int> indegree(n,0);
        for(int i=0;i<n;i++)
        {
            for(auto it:graph[i])
            {
                adj[it].push_back(i);
                indegree[i]++;
            }
        }
        queue<int> qe; 
       for(int i=0;i<n;i++)
       {
        if(indegree[i] == 0)
        qe.push(i);
       }
       vector <int> safe;
       while(!qe.empty())
       {
        int curr=qe.front();
        qe.pop();
        safe.push_back(curr);
        for(auto it:adj[curr])
        {
           indegree[it]--;
           if(indegree[it] == 0)
           qe.push(it);
        }
       }
       sort(safe.begin(),safe.end());
       return safe;
    }
};