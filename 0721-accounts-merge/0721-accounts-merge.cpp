class Disjoint
   { public:
    vector<int> parent,size;
    Disjoint(int n)
    {
    parent.resize(n+1);
    size.resize(n+1);
    for(int i=0;i<=n;i++)
    {parent[i]=i;
    size[i]=1;
    }
    }
    int findUpar(int node)
    {
        if(parent[node] == node)
        return node;
        return parent[node]=findUpar(parent[node]);
    }
    void UnionBySize(int u,int v)
    {
        int ultu=findUpar(u);
        int ultv=findUpar(v);
        if(ultu == ultv)
        return;
        if(size[ultu]<size[ultv])
        {
            parent[ultu]=ultv;
            size[ultv]+=size[ultu];
        }
        else {
            parent[ultv]=ultu;
            size[ultu]+=size[ultv];
        }
    }
   };
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        Disjoint ds(n);
        unordered_map<string,int> mp;
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<accounts[i].size();j++)
            {
                if(mp.find(accounts[i][j]) == mp.end())
                {
                    mp[accounts[i][j]]=i;
                }
                else {
                    ds.UnionBySize(i, mp[accounts[i][j]]);
                }
            }
        }
         vector<vector<string>>  mail(n);
            for(auto it:mp)
            {
                string s=it.first;
                int node=ds.findUpar(it.second);
                mail[node].push_back(s);
            }
            vector<vector<string>> ans;
            for(int i=0;i<n;i++)
            {
                if(mail[i].size() != 0)
                {
                    string name=accounts[i][0];
                    vector <string> temp;
                    temp.push_back(name);
                    sort(mail[i].begin(),mail[i].end());
                    for(auto it:mail[i])
                    {
                        temp.push_back(it);
                    }
                    ans.push_back(temp);
                }
            }
        return ans;
    }
};