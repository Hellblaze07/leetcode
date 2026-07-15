class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector <vector<pair<int,int>>> adj(n);
        for(auto it:flights)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector <int> dist(n,1e9);
       queue<pair<pair<int,int>,int>> qe;
       qe.push({{0,src},0});
       dist[src]=0;
       while(!qe.empty())
       {
        int stops=qe.front().first.first;
        int node=qe.front().first.second;
        int dis=qe.front().second;
        qe.pop();
        if(stops>k)
        continue;
        for(auto it:adj[node])
        {
          if(dis+it.second < dist[it.first] && stops<= k)
           { dist[it.first]=dis+it.second;
           qe.push({{stops+1,it.first},dist[it.first]});
           }
        }
       }
       if(dist[dst] == 1e9)
       return -1;
       return dist[dst];
    }
};