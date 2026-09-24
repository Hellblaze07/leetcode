class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int sum=0;
            int a=nums[i];
            while(a>0)
            {
                sum+=a%10;
                a=a/10;
            }
            if(sum == i)
            return i;
        }
        return -1;
    }
};