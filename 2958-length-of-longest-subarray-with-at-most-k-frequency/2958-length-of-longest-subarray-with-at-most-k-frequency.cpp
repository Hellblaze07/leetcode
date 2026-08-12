class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        map<int,int> mp;
        int l=0,r=0;
        int n=nums.size();
        int maxlen=0;
        while(r<n)
        {
          mp[nums[r]]++;
          while(mp[nums[r]] > k)
          {
            mp[nums[l]]--;
            l++;
          }
          maxlen=max(maxlen,r-l+1);
          r++;
        }
        return maxlen;
    }
};