class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        map<int,int,greater<int>> mp;
        int n=nums.size();
        for(int i=0;i<n;i++)
        mp[nums[i]]++;
        if(k == n)
        {
           for(auto it:mp)
           {
            return it.first;
           }
        }
        else if(k == 1)
        {
           for(auto it:mp)
           {
            if(it.second == 1)
            return it.first;
           }
           return -1;
        }
        else {
         int maxi=-1;
         if(mp[nums[0]] == 1)
         maxi=max(maxi,nums[0]);
         if(mp[nums[n-1]] == 1)
         maxi=max(maxi,nums[n-1]);
         return maxi;
        }
        return -1; 
    }
};