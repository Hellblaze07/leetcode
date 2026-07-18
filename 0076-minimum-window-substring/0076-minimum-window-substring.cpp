class Solution {
public:
    string minWindow(string s, string t) {
        int l=0,r=0;
        map<char,int> mp;
        for(auto it:t)
        mp[it]++;
        int n=s.length();
        int cnt=0;
        int minlen=1e9;
        int index=-1;
        while(r<n)
        {
            if(mp[s[r]] > 0)
            cnt++;
            mp[s[r]]--;
            while(cnt == t.size())
            {
                if(r-l+1<minlen)
                {
                    minlen=r-l+1;
                    index=l;
                }
                mp[s[l]]++;
                if(mp[s[l]] > 0)
                cnt--;
                l++;
            }
            r++;
        }
        return index == -1?"":s.substr(index,minlen);
    }
};