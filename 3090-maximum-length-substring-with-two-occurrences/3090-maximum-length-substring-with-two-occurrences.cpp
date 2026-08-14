class Solution {
public:
    int maximumLengthSubstring(string s) {
        map <int,int> mp;
        int n=s.length();
        int maxi=0;
        int l=0,r=0;
        while(r<n)
        {
            mp[s[r]]++;
            while(mp[s[r]] > 2)
            {
                mp[s[l]]--;
                l++;
            }
            maxi=max(maxi,r-l+1);
            r++;
        }
        return maxi;
    }
};