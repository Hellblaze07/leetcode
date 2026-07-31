class Solution {
public:
    string smallestPalindrome(string s) {
        vector <int> arr(26,0);
        for(auto it:s)
        {
            arr[it-'a']++;
        }
        string ans="";
        string mid="";
        for(int i=0;i<26;i++)
        {
            if(arr[i]>0)
            {
                for(int k=1;k<=(arr[i]/2);k++)
                ans.push_back(char('a'+i));
               if(arr[i]%2)
               mid=char('a'+i);
            }
        }
        ans=ans+mid;
        int i=ans.length()-1-mid.length();
        for(;i>=0;i--)
        {
            ans.push_back(ans[i]);
        }
        return ans;
    }
};