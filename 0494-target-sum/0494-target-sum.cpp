class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum-target<0 || (sum-target)%2 != 0)
        return 0;
        int s1=(sum-target)/2;
        vector <int> prev(s1+1,0);
        vector <int> curr(s1+1,0);
        prev[0]=curr[0]=1;
        if(nums[0] <= s1)
        prev[nums[0]]++;
        for(int i=1;i<n;i++)
        {
            for(int tar=0;tar<=s1;tar++)
            {
                int notpick=prev[tar];
                int pick=0;
                if(nums[i]<=tar)
                pick=prev[tar-nums[i]];
                curr[tar]=notpick+pick;
            }
            prev=curr;
        }
        return prev[s1];
    }
};