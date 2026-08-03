class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {   int count1=0,count2=0;
            for(int j=i;j<n;j++)
            {
               if(nums[j]%2 == 0)
               count2++;
               else count1++;
               if(count1>0 && (count2*b <= count1*a))
               ans++;
            }
        }
        return ans;
    }
};