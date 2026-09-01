class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
       int a=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
       if(a == nums.size() || nums[a] != target)
       return {-1,-1};
       else 
       return {a,int(upper_bound(nums.begin(),nums.end(),target)-nums.begin())-1};
    }
};