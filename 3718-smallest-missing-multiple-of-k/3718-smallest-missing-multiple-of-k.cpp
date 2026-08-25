class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int i=1;
        int x=k;
        sort(nums.begin(),nums.end());
        for(auto it:nums)
        {
            if(x < it)
            break;
            if(x == it)
            {
                x=k*(++i);
            }
        }
        return x;
    }
};