class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int maxi=INT_MIN;
        int mini=INT_MAX;
        int i=-1;
        int j=-1;
        for(int k=0;k<nums.size();k++)
        {
            if(nums[k]>maxi)
            {
                maxi=nums[k];
                i=k;
            }
            if(nums[k]<mini)
            {
                mini=nums[k];
                j=k;
            }
        }
        mini=min(i,j);
        maxi=max(i,j);
        int n=nums.size();
        return min({maxi+1,n-mini,mini+1+(n-maxi)});
    }
};