class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector <int> mp(256,-1);
        int ans=0;
        int l=0,r=0;
        while(r<s.length())
        {
            if(mp[s[r]] >= l)
                {
                  l=mp[s[r]]+1; 
                }
            ans=max(ans,r-l+1);
            mp[s[r]] = r;
            r++;
        }
        return ans;
    }
};