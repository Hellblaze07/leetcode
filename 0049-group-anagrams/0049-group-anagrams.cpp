class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> mp;
        for(auto it:strs)
        {
            string ss=it;
            sort(ss.begin(),ss.end());
            mp[ss].push_back(it);
        }
        vector<vector<string>> st;
        for(auto it:mp)
        st.push_back(it.second);
        return st;
    }
};