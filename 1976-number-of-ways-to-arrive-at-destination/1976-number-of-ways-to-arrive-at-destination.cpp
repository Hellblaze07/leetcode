class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int MOD=1e9+7;
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:roads)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector <long long> dis(n,LLONG_MAX);
        vector <long long> ways(n,0);
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
        pq.push({0,0});
        dis[0]=0;
        ways[0]=1;
        while(!pq.empty())
        {
            long long dist=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto it:adj[node])
            {
                if(dist+it.second < dis[it.first]*1LL)
                {   ways[it.first]=ways[node];
                    dis[it.first]=dist+it.second;
                    pq.push({dis[it.first],it.first});
                }
                else if(dist+it.second == dis[it.first]*1LL)
                {
                   ways[it.first]+=ways[node];
                   ways[it.first]%=MOD;
                }
            }
        }
        return ways[n-1]%MOD;
    }
};