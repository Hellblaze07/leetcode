class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return counting(nums,k)-counting(nums,k-1);
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
            sum+=(nums[r]%2);
            while(sum>goal)
            {
                sum=sum-nums[l]%2;
                l++;
            }
            if(sum<=goal)
            cnt=cnt+(r-l+1);
            r++;
        }
        return cnt;
    }
};