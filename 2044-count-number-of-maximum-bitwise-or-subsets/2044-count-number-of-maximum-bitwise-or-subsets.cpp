class Solution {
public:
    int func(int i,vector<int>& nums,int &maxi,int o)
    {
     if( i < 0)
     {
        if(o == maxi)
        return 1;
        else return 0;
     }
     int notpick=func(i-1,nums,maxi,o);
     int pick=func(i-1,nums,maxi,o|nums[i]);
     return notpick+pick;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int o=0;
        for(auto it:nums)
        o = o | it;
        return func(nums.size()-1,nums,o,0);
        }
};