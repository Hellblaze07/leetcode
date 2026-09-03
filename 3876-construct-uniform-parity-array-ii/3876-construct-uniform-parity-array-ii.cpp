class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int a=nums[0];
        if(a&1)
        return true;
        for(auto it:nums)
        {
          if(it&1)
        return false;
        }
        return true;
    }
};