class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n=nums.size();
        int sum=nums[0];
        int i=1;
        int mp[52]={0};
        mp[nums[0]]++;
        for(;i<n;i++)
        {
            if(nums[i] == nums[i-1]+1)
            sum+=nums[i];
            else break;
            mp[nums[i]]++;
        }
        for(;i<n;i++)
        mp[nums[i]]++;
        while(sum <= 50 && mp[sum] != 0)
        sum++;
        return sum;
    }
};