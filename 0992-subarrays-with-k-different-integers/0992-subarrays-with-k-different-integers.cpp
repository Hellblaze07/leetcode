class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return counting(nums,k)-counting(nums,k-1);
    }
    int counting(vector<int>& nums,int k)
    {
        int l=0,r=0;
        map<int,int> mp;
        int n=nums.size();
        int cnt=0;
        while(r<n)
        {
           mp[nums[r]]++;
            while(mp.size()>k)
            {
                mp[nums[l]]--;
                if(mp[nums[l]] == 0)
                mp.erase(nums[l]);
                l++;          
            }
            if(mp.size()<=k)
            cnt=cnt+(r-l+1);
            r++;
        }
        return cnt;
    }
};