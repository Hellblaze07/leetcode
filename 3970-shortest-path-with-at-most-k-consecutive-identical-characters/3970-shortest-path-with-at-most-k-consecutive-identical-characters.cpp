class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector <vector<pair<int,int>>> adj(n);
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        priority_queue<pair<int,pair<int,string>> , vector <pair<int,pair<int,string>>>,greater <pair<int,pair<int,string>>>> q;
        vector<vector <int>> dist(n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<k;j++)
            {
                dist[i].push_back(1e9);
            }
        }
        dist[0][0]=0;
        q.push({0,{0,string(1,labels[0])}});
        while(!q.empty())
        {
            auto pq=q.top();
            int d=pq.first;
            int s=pq.second.first;
            string st=pq.second.second;
            q.pop();
            if(s == n-1)
                return d;
            if(d> dist[s][st.length()-1])
                continue;
            for(auto it:adj[s])
            {
                if(st[0] != labels[it.first])
                {
                    if(d+it.second < dist[it.first][0])
                    {
                        dist[it.first][0] =d+it.second;
                        q.push({d+it.second,{it.first,string(1,labels[it.first])}});
                    }
                }
                else {
                    if(st.length()+1 > k)
                    {
                        continue;
                    }
                    else {
                       if(d+it.second < dist[it.first][st.length()])
                    {
                        dist[it.first][st.length()] =d+it.second;
                        q.push({d+it.second,{it.first,string(st.length()+1,labels[it.first])}});
                    }
                }
                    }
                }
            }
         return -1;  
        }
};