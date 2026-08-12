class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        set <int> st;
        for(int i=0;i<n;i++)
        st.insert(i);
        vector <int> ans(n,0);
        set <pair<long long,int>> room;
        int start=0;
        int maxi=0;
        for(auto it:meetings)
        {
           long long start=it[0];
           for(auto i=room.begin();i != room.end();)
           {
            if(i->first <= start)
            {   st.insert(i->second);
              i=room.erase(i);
            }
            else break;
           }
           if(st.empty())
           {
             auto i=room.begin();
             start=(*room.begin()).first;
             st.insert((*room.begin()).second);
             room.erase(room.begin());
           }
           int a=*st.begin();
           st.erase(st.begin());
           room.insert({start+1LL*it[1]-it[0],a});
           ans[a]++;
           if(ans[a] > ans[maxi])
           maxi=a;
           else if(ans[a] == ans[maxi])
           maxi=min(maxi,a);
        }
        return maxi;
    }
};