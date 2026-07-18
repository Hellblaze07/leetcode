class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return counting(nums,goal)-counting(nums,goal-1);
    }
    int counting(vector<int>& nums,int goal)
    {
        if(goal<0)
        return 0;
        int l=0,r=0;
        int sum=0;
        int n=nums.size();
        int cnt=0;
        while(r<n)
        {
            sum+=nums[r];
            while(sum>goal)
            {
                sum=sum-nums[l];
                l++;
            }
            if(sum<=goal)
            cnt=cnt+(r-l+1);
            r++;
        }
        return cnt;
    }
};