class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector <int> indegree(n,0);
        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }
        queue<int> qe;
        for(int i=0;i<n;i++)
        {
            if(indegree[i] == 0)
            qe.push(i);
        }
        int cnt=0;
        while(!qe.empty())
        {
            int curr=qe.front();
            qe.pop();
            cnt++;
            for(auto it:adj[curr])
            {
                indegree[it]--;
                if(indegree[it] == 0)
                qe.push(it);
            }
        }
        if(cnt == n)
        return true;
        else return false;
    }
};