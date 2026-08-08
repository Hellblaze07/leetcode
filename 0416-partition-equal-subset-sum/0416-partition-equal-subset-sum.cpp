class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum&1)
        return false;
        int n=nums.size();
        vector <bool> prev(sum/2+1,0);
        vector <bool> curr(sum/2+1,0);
        prev[0]=curr[0]=true;
        if(nums[0] <= sum/2 )
        prev[nums[0]]=true;
        for(int i=1;i<n;i++)
        {
            for(int tar=1;tar<=sum/2;tar++)
            {
                bool nottake=prev[tar];
                bool take=false;
                if(nums[i] <= tar)
                take=prev[tar-nums[i]];
                curr[tar]=take|nottake;
            }
            prev=curr;
        }
        return prev[sum/2];
    }
};