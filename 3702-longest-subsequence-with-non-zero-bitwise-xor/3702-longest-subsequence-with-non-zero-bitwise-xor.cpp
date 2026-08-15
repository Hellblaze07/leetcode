class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xo=0;
        int flag=1;
        int n=nums.size();
        for(auto it:nums)
        {
            if(it != 0)
            flag=0;
            xo=xo^it;
        }
        if(flag)
        return 0;
        return xo == 0?n-1:n;
    }
};